#include "CurlJS.h"

#include <cvv8/XTo.hpp>
#include <cvv8/ClassCreator.hpp>
#include <map>
#include <iostream>
#ifndef CERR
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << " : "
#endif

typedef v8::Persistent<v8::Function> PFuncHnd;
typedef v8::Persistent<v8::Value> PValHnd;
typedef v8::Handle<v8::Function> FuncHnd;
typedef v8::Handle<v8::Value> ValHnd;

#define JSTR(X) v8::String::New(X)

namespace cvv8 {
    CVV8_TypeName_DECL((curl::CurlJS));
    CVV8_TypeName_IMPL((curl::CurlJS),"Curl");
#if 0
    template <>
    class ClassCreator_Factory<curl::CurlJS>
    {
    public:
        typedef curl::CurlJS * ReturnType;
        static ReturnType Create( v8::Persistent<v8::Object> jsSelf, v8::Arguments const & argv );
        static void Delete( curl::CurlJS * obj );
    };
#endif
    template <>
    struct JSToNative<curl::CurlJS>
        : JSToNative_ClassCreator<curl::CurlJS>
    {};


} // ::cvv8

typedef struct curl_slist curl_slist;
namespace cvv8 { namespace curl {
    // For use with CURLOPT_WRITEFUNCTION
    static size_t WriteCallback(char *ptr, size_t size, size_t nmemb, void *data);
    // For use with CURLOPT_READFUNCTION
    static size_t ReadCallback(char *ptr, size_t size, size_t nmemb, void *data);
    // For use with CURLOPT_HEADERFUNCTION
    static size_t HeaderCallback(char *ptr, size_t size, size_t nmemb, void *data);

    typedef std::map<int,curl_slist *> SListMap;
    static curl_slist * ArrayToSList( v8::Handle<v8::Array> ar )
    {
        if( ar.IsEmpty() ) return 0;
        curl_slist * li = 0;
        v8::HandleScope hsc;
        int const len = CastFromJS<int>( ar->Get(JSTR("length")) );
        for( int i = 0; i < len; ++i )
        {
            v8::Local<v8::Value> v = ar->Get( v8::Integer::New(i) );
            std::string const sv( JSToStdString(v) );
            if( sv.empty() ) continue;
            li = curl_slist_append( li, sv.c_str() );
        }
        return li;
    }

    static v8::Handle<v8::Value> SListToArray( curl_slist * li )
    {
        if( ! li ) return v8::Null();
        v8::Handle<v8::Array> ar = v8::Array::New();
        int i = 0;
        for( ; li ; li = li->next )
        {
            ar->Set( v8::Integer::New(i), CastToJS( li->data ? li->data : "" ) );
        }
        return ar;
    }

    /**
       Holds names of JS properties.
    */
    struct Strings
    {
        static char const * easyPerform;
        static char const * fnAddOption;
        static char const * fnDestroy;
        static char const * fnGetInfo;
        static char const * fnPause;
        static char const * fnResume;
        static char const * fnSetOption;
        static char const * optHeaderData;
        static char const * optHeaderFunc;
        static char const * optObj;
        static char const * optObjHidden;
        static char const * optReadData;
        static char const * optReadFunc;
        static char const * optWriteData;
        static char const * optWriteFunc;
    };
    char const * Strings::easyPerform = "easyPerform";
    char const * Strings::fnAddOption = "addOpt";
    char const * Strings::fnDestroy = "destroy";
    char const * Strings::fnGetInfo = "getInfo";
    char const * Strings::fnPause = "pause";
    char const * Strings::fnResume = "resume";
    char const * Strings::fnSetOption = "setOpt";
    char const * Strings::optHeaderData = "headerData";
    char const * Strings::optHeaderFunc = "headerFunction";
    char const * Strings::optObj = "opt";
    char const * Strings::optObjHidden = "$opt";
    char const * Strings::optReadData = "readData";
    char const * Strings::optReadFunc = "readFunction";
    char const * Strings::optWriteData = "writeData";
    char const * Strings::optWriteFunc = "writeFunction";


    static std::string optToName( int id );    
    struct CurlJS::Impl
    {
        CURL * ch;
        /** The JS-side 'this' object for the CurlJS object holding this object. */
        v8::Handle<v8::Object> jself; // we assume this is Persistent elsewhere
        SListMap slist;
        Impl()
            : ch(curl_easy_init()),
              jself(),
              slist()
        {
            if( ! this->ch )
            {
                throw std::runtime_error("curl_easy_init() returned NULL!");
            }
            curl_easy_setopt( this->ch, CURLOPT_WRITEFUNCTION, WriteCallback );
            curl_easy_setopt( this->ch, CURLOPT_WRITEDATA, this );
            curl_easy_setopt( this->ch, CURLOPT_READFUNCTION, ReadCallback );
            curl_easy_setopt( this->ch, CURLOPT_READDATA, this );
            curl_easy_setopt( this->ch, CURLOPT_HEADERFUNCTION, HeaderCallback );
            curl_easy_setopt( this->ch, CURLOPT_HEADERDATA, this );
            curl_easy_setopt( this->ch, CURLOPT_ENCODING, "" );
            //CERR << "Impl() @"<<(void const *)this<<'\n';
        }
        /**
           Cleans up the libcurl resources associated with this object.
        */
        ~Impl()
        {
#if 0
	    /**
               curl_easy_setopt() docs say that i have to delete the
               slist's, but when i do i get double-free() errors!  It
               seems that curl takes over ownership and cleans them up
               in curl_easy_cleanup(). See AddList() for more info.
            */
            SListMap::iterator it = this->slist.begin();
            for( ; this->slist.end() != it; ++it )
            {
                curl_slist * s = (*it).second;
                CERR << "Cleaning up curl_slist @"<<s<<'\n';
                //if( s ) curl_slist_free_all(s);
            }
#endif
            curl_easy_cleanup( this->ch );
        }
        /**
           Adds an slist property to our internal cleanup
           list. id is the CURLOPT_xxx ID. Any previous mapping
           will be destroyed.
        */
        void AddList( int id, curl_slist * s )
        {
#if 0
            /**
                It seems that curl takes over ownership of slist
                properties.
            */
            SListMap::iterator it = this->slist.find(id);
            if( this->slist.end() != it )
            {
                curl_slist * old = (*it).second;
                if( old && (s == old) ) return;
                else if( old ) curl_slist_free_all(s);
            }
#endif
            this->slist[id] = s;

        }
        /** Returns curl_easy_perform(this->ch). */
        int EasyPerform()
        {
            return curl_easy_perform(this->ch);
        }
        /** Returns this->jself->Get("opt"), creating that object if
            needed.
        */
        v8::Handle<v8::Object> opt()
        {
#if 0
            // Reminder: we use a hidden field to avoid recursion in AccessorGetter impls.
            ValHnd ov = this->jself->GetHiddenValue( JSTR(Strings::optObjHidden) );
            v8::Handle<v8::Object> jo;
            if( ov.IsEmpty() || ! ov->IsObject() )
            {
                jo = v8::Object::New();
                this->opt( jo );
            }
            else
            {
                jo = v8::Handle<v8::Object>( v8::Object::Cast( *ov ) );
            }
            return jo;
#else
            ValHnd ov = this->jself->Get( JSTR(Strings::optObj) );
            v8::Handle<v8::Object> jo;
            if( ov.IsEmpty() || ! ov->IsObject() )
            {
                jo = v8::Object::New();
                this->opt( jo );
            }
            else
            {
                jo = v8::Handle<v8::Object>( v8::Object::Cast( *ov ) );
            }
            return jo;
#endif
        }
        /** Returns the given key from jself[Strings::optObj][k] */
        v8::Handle<v8::Value> opt( char const * k )
        {
            v8::Local<v8::String> const jk = JSTR(k);
            return this->opt()->Get( jk );
        }
        /** Sets jself[Strings::optObj] to o. */
        v8::Handle<v8::Value> opt( v8::Handle<v8::Object> const & o )
        {
            //this->jself->SetHiddenValue( JSTR(Strings::optObjHidden), o );
            this->jself->Set( JSTR(Strings::optObj), o );
            return o;
        }
        /**
           Gets the handler callback function associated with n, or an
           empty handle if n is not set or is not-a Function.
        */
        FuncHnd getOptFunc( char const * n )
        {
            ValHnd const h = this->opt(n);
            return (!h.IsEmpty() && h->IsFunction() )
                ? FuncHnd( v8::Function::Cast(*h) )
                : FuncHnd();
        }
    };

}} // cvv8::curl

