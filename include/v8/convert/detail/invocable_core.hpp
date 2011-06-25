#if !defined(CODE_GOOGLE_COM_V8_CONVERT_INVOCABLE_V8_HPP_INCLUDED)
#define CODE_GOOGLE_COM_V8_CONVERT_INVOCABLE_V8_HPP_INCLUDED 1

/** @file invocable_core.hpp

This file houses the core-most "invocation-related" parts of the
v8-convert API. These types and functions are for converting
free and member functions to v8::InvocationCallback functions
so that they can be tied to JS objects. It relies on the
CastToJS() and CastFromJS() functions to do non-function type
conversion.
   
*/

#include "convert_core.hpp"
#include "signature_core.hpp"
#include "TypeList.hpp"

//! Refactoring-related macro. Will go away.
#define V8_CONVERT_CATCH_BOUND_FUNCS 0
namespace v8 { namespace convert {


/** Temporary internal macro - it is undef'd at the end of this file. It is used
    by internal generated code, so don't go renaming it without also changing the
    code generator (been there, done that!).
*/
#define JS_THROW(MSG) v8::ThrowException(v8::Exception::Error(v8::String::New(MSG)))

/**
   Partial specialization for v8::InvocationCallback-like functions
   (differing only in their return type) with an Arity value of -1.
*/
template <typename RV>
struct FunctionSignature< RV (v8::Arguments const &) > : SignatureBase<RV (v8::Arguments const &)>
{
    typedef RV (*FunctionType)(v8::Arguments const &);
};

/**
   Partial specialization for v8::InvocationCallback-like non-const
   member functions (differing only in their return type) with an
   Arity value of -1.
*/
template <typename T, typename RV >
struct MethodSignature< T, RV (Arguments const &) > : SignatureBase< RV (v8::Arguments const &) >
{
    typedef T Type;
    typedef RV (T::*FunctionType)(Arguments const &);
};

/**
   Partial specialization for v8::InvocationCallback-like const member
   functions (differing only in their return type) with an Arity value
   of -1.
*/
template <typename T, typename RV >
struct ConstMethodSignature< T, RV (Arguments const &) > : SignatureBase< RV (v8::Arguments const &) >
{
    typedef T Type;
    typedef RV (T::*FunctionType)(Arguments const &) const;
};

// /**
//    Utility class to generate an InvocationCallback-like signature for
//    a member method of class T.
// */
// template <typename T>
// struct InvocationCallbackMethod
// {
//     typedef v8::Handle<v8::Value> (T::*FunctionType)( Arguments const & );
// };

// /**
//    Utility class to generate an InvocationCallback-like signature for
//    a const member method of class T.
// */
// template <typename T>
// struct ConstInvocationCallbackMethod
// {
//     typedef v8::Handle<v8::Value> (T::*FunctionType)( Arguments const & ) const;
// };

/**
   Full specialization for InvocationCallback and
   InvocationCallback-like functions (differing only by their return
   type), which uses an Arity value of -1.
*/
template <typename RV, RV (*FuncPtr)(v8::Arguments const &) >
struct FunctionPtr<RV (v8::Arguments const &),FuncPtr>
    : FunctionSignature<RV (v8::Arguments const &)>
{
    public:
    typedef FunctionSignature<RV (v8::Arguments const &)> SignatureType;
    typedef typename SignatureType::ReturnType ReturnType;
    typedef typename SignatureType::FunctionType FunctionType;
    static FunctionType GetFunction()
     {
         return FuncPtr;
     }
};

/**
   Full specialization for InvocationCallback and
   InvocationCallback-like functions (differing only by their return
   type), which uses an Arity value of -1.
*/
template <typename T,typename RV, RV (T::*FuncPtr)(v8::Arguments const &) >
struct MethodPtr<T, RV (T::*)(v8::Arguments const &),FuncPtr>
    : MethodSignature<T, RV (T::*)(v8::Arguments const &)>
{
    typedef MethodSignature<T, RV (T::*)(v8::Arguments const &)> SignatureType;
    typedef typename SignatureType::ReturnType ReturnType;
    typedef typename SignatureType::FunctionType FunctionType;
    static FunctionType GetFunction()
     {
         return FuncPtr;
     }
};

/**
   Full specialization for InvocationCallback and
   InvocationCallback-like functions (differing only by their return
   type), which uses an Arity value of -1.
*/
template <typename T,typename RV, RV (T::*FuncPtr)(v8::Arguments const &) const >
struct ConstMethodPtr<T, RV (T::*)(v8::Arguments const &) const,FuncPtr>
    : ConstMethodSignature<T, RV (T::*)(v8::Arguments const &) const>
{
    typedef ConstMethodSignature<T, RV (T::*)(v8::Arguments const &) const> SignatureType;
    typedef typename SignatureType::ReturnType ReturnType;
    typedef typename SignatureType::FunctionType FunctionType;
    static FunctionType GetFunction()
     {
         return FuncPtr;
     }
};


namespace Detail {
    /**
        A sentry class which instantiates a v8::Unlocker
        if the boolean value is true or is a no-op if it is false.
    */
    template <bool> struct V8Unlocker;
    
    template <>
    struct V8Unlocker<true>
    {
        private:
            v8::Unlocker * unlocker;
        public:
            V8Unlocker() :
                //unlocker()
                unlocker(new v8::Unlocker)
            {}
            ~V8Unlocker()
            {
                this->Dispose();
            }
            void Dispose()
            {
                //unlocker->~Unlocker();
                delete unlocker;
                unlocker = NULL;
                //unlocker.~Unlocker();
            }
    };
    template <>
    struct V8Unlocker<false>
    {
        inline void Dispose() const
        {}
    };

}

/**
    A metatemplate which we can use to determine if a given type
    is "safe" to use in conjunction with v8::Unlock.
    
    We optimistically assume that most types are safe and
    add specializations for types we know are not safe, e.g.
    v8::Handle<Anything> and v8::Arguments.
*/
template <typename T>
struct IsSafeToUnlock
{
    enum { Value = 1 };
};
template <typename T>
struct IsSafeToUnlock<T const> : IsSafeToUnlock<T> {};
template <typename T>
struct IsSafeToUnlock<T const &> : IsSafeToUnlock<T> {};
template <typename T>
struct IsSafeToUnlock<T *> : IsSafeToUnlock<T> {};
template <typename T>
struct IsSafeToUnlock<T const *> : IsSafeToUnlock<T> {};

template <typename T>
struct IsSafeToUnlock< v8::Handle<T> >
{
    enum { Value = 0 };
};

template <typename T>
struct IsSafeToUnlock< v8::Local<T> >
{
    enum { Value = 0 };
};

template <>
struct IsSafeToUnlock<v8::Arguments>
{
    enum { Value = 0 };
};


/**
    Given a tmp::TypeList-compatible type list, this metafunction's
    Value member evalues to true if IsSafeToUnlock<T>::Value is
    true for all types in TList, else Value evaluates to false.
    As a special case, an empty list evaluates to true because in this
    API an empty list will refer to a function taking no arguments.
*/
template <typename TList>
struct TypeListIsUnlockable;

namespace Detail
{
    using namespace cv::tmp;
    template <typename T> struct CanUnlockImpl : cv::IsSafeToUnlock<T>{};

