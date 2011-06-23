/************************************************************************
Author: Stephan Beal (http://wanderinghorse.net/home/stephan)

License: New BSD

Based very heavily on:

http://code.google.com/p/v8cgi/source/browse/trunk/src/lib/socket/socket.cc

by Ondrej Zara


************************************************************************/
#if !defined _POSIX_SOURCE
#define _POSIX_SOURCE 1
#endif
#if !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif

#include <v8/convert/convert.hpp>
#include <v8/convert/properties.hpp>

#include <sstream>
#include <vector>

#if 1 && !defined(CERR)
#include <iostream> /* only for debuggering */
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << " : "
#endif

namespace cv = v8::convert;
#define JSTR(X) v8::String::New(X)

#include "bytearray.hpp"

using cv::JSByteArray;


#define BA_JS_CLASS_NAME "ByteArray"

namespace v8 { namespace convert {

    //! In bytearray_z.cpp
    int GZipJSByteArray( JSByteArray const & src, JSByteArray & dest, int level = 3 );
    //! In bytearray_z.cpp    
    int GUnzipJSByteArray( JSByteArray const & src, JSByteArray & dest );

    
    JSByteArray * ClassCreator_Factory<JSByteArray>::Create( v8::Handle<v8::Object> & jsSelf, v8::Arguments const & argv )
    {
        int const argc  = argv.Length();
        JSByteArray * ba = NULL;
        if(1==argc)
        {
            ba = new JSByteArray( argv[0] );
        }
        else if( 2 == argc )
        {
            ba = new JSByteArray( argv[0], cv::CastFromJS<unsigned int>(argv[1]) );
        }
        else if( ! argc )
        {
            ba = new JSByteArray();
        }
        if( !ba )
        {
            throw std::runtime_error("Could not create new JS-side "BA_JS_CLASS_NAME" instance.");
        }
        return ba;
    }

    void ClassCreator_Factory<JSByteArray>::Delete( JSByteArray * obj )
    {
        delete obj;
    }
    
} } // v8::convert

/************************************************************************
   Down here is where the runtime setup parts of the bindings take place...
************************************************************************/
JSByteArray::~JSByteArray()
{
}

JSByteArray::JSByteArray( v8::Handle<v8::Value> const & val, unsigned int len )
    : vec()
{
    if( !val.IsEmpty()
        && !val->IsNull()
        && !val->IsUndefined()
        )
    {
        
        if( val->IsNumber() )
        {
            const int32_t x = cv::JSToInt32( val );
            if( x < 0 )
            {
                std::ostringstream msg;
                msg << BA_JS_CLASS_NAME
                    << " ctor argument may not be a negative number.";
                throw std::runtime_error( msg.str().c_str() );
            }
            this->length( (unsigned int)x );
            return;
        }
        else if( val->IsObject() )
        { // TODO: honor len here.
            JSByteArray * other = CastFromJS<JSByteArray>(val);
            if( other )
            {
                this->append( *other );
                return;
            }
            else
            {
                std::ostringstream msg;
                msg << BA_JS_CLASS_NAME
                    << " ctor argument is not a "<<BA_JS_CLASS_NAME<<" object.";
                throw std::range_error( msg.str().c_str() );
            }
        }
        else
        {
            std::string const & x( cv::JSToStdString( val ) );
            if( ! len ) len = x.size();
            if( len > x.size() ) len = x.size();
            if( len )
            {
                this->length( len );
                this->vec.assign( x.begin(), x.end() );
            }
            return;
        }
    }
}

void JSByteArray::swapBuffer( BufferType & buf )
{
    this->vec.swap(buf);
}

v8::Handle<v8::Value> JSByteArray::indexedPropertyGetter(uint32_t index, const v8::AccessorInfo &info)
{
    //CERR << "indexed getter: "<<index<<'\n';
    JSByteArray * ar = cv::CastFromJS<JSByteArray*>( info.This() );
    if( ! ar ) return v8::ThrowException(JSTR("Native 'this' not found!"));
    if( index >= ar->length() ) return v8::Undefined();
    else
    {
        return cv::CastToJS<int>( ar->vec[index] );
    }
}