namespace cvv8 {

    template <>
    struct ClassCreator_WeakWrap<curl::CurlJS>
    {
        typedef curl::CurlJS * NativeHandle;
        static void PreWrap( v8::Persistent<v8::Object> const &, v8::Arguments const & )
        {
            return;
        }
        static void Wrap( v8::Persistent<v8::Object> const &p, NativeHandle n )
        {
            n->impl->jself = p;
            return;
        }
        static void Unwrap( v8::Handle<v8::Object> const & p, NativeHandle n )
        {
            n->impl->jself.Clear();
            return;
        }
    };
} // ::cvv8

namespace cvv8 { namespace curl {
    
    /**
       Interface for setting a Curl option.

       - jso = the JS object in which to set the property.
       - cu = the CurlJS object to act upon.
       - key = the property name.
       - val = the new value.

       Implementations must respect the type required for the
       underlying curl_easy_setopt() call.
    */
    typedef v8::Handle<v8::Value> (*CurlOptSetter)( v8::Handle<v8::Object> jso, CurlJS * cu, v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & val);

    /**
       Interface for setting Curl options from JS. MUST
       be specialized on CurlOptID and the specializations
       must behave as demonstrated in CurlOptString,
       CurlOptLong, and friends.
    */
    template <int CurlOptID_>
    struct CurlOpt
    {
#if defined(DOXYGEN)
        /**
           Must be-a CURLOPT_xxx value.
        */
        static const int ID = CurlOptID_;
        /**
           Must return the JS property name.
         */
        static char const * Key();
        /**
           Must implement the CurlOptSetter interface.
        */
        static v8::Handle<v8::Value> Set( v8::Handle<v8::Object> jso, CurlJS * cu, v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & jv);
#endif
    };


    /** Convenience base for CurlOpt specializations. */
    template <int _CurlOptID>
    struct CurlOpt_Base
    {
        static const int ID = _CurlOptID;
    };
    /**
       Stores an arbitrary JS object as a curl option. libcurl never
       actually gets the option.
    */
    template <int CurlOptID>
    struct CurlOptJSVal : CurlOpt_Base<CurlOptID>
    {
        static v8::Handle<v8::Value> Set( v8::Handle<v8::Object> jso,
                                          CurlJS *,
                                          v8::Handle<v8::Value> const & key,
                                          v8::Handle<v8::Value> const & jv)
        {
            //CERR << "Setting "<<JSToStdString(key)<<" JSVAL: "<<JSToStdString(jv)<<'\n';
            jso->Set( key, jv );
            return v8::Integer::New(0);
        }
    };
    /**
       Sets a curl string option.
    */
    template <int CurlOptID>
    struct CurlOptString : CurlOpt_Base<CurlOptID>
    {
        static v8::Handle<v8::Value> Set( v8::Handle<v8::Object> jso, CurlJS * cu, v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & jv)
        {
            std::string val;
            if( jv.IsEmpty() )
            {
                return v8::Integer::New(-1);
            }
            else if( jv->IsUndefined()
                     || jv->IsNull() )
            {
                val = "";
            }
            else val = JSToStdString( jv );
            jso->Set( key, CastToJS(val) );
            //CERR << "Setting "<<PropKey<<" STRING: "<<val<<'\n';
            int rc = curl_easy_setopt( cu->Curl(), CURLoption(CurlOptID), val.empty() ? 0 : val.c_str() );
            return v8::Integer::New(rc);
        }
    };

    /**
       Sets a curl 'long' option.
    */
    template <int CurlOptID>
    struct CurlOptLong : CurlOpt_Base<CurlOptID>
    {
        static v8::Handle<v8::Value> Set( v8::Handle<v8::Object> jso, CurlJS * cu, v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & jv)
        {
            long nv = 0;
            if( jv.IsEmpty() || jv->IsUndefined() )
            {
                return v8::Integer::New(-1);
            }
            else
            {
                nv = CastFromJS<long>( jv );
            }
            //CERR << "Setting "<<PropKey<<" LONG: "<<nv<<'\n';
            jso->Set( key, CastToJS(nv) );
            int rc = curl_easy_setopt( cu->Curl(),
                                       CURLoption(CurlOptID),
                                       nv );
            return v8::Integer::New(rc);
        }
    };
    /**
       Sets a curl boolean option (actually a long for libcurl).
    */
    template <int CurlOptID>
    struct CurlOptBool : CurlOpt_Base<CurlOptID>
    {
        static v8::Handle<v8::Value> Set( v8::Handle<v8::Object> jso, CurlJS * cu, v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & jv)
        {
            bool nv = CastFromJS<bool>( jv );
            jso->Set( key, jv );
            //CERR << "Setting "<<PropKey<<" BOOL: "<<nv<<'\n';
            int rc = curl_easy_setopt( cu->Curl(),
                                       CURLoption(CurlOptID),
                                       nv ? 1 : 0 );
            return v8::Integer::New(rc);
        }
    };