    template <>
    struct CanUnlockImpl< tmp::NilType > : cv::tmp::BoolVal<true>
    {};
    
    template <typename H, typename T>
    struct CanUnlockImpl< TypeChain<H,T> >
    {
        enum {
            Value =
               ((CanUnlockImpl<H>::Value && cv::TypeListIsUnlockable<T>::Value) ? 1 : 0)
        };
    };
}

template <typename TList>
struct TypeListIsUnlockable : Detail::CanUnlockImpl<typename TList::ChainType>
{
};

//! End-of-list specialization.
template <>
struct TypeListIsUnlockable<tmp::NilType>
{
    enum { Value = 1 };
};

/**
    Given a SignatureTypeList, this metafunction's Value member
    evaluates to true if:
    
    - IsSafeToUnlock<SigTList::ReturnType>::Value is true and...
    
    - IsSafeToUnlock<SigTList::ClassType>::Value is true and...
    
    - TypeListIsUnlockable< SigTList >::Value is true.
    
    If the value is true, the function signature has passed the
    most basic check for whether or not it is legal to use
    v8::Unlocker to unlock v8 before calling a function with
    this signature. Note that this is a best guess, but this code
    cannot know app-specific conditions which might make this
    guess invalid. e.g. if a bound function itself uses v8
    and does not explicitly acquire a lock then the results are
    undefined (and will very possibly trigger an assertion in v8,
    killing the app).
*/
template <typename SigTList>
struct SignatureTypeListIsUnlockable
    : tmp::And< tmp::TypeList<
        IsSafeToUnlock< typename SigTList::ClassType >,
        IsSafeToUnlock< typename SigTList::ReturnType >,
        TypeListIsUnlockable< SigTList >
    > >
{};

namespace Detail {
/**
    Temporary internal macro to trigger a static assertion if unlocking
    support is requested but cannot be implemented for the given
    wrapper due to constraints on our use of v8 when it is unlocked.
*/
#define ASSERT_UNLOCKV8_IS_FALSE typedef char ThisSpecializationCannotUsedUnlocker[!UnlockV8 ? 1 : -1]
    template <int Arity_, typename Sig, bool UnlockV8 = false >
    struct ArgsToFunctionForwarder;

    template <bool UnlockV8>
    struct ArgsToFunctionForwarder<-1,v8::Handle<v8::Value> (v8::Arguments const &), UnlockV8>
        : FunctionSignature<v8::Handle<v8::Value> (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef FunctionSignature<v8::Handle<v8::Value> (v8::Arguments const &)> SignatureType;
        typedef v8::Handle<v8::Value> (*FunctionType)(v8::Arguments const &);
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == -1 ? 1 : -1];
            return func(argv);
        }
    };
    template <typename RV, bool UnlockV8>
    struct ArgsToFunctionForwarder<-1,RV (v8::Arguments const &), UnlockV8>
        : FunctionSignature<RV (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef FunctionSignature<RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == -1 ? 1 : -1];
            return cv::CastToJS( func(argv) );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<0,Sig, UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 0 ? 1 : -1];
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<true> unlocker;
            RV rv( func() );
            unlocker.Dispose();
            return cv::CastToJS( rv );
        }
    };

    template <int Arity_, typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid;

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<0,Sig, UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef Sig FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 0 ? 1 : -1];
            {
                V8Unlocker<UnlockV8> const unlocker();
                func();
            }
            return v8::Undefined();
        }
    };
    
    template <typename RV, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<-1,RV (v8::Arguments const &), UnlockV8>
        : FunctionSignature<RV (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef FunctionSignature<RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == -1 ? 1 : -1];
            func(argv);
            return v8::Undefined();
        }
    };

}

namespace Detail {
    template <typename T, int Arity_, typename Sig, bool UnlockV8 = false>
    struct ArgsToMethodForwarder;

