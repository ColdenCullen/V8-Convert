// EXPERIMENTAL CODE. Don't use!
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
        //bool operator()( v8::Handle<v8::Value> const & ) const;
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


    template <>
    struct ValIs<int8_t> : ValIs_NumberStrictRange<int8_t> {};
    template <>
    struct ValIs<uint8_t> : ValIs_NumberStrictRange<uint8_t> {};
    template <>
    struct ValIs<int16_t> : ValIs_NumberStrictRange<int16_t> {};
    template <>
    struct ValIs<uint16_t> : ValIs_NumberStrictRange<uint16_t> {};
    template <>
    struct ValIs<int32_t> : ValIs_NumberStrictRange<int32_t> {};
    template <>
    struct ValIs<uint32_t> : ValIs_NumberStrictRange<uint32_t> {};
    template <>
    struct ValIs<int64_t> : ValIs_NumberStrictRange<int64_t> {};
    template <>
    struct ValIs<uint64_t> : ValIs_NumberStrictRange<uint64_t> {};
    template <>
    struct ValIs<double> : ValIs_NumberStrictRange<double> {};
    

    
    template <typename StringT>
    struct ValIs_StringType
    {
        typedef StringT Type;
        inline bool operator()( v8::Handle<v8::Value> const & h ) const
        {
            return h.IsEmpty()
                ? false
                : h->IsString();
        }
    };
    
    template <>
    struct ValIs<char const *> : ValIs_StringType<char const *> {};
    template <>
    struct ValIs<std::string> : ValIs_StringType<std::string> {};

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


    template <typename ClientState = void *>
    class ArgParser;
    
    struct RuleConcept
    {
        template <typename ClientState>
        static bool Test( ArgParser<ClientState> & p );
    };


    struct ArgumentsPredicateConcept
    {
        bool operator()( v8::Arguments const & ) const;
    };

    template <int Min_, int Max_ = Min_>
    struct ArgPred_Length
    {
        enum { Min = Min_, Max = Max_ };
        typedef char AssertRange[ (Min<=Max) ? 1 : -1];
        bool operator()( v8::Arguments const & av ) const
        {
            int const argc = av.Length();
            if( Max < 0 ) return argc >= Min;
            else return (argc>=Min) && (argc<=Max);
        }
    };
    
    template <unsigned short Index, typename T>
    struct ArgAt_IsA
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
    struct ArgAt_IsX
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

    template <typename ClientState>
    class ArgParser
    {
    private:
        v8::Arguments const & av;
        int const argc;
        int pos;
        mutable ClientState cli;
        v8::Handle<v8::Value> result;
    public:
        ArgParser(v8::Arguments const & av, ClientState cli )
            : av(av),
              argc(av.Length()),
              pos(-1),
              cli(cli),
              result()
        {
        }
        
        ~ArgParser()
        {
            this->result = v8::Handle<v8::Value>();
        }
        ClientState State() const { return this->cli; }

        void Result( v8::Handle<v8::Value> v ) { this->result = v; }
        v8::Handle<v8::Value> Result() const { return this->result; }

        int Pos() const { return this->pos; }
        bool AtEnd() const { return this->pos >= this->argc; }
        v8::Arguments const & Arguments() const { return this->av; }
        int Bump(int offset=1)
        {
            this->pos += offset;
            if( this->pos < 0 ) this->pos = 0;
            return this->pos;
        }

        template <typename StartRule>
        v8::Handle<v8::Value> Parse( StartRule const & rule )
        {
            v8::Handle<v8::Value> v = rule.Test( *this );
            return v;
        }
    };
    

#if 0    
    class MyFirstRule
    {
        template <typename ClientState>
        static bool Test( ArgParser<ClientState> & p )
        {
            v8::Arguments const & av( p.Arguments() );
            typedef ArgPred_Length<0,3> Len03;
            if( ! Len03()( av ) )
            {
                return Toss( StringBuffer()<<"Arg count must be between "
                            <<Len03::Min<<" and "<<Len03::Max<<", inclusive.");
            }
            Toss("NYI!");
            return false;
        }
    };
#endif

} } // namespaces
#endif
