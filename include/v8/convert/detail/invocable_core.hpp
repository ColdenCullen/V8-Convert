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
struct FunctionSignature< RV (v8::Arguments const &) > : SignatureBase<RV, -1>
{
    typedef RV (*FunctionType)(v8::Arguments const &);
};

/**
   Partial specialization for v8::InvocationCallback-like non-const
   member functions (differing only in their return type) with an
   Arity value of -1.
*/
template <typename T, typename RV >
struct MethodSignature< T, RV (Arguments const &) > : SignatureBase< RV, -1 >
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
struct ConstMethodSignature< T, RV (Arguments const &) > : SignatureBase< RV, -1 >
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
    template <int Arity_, typename Sig,
              typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionToInCa;
    using v8::Arguments;

    template <typename VT,
              typename FunctionSignature<VT (v8::Arguments const &)>::FunctionType Func
              >
    struct FunctionToInCa<-1,
                               VT (Arguments const &),
                               Func
                               >
        : FunctionPtr<VT (Arguments const &), Func>
    {
    private:
        typedef FunctionPtr<VT (Arguments const &), Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            return CastToJS( (*Func)(argv) );
        }
    };
    
    template <typename Sig,
              typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionToInCa<0,Sig,Func> : FunctionPtr<Sig, Func>
    {
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( Arguments const & )
        {
            Func();
            return Undefined();
        }
    };

    template <int Arity_, typename Sig,
              typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionToInCaVoid;

    template <typename VT, VT (*Func)(Arguments const &) >
    struct FunctionToInCaVoid<-1, VT (Arguments const &), Func>
        : FunctionPtr<VT (Arguments const &), Func>
    {
    private:
        typedef FunctionPtr<VT (Arguments const &), Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            (*Func)(argv);
            return v8::Undefined();
        }
    };
    
    template <typename Sig,
              typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionToInCaVoid<0,Sig,Func> : FunctionPtr<Sig, Func>
    {
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( Arguments const & )
        {
            Func();
            return Undefined();
        }
    };
}


namespace Detail {
    template <typename T, int Arity_, typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodToInCa;

