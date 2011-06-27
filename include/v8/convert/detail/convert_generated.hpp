/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
#if !defined(DOXYGEN)
namespace Detail
{
  template <> struct CtorForwarderProxy <1 >
  {
    enum
    { Arity = 1 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,1>::Ctor() expects at least 1 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
	  typedef Signature < Sig > SigT;
	  typedef typename sl::At < 0, SigT >::Type A0;

	  typedef ArgCaster < A0 > AC0;

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    return new Type (ac0.ToNative (argv[0]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <2 >
  {
    enum
    { Arity = 2 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,2>::Ctor() expects at least 2 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
	  typedef Signature < Sig > SigT;
	  typedef typename sl::At < 0, SigT >::Type A0;
	  typedef typename sl::At < 1, SigT >::Type A1;

	  typedef ArgCaster < A0 > AC0;
	  typedef ArgCaster < A1 > AC1;

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <3 >
  {
    enum
    { Arity = 3 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,3>::Ctor() expects at least 3 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
	  typedef Signature < Sig > SigT;
	  typedef typename sl::At < 0, SigT >::Type A0;
	  typedef typename sl::At < 1, SigT >::Type A1;
	  typedef typename sl::At < 2, SigT >::Type A2;

	  typedef ArgCaster < A0 > AC0;
	  typedef ArgCaster < A1 > AC1;
	  typedef ArgCaster < A2 > AC2;

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <4 >
  {
    enum
    { Arity = 4 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,4>::Ctor() expects at least 4 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
	  typedef Signature < Sig > SigT;
	  typedef typename sl::At < 0, SigT >::Type A0;
	  typedef typename sl::At < 1, SigT >::Type A1;
	  typedef typename sl::At < 2, SigT >::Type A2;
	  typedef typename sl::At < 3, SigT >::Type A3;

	  typedef ArgCaster < A0 > AC0;
	  typedef ArgCaster < A1 > AC1;
	  typedef ArgCaster < A2 > AC2;
	  typedef ArgCaster < A3 > AC3;

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <5 >
  {
    enum
    { Arity = 5 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,5>::Ctor() expects at least 5 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <6 >
  {
    enum
    { Arity = 6 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,6>::Ctor() expects at least 6 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <7 >
  {
    enum
    { Arity = 7 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,7>::Ctor() expects at least 7 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <8 >
  {
    enum
    { Arity = 8 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,8>::Ctor() expects at least 8 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <9 >
  {
    enum
    { Arity = 9 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,9>::Ctor() expects at least 9 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <10 >
  {
    enum
    { Arity = 10 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,10>::Ctor() expects at least 10 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    AC9 /*fixme: can't be const b/c of (char const *) */ ac9;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]), ac9.ToNative (argv[9]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <11 >
  {
    enum
    { Arity = 11 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,11>::Ctor() expects at least 11 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    AC9 /*fixme: can't be const b/c of (char const *) */ ac9;
	    AC10 /*fixme: can't be const b/c of (char const *) */ ac10;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]), ac9.ToNative (argv[9]),
			     ac10.ToNative (argv[10]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <12 >
  {
    enum
    { Arity = 12 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,12>::Ctor() expects at least 12 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    AC9 /*fixme: can't be const b/c of (char const *) */ ac9;
	    AC10 /*fixme: can't be const b/c of (char const *) */ ac10;
	    AC11 /*fixme: can't be const b/c of (char const *) */ ac11;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]), ac9.ToNative (argv[9]),
			     ac10.ToNative (argv[10]),
			     ac11.ToNative (argv[11]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <13 >
  {
    enum
    { Arity = 13 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,13>::Ctor() expects at least 13 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    AC9 /*fixme: can't be const b/c of (char const *) */ ac9;
	    AC10 /*fixme: can't be const b/c of (char const *) */ ac10;
	    AC11 /*fixme: can't be const b/c of (char const *) */ ac11;
	    AC12 /*fixme: can't be const b/c of (char const *) */ ac12;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]), ac9.ToNative (argv[9]),
			     ac10.ToNative (argv[10]),
			     ac11.ToNative (argv[11]),
			     ac12.ToNative (argv[12]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <14 >
  {
    enum
    { Arity = 14 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,14>::Ctor() expects at least 14 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    AC9 /*fixme: can't be const b/c of (char const *) */ ac9;
	    AC10 /*fixme: can't be const b/c of (char const *) */ ac10;
	    AC11 /*fixme: can't be const b/c of (char const *) */ ac11;
	    AC12 /*fixme: can't be const b/c of (char const *) */ ac12;
	    AC13 /*fixme: can't be const b/c of (char const *) */ ac13;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]), ac9.ToNative (argv[9]),
			     ac10.ToNative (argv[10]),
			     ac11.ToNative (argv[11]),
			     ac12.ToNative (argv[12]),
			     ac13.ToNative (argv[13]));
	}
    }
  };
}
namespace Detail
{
  template <> struct CtorForwarderProxy <15 >
  {
    enum
    { Arity = 15 };
      template < typename Sig >
      static typename Signature <
      Sig >::ReturnType Ctor (::v8::Arguments const &argv)
    {
      if (argv.Length () < Arity)
	{
	  throw std::
	    range_error
	    ("CtorForwarder<T,15>::Ctor() expects at least 15 JS arguments!");
	}
      else
	{
	  typedef typename Signature < Sig >::ReturnType Type_;
	  typedef typename TypeInfo < Type_ >::Type Type;
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

	    AC0 /*fixme: can't be const b/c of (char const *) */ ac0;
	    AC1 /*fixme: can't be const b/c of (char const *) */ ac1;
	    AC2 /*fixme: can't be const b/c of (char const *) */ ac2;
	    AC3 /*fixme: can't be const b/c of (char const *) */ ac3;
	    AC4 /*fixme: can't be const b/c of (char const *) */ ac4;
	    AC5 /*fixme: can't be const b/c of (char const *) */ ac5;
	    AC6 /*fixme: can't be const b/c of (char const *) */ ac6;
	    AC7 /*fixme: can't be const b/c of (char const *) */ ac7;
	    AC8 /*fixme: can't be const b/c of (char const *) */ ac8;
	    AC9 /*fixme: can't be const b/c of (char const *) */ ac9;
	    AC10 /*fixme: can't be const b/c of (char const *) */ ac10;
	    AC11 /*fixme: can't be const b/c of (char const *) */ ac11;
	    AC12 /*fixme: can't be const b/c of (char const *) */ ac12;
	    AC13 /*fixme: can't be const b/c of (char const *) */ ac13;
	    AC14 /*fixme: can't be const b/c of (char const *) */ ac14;
	    return new Type (ac0.ToNative (argv[0]), ac1.ToNative (argv[1]),
			     ac2.ToNative (argv[2]), ac3.ToNative (argv[3]),
			     ac4.ToNative (argv[4]), ac5.ToNative (argv[5]),
			     ac6.ToNative (argv[6]), ac7.ToNative (argv[7]),
			     ac8.ToNative (argv[8]), ac9.ToNative (argv[9]),
			     ac10.ToNative (argv[10]),
			     ac11.ToNative (argv[11]),
			     ac12.ToNative (argv[12]),
			     ac13.ToNative (argv[13]),
			     ac14.ToNative (argv[14]));
	}
    }
  };
}
#endif // if !defined(DOXYGEN)
