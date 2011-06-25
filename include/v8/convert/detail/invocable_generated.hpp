/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
#if !defined(DOXYGEN)
namespace Detail {
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<1,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 1 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<1,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 1 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 1, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 1 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 1, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 1 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 1,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            return CastToJS( (self.*func)(  arg0 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            (self.*func)(  arg0 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            return CastToJS( (self.*func)(  arg0 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            (self.*func)(  arg0 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 1, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 1 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            return CastToJS( (self.*Func)(  arg0 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 1, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 1 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            (self.*Func)(  arg0 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 1, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 1 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            return CastToJS( (self.*Func)(  arg0 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 1, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 1 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		
             typedef ArgCaster<A0> AC0;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		
            (self.*Func)(  arg0 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<2,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 2 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<2,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 2 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 2, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 2 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 2, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 2 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 2,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            return CastToJS( (self.*func)(  arg0,  arg1 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            (self.*func)(  arg0,  arg1 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            return CastToJS( (self.*func)(  arg0,  arg1 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            (self.*func)(  arg0,  arg1 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 2, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 2 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 2, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 2 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            (self.*Func)(  arg0,  arg1 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 2, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 2 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 2, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 2 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		
            (self.*Func)(  arg0,  arg1 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<3,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 3 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<3,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 3 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 3, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 3 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 3, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 3 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 3,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            (self.*func)(  arg0,  arg1,  arg2 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            (self.*func)(  arg0,  arg1,  arg2 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 3, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 3 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 3, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 3 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            (self.*Func)(  arg0,  arg1,  arg2 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 3, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 3 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 3, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 3 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		
            (self.*Func)(  arg0,  arg1,  arg2 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<4,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 4 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<4,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 4 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 4, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 4 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 4, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 4 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 4,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 4, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 4 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 4, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 4 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 4, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 4 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 4, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 4 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<5,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 5 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3,  arg4 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<5,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 5 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3,  arg4 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 5, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 5 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 5, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 5 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 5,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 5, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 5 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 5, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 5 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 5, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 5 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 5, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 5 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<6,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 6 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<6,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 6 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 6, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 6 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 6, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 6 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 6,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 6, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 6 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 6, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 6 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 6, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 6 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 6, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 6 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<7,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 7 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<7,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 7 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 7, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 7 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 7, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 7 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 7,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 7, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 7 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 7, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 7 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 7, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 7 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 7, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 7 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<8,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 8 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<8,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 8 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 8, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 8 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 8, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 8 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 8,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 8, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 8 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 8, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 8 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 8, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 8 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 8, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 8 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<9,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 9 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<9,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 9 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 9, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 9 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 9, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 9 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 9,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 9, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 9 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 9, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 9 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 9, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 9 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 9, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 9 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8 );
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
    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarder<10,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 10 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            typedef typename SignatureType::ReturnType RV;
            V8Unlocker<UnlockV8> unlocker;
            RV rv( (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 ) );
            unlocker.Dispose();
            return CastToJS( rv );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct ArgsToFunctionForwarderVoid<10,Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( FunctionType func, v8::Arguments const & argv )
        {
            typedef char AssertArity[ SignatureType::Arity == 10 ? 1 : -1];
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            {
                V8Unlocker<UnlockV8> const unlocker();
                (*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 );
            }
            return v8::Undefined();
        }
    };
}
namespace Detail {
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8 >
struct FunctionToInCa< 10, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarder<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 10 arguments!");
            }
            return Proxy::Call( Func, argv );
        }
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func, bool UnlockV8>
struct FunctionToInCaVoid< 10, Sig, Func, UnlockV8 > : FunctionPtr< Sig, Func >
{
    public:
        //typedef typename ParentType::SignatureType SignatureType;
        static v8::Handle<v8::Value> Call( Arguments const & argv )
        {
            typedef FunctionPtr<Sig, Func> ParentType;
            typedef ArgsToFunctionForwarderVoid<ParentType::Arity, Sig, UnlockV8> Proxy;
            if( !argv.Length() || (argv.Length() < ParentType::Arity) )
            {
                return JS_THROW("This function requires at least 10 arguments!");
            }
            Proxy::Call( Func, argv );
            return v8::Undefined();
        }
};
} // namespace
namespace Detail {
    template <typename T, typename Sig>
    struct ArgsToMethodForwarder<T, 10,Sig> : MethodSignature<T,Sig>
    {
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 ) );
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
        typedef MethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T  & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            return CastToJS( (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 ) );
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
        typedef ConstMethodSignature<T,Sig> SignatureType;
        typedef typename SignatureType::FunctionType FunctionType;
        static v8::Handle<v8::Value> Call( T const & self, FunctionType func, Arguments const & argv )
        {
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            (self.*func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 );
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
namespace Detail {
template <typename T, typename Sig,
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCa<T, 10, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 10 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 ) );
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
typename MethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct MethodToInCaVoid< T, 10, Sig, Func, UnlockV8 > : MethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T  & self, Arguments const & argv )
        {
            typedef MethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 10 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCa<T, 10, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 10 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            return CastToJS( (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 ) );
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
typename ConstMethodSignature<T,Sig>::FunctionType Func, bool UnlockV8>
struct ConstMethodToInCaVoid< T, 10, Sig, Func, UnlockV8 > : ConstMethodPtr< T, Sig, Func >
{
    private:
        //typedef typename ParentType::SignatureType SignatureType;
    public:
        static v8::Handle<v8::Value> Call( T const & self, Arguments const & argv )
        {
            typedef ConstMethodPtr<T, Sig, Func> ParentType;
            if( argv.Length() < ParentType::Arity )
            {
                return JS_THROW("This function requires at least 10 arguments!");
            }
            typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 0>::Type A0;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 1>::Type A1;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 2>::Type A2;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 3>::Type A3;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 4>::Type A4;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 5>::Type A5;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 6>::Type A6;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 7>::Type A7;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 8>::Type A8;
		typedef typename tmp::TypeAt< SignatureTypeList<Sig>, 9>::Type A9;
		
             typedef ArgCaster<A0> AC0;
		 typedef ArgCaster<A1> AC1;
		 typedef ArgCaster<A2> AC2;
		 typedef ArgCaster<A3> AC3;
		 typedef ArgCaster<A4> AC4;
		 typedef ArgCaster<A5> AC5;
		 typedef ArgCaster<A6> AC6;
		 typedef ArgCaster<A7> AC7;
		 typedef ArgCaster<A8> AC8;
		 typedef ArgCaster<A9> AC9;
		
             AC0 ac0; A0 arg0(ac0.ToNative(argv[0]));
		 AC1 ac1; A1 arg1(ac1.ToNative(argv[1]));
		 AC2 ac2; A2 arg2(ac2.ToNative(argv[2]));
		 AC3 ac3; A3 arg3(ac3.ToNative(argv[3]));
		 AC4 ac4; A4 arg4(ac4.ToNative(argv[4]));
		 AC5 ac5; A5 arg5(ac5.ToNative(argv[5]));
		 AC6 ac6; A6 arg6(ac6.ToNative(argv[6]));
		 AC7 ac7; A7 arg7(ac7.ToNative(argv[7]));
		 AC8 ac8; A8 arg8(ac8.ToNative(argv[8]));
		 AC9 ac9; A9 arg9(ac9.ToNative(argv[9]));
		
            (self.*Func)(  arg0,  arg1,  arg2,  arg3,  arg4,  arg5,  arg6,  arg7,  arg8,  arg9 );
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
#endif // if !defined(DOXYGEN)
