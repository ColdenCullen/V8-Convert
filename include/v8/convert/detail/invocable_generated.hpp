/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
template <typename RV,  typename A0 >
struct SignatureBase< RV ( A0), 1 > : SignatureBase< RV, 1 >
{
    typedef RV (*FunctionType)( A0);
	typedef A0 ArgType0;
};

template <typename RV,  typename A0 >
struct SignatureBase< RV (*)( A0), 1 >
  : SignatureBase< RV ( A0), 1 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 1, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 1 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            return CastToJS( Func( ac0.ToNative(argv[0]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 1, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 1 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            Func( ac0.ToNative(argv[0]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 1, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 1 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocableVoid< T, 1, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 1 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            (self.*Func)(  ac0.ToNative(argv[0]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocable<T, 1, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 1 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocableVoid< T, 1, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 1 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            (self.*Func)(  ac0.ToNative(argv[0]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
    template <typename Sig>
    struct ArgsToFunctionForwarder<1,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<1,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            (*func)(  ac0.ToNative(argv[0]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 1,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToMethodForwarderVoid<T, 1,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            (self.*func)(  ac0.ToNative(argv[0]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarder<T, 1,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarderVoid<T, 1,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;
             typedef ArgCaster<A0> AC0;
             AC0 ac0;
            (self.*func)(  ac0.ToNative(argv[0]) );
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
template <typename RV,  typename A0,  typename A1 >
struct SignatureBase< RV ( A0,  A1), 2 > : SignatureBase< RV, 2 >
{
    typedef RV (*FunctionType)( A0,  A1);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
};

template <typename RV,  typename A0,  typename A1 >
struct SignatureBase< RV (*)( A0,  A1), 2 >
  : SignatureBase< RV ( A0,  A1), 2 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 2, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 2 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 2, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 2 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 2, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 2 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocableVoid< T, 2, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 2 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocable<T, 2, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 2 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocableVoid< T, 2, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 2 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
    template <typename Sig>
    struct ArgsToFunctionForwarder<2,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<2,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 2,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToMethodForwarderVoid<T, 2,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarder<T, 2,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarderVoid<T, 2,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;
             AC0 ac0; AC1 ac1;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2 >
struct SignatureBase< RV ( A0,  A1,  A2), 3 > : SignatureBase< RV, 3 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
};

template <typename RV,  typename A0,  typename A1,  typename A2 >
struct SignatureBase< RV (*)( A0,  A1,  A2), 3 >
  : SignatureBase< RV ( A0,  A1,  A2), 3 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 3, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 3 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 3, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 3 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 3, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 3 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocableVoid< T, 3, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 3 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocable<T, 3, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 3 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocableVoid< T, 3, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 3 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
    template <typename Sig>
    struct ArgsToFunctionForwarder<3,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<3,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 3,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToMethodForwarderVoid<T, 3,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarder<T, 3,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarderVoid<T, 3,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;
             AC0 ac0; AC1 ac1; AC2 ac2;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3), 4 > : SignatureBase< RV, 4 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3), 4 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3), 4 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 4, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 4 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 4, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 4 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 4, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 4 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocableVoid< T, 4, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 4 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocable<T, 4, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 4 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocableVoid< T, 4, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 4 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
    template <typename Sig>
    struct ArgsToFunctionForwarder<4,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<4,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 4,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToMethodForwarderVoid<T, 4,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarder<T, 4,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarderVoid<T, 4,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3,  A4), 5 > : SignatureBase< RV, 5 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3,  A4), 5 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3,  A4), 5 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 5, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 5 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 5, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 5 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 5, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 5 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocableVoid< T, 5, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 5 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocable<T, 5, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 5 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) ) );
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
template <typename T, typename Sig,
typename ConstMethodSignature<T,Sig>::FunctionType Func>
struct ConstMethodToInvocableVoid< T, 5, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 5 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
};
} // namespace
namespace Detail {
    template <typename Sig>
    struct ArgsToFunctionForwarder<5,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<5,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 5,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToMethodForwarderVoid<T, 5,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) );
            return v8::Undefined();
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T  * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarder<T, 5,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) ) );
        }
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            T const * self = CastFromJS<T>(argv.This());
            return self
                ? Call(*self, func, argv)
                : JS_THROW("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
        }
    };

    template <typename T, typename Sig>
    struct ArgsToConstMethodForwarderVoid<T, 5,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) );
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
