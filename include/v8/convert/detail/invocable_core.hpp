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
namespace v8 { namespace convert {


/* Temporary internal macro - it is undef'd at the end of this file. */
#define JS_THROW(MSG) v8::ThrowException(v8::String::New(MSG))

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

/**
   Utility class to generate an InvocationCallback-like signature for
   a member method of class T.
*/
template <typename T>
struct InvocationCallbackMethod
{
    typedef v8::Handle<v8::Value> (T::*FunctionType)( Arguments const & );
};

/**
   Utility class to generate an InvocationCallback-like signature for
   a const member method of class T.
*/
template <typename T>
struct ConstInvocationCallbackMethod
{
    typedef v8::Handle<v8::Value> (T::*FunctionType)( Arguments const & ) const;
};

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
    struct FunctionToInvocable;
    using v8::Arguments;

    template <typename VT,
              typename FunctionSignature<VT (v8::Arguments const &)>::FunctionType Func
              >
    struct FunctionToInvocable<-1,
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
    struct FunctionToInvocable<0,Sig,Func> : FunctionPtr<Sig, Func>
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
    struct FunctionToInvocableVoid;

    template <typename VT, VT (*Func)(Arguments const &) >
    struct FunctionToInvocableVoid<-1, VT (Arguments const &), Func>
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
    struct FunctionToInvocableVoid<0,Sig,Func> : FunctionPtr<Sig, Func>
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
    struct MethodToInvocable;

    template <typename T,
              typename VT,
              typename MethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct MethodToInvocable<T, -1, VT (T::*)(Arguments const &), Func>
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
    struct MethodToInvocable<T, -1, VT (Arguments const &), Func>
        : MethodToInvocable<T, -1, VT (T::*)(Arguments const &), Func>
    {};
    
    template <typename T, typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodToInvocable<T, 0,Sig,Func> : MethodPtr<T, Sig, Func>
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
    struct MethodToInvocableVoid;

    template <typename T,
              typename VT,
              typename MethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct MethodToInvocableVoid<T, -1, VT (T::*)(Arguments const &), Func>
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
    struct MethodToInvocableVoid<T, -1, VT (Arguments const &), Func>
        : MethodToInvocableVoid<T, -1, VT (T::*)(Arguments const &), Func>
    {};
    
    template <typename T, typename Sig,
              typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodToInvocableVoid<T, 0,Sig,Func> : MethodPtr<T, Sig, Func>
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
    struct ConstMethodToInvocable;

    template <typename T,
              typename VT,
              typename ConstMethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct ConstMethodToInvocable<T, -1, VT (T::*)(Arguments const &) const, Func>
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
    struct ConstMethodToInvocable<T, -1, VT (Arguments const &) const, Func>
        : ConstMethodToInvocable<T, -1, VT (T::*)(Arguments const &) const, Func>
    {};

    template <typename T, typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func>
    struct ConstMethodToInvocable<T, 0,Sig,Func> : ConstMethodPtr<T, Sig, Func>
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
    struct ConstMethodToInvocableVoid;

    template <typename T,
              typename VT,
              typename ConstMethodSignature<T, VT (v8::Arguments const &)>::FunctionType Func
    >
    struct ConstMethodToInvocableVoid<T, -1, VT (T::*)(Arguments const &) const, Func>
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
    struct ConstMethodToInvocableVoid<T, -1, VT (Arguments const &) const, Func>
        : ConstMethodToInvocableVoid<T, -1, VT (T::*)(Arguments const &) const, Func>
    {};
    
    template <typename T, typename Sig,
              typename ConstMethodSignature<T,Sig>::FunctionType Func>
    struct ConstMethodToInvocableVoid<T, 0,Sig,Func> : ConstMethodPtr<T, Sig, Func>
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
struct FunctionToInvocable : FunctionPtr<Sig,Func>
{
private:
    /** Select the exact implementation dependent on whether
        FunctionSignature<Sig>::ReturnType is void or not.
    */
    typedef 
    typename tmp::IfElse< tmp::SameType<void ,typename FunctionSignature<Sig>::ReturnType>::Value,
                 Detail::FunctionToInvocableVoid< FunctionSignature<Sig>::Arity,
                                                  Sig, Func>,
                 Detail::FunctionToInvocable< FunctionSignature<Sig>::Arity,
                                              Sig, Func>
    >::Type
    ProxyType;
public:
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
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
    }
};

/**
   A template for converting non-const member function pointers to
   v8::InvocationCallback. For const member functions use
   ConstMethodToInvocable instead.

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
struct MethodToInvocable : MethodPtr<T, Sig,Func>
{
private:
    /** Select the exact implementation dependent on whether
        MethodSignature<T,Sig>::ReturnType is void or not.
    */
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename MethodSignature<T, Sig>::ReturnType>::Value,
                 Detail::MethodToInvocableVoid< T, MethodSignature<T, Sig>::Arity,
                                                typename MethodSignature<T, Sig>::FunctionType, Func>,
                 Detail::MethodToInvocable< T, MethodSignature<T, Sig>::Arity,
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
    }
    /**
       Tries to extract a (T*) from argv.This(). On success it calls
       Call( thatObject, argv ). On error it throws a JS-side
       exception.
    */
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
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
    }
};