    /**
       Sets a curl_slist option.
    */
    template <int CurlOptID>
    struct CurlOptSList : CurlOpt_Base<CurlOptID>
    {
        static v8::Handle<v8::Value> Set( v8::Handle<v8::Object> jso, CurlJS * cu, v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & jv)
        {
            if( jv.IsEmpty() || (!jv->IsArray() && !jv->IsUndefined() && !jv->IsNull()))
            {
                StringBuffer msg;
                msg << "Curl option #"<<CurlOptID
                    <<" ("<<optToName(CurlOptID)<<") "
                    <<"requires a Array of Strings as its argument!";
#if 0
                /**
                   TOSS'ing from here causes v8 to crash at some point
                   when we call this from CurlJS::SetOpt(Object).
                   But throwing works from other handlers!

                   In some cases it crashes silently - ending my app
                   immediately with RC=0!
                */
                //ValHnd ex = TOSSV(msg);
                //return hsc.Close( ex );
                return Toss(msg);
                //return hsc.Close(TOSSV(msg));
#elif 1
                // second-choice behaviour, which we accommodate in CurlJS::SetOpt()
                // and friends:
                // CERR << msg.Content() << '\n';
                return v8::Integer::New(-1);
#endif
            }
            typedef v8::Handle<v8::Array> ARH;
            ARH ar( jv->IsArray() ? ARH( v8::Array::Cast(*jv) ) : ARH() );
            curl_slist * sl = ArrayToSList( ar );
            cu->impl->AddList( CurlOptID, sl );
            jso->Set( key, CastToJS(jv) );
            //CERR << "Setting slist property "<<JSToStdString(key)<<" @"<<sl<<'\n';
            int rc = curl_easy_setopt( cu->Curl(), CURLoption(CurlOptID), sl );
            return v8::Integer::New(rc);
        }
    };

/**
   Set up CurlOpt<> specializations for all CURLOPT_XXX options we support...
*/
#define OPTKEY(KEY) static char const * Key() { return KEY; }
#define COPT_LONG(SUFFIX,KEY) template <> struct CurlOpt< CURLOPT_ ## SUFFIX > : CurlOptLong<CURLOPT_ ## SUFFIX> {OPTKEY(KEY)}
#define COPT_BOOL(SUFFIX,KEY) template <> struct CurlOpt< CURLOPT_ ## SUFFIX > : CurlOptBool<CURLOPT_ ## SUFFIX> {OPTKEY(KEY)}
#define COPT_STR(SUFFIX,KEY) template <> struct CurlOpt< CURLOPT_ ## SUFFIX > : CurlOptString<CURLOPT_ ## SUFFIX> {OPTKEY(KEY)}
#define COPT_JVAL(SUFFIX,KEY) template <> struct CurlOpt< CURLOPT_ ## SUFFIX > : CurlOptJSVal<CURLOPT_ ## SUFFIX> {OPTKEY(KEY)}
#define COPT_SLIST(SUFFIX,KEY) template <> struct CurlOpt< CURLOPT_ ## SUFFIX > : CurlOptSList<CURLOPT_ ## SUFFIX> {OPTKEY(KEY)}
    COPT_BOOL(FAILONERROR, "failOnError");
    COPT_BOOL(FOLLOWLOCATION, "followLocation");
    COPT_BOOL(HEADER, "header");
    COPT_BOOL(NOBODY, "noBody");
    COPT_BOOL(NOSIGNAL, "noSignal");
    COPT_BOOL(POST,"post");
    COPT_BOOL(TCP_NODELAY,"tcpNoDelay");
    COPT_BOOL(VERBOSE,"verbose");
    COPT_JVAL(HEADERDATA, Strings::optHeaderData);
    COPT_JVAL(HEADERFUNCTION, Strings::optHeaderFunc);
    COPT_JVAL(WRITEDATA, Strings::optWriteData);
    COPT_JVAL(WRITEFUNCTION, Strings::optWriteFunc);
    COPT_JVAL(READDATA, Strings::optReadData);
    COPT_JVAL(READFUNCTION, Strings::optReadFunc);
    COPT_LONG(BUFFERSIZE, "bufferSize");
    COPT_LONG(CONNECTTIMEOUT, "connectionTimeout");
    COPT_LONG(CRLF, "crlf");
    COPT_LONG(DNS_CACHE_TIMEOUT, "dnsCacheTimeout");
    COPT_LONG(LOW_SPEED_LIMIT,"lowSpeedLimit");
    COPT_LONG(LOW_SPEED_TIME,"lowSpeedTime");
    COPT_LONG(MAXREDIRS, "maxRedirs");
    COPT_LONG(PORT, "port");
    COPT_LONG(PROXYPORT, "proxyPort");
    COPT_LONG(RESUME_FROM,"resumeFrom");
    COPT_LONG(TIMEOUT, "timeout");
    COPT_LONG(TIMEOUT_MS, "timeoutMs");
    COPT_STR(INTERFACE, "interface");
    COPT_STR(NOPROXY, "noProxy");
    COPT_STR(PROXY, "proxy");
    COPT_STR(RANGE, "range");
    COPT_STR(URL, "url");
    COPT_STR(USERAGENT, "userAgent");
    COPT_STR(USERNAME, "userName");
    COPT_STR(USERPWD, "userPwd");
    COPT_SLIST(HTTPHEADER, "httpHeader");
    COPT_SLIST(HTTP200ALIASES,"http200Aliases");
    COPT_SLIST(PREQUOTE,"preQuote");
    COPT_SLIST(POSTQUOTE,"postQuote");
    COPT_SLIST(QUOTE,"quote");
    //COPT_SLIST(TELNETOPTIONS,"telnetOptions"); // my curl doesn't have CURLOPT_TELNETOPTIONS
#undef OPTKEY
#undef COPT_LONG
#undef COPT_BOOL
#undef COPT_STR
#undef COPT_JVAL
#undef COPY_SLIST
    /**
       Stores info for mapping between CURLOPT_xxx and JS-friendly names for
       various Curl options.
    */
    struct COptMeta
    {
        int ID;
        char const * PropName;
        CurlOptSetter Setter;
    };
    /**
       Each entry must have a unique ID and corresponding CurlOpt<> specialization.
       Order is irrelevant, but the list must end with an entry which has all fields
       set to 0.
    */
    static const COptMeta OptInfoList[] =
        {
#define O1(I) { CURLOPT_##I, CurlOpt<CURLOPT_##I>::Key(), CurlOpt<CURLOPT_##I>::Set }
#define O2(I,S) { CURLOPT_##I, Strings::S, CurlOpt<CURLOPT_##I>::Set }
        O1(BUFFERSIZE),
        O1(CONNECTTIMEOUT),
        O1(CRLF),
        O1(DNS_CACHE_TIMEOUT),
        O1(FAILONERROR),
        O1(FOLLOWLOCATION),
        O1(HEADER),
        O2(HEADERDATA, optHeaderData),
        O2(HEADERFUNCTION, optHeaderFunc),
        O1(HTTP200ALIASES),
        O1(HTTPHEADER),
        O1(INTERFACE),
        O1(MAXREDIRS),
        O1(NOBODY),
        O1(NOPROXY),
        O1(PORT),
        O1(POST),
        O1(POSTQUOTE),
        O1(PREQUOTE),
        O1(PROXY),
        O1(PROXYPORT),
        O1(QUOTE),
        O1(RANGE),
        O1(TIMEOUT),
        O1(TIMEOUT_MS),
        O1(URL),
        O1(USERAGENT),
        O1(USERNAME),
        O1(USERPWD),
        O1(VERBOSE),
        O2(READDATA, optReadData),
        O2(READFUNCTION, optReadFunc),
        O2(WRITEDATA, optWriteData),
        O2(WRITEFUNCTION, optWriteFunc),
#undef O1
#undef O2
        {0,0,0}
        };
    typedef std::map<std::string,COptMeta const *> KeyToOptMap;
    static KeyToOptMap const & keyToOpt()
    {
        static KeyToOptMap m;
        if( m.empty() )
        {
            COptMeta const * o = OptInfoList;
            for( ; o->ID; ++o )
            {
                m[o->PropName] = o;
            }
        }
        return m;
    }

