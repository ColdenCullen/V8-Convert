// EXPERIMENTAL CODE. Don't use!
// Don't rely on any interfaces in this file until this notice goes away!
#if !defined(V8_CONVERT_ARGUMENTS_HPP_INCLUDED)
#define V8_CONVERT_ARGUMENTS_HPP_INCLUDED
#include "convert.hpp"
#include <limits>

namespace v8 { namespace convert { //namespace arg {

    template <int I>
    struct ArgAt
    {
        typedef char AssertIndex[ (I>=0) ? 1 : -1];
        v8::Handle<v8::Value> operator()( v8::Arguments const & argv ) const
        {
            return (argv.Length() > I) ? argv[I] : v8::Undefined();
        }
        v8::Handle<v8::Value> operator()( v8::Arguments const & argv, int i ) const
        {
            return (i<0) ? Toss("Index may not be negative.") : argv[i];
        }
    };

    struct ValuePredicateConcept
    {
        bool operator()( v8::Handle<v8::Value> const & ) const;
    };

    template <typename T>
    struct ValIs : ValuePredicateConcept
    {
        typedef T Type;
        inline bool operator()( v8::Handle<v8::Value> const & v ) const
        {
            return NULL != CastFromJS<T const *>(v);
        }
    };
    
    template <typename T>
    struct ValIs<T const> : ValIs<T> {};
    
    template <typename T>
    struct ValIs<T *> : ValIs<T> {};
    
    template <typename T>
    struct ValIs<T const *> : ValIs<T> {};

    template <>
    struct ValIs<void>
    {
        typedef void Type;
        inline bool operator()( v8::Handle<v8::Value> const & h ) const
        {
            return h.IsEmpty() || h->IsUndefined();
        }
    };
    
    namespace Detail {
        template <bool (v8::Value::*Getter)() const>
        struct ValIs_X
        {
            bool operator()( v8::Handle<v8::Value> const & v ) const
            {
                return v.IsEmpty() ? false : ((*v)->*Getter)();
            }  
        };
    }
    struct ValIs_Array : Detail::ValIs_X<&v8::Value::IsArray> {};
    struct ValIs_Object : Detail::ValIs_X<&v8::Value::IsObject> {};
    struct ValIs_Boolean : Detail::ValIs_X<&v8::Value::IsBoolean> {};
    struct ValIs_Date : Detail::ValIs_X<&v8::Value::IsDate> {};
    struct ValIs_External : Detail::ValIs_X<&v8::Value::IsExternal> {};
    struct ValIs_False : Detail::ValIs_X<&v8::Value::IsFalse> {};
    struct ValIs_Function : Detail::ValIs_X<&v8::Value::IsFunction> {};
    struct ValIs_Int32 : Detail::ValIs_X<&v8::Value::IsInt32> {};
    struct ValIs_UInt32 : Detail::ValIs_X<&v8::Value::IsUint32> {};
    struct ValIs_Null : Detail::ValIs_X<&v8::Value::IsNull> {};
    struct ValIs_Undefined : Detail::ValIs_X<&v8::Value::IsUndefined> {};
    struct ValIs_Number : Detail::ValIs_X<&v8::Value::IsNumber> {};
    struct ValIs_RegExp : Detail::ValIs_X<&v8::Value::IsRegExp> {};
    struct ValIs_String : Detail::ValIs_X<&v8::Value::IsString> {};
    struct ValIs_True : Detail::ValIs_X<&v8::Value::IsTrue> {};


    namespace Detail {
        template <typename NumT>
        struct ValIs_NumberStrictRange
        {
            typedef NumT Type;
            inline bool operator()( v8::Handle<v8::Value> const & h ) const
            {
                if( h.IsEmpty() || ! h->IsNumber() ) return false;
                else
                {
                    double const dv( h->NumberValue() );
                    return (dv >= std::numeric_limits<NumT>::min())
                        && (dv <= std::numeric_limits<NumT>::max());
                }
            }
        };
        template <>
        struct ValIs_NumberStrictRange<double>
        {
            typedef double Type;
            inline bool operator()( v8::Handle<v8::Value> const & h ) const
            {
                return !h.IsEmpty() && h->IsNumber();
            }
        };
    }

    template <>
    struct ValIs<int8_t> : Detail::ValIs_NumberStrictRange<int8_t> {};
    template <>
    struct ValIs<uint8_t> : Detail::ValIs_NumberStrictRange<uint8_t> {};
    template <>
    struct ValIs<int16_t> : Detail::ValIs_NumberStrictRange<int16_t> {};
    template <>
    struct ValIs<uint16_t> : Detail::ValIs_NumberStrictRange<uint16_t> {};
    template <>
    struct ValIs<int32_t> : Detail::ValIs_NumberStrictRange<int32_t> {};
    template <>
    struct ValIs<uint32_t> : Detail::ValIs_NumberStrictRange<uint32_t> {};
    template <>
    struct ValIs<int64_t> : Detail::ValIs_NumberStrictRange<int64_t> {};
    template <>
    struct ValIs<uint64_t> : Detail::ValIs_NumberStrictRange<uint64_t> {};
    template <>
    struct ValIs<double> : ValIs_Number {};

    
    template <>
    struct ValIs<char const *> : ValIs_String {};
    
    template <>
    struct ValIs<std::string> : ValIs_String {};

    struct ArgumentsPredicateConcept
    {
        bool operator()( v8::Arguments const & ) const;
    };

    template <int Min_, int Max_ = Min_>
    struct ArgPred_Length : ArgumentsPredicateConcept
    {
        enum { Min = Min_, Max = Max_ };
        bool operator()( v8::Arguments const & av ) const
        {
            
            int const argc = av.Length();
            return (Max < Min)
                ? argc >= Min
                : (argc>=Min) && (argc<=Max);
        }
    };