    template <typename T, typename Sig, bool UnlockV8>
    struct ArgsToMethodForwarder<T, 0, Sig, UnlockV8> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, v8::Arguments const & argv )
        {
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv((self.*func)());
            unlocker.Dispose();
            return CastToJS( rv );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename RV, bool UnlockV8>
    struct ArgsToMethodForwarder<T, -1, RV (v8::Arguments const &), UnlockV8>
        : MethodSignature<T, RV (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef MethodSignature<T, RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == -1 ? 1 : -1];
            return CastToJS( (self.*func)(argv) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    template <typename T, typename RV, bool UnlockV8, int _Arity>
    struct ArgsToMethodForwarder<T,_Arity, RV (T::*)(v8::Arguments const &), UnlockV8> : MethodSignature<T,RV (v8::Arguments const &)>
    {
    public:
        typedef MethodSignature<T,RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, v8::Arguments const & argv )
        {
            V8Unlocker<UnlockV8> unlocker;
            RV rv((self.*func)(argv));
            unlocker.Dispose();
            return cv::CastToJS( rv );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, int Arity_, typename Sig, bool UnlockV8 = false>
    struct ArgsToMethodForwarderVoid;

    template <typename T, typename Sig, bool UnlockV8>
    struct ArgsToMethodForwarderVoid<T,0,Sig, UnlockV8> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, v8::Arguments const & argv )
        {
            {
                V8Unlocker<UnlockV8> const unlocker();
                (self.*func)();
            }
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename RV, bool UnlockV8>
    struct ArgsToMethodForwarderVoid<T,-1, RV (v8::Arguments const &), UnlockV8> : MethodSignature<T,RV (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef MethodSignature<T,RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, v8::Arguments const & argv )
        {
            (self.*func)(argv);
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    
    template <typename T, int Arity_, typename Sig, bool UnlockV8 = false>
    struct ArgsToConstMethodForwarder;

    template <typename T, typename Sig, bool UnlockV8>
    struct ArgsToConstMethodForwarder<T,0,Sig, UnlockV8> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, v8::Arguments const & argv )
        {
            V8Unlocker<UnlockV8> unlocker;
            typedef typename SignatureType::ReturnType ReturnType;
            ReturnType rv((self.*func)());
            unlocker.Dispose();
            return cv::CastToJS( rv );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename RV, bool UnlockV8>
    struct ArgsToConstMethodForwarder<T, -1, RV (v8::Arguments const &), UnlockV8>
        : ConstMethodSignature<T, RV (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef ConstMethodSignature<T, RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == -1 ? 1 : -1];
            return CastToJS( (self.*func)(argv) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };


    template <typename T, int Arity_, typename Sig, bool UnlockV8 = false>
    struct ArgsToConstMethodForwarderVoid;

    template <typename T, typename Sig, bool UnlockV8>
    struct ArgsToConstMethodForwarderVoid<T,0,Sig, UnlockV8> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, v8::Arguments const & argv )
        {
            {
                V8Unlocker<UnlockV8> const unlocker();
                (self.*func)();
            }
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    
    template <typename T, typename RV, bool UnlockV8>
    struct ArgsToConstMethodForwarderVoid<T, -1, RV (v8::Arguments const &), UnlockV8>
        : ConstMethodSignature<T, RV (v8::Arguments const &)>
    {
    public:
        ASSERT_UNLOCKV8_IS_FALSE;
        typedef ConstMethodSignature<T, RV (v8::Arguments const &)> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == -1 ? 1 : -1];
            (self.*func)(argv);
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
#undef ASSERT_UNLOCKV8_IS_FALSE
}

/**
   A helper type for passing v8::Arguments lists to native non-member
   functions.

   Sig must be a function-signature-like argument. e.g. <double (int,double)>,
   and the members of this class expect functions matching that signature.

   TODO: Now that we have InCaCatcher, we could potentially
   templatize this to customize exception handling. Or we could
   remove the handling altogether and require clients to use
   InCaCatcher and friends if they want to catch exceptions.
*/
template <typename Sig, bool UnlockV8 = false>
struct ArgsToFunctionForwarder
{
private:
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename FunctionSignature<Sig>::ReturnType>::Value,
                 Detail::ArgsToFunctionForwarderVoid< FunctionSignature<Sig>::Arity, Sig, UnlockV8 >,
                 Detail::ArgsToFunctionForwarder< FunctionSignature<Sig>::Arity, Sig, UnlockV8 >
    >::Type
    ProxyType;
public:
    typedef typename ProxyType::SignatureType SignatureType;
    typedef typename ProxyType::FunctionType FunctionType;
    /**
       Passes the given arguments to func(), converting them to the appropriate
       types. If argv.Length() is less than SignatureType::Arity then
       a JS exception is thrown.
    */
    static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( func, argv );
#else
        try
        {
            return ProxyType::Call( func, argv );
        }
        catch(std::exception const &ex)
        {
            return CastToJS(ex);
        }
        catch(...)
        {
            return JS_THROW("Native code through unknown exception type.");
        }
#endif
    }
    /** Returns Call( Func, argv ). */
    template < typename FunctionSignature<Sig>::FunctionType Func >
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
        return Call( Func, argv );
    }    
};

namespace Detail {
/**
    Temporary internal macro to trigger a static assertion if:
    UnlockV8 is true and SignatureTypeListIsUnlockable<...>::Value is
    false. This is to prohibit that someone accidentally enables
    locking when using an argument/return type which we know cannot
    obey the locking rules.
*/
#define ASSERT_UNLOCK_SANITY_CHECK typedef char  AssertCanEnableUnlock[tmp::Assertion< !UnlockV8 ? 1 : (cv::SignatureTypeListIsUnlockable< cv::SignatureTypeList<Sig> >::Value ? 1 : 0)>::Value ? 1 : -1]
    template <typename Sig,
              typename FunctionSignature<Sig>::FunctionType Func,
              bool UnlockV8 = false>
    struct FunctionToInCa : FunctionPtr<Sig, Func>
    {
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            ASSERT_UNLOCK_SANITY_CHECK;
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder< ParentType::Arity, Sig, UnlockV8 > Proxy;
            return Proxy::Call( Func, argv );
        }
    };

    template <typename Sig,
              typename FunctionSignature<Sig>::FunctionType Func,
              bool UnlockV8>
    struct FunctionToInCaVoid : FunctionPtr<Sig,Func>
    {
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            ASSERT_UNLOCK_SANITY_CHECK;
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid< ParentType::Arity, Sig, UnlockV8 > Proxy;
            return Proxy::Call( Func, argv );
        }
    };

    template <typename T,
              typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func,
              bool UnlockV8 = false>
    struct MethodToInCa : MethodPtr<T,Sig, Func>
    {
        ASSERT_UNLOCK_SANITY_CHECK;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            
            typedef MethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToMethodForwarder< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            return Proxy::Call( Func, argv );
        }
        static v8::Handle<v8::Value> Call( T & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToMethodForwarder< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            return Proxy::Call( self, Func, argv );
        }
    };

    template <typename T,
              typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func,
              bool UnlockV8 = false>
    struct MethodToInCaVoid : MethodPtr<T,Sig,Func>
    {
        ASSERT_UNLOCK_SANITY_CHECK;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToMethodForwarderVoid< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( T & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToMethodForwarderVoid< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            Proxy::Call( self, Func, argv );
            return v8::Undefined();
        }
    };

    template <typename T,
              typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func,
              bool UnlockV8 = false>
    struct ConstMethodToInCa : ConstMethodPtr<T,Sig, Func>
    {
        ASSERT_UNLOCK_SANITY_CHECK;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToConstMethodForwarder< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            return Proxy::Call( Func, argv );
        }
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToConstMethodForwarder< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            Proxy::Call( self, Func, argv );
            return v8::Undefined();
        }
    };

    template <typename T,
              typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func,
              bool UnlockV8 = false>
    struct ConstMethodToInCaVoid : ConstMethodPtr<T,Sig,Func>
    {
        ASSERT_UNLOCK_SANITY_CHECK;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef ConstMethodPtr<T,Sig, Func> ParentType;
            typedef ArgsToConstMethodForwarderVoid< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
        
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            typedef ArgsToConstMethodForwarderVoid< T, ParentType::Arity, Sig, UnlockV8 > Proxy;
            Proxy::Call( self, Func, argv );
            return v8::Undefined();
        }
    };