    COptMeta const * optInfo( std::string const & prop )
    {
        KeyToOptMap const & m( keyToOpt() );
        KeyToOptMap::const_iterator it = m.find(prop);
        return (m.end() == it)
            ? 0
            : (*it).second;
    }

    typedef std::map<int,COptMeta const *> IntToOptMap;
    static IntToOptMap const & optToProp()
    {
        static IntToOptMap m;
        if( m.empty() )
        {
            COptMeta const * o = OptInfoList;
            for( ; o->ID; ++o )
            {
                m[o->ID] = o;
            }
        }
        return m;
    }

    static COptMeta const * optInfo( int id )
    {
        IntToOptMap const & m( optToProp() );
        IntToOptMap::const_iterator it = m.find(id);
        return (m.end() == it)
            ? 0
            : (*it).second;
    }
    static std::string optToName( int id )
    {
        IntToOptMap const & m( optToProp() );
        IntToOptMap::const_iterator it = m.find(id);
        COptMeta const * i = (m.end() == it) ? 0 : (*it).second;
        return (i && i->PropName) ? i->PropName : "";
    }


    /**
        Interface for fetching CURLINFO_xxx into JS space. Each
        handler is responsible for one CURLINFO_xxx value.
    */
    typedef v8::Handle<v8::Value> (*CurlInfoGetter)( CURL * c );

    /**
       Interface for fetching CURLINFO_xxx data. InfoID must be a
       supported CURLINFO_xxx value.
    */
    template <int InfoID>
    struct CInfoGet
    {
#if defined(DOXYGEN)
        static v8::Handle<v8::Value> Get( CURL * c )
        {
            return Toss("Unspecialized CURLINFO value!");
        }
        // ^^^^ remove this (to force a compile error on non-specialization
        // once all handlers are in place
#endif
    };
    /**
       Base class for CInfoGet implementations. The Get()
       member throws a JS exception.
    */
    template <int InfoID>
    struct CInfoGet_Base
    {
        static const int ID = InfoID;
        static v8::Handle<v8::Value> Get( CURL * c )
        {
            StringBuffer msg;
            msg << "CURLINFO ID #"<<InfoID<<" is not handled.";
            return Toss(msg);
        }
    };
/* A error implementations for certain CURLINFO values... */
// #define CINFO(X) template <> struct CInfoGet<X> : CInfoGet_Base<X> {}
//     CINFO(CURLINFO_NONE);
//     CINFO(CURLINFO_LASTONE);
// #undef CINFO
    template <int InfoID>
    struct CInfoGet_String : CInfoGet_Base<InfoID>
    {
        static v8::Handle<v8::Value> Get( CURL * c )
        {
	    char const * nv = 0;
	    CURLcode rc = curl_easy_getinfo( c, CURLINFO(InfoID), &nv );
	    if( CURLE_OK != rc )
	    {
		StringBuffer msg;
		msg << "curl_easy_getinfo(Curl@"<<c<<", "<<InfoID<<", STRING) failed with RC "<<int(rc)<<'!';
		return Toss(msg);
	    }
	    else
	    {
		if( nv ) return CastToJS( nv );
		else return v8::Null();
	    }
        }        
    };
    template <int InfoID>
    struct CInfoGet_Long : CInfoGet_Base<InfoID>
    {
        static v8::Handle<v8::Value> Get( CURL * c )
        {
	    long nv = 0;
	    CURLcode rc = curl_easy_getinfo( c, CURLINFO(InfoID), &nv );
	    if( CURLE_OK != rc )
	    {
		StringBuffer msg;
		msg << "curl_easy_getinfo(Curl@"<<c<<", "<<InfoID<<", LONG) failed with RC "<<int(rc)<<'!';
		return Toss(msg);
	    }
	    else
	    {
		return CastToJS( nv );
	    }
        }        
    };
    template <int InfoID>
    struct CInfoGet_Double : CInfoGet_Base<InfoID>
    {
        static v8::Handle<v8::Value> Get( CURL * c )
        {
	    double nv = 0;
	    CURLcode rc = curl_easy_getinfo( c, CURLINFO(InfoID), &nv );
	    if( CURLE_OK != rc )
	    {
		StringBuffer msg;
		msg << "curl_easy_getinfo(Curl@"<<c<<", "<<InfoID<<",DOUBLE) failed with RC "<<int(rc)<<'!';
		return Toss(msg);
	    }
	    else
	    {
		return CastToJS( nv );
	    }
        }        
    };
    template <int InfoID>
    struct CInfoGet_SList : CInfoGet_Base<InfoID>
    {
        static v8::Handle<v8::Value> Get( CURL * c )
        {
            curl_slist * li = 0;
            int rc = curl_easy_getinfo( c, CURLINFO(InfoID), &li );
	    if( CURLE_OK != rc )
	    {
		StringBuffer msg;
		msg << "curl_easy_getinfo(Curl@"<<c<<", "<<InfoID<<",SLIST) failed with RC "<<int(rc)<<'!';
                if(li) curl_slist_free_all(li);
		return Toss(msg);
	    }
	    else
	    {
		v8::Handle<v8::Value> rc = SListToArray( li );
                if(li) curl_slist_free_all(li);
                return rc;
	    }
        }        
    };

    /** Metatemplate for choosing a conversion handler for a CURLINFO_xxx value. */
    template <int Mask,int V>
    struct CInfoChoose
    {
#if defined(DOXYGEN)
        /** Specializations must define this to a CInfoGet-compliant type. */
        typedef CInfoGet<V> Type;
#endif
    };
    template <int V>
    struct CInfoChoose<CURLINFO_STRING,V>
    {
        typedef CInfoGet_String<V> Type;
    };
    template <int V>
    struct CInfoChoose<CURLINFO_LONG,V>
    {
        typedef CInfoGet_Long<V> Type;
    };
    template <int V>
    struct CInfoChoose<CURLINFO_DOUBLE,V>
    {
        typedef CInfoGet_Double<V> Type;
    };
    template <int V>
    struct CInfoChoose<CURLINFO_SLIST,V>
    {
        typedef CInfoGet_SList<V> Type;
    };

    /**
       Metatemplate to pick a CInfoGet specialization for the
       CURLOPT_xxx value I.
    */
    template <int I>
    struct CInfoHandler
    {
        typedef typename CInfoChoose<I & CURLINFO_TYPEMASK,I>::Type Type;
    };
    
