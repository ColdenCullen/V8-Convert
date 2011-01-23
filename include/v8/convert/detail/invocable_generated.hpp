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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5), 6 > : SignatureBase< RV, 6 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3,  A4,  A5), 6 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5), 6 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 6, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 6 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 6, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 6 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 6, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 6 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) ) );
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
struct MethodToInvocableVoid< T, 6, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 6 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) );
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
struct ConstMethodToInvocable<T, 6, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 6 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) ) );
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
struct ConstMethodToInvocableVoid< T, 6, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 6 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) );
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
    struct ArgsToFunctionForwarder<6,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<6,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 6,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) ) );
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
    struct ArgsToMethodForwarderVoid<T, 6,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) );
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
    struct ArgsToConstMethodForwarder<T, 6,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) ) );
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
    struct ArgsToConstMethodForwarderVoid<T, 6,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6), 7 > : SignatureBase< RV, 7 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6), 7 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6), 7 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 7, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 7 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 7, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 7 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 7, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 7 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) ) );
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
struct MethodToInvocableVoid< T, 7, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 7 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) );
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
struct ConstMethodToInvocable<T, 7, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 7 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) ) );
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
struct ConstMethodToInvocableVoid< T, 7, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 7 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) );
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
    struct ArgsToFunctionForwarder<7,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<7,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 7,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) ) );
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
    struct ArgsToMethodForwarderVoid<T, 7,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) );
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
    struct ArgsToConstMethodForwarder<T, 7,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) ) );
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
    struct ArgsToConstMethodForwarderVoid<T, 7,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7), 8 > : SignatureBase< RV, 8 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
	typedef A7 ArgType7;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7), 8 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7), 8 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 8, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 8 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 8, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 8 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 8, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 8 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) ) );
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
struct MethodToInvocableVoid< T, 8, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 8 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) );
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
struct ConstMethodToInvocable<T, 8, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 8 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) ) );
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
struct ConstMethodToInvocableVoid< T, 8, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 8 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) );
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
    struct ArgsToFunctionForwarder<8,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<8,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 8,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) ) );
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
    struct ArgsToMethodForwarderVoid<T, 8,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) );
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
    struct ArgsToConstMethodForwarder<T, 8,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) ) );
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
    struct ArgsToConstMethodForwarderVoid<T, 8,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8), 9 > : SignatureBase< RV, 9 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
	typedef A7 ArgType7;
	typedef A8 ArgType8;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8), 9 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8), 9 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 9, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 9 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 9, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 9 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 9, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 9 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) ) );
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
struct MethodToInvocableVoid< T, 9, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 9 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) );
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
struct ConstMethodToInvocable<T, 9, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 9 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) ) );
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
struct ConstMethodToInvocableVoid< T, 9, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 9 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) );
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
    struct ArgsToFunctionForwarder<9,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<9,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 9,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) ) );
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
    struct ArgsToMethodForwarderVoid<T, 9,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) );
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
    struct ArgsToConstMethodForwarder<T, 9,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) ) );
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
    struct ArgsToConstMethodForwarderVoid<T, 9,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) );
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
template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9), 10 > : SignatureBase< RV, 10 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
	typedef A7 ArgType7;
	typedef A8 ArgType8;
	typedef A9 ArgType9;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct SignatureBase< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9), 10 >
  : SignatureBase< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9), 10 >
{};

namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func >
struct FunctionToInvocable< 10, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 10 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            return CastToJS( Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) ) );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
struct FunctionToInvocableVoid< 10, Sig, Func > : FunctionPtr< Sig, Func >
{
    private:
        typedef FunctionPtr<Sig, Func> ParentType;
    public:
        typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 10 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            Func( ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]));
            return Undefined();
        }
};
} // namespace
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func>
struct MethodToInvocable<T, 10, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 10 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) ) );
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
struct MethodToInvocableVoid< T, 10, Sig, Func > : MethodPtr< T, Sig, Func >
{
    private:
        typedef MethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 10 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) );
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
struct ConstMethodToInvocable<T, 10, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 10 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            return CastToJS( (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) ) );
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
struct ConstMethodToInvocableVoid< T, 10, Sig, Func > : ConstMethodPtr< T, Sig, Func >
{
    private:
        typedef ConstMethodPtr<T, Sig, Func> ParentType;
        typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires exactly 10 arguments!");
            }
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            (self.*Func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) );
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
    struct ArgsToFunctionForwarder<10,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            return CastToJS( (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) ) );
        }
    };
    template <typename Sig>
    struct ArgsToFunctionForwarderVoid<10,Sig> : FunctionSignature<Sig>
    {
    public:
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            (*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) );
            return v8::Undefined();
        }
    };
}
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 10,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) ) );
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
    struct ArgsToMethodForwarderVoid<T, 10,Sig> : MethodSignature<T,Sig>
    {
    public:
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) );
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
    struct ArgsToConstMethodForwarder<T, 10,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            return CastToJS( (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) ) );
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
    struct ArgsToConstMethodForwarderVoid<T, 10,Sig> : ConstMethodSignature<T,Sig>
    {
    public:
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename SignatureType::ArgType0 A0;typedef typename SignatureType::ArgType1 A1;typedef typename SignatureType::ArgType2 A2;typedef typename SignatureType::ArgType3 A3;typedef typename SignatureType::ArgType4 A4;typedef typename SignatureType::ArgType5 A5;typedef typename SignatureType::ArgType6 A6;typedef typename SignatureType::ArgType7 A7;typedef typename SignatureType::ArgType8 A8;typedef typename SignatureType::ArgType9 A9;
             typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;
             AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
            (self.*func)(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) );
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