#undef ASSERT_UNLOCK_SANITY_CHECK
} // Detail namespace

/**
   A template for converting free (non-member) function pointers
   to v8::InvocationCallback.

   Sig must be a function signature. Func must be a pointer to a function
   with that signature.

   If UnlockV8 is true then v8::Unlocker will be used to unlock v8
   for the duration of the call to Func(). HOWEVER... (the rest of
   these docs are about the caveats)...
   
   By default SignatureTypeListIsUnlockable<Sig>::Value is used to
   determine whether or not it is feasible to use v8::Unlocker
   or not. That heuristic is reasonably sound but it cannot
   predict certain app-dependent conditions which render its
   guess invalid. See SignatureTypeListIsUnlockable for more
   information.
   
   It is illegal for UnlockV8 to be true if ANY of the following 
   applies:
   
   - The callback itself will "use" v8. (This _might_ be okay if it 
   uses a v8::Locker. We'll have to try and see.) We cannot 
   determine this programmatically except by guessing based on the 
   return and arguments types.
   
   - Any of the return or argument types for the function are v8 
   types, e.g. v8::Handle<Anything> or v8::Arguments. 
   SignatureTypeListIsUnlockable<Sig>::Value will evaluate to false 
   if any of the "known bad" types is contained in the function's 
   signature.
   
   - There might be other, as yet unknown/undocumented, corner cases 
   where unlocking v8 is semantically illegal at this level of the 
   API.

   Violating any of these leads to undefined behaviour. The library 
   tries to fail at compile time for invalid combinations when it 
   can, but there are plenty of things which require more 
   metatemplate coding in order to catch at compile-time, e.g. if a 
   bound function takes a v8::Handle<> as an argument (which makes it
   illegal for unlocking purpose).
   
   It might also be noteworthy that unlocking v8 requires, for
   reasons of scoping, one additional (very small) memory allocation
   vis-a-vis not unlocking. The memory is freed, of course, right
   after the native call returns.
*/
template <typename Sig,
          typename FunctionSignature<Sig>::FunctionType Func,
          bool UnlockV8 = SignatureTypeListIsUnlockable< SignatureTypeList<Sig> >::Value
          >
struct FunctionToInCa
    : tmp::IfElse< tmp::SameType<void ,typename FunctionSignature<Sig>::ReturnType>::Value,
                 Detail::FunctionToInCaVoid< Sig, Func, UnlockV8>,
                 Detail::FunctionToInCa< Sig, Func, UnlockV8>
        >::Type
{};

/**
   A template for converting non-const member function pointers to
   v8::InvocationCallback. For const member functions use
   ConstMethodToInCa instead.

   To convert JS objects to native 'this' pointers this API uses
   CastFromJS<T>(arguments.This()), where arguments is the
   v8::Arguments instance passed to the generated InvocationCallback
   implementation. If that conversion fails then the generated
   functions will throw a JS-side exception when called.

   T must be some client-specified type which is presumably bound (or
   at least bindable) to JS-side Objects. Sig must be a member
   function signature for T. Func must be a pointer to a function with
   that signature.
   
   See FunctionToInCa for details about the UnlockV8 parameter.
*/
template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func,
          bool UnlockV8 = tmp::And< tmp::TypeList<
            SignatureTypeListIsUnlockable< SignatureTypeList<Sig> >,
            IsSafeToUnlock<T>
            > >::Value
          >
struct MethodToInCa
    : tmp::IfElse< tmp::SameType<void ,typename MethodSignature<T,Sig>::ReturnType>::Value,
                 Detail::MethodToInCaVoid<T, Sig, Func, UnlockV8>,
                 Detail::MethodToInCa<T, Sig, Func, UnlockV8>
        >::Type
{
};

/**
   Functionally identical to MethodToInCa, but for const member functions.
   
   See FunctionToInCa for details about the UnlockV8 parameter.
*/
template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType Func,
          bool UnlockV8 = tmp::And< tmp::TypeList<
            SignatureTypeListIsUnlockable< SignatureTypeList<Sig> >,
            IsSafeToUnlock<T>
            > >::Value
          >
struct ConstMethodToInCa
    : tmp::IfElse< tmp::SameType<void ,typename ConstMethodSignature<T, Sig>::ReturnType>::Value,
                 Detail::ConstMethodToInCaVoid<T, Sig, Func, UnlockV8>,
                 Detail::ConstMethodToInCa<T, Sig, Func, UnlockV8>
        >::Type
{};

/**
   A v8::InvocationCallback implementation which forwards the arguments from argv
   to the template-specified function. If Func returns void then the return
   value will be v8::Undefined().

   Example usage:

   @code
   v8::InvocationCallback cb = FunctionToInvocationCallback<int (char const *), ::puts>;
   @endcode
*/
template <typename FSig,
          typename FunctionSignature<FSig>::FunctionType Func>
v8::Handle<v8::Value> FunctionToInvocationCallback( v8::Arguments const & argv )
{
    return FunctionToInCa<FSig,Func>::Call(argv);
}

/**
   A v8::InvocationCallback implementation which forwards the arguments from argv
   to the template-specified member of "a" T object. This function uses
   CastFromJS<T>( argv.This() ) to fetch the native 'this' object, and will
   fail (with a JS-side exception) if that conversion fails.

   If Func returns void then the return value will be v8::Undefined().

   Example usage:

   @code
   v8::InvocationCallback cb = MethodToInvocationCallback<MyType, int (double), &MyType::doSomething >;
   @endcode

*/
template <typename T,typename FSig,
          typename MethodSignature<T,FSig>::FunctionType Func>
v8::Handle<v8::Value> MethodToInvocationCallback( v8::Arguments const & argv )
{
    return MethodToInCa<T,FSig,Func>::Call(argv);
}


/**
   Identical to MethodToInvocationCallback(), but is for const member functions.

   @code
   v8::InvocationCallback cb = ConstMethodToInvocationCallback<MyType, int (double), &MyType::doSomethingConst >;
   @endcode

*/
template <typename T,typename FSig,
          typename ConstMethodSignature<T,FSig>::FunctionType Func>
v8::Handle<v8::Value> ConstMethodToInvocationCallback( v8::Arguments const & argv )
{
    return ConstMethodToInCa<T,FSig,Func>::Call(argv);
}