v8::Handle<v8::Value> JSByteArray::indexedPropertySetter(uint32_t index, v8::Local< v8::Value > value, const v8::AccessorInfo &info)
{
    //CERR << "indexed setter: "<<index<<'\n';
    v8::Handle<v8::Value> rv;
    JSByteArray * ar = cv::CastFromJS<JSByteArray*>( info.This() );
    if( ! ar ) return v8::ThrowException(JSTR("Native 'this' not found!"));
#if 0
    if( index >= ar->length() )
    {
        ar->length( index+1 );
        //CERR << "capacity = "<<ar->vec.capacity()<<'\n';
        //CERR << "size = "<<ar->vec.size()<<'\n';
    }
#endif
    if( index >= ar->length() )
    {
#if 1
        cv::StringBuffer msg;
        msg << "Index "<<index<<" is out of bounds for "
            <<BA_JS_CLASS_NAME
            << " of length "<<ar->length()<<'!';
        return v8::ThrowException(msg);
#else
        return rv;
#endif
    }
    else
    {
        return cv::CastToJS<uint16_t>( ar->vec[index] = static_cast<unsigned char>( cv::CastFromJS<uint16_t>(value) ) );
    }
}

v8::Handle<v8::Integer> JSByteArray::indexedPropertyQuery(uint32_t index, const v8::AccessorInfo &info)
{
    //CERR << "indexed query "<<index<<'\n';
    JSByteArray * ar = cv::CastFromJS<JSByteArray*>( info.This() );
    if( ! ar ) return v8::Handle<v8::Integer>();
    else
    {
#if 0
        return (index < ar->length())
            ? v8::True()
            : v8::False()
            ;
#else
        return v8::Integer::New(0);
        /*
          The return type of this function changed from Boolean
          sometime in 2010 and the bastards didn't document what the
          new semantics are. They write only that the integer "encodes
          information about the property." Poking around in v8's
          sources seems to imply that any non-empty integer handle is
          treated as "true" here.
         */
#endif
    }
}
v8::Handle<v8::Boolean> JSByteArray::indexedPropertyDeleter(uint32_t index, const v8::AccessorInfo &info)
{
    //CERR << "indexed deleter "<<index<<'\n';
    //CERR << "marker!\n";
    return v8::False();
}
v8::Handle<v8::Array> JSByteArray::indexedPropertyEnumerator(const v8::AccessorInfo &info)
{
    //CERR << "indexed enumerator\n";
    v8::Handle<v8::Array> rv;
    JSByteArray * ar = cv::CastFromJS<JSByteArray*>( info.This() );
    if( ! ar )
    {
        v8::ThrowException(JSTR("Native 'this' not found!"));
        return rv;
    }
    rv = v8::Handle<v8::Array>( v8::Array::New(ar->length()) );
    for( uint32_t i = 0; i < ar->length(); ++i )
    {
        rv->Set( i, cv::CastToJS(i) );
    }
    return rv;
}
std::string JSByteArray::toString() const
{
    std::ostringstream os;
    os << "[object "
       << BA_JS_CLASS_NAME
       << "@"<<(void const *)this
       << ", length="<<this->length()
       << ']';
    return os.str();
}

#if 0
void * JSByteArray::rawBuffer()
{
    return this->vec.empty()
        ? NULL
        : &this->vec[0];
}
#endif

void const * JSByteArray::rawBuffer() const
{
    return this->vec.empty()
        ? NULL
        : &this->vec[0];
}

uint32_t JSByteArray::length( uint32_t sz )
{
    //CERR << "length("<<sz<<")!\n";
    if( sz > this->vec.max_size() )
    {
        cv::StringBuffer msg;
        msg << BA_JS_CLASS_NAME
            << " length "<<sz << " is too large to store "
            << "in std::vector! Max size is "<< this->vec.max_size()<<".";
        throw std::runtime_error( msg.Content().c_str() );
    }
    if( sz != this->vec.size() )
    {
        this->vec.resize(sz,0);
    }
    return this->vec.size();
}

void JSByteArray::append( void const * src, unsigned int len )
{
    if( ! src || !len ) return;
    size_t const newLen = this->length() + len;
    this->vec.reserve( newLen );
    unsigned char const * beg = (unsigned char const *)src;
    std::copy( beg, beg + len, std::back_inserter(this->vec) );
}
void JSByteArray::append( JSByteArray const & other )
{
    std::copy( other.vec.begin(), other.vec.end(), std::back_inserter(this->vec) );
}


void JSByteArray::append( v8::Handle<v8::Value> val )
{
    if( val->IsString() )
    {
        v8::String::Utf8Value asc(val);
        this->append( *asc, static_cast<unsigned int>(asc.length()) );
        return;
    }
    else if( val->IsNumber() )
    {
        unsigned char x = (unsigned char)val->Int32Value();
        this->append( &x, 1 );
        return;
    }
    else
    {
        JSByteArray * ba = cv::CastFromJS<JSByteArray>(val);
        if( !ba )
        {
            goto toss;
        }
        this->append( ba->rawBuffer(), ba->length() );
        return;
    }
    toss:
    v8::ThrowException(v8::Exception::Error(JSTR("Argument to append() must be one of (Number,String,ByteArray)")));
    return;
}

