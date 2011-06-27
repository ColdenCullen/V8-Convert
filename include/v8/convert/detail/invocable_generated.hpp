/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
#if !defined(DOXYGEN)
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <1, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 1 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;

      typedef ArgCaster < A0 > AC0;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <1, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 1 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;

      typedef ArgCaster < A0 > AC0;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 1, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;

      typedef ArgCaster < A0 > AC0;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 1, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;

      typedef ArgCaster < A0 > AC0;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 1, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;

      typedef ArgCaster < A0 > AC0;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 1, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;

      typedef ArgCaster < A0 > AC0;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <2, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 2 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <2, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 2 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 2, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 2, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 2, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 2, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <3, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 3 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <3, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 3 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 3, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 3, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 3, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 3, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <4, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 4 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2, arg3));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <4, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 4 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 4, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 4, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 4, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 4, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <5, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 5 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2, arg3, arg4));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <5, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 5 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 5, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 5, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 5, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 5, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <6, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 6 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2, arg3, arg4, arg5));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <6, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 6 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 6, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 6, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 6, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 6, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <7, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 7 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <7, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 7 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 7, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 7, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 7, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 7, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <8, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 8 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <8, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 8 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 8, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 8, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 8, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 8, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <9, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 9 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <9, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 9 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 9, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 9, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 9, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 9, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <10, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 10 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func)
	     (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <10, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 10 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		   arg9);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 10, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 10, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 10, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 10, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <11, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 11 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func)
	     (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
	      arg10));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <11, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 11 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
		   arg10);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 11, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 11, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 11, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 11, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <12, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 12 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func)
	     (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
	      arg10, arg11));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <12, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 12 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
		   arg10, arg11);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 12, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 12, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 12, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 12, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <13, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 13 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func)
	     (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
	      arg10, arg11, arg12));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <13, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 13 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
		   arg10, arg11, arg12);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 13, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11, arg12));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 13, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11, arg12);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 13, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11, arg12));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 13, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11, arg12);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <14, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 14 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func)
	     (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
	      arg10, arg11, arg12, arg13));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <14, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 14 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
		   arg10, arg11, arg12, arg13);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 14, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11, arg12, arg13));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 14, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11, arg12, arg13);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 14, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11, arg12, arg13));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 14, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11, arg12, arg13);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarder <15, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 15 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;
      typedef typename sl::At < 14, SigT >::Type A14;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;
      typedef ArgCaster < A14 > AC14;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));
      AC14 ac14;
      A14 arg14 (ac14.ToNative (argv[14]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((*func)
	     (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
	      arg10, arg11, arg12, arg13, arg14));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
  };

  template < typename Sig, bool UnlockV8 >
    struct ArgsToFunctionForwarderVoid <15, Sig,
    UnlockV8 >:FunctionSignature < Sig >
  {
    typedef FunctionSignature < Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (FunctionType func,
					  v8::Arguments const &argv)
    {
      typedef char AssertArity[SignatureType::Arity == 15 ? 1 : -1];
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;
      typedef typename sl::At < 14, SigT >::Type A14;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;
      typedef ArgCaster < A14 > AC14;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));
      AC14 ac14;
      A14 arg14 (ac14.ToNative (argv[14]));

      {
	V8Unlocker < UnlockV8 > const unlocker ();
	  (*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
		   arg10, arg11, arg12, arg13, arg14);
      }
      return v8::Undefined ();
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarder <T, 15, Sig, UnlockV8 >:MethodSignature < T,
    Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;
      typedef typename sl::At < 14, SigT >::Type A14;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;
      typedef ArgCaster < A14 > AC14;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));
      AC14 ac14;
      A14 arg14 (ac14.ToNative (argv[14]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11, arg12, arg13, arg14));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToMethodForwarderVoid <T, 15, Sig,
    UnlockV8 >:MethodSignature < T, Sig >
  {
    typedef MethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T & self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;
      typedef typename sl::At < 14, SigT >::Type A14;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;
      typedef ArgCaster < A14 > AC14;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));
      AC14 ac14;
      A14 arg14 (ac14.ToNative (argv[14]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11, arg12, arg13, arg14);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
namespace Detail
{
  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarder <T, 15, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;
      typedef typename sl::At < 14, SigT >::Type A14;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;
      typedef ArgCaster < A14 > AC14;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));
      AC14 ac14;
      A14 arg14 (ac14.ToNative (argv[14]));

      typedef typename SignatureType::ReturnType RV;
        V8Unlocker < UnlockV8 > unlocker;
      RV rv ((self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
			   arg8, arg9, arg10, arg11, arg12, arg13, arg14));
        unlocker.Dispose ();
        return CastToJS (rv);
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
        return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };

  template < typename T, typename Sig, bool UnlockV8 >
    struct ArgsToConstMethodForwarderVoid <T, 15, Sig,
    UnlockV8 >:ConstMethodSignature < T, Sig >
  {
    typedef ConstMethodSignature < T, Sig > SignatureType;
    typedef typename SignatureType::FunctionType FunctionType;
    static v8::Handle < v8::Value > Call (T const &self, FunctionType func,
					  Arguments const &argv)
    {
      typedef Signature < Sig > SigT;
      typedef typename sl::At < 0, SigT >::Type A0;
      typedef typename sl::At < 1, SigT >::Type A1;
      typedef typename sl::At < 2, SigT >::Type A2;
      typedef typename sl::At < 3, SigT >::Type A3;
      typedef typename sl::At < 4, SigT >::Type A4;
      typedef typename sl::At < 5, SigT >::Type A5;
      typedef typename sl::At < 6, SigT >::Type A6;
      typedef typename sl::At < 7, SigT >::Type A7;
      typedef typename sl::At < 8, SigT >::Type A8;
      typedef typename sl::At < 9, SigT >::Type A9;
      typedef typename sl::At < 10, SigT >::Type A10;
      typedef typename sl::At < 11, SigT >::Type A11;
      typedef typename sl::At < 12, SigT >::Type A12;
      typedef typename sl::At < 13, SigT >::Type A13;
      typedef typename sl::At < 14, SigT >::Type A14;

      typedef ArgCaster < A0 > AC0;
      typedef ArgCaster < A1 > AC1;
      typedef ArgCaster < A2 > AC2;
      typedef ArgCaster < A3 > AC3;
      typedef ArgCaster < A4 > AC4;
      typedef ArgCaster < A5 > AC5;
      typedef ArgCaster < A6 > AC6;
      typedef ArgCaster < A7 > AC7;
      typedef ArgCaster < A8 > AC8;
      typedef ArgCaster < A9 > AC9;
      typedef ArgCaster < A10 > AC10;
      typedef ArgCaster < A11 > AC11;
      typedef ArgCaster < A12 > AC12;
      typedef ArgCaster < A13 > AC13;
      typedef ArgCaster < A14 > AC14;

      AC0 ac0;
      A0 arg0 (ac0.ToNative (argv[0]));
      AC1 ac1;
      A1 arg1 (ac1.ToNative (argv[1]));
      AC2 ac2;
      A2 arg2 (ac2.ToNative (argv[2]));
      AC3 ac3;
      A3 arg3 (ac3.ToNative (argv[3]));
      AC4 ac4;
      A4 arg4 (ac4.ToNative (argv[4]));
      AC5 ac5;
      A5 arg5 (ac5.ToNative (argv[5]));
      AC6 ac6;
      A6 arg6 (ac6.ToNative (argv[6]));
      AC7 ac7;
      A7 arg7 (ac7.ToNative (argv[7]));
      AC8 ac8;
      A8 arg8 (ac8.ToNative (argv[8]));
      AC9 ac9;
      A9 arg9 (ac9.ToNative (argv[9]));
      AC10 ac10;
      A10 arg10 (ac10.ToNative (argv[10]));
      AC11 ac11;
      A11 arg11 (ac11.ToNative (argv[11]));
      AC12 ac12;
      A12 arg12 (ac12.ToNative (argv[12]));
      AC13 ac13;
      A13 arg13 (ac13.ToNative (argv[13]));
      AC14 ac14;
      A14 arg14 (ac14.ToNative (argv[14]));

      {
	V8Unlocker < UnlockV8 > unlocker ();
	(self.*func) (arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
		      arg9, arg10, arg11, arg12, arg13, arg14);
      }
      return v8::Undefined ();
    }
    static v8::Handle < v8::Value > Call (FunctionType func,
					  Arguments const &argv)
    {
      T const *self = CastFromJS < T > (argv.This ());
      return self
	? Call (*self, func, argv)
	: Toss ("CastFromJS<T>() returned NULL! Cannot find 'this' pointer!");
    }
  };
}
#endif // if !defined(DOXYGEN)