/**
   Identicial to ArgsToFunctionForwarder, but works on non-const
   member methods of type T.

   Sig must be a function-signature-like argument. e.g. <double
   (int,double)>, and the members of this class expect T member
   functions matching that signature.
*/
template <typename T, typename Sig>
struct ArgsToMethodForwarder
{
private:
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename MethodSignature<T,Sig>::ReturnType>::Value,
                 Detail::ArgsToMethodForwarderVoid< T, MethodSignature<T,Sig>::Arity, Sig >,
                 Detail::ArgsToMethodForwarder< T, MethodSignature<T,Sig>::Arity, Sig >
    >::Type
    ProxyType;
public:
    typedef typename ProxyType::SignatureType SignatureType;
    typedef typename ProxyType::FunctionType FunctionType;

    /**
       Passes the given arguments to (self.*func)(), converting them
       to the appropriate types. If argv.Length() is less than
       SignatureType::Arity then a JS exception is thrown.
    */
    static v8::Handle<v8::Value> Call( T & self, FunctionType func, v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( self, func, argv );
#else
        try
        {
            return ProxyType::Call( self, func, argv );
        }
        catch(std::exception const &ex)
        {
            return CastToJS(ex);
        }
        catch(...)
        {
            return JS_THROW("Native code through unknown exception type.");
        }
#endif
    }

    /**
       Like the 3-arg overload, but tries to extract the (T*) object using
       CastFromJS<T>(argv.This()).
    */
    static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
    {
        T * self = CastFromJS<T>(argv.This());
        return self
            ? Call(*self, func, argv)
            : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
};


/**
   Identicial to ArgsToMethodForwarder, but works on const member methods.
*/
template <typename T, typename Sig>
struct ArgsToConstMethodForwarder
{
private:
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename ConstMethodSignature<T,Sig>::ReturnType>::Value,
                 Detail::ArgsToConstMethodForwarderVoid< T, ConstMethodSignature<T,Sig>::Arity, Sig >,
                 Detail::ArgsToConstMethodForwarder< T, ConstMethodSignature<T,Sig>::Arity, Sig >
    >::Type
    ProxyType;
public:
    typedef typename ProxyType::SignatureType SignatureType;
    typedef typename ProxyType::FunctionType FunctionType;

    /**
       Passes the given arguments to (self.*func)(), converting them
       to the appropriate types. If argv.Length() is less than
       SignatureType::Arity then a JS exception is thrown.
    */
    static v8::Handle<v8::Value> Call( T const & self, FunctionType func, v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( self, func, argv );
#else
        try
        {
            return ProxyType::Call( self, func, argv );
        }
        catch(std::exception const &ex)
        {
            return CastToJS(ex);
        }
        catch(...)
        {
            return JS_THROW("Native code through unknown exception type.");
        }
#endif
    }

    /**
       Like the 3-arg overload, but tries to extract the (T const *)
       object using CastFromJS<T>(argv.This()).
    */
    static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
    {
        T const * self = CastFromJS<T>(argv.This());
        return self
            ? Call(*self, func, argv)
            : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
};



namespace Detail {
    namespace cv = ::v8::convert;