/**
   Identical to MethodToInvocable, but for const member functions.
*/
template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocable : ConstMethodPtr<T, Sig, Func>
{
private:
    /** Select the exact implementation dependent on whether
        ConstMethodSignature<T,Sig>::ReturnType is void or not.
    */
    typedef typename
    tmp::IfElse< tmp::SameType<void ,typename ConstMethodSignature<T, Sig>::ReturnType>::Value,
                 Detail::ConstMethodToInvocableVoid< T, ConstMethodSignature<T, Sig>::Arity,
                                                     typename ConstMethodSignature<T, Sig>::FunctionType, Func>,
                 Detail::ConstMethodToInvocable< T, ConstMethodSignature<T, Sig>::Arity,
                                                 typename ConstMethodSignature<T, Sig>::FunctionType, Func>
    >::Type
    ProxyType;
public:
    static v8::Handle<v8::Value> Call( T const & self, v8::Arguments const & argv )
    {
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
    }
    static v8::Handle<v8::Value> Call( v8::Arguments const & argv )
    {
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
    }
};


/**
   A v8::InvocationCallback implementation which forwards the arguments from argv
   to the template-specified function. If Func returns void then the return
   value will be v8::Undefined().
*/
template <typename FSig,
          typename FunctionSignature<FSig>::FunctionType Func>
v8::Handle<v8::Value> FunctionToInvocationCallback( v8::Arguments const & argv )
{
    return FunctionToInvocable<FSig,Func>::Call(argv);
}

/**
   A v8::InvocationCallback implementation which forwards the arguments from argv
   to the template-specified member of "a" T object. This function uses
   CastFromJS<T>( argv.This() ) to fetch the native 'this' object, and will
   fail (with a JS-side exception) if that conversion fails.

   If Func returns void then the return value will be v8::Undefined().
*/
template <typename T,typename FSig,
          typename MethodSignature<T,FSig>::FunctionType Func>
v8::Handle<v8::Value> MethodToInvocationCallback( v8::Arguments const & argv )
{
    return MethodToInvocable<T,FSig,Func>::Call(argv);
}


/**
   Identical to MethodToInvocationCallback(), but is for const member functions.
*/
template <typename T,typename FSig,
          typename ConstMethodSignature<T,FSig>::FunctionType Func>
v8::Handle<v8::Value> ConstMethodToInvocationCallback( v8::Arguments const & argv )
{
    return ConstMethodToInvocable<T,FSig,Func>::Call(argv);
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
   A helper type for passing v8::Arguments lists to native functions.

   Sig must be a function-signature-like argument. e.g. <double (int,double)>,
   and the members of this class expect functions matching that signature.
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
    }

    /**
       Like the 3-arg overload, but tries to extract the (T*) object using
       CastFromJS<T>(argv.This()).
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
        typedef FunctionSignature<FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToFunctionForwarder<FSig> Proxy;
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename FSig>
    struct ForwardFunctionVoid
    {
        typedef FunctionSignature<FSig> SignatureType;
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
        typedef MethodSignature<T,FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToMethodForwarder<T,FSig> Proxy;
        static ReturnType Call( T & self, FSig func, v8::Arguments const & argv )
        {
            return CastFromJS<ReturnType>( Proxy::Call( self, func, argv ) );
        }
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename T, typename FSig>
    struct ForwardMethodVoid
    {
        typedef MethodSignature<T,FSig> SignatureType;
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
        typedef ConstMethodSignature<T,FSig> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef cv::ArgsToConstMethodForwarder<T,FSig> Proxy;
        static ReturnType Call( T const & self, FSig func, v8::Arguments const & argv )
        {
            return CastFromJS<ReturnType>( Proxy::Call( self, func, argv ) );
        }
        static ReturnType Call( FSig func, v8::Arguments const & argv )
        {
            return CastFromJS<ReturnType>( Proxy::Call( func, argv ) );
        }
    };
    template <typename T, typename FSig>
    struct ForwardConstMethodVoid
    {
        typedef ConstMethodSignature<T,FSig> SignatureType;
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
           is already RV. Not all compilers allow explicitly returning
           void values, and thus the kludge.
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
        /* the explicit cast there is a workaround for the
           RV==void case. It is a no-op for other cases,
           since the return value is already RV.
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
        /* the explicit cast there is a workaround for the
           RV==void case. It is a no-op for other cases,
           since the return value is already RV.
        */
        ;
}

    
/**
   Works like forwardMember(), but forwards to the given const
   member function and treats the given object as the 'this' pointer.

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
        /* the explicit cast there is a workaround for the
           RV==void case. It is a no-op for other cases,
           since the return value is already RV.
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

    
#include "invocable_generated.hpp"

}} // namespaces

#undef JS_THROW

#endif /* CODE_GOOGLE_COM_V8_CONVERT_INVOCABLE_V8_HPP_INCLUDED */