    template <unsigned short Index, typename ValIsType >
    struct ArgAt_Is : ArgumentsPredicateConcept
    {
        bool operator()( v8::Arguments const & av ) const
        {
            return (Index >= av.Length())
                ? false
                : ValIsType()( av[Index] );
        }
    };

    
    template <unsigned short Index, typename T>
    struct ArgAt_IsA : ArgumentsPredicateConcept
    {
        bool operator()( v8::Arguments const & av ) const
        {
            typedef ValIs<T> ISA;
            return (Index >= av.Length())
                ? false
                : ISA()( av[Index] );
        }
    };

    template <unsigned short Index, bool (v8::Value::*Getter)() const>
    struct ArgAt_IsX : ArgumentsPredicateConcept
    {
        bool operator()( v8::Arguments const & av ) const
        {
            return ( av.Length() <= Index )
                ? false
                : ((*av[Index])->*Getter)();
        }  
    };
    template <unsigned short Index>
    struct ArgAt_IsArray : ArgAt_IsX<Index, &v8::Value::IsArray> {};

    template <unsigned short Index>
    struct ArgAt_IsObject : ArgAt_IsX<Index, &v8::Value::IsObject> {};

    template <unsigned short Index>
    struct ArgAt_IsBoolean : ArgAt_IsX<Index, &v8::Value::IsBoolean> {};

    template <unsigned short Index>
    struct ArgAt_IsDate : ArgAt_IsX<Index, &v8::Value::IsDate> {};

    template <unsigned short Index>
    struct ArgAt_IsExternal : ArgAt_IsX<Index, &v8::Value::IsExternal> {};

    template <unsigned short Index>
    struct ArgAt_IsFalse : ArgAt_IsX<Index, &v8::Value::IsFalse> {};

    template <unsigned short Index>
    struct ArgAt_IsFunction : ArgAt_IsX<Index, &v8::Value::IsFunction> {};

    template <unsigned short Index>
    struct ArgAt_IsInt32 : ArgAt_IsX<Index, &v8::Value::IsInt32> {};

    template <unsigned short Index>
    struct ArgAt_IsUInt32 : ArgAt_IsX<Index, &v8::Value::IsUint32> {};

    template <unsigned short Index>
    struct ArgAt_IsNull : ArgAt_IsX<Index, &v8::Value::IsNull> {};
    
    template <unsigned short Index>
    struct ArgAt_IsUndefined : ArgAt_IsX<Index, &v8::Value::IsUndefined> {};

    template <unsigned short Index>
    struct ArgAt_IsNumber : ArgAt_IsX<Index, &v8::Value::IsNumber> {};

    template <unsigned short Index>
    struct ArgAt_IsRegExp : ArgAt_IsX<Index, &v8::Value::IsRegExp> {};

    template <unsigned short Index>
    struct ArgAt_IsString : ArgAt_IsX<Index, &v8::Value::IsString> {};

    template <unsigned short Index>
    struct ArgAt_IsTrue : ArgAt_IsX<Index, &v8::Value::IsTrue> {};



#if 0 // i don't think i like this stuff...
    template <typename T>
    struct ValCanBe : ValuePredicateConcept
    {
        inline bool operator()( v8::Handle<v8::Value> const & v ) const
        {
            return NULL != CastFromJS<T const *>(v);
        }
    };
    template <>
    struct ValCanBe<void>
    {
        inline bool operator()( v8::Handle<v8::Value> const & v ) const
        {
            return v.IsEmpty() || v->IsUndefined();
        }
    };
    
    template <typename T>
    struct ValCanBe_AnyNonEmpty
    {
        typedef T Type;
        inline bool operator()( v8::Handle<v8::Value> const & h ) const
        {
            return !h.IsEmpty();
        }
    };
    
#if 0
    struct ValCanBe_Number
    {
        inline bool operator()( v8::Handle<v8::Value> const & h ) const
        {
            return ( h.IsEmpty() )
                ? false
                : h->IsNumber();
        }
    };
#endif

    template <typename NumT>
    struct ValCanBe_NumberStrictRange : ValIs_NumberStrictRange<NumT> {};

    template <>
    struct ValCanBe<bool> : ValCanBe_AnyNonEmpty<bool> {};
    template <>
    struct ValCanBe<int8_t> : ValCanBe_NumberStrictRange<int8_t> {};
    template <>
    struct ValCanBe<uint8_t> : ValCanBe_NumberStrictRange<uint8_t> {};
    template <>
    struct ValCanBe<int16_t> : ValCanBe_NumberStrictRange<int16_t> {};
    template <>
    struct ValCanBe<uint16_t> : ValCanBe_NumberStrictRange<uint16_t> {};
    template <>
    struct ValCanBe<int32_t> : ValCanBe_NumberStrictRange<int32_t> {};
    template <>
    struct ValCanBe<uint32_t> : ValCanBe_NumberStrictRange<uint32_t> {};
    template <>
    struct ValCanBe<int64_t> : ValCanBe_NumberStrictRange<int64_t> {};
    template <>
    struct ValCanBe<uint64_t> : ValCanBe_NumberStrictRange<uint64_t> {};
    template <>
    struct ValCanBe<double> : ValCanBe_NumberStrictRange<double> {};
    template <>
    struct ValCanBe<char const *> : ValCanBe_AnyNonEmpty<char const *> {};
    template <>
    struct ValCanBe<std::string> : ValCanBe_AnyNonEmpty<std::string> {};

#endif
} } // namespaces

#endif