    /**
       Internal level of indirection to handle void return
       types from forwardFunction().
     */
    template <typename FSig, bool UnlockV8 = false>
    struct ForwardFunction
    {
        typedef cv::FunctionSignature<FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToFunctionForwarder<FSig,UnlockV8> Proxy;
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return cv::CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename FSig, bool UnlockV8 = false>
    struct ForwardFunctionVoid
    {
        typedef cv::FunctionSignature<FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToFunctionForwarder<FSig, UnlockV8> Proxy;
        static void Call( FSig func, v8::Arguments const & argv )
        {
            Proxy::Call( func, argv );
        }
    };
    /**
       Internal level of indirection to handle void return
       types from forwardMethod().
     */
    template <typename T, typename FSig>
    struct ForwardMethod
    {
        typedef cv::MethodSignature<T,FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToMethodForwarder<T,FSig> Proxy;
        static ReturnType Call( T & self, FSig func, v8::Arguments const & argv )
        {
            return cv::CastFromJS<ReturnType>( Proxy::Call( self, func, argv ) );
        }
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return cv::CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename T, typename FSig>
    struct ForwardMethodVoid
    {
        typedef cv::MethodSignature<T,FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToMethodForwarder<T,FSig> Proxy;
        static void Call( T & self, FSig func, v8::Arguments const & argv )
        {
            Proxy::Call( self, func, argv );
        }
        static void Call( FSig func, v8::Arguments const & argv )
        {
            Proxy::Call( func, argv );
        }
    };
    template <typename T, typename FSig>
    struct ForwardConstMethod
    {
        typedef cv::ConstMethodSignature<T,FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToConstMethodForwarder<T,FSig> Proxy;
        static ReturnType Call( T const & self, FSig func, v8::Arguments const & argv )
        {
            return cv::CastFromJS<ReturnType>( Proxy::Call( self, func, argv ) );
        }
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return cv::CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename T, typename FSig>
    struct ForwardConstMethodVoid
    {
        typedef cv::ConstMethodSignature<T,FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToConstMethodForwarder<T,FSig> Proxy;
        static void Call( T const & self, FSig func, v8::Arguments const & argv )
        {
            Proxy::Call( self, func, argv );
        }
        static void Call( FSig func, v8::Arguments const & argv )
        {
            Proxy::Call( func, argv );
        }
    };
}
    
/**
   Tries to forward the given arguments to the given native
   function. Will fail if argv.Lengt() is not at least
   FunctionSignature<FSig>::Arity, throwing a JS exception
   in that case.
*/
template <typename FSig>
inline typename FunctionSignature<FSig>::ReturnType
forwardFunction( FSig func, Arguments const & argv )
{
    typedef FunctionSignature<FSig> MSIG;
    typedef typename MSIG::ReturnType RV;
    typedef typename
        tmp::IfElse< tmp::SameType<void ,RV>::Value,
        Detail::ForwardFunctionVoid< FSig >,
        Detail::ForwardFunction< FSig >
        >::Type ProxyType;
    return (RV)ProxyType::Call( func, argv )
        /* the explicit cast there is a workaround for the RV==void
           case. It is a no-op for other cases, since the return value
           is already RV. Some compilers (MSVC) don't allow an explit
           return of a void expression without the cast.
        */
        ;
}

/**
   Works like forwardFunction(), but forwards to the
   given non-const member function and treats the given object
   as the 'this' pointer.
*/
template <typename T, typename FSig>
inline typename MethodSignature<T,FSig>::ReturnType
forwardMethod( T & self,
               FSig func,
               /* if i do: typename MethodSignature<T,FSig>::FunctionType
                  then this template is never selected. */
               Arguments const & argv )
{
    typedef MethodSignature<T,FSig> MSIG;
    typedef typename MSIG::ReturnType RV;
    typedef typename
        tmp::IfElse< tmp::SameType<void ,RV>::Value,
                 Detail::ForwardMethodVoid< T, FSig >,
                 Detail::ForwardMethod< T, FSig >
    >::Type ProxyType;
    return (RV)ProxyType::Call( self, func, argv )
        /* the explicit cast there is a workaround for the RV==void
           case. It is a no-op for other cases, since the return value
           is already RV. Some compilers (MSVC) don't allow an explit
           return of a void expression without the cast.
        */
        ;
}

/**
   Like the 3-arg forwardMethod() overload, but
   extracts the native T 'this' object from argv.This().

   Note that this function requires that the caller specify
   the T template parameter - it cannot deduce it.
*/
template <typename T, typename FSig>
typename MethodSignature<T,FSig>::ReturnType
forwardMethod(FSig func, v8::Arguments const & argv )
{
    typedef MethodSignature<T,FSig> MSIG;
    typedef typename MSIG::ReturnType RV;
    typedef typename
        tmp::IfElse< tmp::SameType<void ,RV>::Value,
                 Detail::ForwardMethodVoid< T, FSig >,
                 Detail::ForwardMethod< T, FSig >
    >::Type ProxyType;
    return (RV)ProxyType::Call( func, argv )
        /* the explicit cast there is a workaround for the RV==void
           case. It is a no-op for other cases, since the return value
           is already RV. Some compilers (MSVC) don't allow an explit
           return of a void expression without the cast.
        */
        ;
}

    
/**
   Works like forwardMethod(), but forwards to the given const member
   function and treats the given object as the 'this' pointer.

*/
template <typename T, typename FSig>
inline typename ConstMethodSignature<T,FSig>::ReturnType
forwardConstMethod( T const & self,
                    //typename ConstMethodSignature<T,FSig>::FunctionType func,
                    FSig func,
                    v8::Arguments const & argv )
{
    typedef ConstMethodSignature<T,FSig> MSIG;
    typedef typename MSIG::ReturnType RV;
    typedef typename
        tmp::IfElse< tmp::SameType<void ,RV>::Value,
                 Detail::ForwardConstMethodVoid< T, FSig >,
                 Detail::ForwardConstMethod< T, FSig >
    >::Type ProxyType;
    return (RV)ProxyType::Call( self, func, argv )
        /* the explicit cast there is a workaround for the RV==void
           case. It is a no-op for other cases, since the return value
           is already RV. Some compilers (MSVC) don't allow an explit
           return of a void expression without the cast.
        */
        ;
}

/**
   Like the 3-arg forwardConstMethod() overload, but
   extracts the native T 'this' object from argv.This().

   Note that this function requires that the caller specify
   the T template parameter - it cannot deduce it.
*/
template <typename T, typename FSig>
typename ConstMethodSignature<T,FSig>::ReturnType
forwardConstMethod(FSig func, v8::Arguments const & argv )
{
    typedef ConstMethodSignature<T,FSig> MSIG;
    typedef typename MSIG::ReturnType RV;
    typedef typename
        tmp::IfElse< tmp::SameType<void ,RV>::Value,
                 Detail::ForwardConstMethodVoid< T, FSig >,
                 Detail::ForwardConstMethod< T, FSig >
    >::Type ProxyType;
    return (RV)ProxyType::Call( func, argv )
        /* the explicit cast there is a workaround for the
           RV==void case. It is a no-op for other cases,
           since the return value is already RV.
        */
        ;
}
#if 0
/**
   A structified/functorified form of v8::InvocationCallback.  It is
   sometimes convenient to be able to use a typedef to create an alias
   for a given InvocationCallback. Since we cannot typedef function
   templates this way, this class can fill that gap.
*/
template <v8::InvocationCallback ICB>
struct InCa : FunctionToInCa< v8::Handle<v8::Value> (v8::Arguments const &), ICB>
{
};

/**
   "Converts" an InCa<ICB> instance to JS by treating it as an
   InvocationCallback function.
*/
template <v8::InvocationCallback ICB>
struct NativeToJS< InCa<ICB> >
{
    /**
       Returns a JS handle to InCa<ICB>::Call().
    */
    v8::Handle<v8::Value> operator()( InCa<ICB> const & )
    {
        return v8::FunctionTemplate::New(InCa<ICB>::Call)->GetFunction();
    }
};
#endif

/**
   InvocationCallback wrapper which calls another InvocationCallback
   and translates any native ExceptionT exceptions thrown by that
   function into JS exceptions.

   ExceptionT must be an exception type which is thrown by copy
   (e.g. STL-style) as opposed to by pointer (MFC-style).
   
   SigGetMsg must be a function-signature-style argument describing
   a method within ExceptionT which can be used to fetch the message
   reported by the exception. It must meet these requirements:

   a) Be const
   b) Take no arguments
   c) Return a type convertible to JS via CastToJS()

   Getter must be a pointer to a function matching that signature.

   ICB must be a v8::InvocationCallback. When this function is called
   by v8, it will pass on the call to ICB and catch exceptions.

   Exceptions of type ExceptionT which are thrown by ICB get
   translated into a JS exception with an error message fetched using
   ExceptionT::Getter().

   If PropagateOtherExceptions is true then exception of types other
   than ExceptionT are re-thrown (which can be fatal to v8, so be
   careful). If it is false then they are not propagated but the error
   message in the generated JS exception is unspecified (because we
   have no generic way to get such a message). If a client needs to
   catch multiple exception types, enable propagation and chain the
   callbacks together. In such a case, the outer-most (first) callback
   in the chain should not propagate unknown exceptions (to avoid
   killing v8).


   This type can be used to implement "chaining" of exception
   catching, such that we can use the InCaCatcher
   to catch various distinct exception types in the context
   of one v8::InvocationCallback call.

   Example:

   @code
   // Here we want to catch MyExceptionType, std::runtime_error, and
   // std::exception (the base class of std::runtime_error, by the
   // way) separately:

   // When catching within an exception hierarchy, start with the most
   // specific (most-derived) exceptions.

   // Client-specified exception type:
   typedef InCaCatcher<
      MyExceptionType,
      std::string (),
      &MyExceptionType::getMessage,
      MyCallbackWhichThrows, // the "real" InvocationCallback
      true // make sure propagation is turned on!
      > Catch_MyEx;

  // std::runtime_error:
  typedef InCaCatcher<
      std::runtime_error,
      char const * (),
      &std::runtime_error::what,
      Catch_MyEx::Catch, // next Callback in the chain
      true // make sure propagation is turned on!
      > Catch_RTE;

   // std::exception:
   typedef InCaCatcher_std<
       Catch_RTE::Call,
       false // Often we want no propagation at the top-most level,
             // to avoid killing v8.
       > MyCatcher;

   // Now MyCatcher::Call is-a InvocationCallback which will handle
   // MyExceptionType, std::runtime_error, and std::exception via
   // different catch blocks. Note, however, that the visible
   // behaviour for runtime_error and std::exception (its base class)
   // will be identical here, though they actually have different
   // code.

   @endcode

   Note that the InvocationCallbacks created by most of the
   v8::convert API adds (non-propagating) exception catching for
   std::exception to the generated wrappers. Thus this type is not
   terribly useful with them. It is, however, useful when one wants to
   implement an InvocationCallback such that it can throw, but wants
   to make sure that the exceptions to not pass back into v8 when JS
   is calling the InvocationCallback (as propagating exceptions
   through v8 is fatal to v8).

   TODO: consider removing the default-imposed exception handling
   created by most forwarders/wrappers in favour of this
   approach. This way is more flexible and arguably "more correct",
   but adds a burder to users who want exception catching built in.
*/
template < typename ExceptionT,
           typename SigGetMsg,
           typename v8::convert::ConstMethodSignature<ExceptionT,SigGetMsg>::FunctionType Getter,
           // how to do something like this: ???
           // template <class ET, class SGM> class SigT::FunctionType Getter,
           v8::InvocationCallback ICB,
           bool PropagateOtherExceptions = false
    >
struct InCaCatcher
{
    static v8::Handle<v8::Value> Call( v8::Arguments const & args )
    {
        try
        {
            return ICB( args );
        }
        catch( ExceptionT const & e2 )
        {
            return v8::ThrowException(v8::Exception::Error(CastToJS((e2.*Getter)())->ToString()));
        }
        catch( ExceptionT const * e2 )
        {
            return v8::ThrowException(v8::Exception::Error(CastToJS((e2->*Getter)())->ToString()));
        }
        catch(...)
        {
            if( PropagateOtherExceptions ) throw;
            else return JS_THROW("Unknown native exception thrown!");
        }
    }
};
    
namespace Detail {
    template <int Arity>
    v8::Handle<v8::Value> TossArgCountError( v8::Arguments const & args )
    {
        using v8::convert::StringBuffer;
        return v8::ThrowException(v8::Exception::Error(StringBuffer()
                                                       <<"Incorrect argument count ("<<args.Length()
                                                       <<") for function - expecting "
                                                       <<Arity<<" arguments."));
    }

}

/**
   A utility template to assist in the creation of InvocationCallbacks
   overloadable based on the number of arguments passed to them at
   runtime.

   See Call() for more details.
   
   Using this class almost always requires more code than
   doing the equivalent with InCaOverload. The exception to that
   guideline is when we have only two overloads.
*/
template < int Arity,
           v8::InvocationCallback ICB,
           v8::InvocationCallback Fallback = Detail::TossArgCountError<Arity>
>
struct InCaOverloader
{
    /**
       When called, if (Artity==-1) or if (Arity==args.Length()) then
       ICB(args) is returned, else Fallback(args) is returned.

       The default Fallback implementation triggers a JS-side
       exception when called, its error string indicating the argument
       count mismatch.

       Implementats the InvocationCallback interface.
    */
    static v8::Handle<v8::Value> Call( v8::Arguments const & args )
    {
        return ( (-1==Arity) || (Arity == args.Length()) )
            ? ICB(args)
            : Fallback(args);
    }
};

/**
   Convenience form of InCaCatcher which catches
   std::exception and uses their what() method to
   fetch the error message.
   
   The ConcreteException parameter may be std::exception (the 
   default) or (in theory) any publically derived subclass.
   When using a non-default value, one can chain exception catchers
   to catch most-derived types first.
   
   PropagateOtherExceptions defaults to false if ConcreteException is
   std::exception, else it defaults to true. The reasoning is: when chaining
   these handlers we need to catch the most-derived first. Those handlers
   need to propagate other exceptions so that we can catch the lesser-derived
   ones (or those from completely different hierarchies) in subsequent
   catchers.
   
   Here is an example of chaining:
   
   @code
    typedef InCaCatcher_std< MyThrowingCallback, std::logic_error > LECatch;
    typedef cv::InCaCatcher_std< LECatch::Call, std::runtime_error > RECatch;
    typedef cv::InCaCatcher_std< RECatch::Call > BaseCatch;
    v8::InvocationCallback cb = BaseCatch::Call;
   @endcode
*/
template <v8::InvocationCallback ICB,
        typename ConcreteException = std::exception,
        bool PropagateOtherExceptions = !tmp::SameType< std::exception, ConcreteException >::Value
>
struct InCaCatcher_std :
    InCaCatcher<ConcreteException,
                char const * (),
                &ConcreteException::what,
                ICB,
                PropagateOtherExceptions
                >
{};



namespace Detail
{
    namespace cv = v8::convert;
    namespace tmp = cv::tmp;
    template <typename FWD>
    struct ArityOverloaderOne
    {
        static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
        {
            if( (FWD::Arity<0) || (FWD::Arity == argv.Length()) )
            {
                return FWD::Call( argv );
            }
            else
            {
                cv::StringBuffer msg;
                msg << "ArityOverloaderOne<>::Call(): "
                    //<< argv.Callee()->GetName()
                    << "called with "<<argv.Length()<<" arguments, "
                    << "but requires "<<(int)FWD::Arity<<"!\n";
                return v8::ThrowException(msg.toError());
            }
        }
    };
    /**
       Internal dispatch end-of-list routine.
    */
    template <>
    struct ArityOverloaderOne<tmp::NilType>
    {
        static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
        {
            return v8::ThrowException(v8::Exception::Error(v8::String::New("ArityOverloaderOne<> end-of-list specialization should not have been called!")));
        }
    };
    /**
       FwdList must be-a TypeList of classes with Call() and Arity members.
    */
    template <typename List>
    struct ArityOverloaderList
    {
        static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
        {
            typedef typename List::Head FWD;
            typedef typename List::Tail Tail;
            if( (FWD::Arity == argv.Length()) || (FWD::Arity<0) )
            {
                return ArityOverloaderOne< FWD >::Call( argv );
            }
            {
                return ArityOverloaderList< Tail >::Call(argv);
            }
            return v8::Undefined(); // can't get this far.
        }
    };