    template <typename T,
              typename VT,
              typename MethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct MethodToInCa<T, -1, VT (T::*)(Arguments const &), Func>
        : MethodPtr<T, VT (Arguments const &), Func>
    {
    private:
        typedef MethodPtr<T, VT (Arguments const &), Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T & t, Arguments const & argv )
        {
            return CastToJS( (t.*Func)(argv) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    template <typename T,
              typename VT,
              typename MethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct MethodToInCa<T, -1, VT (Arguments const &), Func>
        : MethodToInCa<T, -1, VT (T::*)(Arguments const &), Func>
    {};
    
    template <typename T, typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodToInCa<T, 0,Sig,Func> : MethodPtr<T, Sig, Func>
    {
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T & t, Arguments const & argv )
        {
            return CastToJS( (t.*Func)() );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, int Arity_, typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodToInCaVoid;

    template <typename T,
              typename VT,
              typename MethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct MethodToInCaVoid<T, -1, VT (T::*)(Arguments const &), Func>
        : MethodPtr<T, VT (T::*)(Arguments const &), Func>
    {
    private:
        typedef MethodPtr<T, VT (T::*)(Arguments const &), Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T & t, Arguments const & argv )
        {
            (t.*Func)(argv);
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    template <typename T,
              typename VT,
              typename MethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct MethodToInCaVoid<T, -1, VT (Arguments const &), Func>
        : MethodToInCaVoid<T, -1, VT (T::*)(Arguments const &), Func>
    {};
    
    template <typename T, typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodToInCaVoid<T, 0,Sig,Func> : MethodPtr<T, Sig, Func>
    {
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T & t, Arguments const & argv )
        {
            (t.*Func)();
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
}

namespace Detail {
    template <typename T, int Arity_, typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func>
    struct ConstMethodToInCa;

    template <typename T,
              typename VT,
              typename ConstMethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct ConstMethodToInCa<T, -1, VT (T::*)(Arguments const &) const, Func>
        : ConstMethodPtr<T, VT (Arguments const &), Func>
    {
    private:
        typedef ConstMethodPtr<T, VT (Arguments const &), Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T const & t, Arguments const & argv )
        {
            return (t.*Func)(argv);
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T const>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    template <typename T,
              typename VT,
              typename ConstMethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct ConstMethodToInCa<T, -1, VT (Arguments const &) const, Func>
        : ConstMethodToInCa<T, -1, VT (T::*)(Arguments const &) const, Func>
    {};

    template <typename T, typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func>
    struct ConstMethodToInCa<T, 0,Sig,Func> : ConstMethodPtr<T, Sig, Func>
    {
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T const & t, Arguments const & argv )
        {
            return CastToJS( (t.*Func)() );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T const>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, int Arity_, typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func>
    struct ConstMethodToInCaVoid;

    template <typename T,
              typename VT,
              typename ConstMethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct ConstMethodToInCaVoid<T, -1, VT (T::*)(Arguments const &) const, Func>
        : ConstMethodPtr<T, VT (Arguments const &), Func>
    {
    private:
        typedef ConstMethodPtr<T, VT (T::*)(Arguments const &), Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T & t, Arguments const & argv )
        {
            (t.*Func)(argv);
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
    template <typename T,
              typename VT,
              typename ConstMethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct ConstMethodToInCaVoid<T, -1, VT (Arguments const &) const, Func>
        : ConstMethodToInCaVoid<T, -1, VT (T::*)(Arguments const &) const, Func>
    {};
    
    template <typename T, typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func>
    struct ConstMethodToInCaVoid<T, 0,Sig,Func> : ConstMethodPtr<T, Sig, Func>
    {
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
    public:
        static v8::Handle<v8::Value> Call( T & t, Arguments const & argv )
        {
            (t.*Func)();
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };


}

/**
   A template for converting free (non-member) function pointers
   to v8::InvocationCallback.

   Sig must be a function signature. Func must be a pointer to a function
   with that signature.
*/
template <typename Sig,
          typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInCa : FunctionPtr<Sig,Func>
{
private:
    /** Select the exact implementation dependent on whether
        FunctionSignature<Sig>::ReturnType is void or not.
    */
    typedef 
    typename tmp::IfElse< tmp::SameType<void ,typename FunctionSignature<Sig>::ReturnType>::Value,
                 Detail::FunctionToInCaVoid< FunctionSignature<Sig>::Arity,
                                                  Sig, Func>,
                 Detail::FunctionToInCa< FunctionSignature<Sig>::Arity,
                                              Sig, Func>
    >::Type
    ProxyType;
public:
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( argv );
#else
        try
        {
            return ProxyType::Call( argv );
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
};

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
*/
template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInCa : MethodPtr<T, Sig,Func>
{
private:
    /** Select the exact implementation dependent on whether
        MethodSignature<T,Sig>::ReturnType is void or not.
    */
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename MethodSignature<T, Sig>::ReturnType>::Value,
                 Detail::MethodToInCaVoid< T, MethodSignature<T, Sig>::Arity,
                                                typename MethodSignature<T, Sig>::FunctionType, Func>,
                 Detail::MethodToInCa< T, MethodSignature<T, Sig>::Arity,
                                            typename MethodSignature<T, Sig>::FunctionType, Func>
    >::Type
    ProxyType;
public:
    /**
       Calls self.Func(), passing it the arguments from argv. Throws a JS exception
       if argv has too few arguments.
    */
    static v8::Handle<v8::Value> Call( T & self, v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( argv );
#else
        try
        {
            return ProxyType::Call( self, argv );
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
       Tries to extract a (T*) from argv.This(). On success it calls
       Call( thatObject, argv ). On error it throws a JS-side
       exception.
    */
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( argv );
#else
        try
        {
            return ProxyType::Call( argv );
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
};

/**
   Identical to MethodToInCa, but for const member functions.
*/
template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInCa : ConstMethodPtr<T, Sig, Func>
{
private:
    /** Select the exact implementation dependent on whether
        ConstMethodSignature<T,Sig>::ReturnType is void or not.
    */
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename ConstMethodSignature<T, Sig>::ReturnType>::Value,
                 Detail::ConstMethodToInCaVoid< T, ConstMethodSignature<T, Sig>::Arity,
                                                     typename ConstMethodSignature<T, Sig>::FunctionType, Func>,
                 Detail::ConstMethodToInCa< T, ConstMethodSignature<T, Sig>::Arity,
                                                 typename ConstMethodSignature<T, Sig>::FunctionType, Func>
    >::Type
    ProxyType;
public:
    static v8::Handle<v8::Value> Call( T const & self, v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( argv );
#else
        try
        {
            return ProxyType::Call( self, argv );
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
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
#if !V8_CONVERT_CATCH_BOUND_FUNCS
        return ProxyType::Call( argv );
#else
        try
        {
            return ProxyType::Call( argv );
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
};


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



namespace Detail {
    template <int Arity_, typename Sig>
    struct ArgsToFunctionForwarder;

    // FIXME? use (RV (Arguments const &)) instead
    template <>
    struct ArgsToFunctionForwarder<-1,v8::InvocationCallback> : FunctionSignature<v8::InvocationCallback>
    {
    public:
        typedef FunctionSignature<v8::InvocationCallback> SignatureType;
        typedef v8::InvocationCallback FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            return func(argv);
        }
    };

    template <typename Sig>
    struct ArgsToFunctionForwarder<0,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef Sig FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            return CastToJS( func() );
        }
    };

    template <int Arity_, typename Sig>
    struct ArgsToFunctionForwarderVoid;

    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<0,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef Sig FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            func();
            return v8::Undefined();
        }
    };

}

namespace Detail {
    template <typename T, int Arity_, typename Sig>
    struct ArgsToMethodForwarder;

    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T,0,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, Arguments const & argv )
        {
            return CastToJS( (self.*func)() );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, int Arity_, typename Sig>
    struct ArgsToMethodForwarderVoid;

    template <typename T, typename Sig>
    struct ArgsToMethodForwarderVoid<T,0,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T & self, FunctionType func, Arguments const & argv )
        {
            (self.*func)();
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    
    template <typename T, int Arity_, typename Sig>
    struct ArgsToConstMethodForwarder;

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarder<T,0,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            return CastToJS( (self.*func)() );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, int Arity_, typename Sig>
    struct ArgsToConstMethodForwarderVoid;

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarderVoid<T,0,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        typedef T Type;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            (self.*func)();
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
template <typename Sig>
struct ArgsToFunctionForwarder
{
private:
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename FunctionSignature<Sig>::ReturnType>::Value,
                 Detail::ArgsToFunctionForwarderVoid< FunctionSignature<Sig>::Arity, Sig >,
                 Detail::ArgsToFunctionForwarder< FunctionSignature<Sig>::Arity, Sig >
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
};

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
    template <typename FSig>
    struct ForwardFunction
    {
        typedef cv::FunctionSignature<FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToFunctionForwarder<FSig> Proxy;
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return cv::CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename FSig>
    struct ForwardFunctionVoid
    {
        typedef cv::FunctionSignature<FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToFunctionForwarder<FSig> Proxy;
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

}} // namespaces

#undef JS_THROW
#undef V8_CONVERT_CATCH_BOUND_FUNCS

#endif /* CODE_GOOGLE_COM_V8_CONVERT_INVOCABLE_V8_HPP_INCLUDED */