    /**
       Holder for CURLINFO_xxx binding info.
    */
    struct CInfoMeta
    {
        int ID;
        char const * PropName;
        CurlInfoGetter Getter;
    };
    static const CInfoMeta CInfoList[] =
        {
#define INFO(K) { CURLINFO_ ## K, "INFO_" # K, \
                  CInfoHandler<CURLINFO_ ## K>::Type::Get }
#define INFO_NOOP(K) { CURLINFO_ ## K, "INFO_" # K, 0 }
        INFO(APPCONNECT_TIME),
        INFO(CERTINFO),
        INFO(CONDITION_UNMET),
        INFO(CONNECT_TIME),
        INFO(CONTENT_LENGTH_DOWNLOAD),
        INFO(CONTENT_LENGTH_UPLOAD),
        INFO(CONTENT_TYPE),
        INFO(COOKIELIST),
        INFO(DOUBLE),
        INFO(EFFECTIVE_URL),
        INFO(FILETIME),
        INFO(FTP_ENTRY_PATH),
        INFO(HEADER_SIZE),
        INFO(HTTPAUTH_AVAIL),
        INFO(HTTP_CONNECTCODE),
        INFO(LASTSOCKET),
        INFO(LONG),
        INFO(NAMELOOKUP_TIME),
        INFO(NUM_CONNECTS),
        INFO(OS_ERRNO),
        INFO(PRETRANSFER_TIME),
        INFO(PRIMARY_IP),
        INFO(PROXYAUTH_AVAIL),
        INFO(REDIRECT_COUNT),
        INFO(REDIRECT_TIME),
        INFO(REDIRECT_URL),
        INFO(REQUEST_SIZE),
        INFO(RESPONSE_CODE),
        INFO(SIZE_DOWNLOAD),
        INFO(SIZE_UPLOAD),
        INFO(SLIST),
        INFO(SPEED_DOWNLOAD),
        INFO(SPEED_UPLOAD),
        INFO(SSL_ENGINES),
        INFO(SSL_VERIFYRESULT),
        INFO(STARTTRANSFER_TIME),
        INFO(STRING),
        INFO(TOTAL_TIME),
        INFO_NOOP(NONE),
        INFO_NOOP(DATA_IN),
        INFO_NOOP(DATA_OUT),
        INFO_NOOP(END),
        INFO_NOOP(HEADER_IN),
        INFO_NOOP(HEADER_OUT),
        INFO_NOOP(MASK),
        INFO_NOOP(SSL_DATA_IN),
        INFO_NOOP(SSL_DATA_OUT),
        INFO_NOOP(TEXT),
        INFO_NOOP(TYPEMASK),
        INFO_NOOP(LASTONE),
#undef INFO
#undef INFO_NOOP
        {0,0,0}
        };
    
    /**
       CURLOPT_xxxFUNCTION callback for WRITEFUNCTION and HEADERFUNCTION.

       OptKey == callback function name.
       DataKey == "data argument" property name.

       BUGS:

       - Our callback mechanism does not 100% match what libcurl specifies
       for CURLOPT_HEADERFUNCTION when HEADERFUNCTION is null but HEADERDATA
       is not. See:

       http://curl.haxx.se/libcurl/c/curl_easy_setopt.html#CURLOPTHEADERFUNCTION
       
    */
    template <char const * &OptKey,char const * &DataKey>
    static size_t WriterCallback( void *ptr, size_t size, size_t nmemb, void *data)
    {
        //CERR << "WriterCallback<"<<OptKey<<", "<<DataKey<<">() "<<(size*nmemb)<<" bytes.\n";
        CurlJS::Impl * im;
        im = reinterpret_cast<CurlJS::Impl *>( data );
        FuncHnd fh = im->getOptFunc( OptKey );
        if( fh.IsEmpty() ) return (size*nmemb);
        enum { argc = 3 };
        size_t len = size * nmemb;
        char const * cp = (len) ? reinterpret_cast<char const *>( ptr ) : 0;
        ValHnd argv[argc] = {
            v8::String::New( cp ? cp : "", cp ? static_cast<int>( len ) : 0 ),
            v8::Integer::NewFromUnsigned( len ),
            im->opt( DataKey )
        };
        v8::Local<v8::Value> rv = fh->Call( im->jself, argc, argv );
        return rv.IsEmpty() ? 0 : CastFromJS<size_t>( rv );
    }
    
    static size_t WriteCallback(char *ptr, size_t size, size_t nmemb, void *data)
    {
        return WriterCallback<Strings::optWriteFunc,Strings::optWriteData>( ptr, size, nmemb, data );
    }
    static size_t HeaderCallback(char *ptr, size_t size, size_t nmemb, void *data)
    {
        return WriterCallback<Strings::optHeaderFunc,Strings::optHeaderData>( ptr, size, nmemb, data );
    }

    static size_t ReadCallback( char *ptr, size_t size, size_t nmemb, void *data)
    {
        //CERR << "WriterCallback<"<<OptKey<<", "<<DataKey<<">() "<<(size*nmemb)<<" bytes.\n";
        CurlJS::Impl * im;
        im = reinterpret_cast<CurlJS::Impl *>( data );
        FuncHnd fh = im->getOptFunc( Strings::optReadFunc );
        if( fh.IsEmpty() ) return CURL_READFUNC_ABORT; // (size*nmemb);
        enum { argc = 2 };
        size_t len = size * nmemb;
        //char const * cp = (len) ? reinterpret_cast<char const *>( ptr ) : 0;
        ValHnd argv[argc] = {
            v8::Integer::NewFromUnsigned( len ),
            im->opt( Strings::optReadData )
        };
        v8::Local<v8::Value> rv = fh->Call( im->jself, argc, argv );
        if( rv.IsEmpty() )
        {
            return CURL_READFUNC_ABORT;
        }
        v8::Local<v8::String> sv( rv->ToString() );
        v8::String::AsciiValue const asc( sv );
        size_t rc = static_cast<size_t>( asc.length() );
        if( rc < len ) len = rc;
        memcpy( ptr, *asc, len );
        return len;
    }

    CurlJS::CurlJS()
        : impl(new CurlJS::Impl)
    {
    }

    CurlJS::~CurlJS()
    {
        delete this->impl;
    }
    CURL * CurlJS::Curl()
    {
        return this->impl->ch;
    }
    int CurlJS::EasyPerform()
    {
        return this->impl->EasyPerform();
    }

    v8::Handle<v8::Value> CurlJS::toString() const
    {
        StringBuffer s;
        s << "[object "<<CurlJS::ClassName()
          <<'@'<<(void const *)this<<']';
        return s;
    }

    int CurlJS::Pause()
    {
        return this->Pause( CURLPAUSE_ALL );
    }
    int CurlJS::Resume()
    {
        return this->Pause( CURLPAUSE_CONT );
    }
    int CurlJS::Pause( int mask )
    {
        return curl_easy_pause( this->Curl(), mask );
    }

    

