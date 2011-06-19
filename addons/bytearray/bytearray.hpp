#if !defined (V8_CONVERT_BYTEARRAY_H_INCLUDED)
#define V8_CONVERT_BYTEARRAY_H_INCLUDED
#include <v8.h>

namespace v8 { namespace convert {

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

}} // namespaces
#endif /* V8_CONVERT_BYTEARRAY_H_INCLUDED */
