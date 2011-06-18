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

#include <v8/convert/ClassCreator.hpp>
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



/**
   Not yet complete.
*/
class JSByteArray
{
public:
    typedef std::vector<unsigned char> BufferType;
    BufferType vec;
    JSByteArray()
        :vec()
    {
    }
    /**
       JS Usage:

       new ByteArray( [string data = null [, int length=data.length]] )
    */
    JSByteArray( v8::Handle<v8::Value> const & val, unsigned int len = 0 );
    ~JSByteArray()
    {
        //CERR "~JSByteArray@"<<this<<'\n';
    }
    /** Returns the current length of the byte array. */
    uint32_t length() const
    {
        //CERR << "length()\n";
        return this->vec.size();
    }
    /** Sets the length of the byte array. Throws if sz is "too
        long." Returns the new number of items. Any new entries (via
        growing the array) are filled with zeroes.
     */
    uint32_t length( uint32_t sz );

    /** toString() for JS. */
    std::string toString() const;    

    /**
       Returns array contents as a std::string.
    */
    std::string stringValue() const
    {
        return this->vec.empty()
            ? std::string()
            : std::string( this->vec.begin(), this->vec.end() );
    }
    
//     std::string asString() const;
//     std::string asString( unsigned int fromOffset ) const;
//     std::string asString( unsigned int fromOffset, unsigned int len ) const;
    
    static v8::Handle<v8::Value> indexedPropertyGetter(uint32_t index, const v8::AccessorInfo &info);
    static v8::Handle<v8::Value> indexedPropertySetter(uint32_t index, v8::Local< v8::Value > value, const v8::AccessorInfo &info);
    static v8::Handle<v8::Integer> indexedPropertyQuery(uint32_t index, const v8::AccessorInfo &info);
    static v8::Handle<v8::Boolean> indexedPropertyDeleter(uint32_t index, const v8::AccessorInfo &info);
    static v8::Handle<v8::Array> indexedPropertyEnumerator(const v8::AccessorInfo &info);
    static void SetupBindings( v8::Handle<v8::Object> dest );
};




#define BA_JS_CLASS_NAME "ByteArray"
namespace v8 { namespace convert
{

    template <>
    struct JSToNative< JSByteArray > : cv::JSToNative_ClassCreator< JSByteArray >
    {};

    template <>
    class ClassCreator_Factory<JSByteArray>
    {
    public:
        typedef JSByteArray * ReturnType;
        static ReturnType Create( v8::Handle<v8::Object> & jsSelf, v8::Arguments const & argv )
        {
            int const argc  = argv.Length();
            if( argc <= 0 )
            {
                throw std::range_error(BA_JS_CLASS_NAME" ctor requires (string[,int]) or (int) argumemtns.");
            }
            JSByteArray * ba = (1==argc)
                ? new JSByteArray( argv[0] )
                : new JSByteArray( argv[0], cv::CastFromJS<unsigned int>(argv[1]) );
            return ba;
        }
        static void Delete( JSByteArray * obj )
        {
            delete obj;
        }
    };
    
} } // v8::convert

/************************************************************************
   Down here is where the runtime setup parts of the bindings take place...
************************************************************************/

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
        }
    }
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

    
void JSByteArray::SetupBindings( v8::Handle<v8::Object> dest )
{
    using namespace v8;

    //HandleScope scope;
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
        .Set( "destroy", (v8::InvocationCallback)CW::DestroyObject )
        ;
    v8::Handle<v8::ObjectTemplate> const & proto( cw.Prototype() );
    proto->SetAccessor( JSTR("length"),
                        SPB::MethodToAccessorGetterConst<uint32_t(),&N::length>,
                        SPB::MethodToAccessorSetter<uint32_t (uint32_t), &N::length> );
    proto->SetAccessor( JSTR("stringValue"),
                        SPB::MethodToAccessorGetterConst<std::string(),&N::stringValue>,
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

void SetupJSByteArray( v8::Handle<v8::Object> dest )
{
    JSByteArray::SetupBindings(dest);
}