    v8::Handle<v8::Value> CurlJS::GetInfo( int flag )
    {
        typedef std::map<int,CInfoMeta const *> InfoMetaMap;
        static InfoMetaMap map;
        if( map.empty() )
        {
            CInfoMeta const * ci = CInfoList;
            for( ; ci && ci->PropName; ++ci )
            {
                map[ci->ID] = ci;
            }
        }
        InfoMetaMap::const_iterator it = map.find(flag);
        if( map.end() == it )
        {
            StringBuffer msg;
            msg << "The value "<<flag<<" does not correspond to "
                << "a supported CURLINFO_XXX constant.";
            return Toss(msg);
        }
        if( ! it->second->Getter )
        {
            StringBuffer msg;
            msg << "The value "<<flag<<" does not correspond to "
                << "a "<<Strings::fnGetInfo<<"()'able CURLINFO_XXX constant.";
            return Toss(msg);
        }
        return it->second->Getter( this->impl->ch );
    }

    v8::Handle<v8::Value> CurlJS::SetOpt( int curlID, v8::Handle<v8::Value> const & val )
    {
        //CERR << "setOption("<<curlID<<","<<JSToStdString(val)<<")\n";
        COptMeta const * oi = optInfo(curlID);
        if( ! oi )
        {
            StringBuffer msg;
            msg << "Unknown Curl option ID: "<<curlID;
            return Toss(msg);
        }
        return oi->Setter( this->impl->opt(), this, CastToJS(oi->PropName), val );
    }

    v8::Handle<v8::Value> CurlJS::SetOpt( v8::Handle<v8::Value> const & key, v8::Handle<v8::Value> const & val )
    {
        //CERR << "setOption("<<JSToStdString(val)<<","<<JSToStdString(val)<<")\n";
        const int curlID = key->IsNumber() ? CastFromJS<int>(key) : 0;
        COptMeta const * oi = curlID ? optInfo(curlID) : 0;
        ValHnd setrc;
        if( oi )
        {
            setrc = this->SetOpt( curlID, val );
        }
        else
        {
            oi = optInfo( JSToStdString(key) );
            if( ! oi )
            {
                StringBuffer msg;
                msg << "Unknown Curl option: "<<JSToStdString(key)
                    << " = "<<JSToStdString(val);
                return Toss(msg);
                //CERR << msg.Content() << '\n';
                //return v8::Integer::New(-1);
            }
        }
        setrc = oi->Setter( this->impl->opt(), this, CastToJS(oi->PropName), val );
#if 0
        return setrc;
#else
        if( setrc.IsEmpty() )
        {
            return setrc;
        }
        else if( 0 == setrc->Int32Value() )
        {
            return setrc;
        }
        else
        {
            // This is a workaround. Grep this code for "crash" for the reason
            StringBuffer msg;
            msg << "Setting of curl property";
            msg <<" '"<<oi->PropName<<"' failed with rc ";
            msg <<setrc<<"!";
            return Toss(msg);
        }
#endif
    }

    /**
       If key is a known curl property then the registered COptMeta object
       will be used to set the option. True is returned if key is a known
       option, else true is returned if COptMeta::Setter returns 0.
     */
    static v8::Handle<v8::Value> SetNamedCurlOption( CurlJS * c,
                                                     v8::Handle<v8::Value> const & key,
                                                     v8::Handle<v8::Value> const & val )
    {
        std::string const pname = JSToStdString(key);
        COptMeta const * oi = optInfo( pname );
        if( ! oi )
        {
            //CERR << "Warning: skipping non-Curl option '"<<JSToStdString(key)<<"'.\n";
            return v8::Integer::New(-1);
        }
        return oi->Setter( c->impl->opt(), c, key, val );
    }

    v8::Handle<v8::Value> CurlJS::SetOpts( v8::Handle<v8::Value> const & value )
    {
        if( value.IsEmpty() || !value->IsObject() )
        {
            StringBuffer msg;
            msg << CurlJS::ClassName() << "."<<Strings::fnSetOption << "(1 argument): Argument must be-a Object.";
            return Toss(msg);
        }
        //v8::HandleScope hsc;
        v8::Local<v8::Object> src( v8::Object::Cast(*value) );
        v8::Handle<v8::Object> pobj( v8::Object::New() );
        CERR << "SetOpts(Object)\n";
        this->impl->opt( pobj );
        v8::Local<v8::Array> ar = src->GetPropertyNames();
        const int arlen = CastFromJS<int>( ar->Get(JSTR("length")) );
        uint32_t rc = 0;
        v8::Handle<v8::Value> setrc;
        for( int i = 0; (i < arlen); ++i )
        {
            // FUCK: if a Setter throws or propogates a JS exception, v8 crashes!
            // But when it throws from SetOpt() it works fine!!!
            v8::Local<v8::Value> pkey = ar->Get( v8::Integer::New(i) );
#if 1
            //this->impl->jself->Set( pkey, src->Get( pkey ) );
            setrc = SetNamedCurlOption( this, pkey, src->Get( pkey ) );
            //if( tryer.HasCaught() ) return ValHnd();
#else
            setrc = this->setOption( pkey, src->Get( pkey ) );
            // ^^^ can cause a crash somewhere!
#endif
            //CERR << "setrc = "<<JSToStdString(setrc) << '\n';
            if( setrc.IsEmpty() )
            {
                return setrc; // pass on exception
            }
            else if( 0 == setrc->Int32Value() )
            {
                ++rc;
            }
            else
            {
                // This is a workaround. Grep this code for "crash" for the reason
                StringBuffer msg;
                msg << "Setting of curl property";
                msg <<" '"<<pkey<<"' failed with rc ";
                msg <<setrc<<"!";
                return Toss(msg);
            }
        }
        return CastToJS(rc);//hsc.Close(CastToJS(rc));
    }

    v8::Handle<v8::Value> CurlJS::AddOpts( v8::Handle<v8::Value> const & value )
    {
        if( value.IsEmpty() || !value->IsObject() )
        {
            StringBuffer msg;
            msg << CurlJS::ClassName() << "."<<Strings::fnSetOption << "(1 argument): Argument must be-a Object.";
            return Toss(msg);
        }
        v8::Local<v8::Object> src( v8::Object::Cast(*value) );
        v8::Local<v8::Array> ar = src->GetPropertyNames();
        const int arlen = CastFromJS<int>( ar->Get(JSTR("length")) );
        uint32_t rc = 0;
        v8::Handle<v8::Value> setrc;
        for( int i = 0; (i < arlen); ++i )
        {
            v8::Local<v8::Value> pkey = ar->Get( v8::Integer::New(i) );
            setrc = SetNamedCurlOption( this, pkey, src->Get( pkey ) );
            if( setrc.IsEmpty() )
            {
                return setrc; // pass on exception
            }
            else if( 0 == setrc->Int32Value() )
            {
                ++rc;
            }
            else
            {
                // This is a workaround. Grep this code for "crash" for the reason
                StringBuffer msg;
                msg << "Setting of curl property";
                msg <<" '"<<pkey<<"' failed with rc ";
                msg <<setrc<<"!";
                return Toss(msg);
            }
        }
        return CastToJS(rc);
    }

