/*
  Author: Stephan Beal (http://wanderinghorse.net/home/stephan/)

  License: Public Domain
*/
#include "bytearray.hpp"
#include <zlib.h>
#include <string.h> /* memset() */

namespace v8 { namespace convert {

    int GZipJSByteArray( JSByteArray const & src, JSByteArray & dest, int level )
    {
        /**
           Achtung: this impl was a quick hack port from another tree. It is
           not an optimal solution.
        */
        if( &src == &dest ) return -1;
        else if( level != Z_DEFAULT_COMPRESSION )
        {
            if( level < Z_NO_COMPRESSION ) level = Z_NO_COMPRESSION;
            else if (level > Z_BEST_COMPRESSION) level = Z_BEST_COMPRESSION;
        }
        {
            /* Code taken 99% from http://zlib.net/zlib_how.html */
            int ret;
            int flush;
            size_t have;
            z_stream strm;
            enum { bufSize  = 1024 * 8 };
            unsigned char const * in = NULL;
            unsigned char const * inPos = NULL;
            uint32_t const inLen = src.length();
            unsigned char out[bufSize];
            memset( &strm, 0, sizeof(z_stream) );

            in = (unsigned char const *)src.rawBuffer();
            inPos = in;
            /* allocate deflate state */
            strm.zalloc = Z_NULL;
            strm.zfree = Z_NULL;
            strm.opaque = Z_NULL;
            ret = /*deflateInit(&strm, level) */
                deflateInit2( &strm, level, Z_DEFLATED, 16+MAX_WBITS /*gzip compat*/, 8, Z_DEFAULT_STRATEGY )
                ;
            if (ret != Z_OK)
            {
                return ret;
            }

            /* compress until end of file */
            do
            {
                size_t iosize = bufSize;
                if( (inPos + iosize) >= (in + inLen) )
                {
                    iosize = in + inLen - inPos;
                }
                strm.avail_in = iosize;
                flush = (iosize < bufSize) ? Z_FINISH : Z_NO_FLUSH;
                strm.next_in = (Bytef *)inPos;
                inPos += iosize;
                /* run deflate() on input until output buffer not full, finish
                   compression if all of source has been read in */
                do
                {
                    strm.avail_out = bufSize;
                    strm.next_out = out;
                    ret = deflate(&strm, flush);    /* no bad return value */
                    if( Z_STREAM_ERROR == ret )
                    {
                        (void)deflateEnd(&strm);
                        return Z_STREAM_ERROR;
                    }
                    have = bufSize - strm.avail_out;
                    if( have )
                    {
                        dest.append( out, have );
                    }
                } while (strm.avail_out == 0);
                if( strm.avail_in != 0)
                {
                    fprintf(stderr,"Not all input was consumed! %u byte(s) remain!",
                            (unsigned int) strm.avail_in );
                    (void)deflateEnd(&strm);
                    return Z_STREAM_ERROR;
                }
                /* done when last data in file processed */
            } while (flush != Z_FINISH);
            /*assert(ret == Z_STREAM_END);        //stream will be complete */
            /* clean up and return */
            (void)deflateEnd(&strm);
            return (ret == Z_STREAM_END) ? Z_OK : ret;
        }
    }

    int GUnzipJSByteArray( JSByteArray const & src, JSByteArray & dest )
    {
        /**
           Achtung: this impl was a quick hack port from another tree. It is
           not an optimal solution.
        */
        if( &src == &dest ) return -1;
        else
        {
            /* Code taken 99% from http://zlib.net/zlib_how.html */
            int ret;
            size_t have;
            z_stream strm;
            enum { bufSize  = 1024 * 8 };
            unsigned char const * in = (unsigned char const *)src.rawBuffer();
            unsigned char const * inPos = in;
            uint32_t const inLen = src.length();
            unsigned char out[bufSize];
            memset( &strm, 0, sizeof(z_stream) );
            strm.zalloc = Z_NULL;
            strm.zfree = Z_NULL;
            strm.opaque = Z_NULL;
            strm.avail_in = 0;
            strm.next_in = Z_NULL;
            ret = /*inflateInit( &strm ) */
                inflateInit2( &strm, 16+MAX_WBITS /* for gzip compatibility */ )
                /* valgrind says:

                ==4503== Conditional jump or move depends on uninitialised value(s)
                ==4503==    at 0x5B8EE40: inflateReset2 (in /lib/libz.so.1.2.3.4)
                ==4503==    by 0x5B8EF2F: inflateInit2_ (in /lib/libz.so.1.2.3.4)
                ==4503==    by 0x4E3E91C: whio_stream_gunzip (whio_zlib.c:130)
                ...
                ==4503==  Uninitialised value was created by a heap allocation
                ==4503==    at 0x4C2815C: malloc (vg_replace_malloc.c:236)
                ==4503==    by 0x5B8EF0B: inflateInit2_ (in /lib/libz.so.1.2.3.4)
                ==4503==    by 0x4E3E91C: whio_stream_gunzip (whio_zlib.c:130)
                ...

                but i have no clue why.

                (is libz really version 1.2.3.4?)
                */
                ;
            if (ret != Z_OK)
            {
                return ret;
            }
            do
            {
                size_t iosize = bufSize;
                if( (inPos + iosize) >= (in + inLen) )
                {
                    iosize = in + inLen - inPos;
                }
                strm.avail_in = iosize;
                if (strm.avail_in == 0)
                    break;
                strm.next_in = (Bytef *)inPos;
                inPos += iosize;
                /* run inflate() on input until output buffer not full */
                do
                {
                    strm.avail_out = bufSize;
                    strm.next_out = out;
                    ret = inflate(&strm, Z_NO_FLUSH);
                    switch (ret)
                    {
                      case Z_NEED_DICT:
                          ret = Z_DATA_ERROR; /* and fall through */
                      case Z_STREAM_ERROR:
                      case Z_DATA_ERROR:
                      case Z_MEM_ERROR:
                          (void)inflateEnd(&strm);
                          return ret;
                      default:
                          break;
                    }
                    have = bufSize - strm.avail_out;
                    if( have )
                    {
                        dest.append( out, have );
                    }
                } while (strm.avail_out == 0);
                /* done when inflate() says it's done */
            } while (ret != Z_STREAM_END);
            (void)inflateEnd( &strm );
            return (ret == Z_STREAM_END) ? Z_OK : Z_DATA_ERROR;
        }
    }
    
}}