    /**
       End-of-list specialization.
    */
    template <>
    struct ArityOverloaderList<tmp::NilType>
    {
        static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
        {
            cv::StringBuffer msg;
            msg << "ArityOverloaderList<>::Call() there is no overload "
                //<< argv.Callee()->GetName() // name is normally empty
                << "taking "<<argv.Length()<<" arguments!\n";
            return v8::ThrowException( msg.toError() );
        }
    };       
} // namespace Detail

/**
   A helper class which allows us to dispatch to multiple
   overloaded native functions from JS, depending on the argument
   count.

   FwdList must be-a v8::convert::tmp::TypeList (or 
   interface-compatible type list) containing types which have the 
   following function:

   static v8::Handle<v8::Value> Call( v8::Arguments const & argv );

   And a static const integer (or enum) value called Arity, 
   which must specify the expected number of arguments, or be 
   negative specify that the function accepts any number of 
   arguments.

   In other words, all entries in FwdList must implement the
   interface used by most of the InCa-related API.
   
   Example:
   
   @code
   // Overload 3 variants of a member function:
   namespace cv = v8::convert;
   typedef cv::tmp::TypeList<
            cv::MethodToInCa<BoundNative, void(), &BoundNative::overload0>,
            cv::MethodToInCa<BoundNative, void(int), &BoundNative::overload1>,
            cv::MethodToInCa<BoundNative, void(int,int), &BoundNative::overload2>
        > OverloadList;
   typedef cv::InCaOverloadList< OverloadList > MyOverloads;
   v8::InvocationCallback cb = MyOverloads::Call;     
   @endcode
   
   Note that only one line of that code is evaluated at runtime - the rest
   is all done at compile-time.
*/
template < typename FwdList >
struct InCaOverloadList
{
    // arguable: static const Arity = -1;
    /**
       Tries to dispatch argv to one of the bound functions defined
       in FwdList, based on the number of arguments in argv and
       the Arity 

       Implements the v8::InvocationCallback interface.
    */
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
        typedef Detail::ArityOverloaderList<FwdList> X;
        return X::Call( argv );
    }
};

#include "invocable_generated.hpp"


#if 1
namespace Detail {
    namespace cv = v8::convert;