    /**
       v8::AccessorSetter impl.
       
       CurlOptID must be one of the supported CURLOPT_xxx values and
       jkey is expected to be equal to one of the Strings members.

       CurlOpt<CurlOptID> must be specialized.
    */
    template <int CurlOptID>//, char const * & OptKey>
    static void OptSet(v8::Local< v8::String > jkey,
                       v8::Local< v8::Value > value,
                       const v8::AccessorInfo &info)
    {
        CurlJS * c = CastFromJS<CurlJS>( info.This() );
        //CERR << "OptSet<"<<CurlOptID<<','<<JSToStdString(jkey)<<">()@"<<(void const *)c<<" = "<<JSToStdString(value)<<"\n";
        if( ! c )
        {
            StringBuffer msg;
            msg << CurlJS::ClassName() << '.'<<JSToStdString(jkey)
                << " setter could not find native 'this' object!";
            Toss(msg);
            return;
        }
        int check = CurlOpt<CurlOptID>::Set( c->impl->opt(), c, jkey, value );
        if( 0 != check )
        {
            StringBuffer msg;
            msg << "Error setting Curl property '"
                << JSToStdString(jkey) << "' (#"<<CurlOptID<<").";
            Toss(msg);
            return;
        }
    }

    /** Calls curl_global_init() at construction and
        curl_global_cleanup() at destruction.
    */
    struct CurlGlobalInitializer
    {
        CurlGlobalInitializer()
        {
            curl_global_init(CURL_GLOBAL_ALL);
        }
        ~CurlGlobalInitializer()
        {
            //curl_global_cleanup();
            
        }
    };

    unsigned int strlenBytes( v8::Handle<v8::Value> const & h )
    {
        if(h.IsEmpty()) return 0;
        else {
            v8::Handle<v8::String> const & str(h->ToString());
            return str->Utf8Length();
        }
    }
    