int JSByteArray::gzipTo( JSByteArray & dest, int level ) const
{
    return GZipJSByteArray( *this, dest, level );
}
int JSByteArray::gzipTo( JSByteArray & dest ) const
{
    return GZipJSByteArray( *this, dest, 3 );
}

int JSByteArray::gunzipTo( JSByteArray & dest ) const
{
    return GUnzipJSByteArray( *this, dest );
}

v8::Handle<v8::Value> JSByteArray::gzip() const
{
    v8::HandleScope sc;
    typedef cv::ClassCreator<JSByteArray> CW;
    v8::Handle<v8::Object> jba =
        CW::Instance().NewInstance( 0, NULL );
    JSByteArray * ba = cv::CastFromJS<JSByteArray>( jba );
    if( ! ba )
    {
        cv::StringBuffer msg;
        msg << "Creation of ByteArray object failed!";
        return v8::ThrowException( msg.toError() );
    }
    int const rc = this->gzipTo( *ba );
    if( rc )
    {
        CW::Instance().DestroyObject( jba );
        return v8::Null();
    }
    return sc.Close(jba);
}
v8::Handle<v8::Value> JSByteArray::gunzip() const
{
    v8::HandleScope sc;
    typedef cv::ClassCreator<JSByteArray> CW;
    v8::Handle<v8::Object> jba =
        CW::Instance().NewInstance( 0, NULL );
    JSByteArray * ba = cv::CastFromJS<JSByteArray>( jba );
    if( ! ba )
    {
        cv::StringBuffer msg;
        msg << "Creation of ByteArray object failed!";
        return v8::ThrowException( msg.toError() );
    }
    int const rc = this->gunzipTo( *ba );
    if( rc )
    {
        CW::Instance().DestroyObject( jba );
        return v8::Null();
    }
    return sc.Close(jba);
}


void JSByteArray::SetupBindings( v8::Handle<v8::Object> dest )
{
    using namespace v8;
    HandleScope scope;
    typedef JSByteArray N;
    typedef cv::ClassCreator<N> CW;
    CW & cw( CW::Instance() );
    //CERR <<"Binding class "<<BA_JS_CLASS_NAME<<"...\n";
    if( cw.IsSealed() )
    {
        cw.AddClassTo( BA_JS_CLASS_NAME, dest );
        return;
    }
    typedef cv::MemberPropertyBinder<N> SPB;
    cw
        .Set( "toString", cv::ConstMethodToInvocationCallback<N, std::string (),&N::toString> )
        .Set( "destroy", CW::DestroyObjectCallback )
        .Set( "append", cv::MethodToInvocationCallback<N, void (v8::Handle<v8::Value>), &N::append> )
        .Set( "gzipTo", cv::ConstMethodToInvocationCallback<N, int (N &), &N::gzipTo> )
        .Set( "gunzipTo", cv::ConstMethodToInvocationCallback<N, int (N &), &N::gunzipTo> )
        .Set( "gzip", cv::ConstMethodToInvocationCallback<N, v8::Handle<v8::Value> (), &N::gzip> )
        .Set( "gunzip", cv::ConstMethodToInvocationCallback<N, v8::Handle<v8::Value> (), &N::gunzip> )
        ;
    v8::Handle<v8::ObjectTemplate> const & proto( cw.Prototype() );
    proto->SetAccessor( JSTR("length"),
                        SPB::ConstMethodToAccessorGetter<uint32_t(),&N::length>,
                        SPB::MethodToAccessorSetter<uint32_t (uint32_t), &N::length> );
    proto->SetAccessor( JSTR("stringValue"),
                        SPB::ConstMethodToAccessorGetter<std::string(),&N::stringValue>,
                        SPB::AccessorSetterThrow );
    v8::Handle<v8::FunctionTemplate> ctorTmpl = cw.CtorTemplate();
    ctorTmpl->InstanceTemplate()->SetIndexedPropertyHandler( JSByteArray::indexedPropertyGetter,
                                                             JSByteArray::indexedPropertySetter,
                                                             JSByteArray::indexedPropertyQuery,
                                                             NULL/*JSByteArray::indexedPropertyDeleter*/,
                                                             NULL/*JSByteArray::indexedPropertyEnumerator*/
                                                            );
    cw.AddClassTo( BA_JS_CLASS_NAME, dest );
    //CERR <<"Binding done.\n";
    return;
}


#undef DBGOUT
#undef JSTR
#undef BA_JS_CLASS_NAME
#undef CERR