    template <bool IsConst, typename T, typename Sig>
    struct ConstOrNotSig;
    
    template <typename T, typename Sig>
    struct MethodOrFunctionSig : cv::MethodSignature<T,Sig> {};
    template <typename Sig>
    struct MethodOrFunctionSig<void,Sig> : cv::FunctionSignature<Sig> {};
    
    template <typename T, typename Sig>
    struct ConstOrNotSig<true,T,Sig> : cv::ConstMethodSignature<T,Sig>
    {};
    
    template <typename T, typename Sig>
    struct ConstOrNotSig<false,T,Sig> : MethodOrFunctionSig<T,Sig>
    {
    };
    
    template <bool IsConst, typename T, typename Sig,
            typename ConstOrNotSig<IsConst,T,Sig>::FunctionType Func,
            bool UnlockV8 = false>
    struct ConstOrNotMethodToInCa;
    
    template <typename T, typename Sig,
            typename cv::ConstMethodSignature<T,Sig>::FunctionType Func,
            bool UnlockV8>
    struct ConstOrNotMethodToInCa<true,T,Sig,Func,UnlockV8> : cv::ConstMethodToInCa<T,Sig,Func>
    {};
    
    template <typename T, typename Sig,
            typename cv::MethodSignature<T,Sig>::FunctionType Func,
            bool UnlockV8>
    struct ConstOrNotMethodToInCa<false,T,Sig,Func,UnlockV8> : cv::MethodToInCa<T,Sig,Func>
    {};
}

/**
    A wrapper for MethodToInCa, ConstMethodToInCa, and 
    FunctionToInCa, which determines which one of those to use based 
    on the type of T and the constness of the method signature Sig.

    For non-member functions, T must be void.

    See FunctionToInCa for the meaning of the UnlockV8 parameter.

    Examples:

    @code
    typedef ToInCa<MyT, int (int), &MyT::nonConstFunc> NonConstMethod;
    typedef ToInCa<MyT, void (int) const, &MyT::constFunc> ConstMethod;
    typedef ToInCa<void, int (char const *), ::puts, true> Func;
    
    v8::InvocationCallback cb;
    cb = NonConstMethod::Call;
    cb = ConstMethod::Call;
    cb = Func::Call;
    @endcode

    Note the extra 'const' qualification for const method. This is
    unfortunately neccessary (or at least i haven't found a way around
    it yet). Also note that 'void' 1st parameter for non-member
    functions (another minor hack).

    It is unknown whether or not this template will work in Microsoft
    compilers which reportedly have trouble differentiating 
    constness in templates. The whole reason why (Const)MethodToInCa 
    is split into const- and non-const forms is to be able to 
    work around that shortcoming :/.

    Maintenance reminder: we need the extra level of indirection
    (the classes in the Detail namespace) to avoid instantiating
    both ConstMethodToInCa and MethodToInCa with the given
    singature/function combination (which won't compile).
    
*/
template <typename T, typename Sig,
        typename Detail::ConstOrNotSig<SignatureTypeList<Sig>::IsConst,T,Sig>::FunctionType Func,
        bool UnlockV8 = tmp::And< tmp::TypeList<
            SignatureTypeListIsUnlockable< SignatureTypeList<Sig> >,
            IsSafeToUnlock<T>
            > >::Value
        >
struct ToInCa : Detail::ConstOrNotMethodToInCa<SignatureTypeList<Sig>::IsConst,T,Sig,Func,UnlockV8>
{
};
/**
    Specialization for FunctionToInCa behaviour.
*/
template <typename Sig,
    typename FunctionSignature<Sig>::FunctionType Func,
    bool UnlockV8
>
struct ToInCa<void,Sig,Func,UnlockV8> : FunctionToInCa<Sig,Func,UnlockV8>
{
};
#endif

}} // namespaces

#undef JS_THROW
#undef V8_CONVERT_CATCH_BOUND_FUNCS

#endif /* CODE_GOOGLE_COM_V8_CONVERT_INVOCABLE_V8_HPP_INCLUDED */