    void CurlJS::SetupBindings( v8::Handle<v8::Object> const & target )
    {

        typedef CurlJS N;
        typedef ClassCreator<N> CC;
        CC & cc( CC::Instance() );
        if( cc.IsSealed() )
        {
            cc.AddClassTo(TypeName<N>::Value, target);
            return;
        }
        {
            /**
               Initialize these maps now, when we are almost certain
               to be running under a mutex (via
               v8::juice::plugin::LoadPlugin()) or otherwise not in
               multiple threads.
            */
            keyToOpt();
            optToProp();
        }

        static const CurlGlobalInitializer curlResources;
        /** ^^^ We have no real way of knowing if this was already done, or if we should
            clean up! We WILL cause grief here if the main application is also using
            the curl API.
        */
#if 0
                typedef tmp::TypeList<
            convert::InvocableMemFunc1<N,ValHnd,ValHnd const &,&N::SetOpts>,
            convert::InvocableMemFunc2<N,ValHnd,ValHnd const &,ValHnd const &,&N::SetOpt>
            > SetOptList;
        typedef tmp::TypeList<
            convert::InvocableMemFunc0<N,int,&N::Pause>,
            convert::InvocableMemFunc1<N,int,int,&N::Pause>
            > PauseList;
#endif

        // Overloadload setOpt():
        typedef ArityDispatchList< CVV8_TYPELIST((
            MethodTo<InCa, N, ValHnd (ValHnd const &), &N::SetOpts>,
            MethodTo<InCa, N, ValHnd (ValHnd const &, ValHnd const &), &N::SetOpt>
            )) > OLoad_SetOpt;
        // Overloadload pause():
        typedef ArityDispatchList< CVV8_TYPELIST((
           MethodTo<InCa, N, int (), &N::Pause>,
           MethodTo<InCa, N, int (int), &N::Pause>
           )) > OLoad_Pause;
        
        cc( Strings::easyPerform, MethodTo<InCa, N, int (), &N::EasyPerform>::Call )
            ( "toString", MethodTo<InCa, const N, ValHnd (),&N::toString>::Call )
            ( Strings::fnAddOption, MethodTo<InCa, N, ValHnd (ValHnd const &),&N::AddOpts>::Call )
            ( Strings::fnGetInfo, MethodTo<InCa, N, ValHnd (int),&N::GetInfo>::Call )
            ( Strings::fnDestroy, CC::DestroyObjectCallback )
            ( Strings::fnResume, MethodTo<InCa,N, int (),&N::Resume>::Call )
            ( Strings::fnSetOption, OLoad_SetOpt::Call )
            ( Strings::fnPause, OLoad_Pause::Call )
            ;
        
        cc.AddClassTo(TypeName<N>::Value, target);

        v8::Handle<v8::Function> const & ctor( cc.CtorFunction() );

        ctor->Set( JSTR("strlenBytes"),
                   v8::FunctionTemplate::New(FunctionTo<InCa, unsigned int (ValHnd const &), strlenBytes >::Call)->GetFunction()
                   );
        
        /**
           Add Curl.OPT_XXX mappings to CURLOPT_XXX.

           Maintenance reminder: we cannot combine this with the above ACC()
           bits because of order-of-operations requirements on the object
           creation process. If we fetch the ctor object we can no longer
           change the prototype template, so we cannot do this stuff until
           cw.Seal() has been called and cannot do the ACC() stuff after
           cw.Seal() has been called.
        */
#define OPTKEY(O) ctor->Set( JSTR("OPT_"#O), v8::Integer::New( CURLOPT_ ## O ) )
        OPTKEY(BUFFERSIZE);
        OPTKEY(CONNECTTIMEOUT);
        OPTKEY(DNS_CACHE_TIMEOUT);
        OPTKEY(CRLF);
        OPTKEY(FAILONERROR);
        OPTKEY(FOLLOWLOCATION);
        OPTKEY(HEADER);
        OPTKEY(HEADERDATA);
        OPTKEY(HEADERFUNCTION);
        OPTKEY(HTTP200ALIASES);
        OPTKEY(HTTPHEADER);
        OPTKEY(INTERFACE);
        OPTKEY(LOW_SPEED_LIMIT);
        OPTKEY(LOW_SPEED_TIME);
        OPTKEY(MAXREDIRS);
        OPTKEY(NOBODY);
        OPTKEY(NOSIGNAL);
        OPTKEY(NOPROXY);
        OPTKEY(PORT);
        OPTKEY(POST);
        OPTKEY(POSTQUOTE);
        OPTKEY(PREQUOTE);
        OPTKEY(PROXY);
        OPTKEY(QUOTE);
        OPTKEY(RANGE);
        OPTKEY(READDATA);
        OPTKEY(READFUNCTION);
        OPTKEY(RESUME_FROM);
        //OPTKEY(TELNETOPTIONS);
        OPTKEY(TCP_NODELAY);
        OPTKEY(TIMEOUT);
        OPTKEY(TIMEOUT_MS);
        OPTKEY(URL);
        OPTKEY(USERAGENT);
        OPTKEY(USERNAME);
        OPTKEY(USERPWD);
        OPTKEY(VERBOSE);
        OPTKEY(WRITEDATA);
        OPTKEY(WRITEFUNCTION);
#undef OPTKEY

#define PAUSE(O) ctor->Set( JSTR("PAUSE_"#O), v8::Integer::New( CURLPAUSE_ ## O ) )
        PAUSE(RECV);
        PAUSE(SEND);
        PAUSE(ALL);
        PAUSE(CONT);
#undef PAUSE
        
#define SETUINT(K,V) ctor->Set( JSTR(K), v8::Integer::NewFromUnsigned( V ) )
	// TODO: MAKE SURE that the values here are converted correctly to/from JS, and that we
	// do not fall victim to problems involving different value type sizes.
	SETUINT("READFUNC_ABORT", CURL_READFUNC_ABORT);
	SETUINT("READFUNC_PAUSE", CURL_READFUNC_PAUSE);
	SETUINT("WRITEFUNC_PAUSE", CURL_WRITEFUNC_PAUSE);
#undef SETUINT

	// Add CURLE_xxx as Curl.E_xxx:
#define SETE(K) ctor->Set( JSTR("E_"#K), v8::Integer::New( CURLE_ ## K ) )
	SETE(OK);
	SETE(UNSUPPORTED_PROTOCOL);
	SETE(FAILED_INIT);
	SETE(URL_MALFORMAT);
	//SETE(OBSOLETE4);
	SETE(COULDNT_RESOLVE_PROXY);
	SETE(COULDNT_RESOLVE_HOST);
	SETE(COULDNT_CONNECT);
        SETE(FTP_WEIRD_SERVER_REPLY);
	SETE(REMOTE_ACCESS_DENIED);
	SETE(OBSOLETE10);
	SETE(FTP_WEIRD_PASS_REPLY);
	SETE(OBSOLETE12);
	SETE(FTP_WEIRD_PASV_REPLY);
	SETE(FTP_WEIRD_227_FORMAT);
	SETE(FTP_CANT_GET_HOST);
	SETE(OBSOLETE16);
	SETE(FTP_COULDNT_SET_TYPE);
	SETE(PARTIAL_FILE);
	SETE(FTP_COULDNT_RETR_FILE);
	SETE(OBSOLETE20);
	SETE(QUOTE_ERROR);
	SETE(HTTP_RETURNED_ERROR);
	SETE(WRITE_ERROR);
	SETE(OBSOLETE24);
	SETE(UPLOAD_FAILED);
	SETE(READ_ERROR);
	SETE(OUT_OF_MEMORY);
	SETE(OPERATION_TIMEDOUT);
	SETE(OBSOLETE29);
	SETE(FTP_PORT_FAILED);
	SETE(FTP_COULDNT_USE_REST);
	SETE(OBSOLETE32);
	SETE(RANGE_ERROR);
	SETE(HTTP_POST_ERROR);
	SETE(SSL_CONNECT_ERROR);
	SETE(BAD_DOWNLOAD_RESUME);
	SETE(FILE_COULDNT_READ_FILE);
	SETE(LDAP_CANNOT_BIND);
	SETE(LDAP_SEARCH_FAILED);
	SETE(OBSOLETE40);
	SETE(FUNCTION_NOT_FOUND);
	SETE(ABORTED_BY_CALLBACK);
	SETE(BAD_FUNCTION_ARGUMENT);
	SETE(OBSOLETE44);
	SETE(INTERFACE_FAILED);
	SETE(OBSOLETE46);
	SETE(TOO_MANY_REDIRECTS );
	SETE(UNKNOWN_TELNET_OPTION);
	SETE(TELNET_OPTION_SYNTAX );
	SETE(OBSOLETE50);
	SETE(PEER_FAILED_VERIFICATION);
	SETE(GOT_NOTHING);
	SETE(SSL_ENGINE_NOTFOUND);
	SETE(SSL_ENGINE_SETFAILED);
	SETE(SEND_ERROR);
	SETE(RECV_ERROR);
	SETE(OBSOLETE57);
	SETE(SSL_CERTPROBLEM);
	SETE(SSL_CIPHER);
	SETE(SSL_CACERT);
	SETE(BAD_CONTENT_ENCODING);
	SETE(LDAP_INVALID_URL);
	SETE(FILESIZE_EXCEEDED);
	SETE(USE_SSL_FAILED);
	SETE(SEND_FAIL_REWIND);
	SETE(SSL_ENGINE_INITFAILED);
	SETE(LOGIN_DENIED);
	SETE(TFTP_NOTFOUND);
	SETE(TFTP_PERM);
	SETE(REMOTE_DISK_FULL);
	SETE(TFTP_ILLEGAL);
	SETE(TFTP_UNKNOWNID);
	SETE(REMOTE_FILE_EXISTS);
	SETE(TFTP_NOSUCHUSER);
	SETE(CONV_FAILED);
	SETE(CONV_REQD);
	SETE(SSL_CACERT_BADFILE);
	SETE(REMOTE_FILE_NOT_FOUND);
	SETE(SSH);
	SETE(SSL_SHUTDOWN_FAILED);
	SETE(AGAIN);
	SETE(SSL_CRL_BADFILE);
	SETE(SSL_ISSUER_ERROR);
	SETE(SSL_PEER_CERTIFICATE);
	SETE(OBSOLETE);
	SETE(BAD_PASSWORD_ENTERED);
	SETE(BAD_CALLING_ORDER);
	SETE(FTP_USER_PASSWORD_INCORRECT);
	SETE(FTP_CANT_RECONNECT);
	SETE(FTP_COULDNT_GET_SIZE);
	SETE(FTP_COULDNT_SET_ASCII);
	SETE(FTP_WEIRD_USER_REPLY);
	SETE(FTP_WRITE_ERROR);
	SETE(LIBRARY_NOT_FOUND);
	SETE(MALFORMAT_USER);
	SETE(SHARE_IN_USE);
	SETE(URL_MALFORMAT_USER);
	SETE(FTP_ACCESS_DENIED);
	SETE(FTP_COULDNT_SET_BINARY);
	SETE(FTP_QUOTE_ERROR);
	SETE(TFTP_DISKFULL);
	SETE(TFTP_EXISTS);
	SETE(HTTP_RANGE_ERROR);
	SETE(FTP_SSL_FAILED);
	SETE(OPERATION_TIMEOUTED);
	SETE(HTTP_NOT_FOUND);
	SETE(HTTP_PORT_FAILED);
	SETE(FTP_COULDNT_STOR_FILE);
	SETE(FTP_PARTIAL_FILE);
	SETE(FTP_BAD_DOWNLOAD_RESUME);
	SETE(ALREADY_COMPLETE);
#undef SETE

        /**
           Add Curl.INFO_XXX mappings to CURLINFO_XXX.
        */
	CInfoMeta const * cinfo = CInfoList;
	for( ; cinfo && cinfo->PropName; ++cinfo )
	{
	    ctor->Set( JSTR( cinfo->PropName ), v8::Integer::New(cinfo->ID) );
	}
        return;
    }

} } // cvv8::curl


#undef JSTR
#undef TOSS
#undef TOSSV
#undef CERR
