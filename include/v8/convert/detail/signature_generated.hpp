/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
template <typename RV,  typename A0 >
struct FunctionSignature< RV ( A0) > : SignatureBase< RV, 1 >
{
    typedef RV (*FunctionType)( A0);
	typedef A0 ArgType0;
};

template <typename RV,  typename A0 >
struct FunctionSignature< RV (*)( A0) >
  : FunctionSignature< RV ( A0) >
{};


template <typename T, typename RV,  typename A0 >
struct MethodSignature< T, RV (T::*)( A0) > : SignatureBase< RV, 1 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0);
	typedef A0 ArgType0;
};

template <typename T, typename RV,  typename A0 >
struct ConstMethodSignature< T, RV (T::*)( A0) const > : SignatureBase< RV, 1 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0) const;
	typedef A0 ArgType0;
};

template <typename RV,  typename A0,  typename A1 >
struct FunctionSignature< RV ( A0,  A1) > : SignatureBase< RV, 2 >
{
    typedef RV (*FunctionType)( A0,  A1);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
};

template <typename RV,  typename A0,  typename A1 >
struct FunctionSignature< RV (*)( A0,  A1) >
  : FunctionSignature< RV ( A0,  A1) >
{};


template <typename T, typename RV,  typename A0,  typename A1 >
struct MethodSignature< T, RV (T::*)( A0,  A1) > : SignatureBase< RV, 2 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
};

template <typename T, typename RV,  typename A0,  typename A1 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1) const > : SignatureBase< RV, 2 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
};

template <typename RV,  typename A0,  typename A1,  typename A2 >
struct FunctionSignature< RV ( A0,  A1,  A2) > : SignatureBase< RV, 3 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
};

template <typename RV,  typename A0,  typename A1,  typename A2 >
struct FunctionSignature< RV (*)( A0,  A1,  A2) >
  : FunctionSignature< RV ( A0,  A1,  A2) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2) > : SignatureBase< RV, 3 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2) const > : SignatureBase< RV, 3 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3) > : SignatureBase< RV, 4 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3) > : SignatureBase< RV, 4 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3) const > : SignatureBase< RV, 4 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4) > : SignatureBase< RV, 5 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4) > : SignatureBase< RV, 5 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4) const > : SignatureBase< RV, 5 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5) > : SignatureBase< RV, 6 >
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
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5) > : SignatureBase< RV, 6 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5) const > : SignatureBase< RV, 6 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6) > : SignatureBase< RV, 7 >
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
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6) > : SignatureBase< RV, 7 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6) const > : SignatureBase< RV, 7 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) > : SignatureBase< RV, 8 >
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
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) > : SignatureBase< RV, 8 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
	typedef A7 ArgType7;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) const > : SignatureBase< RV, 8 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
	typedef A5 ArgType5;
	typedef A6 ArgType6;
	typedef A7 ArgType7;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) > : SignatureBase< RV, 9 >
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
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) > : SignatureBase< RV, 9 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8);
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) const > : SignatureBase< RV, 9 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) const;
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

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) > : SignatureBase< RV, 10 >
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
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) > : SignatureBase< RV, 10 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9);
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) const > : SignatureBase< RV, 10 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) const;
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

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10) > : SignatureBase< RV, 11 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10);
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
	typedef A10 ArgType10;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10 >
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10) > : SignatureBase< RV, 11 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10);
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
	typedef A10 ArgType10;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10) const > : SignatureBase< RV, 11 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10) const;
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
	typedef A10 ArgType10;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11) > : SignatureBase< RV, 12 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11);
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
	typedef A10 ArgType10;
	typedef A11 ArgType11;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11 >
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11) > : SignatureBase< RV, 12 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11);
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
	typedef A10 ArgType10;
	typedef A11 ArgType11;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11) const > : SignatureBase< RV, 12 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11) const;
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
	typedef A10 ArgType10;
	typedef A11 ArgType11;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11,  typename A12 >
struct FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12) > : SignatureBase< RV, 13 >
{
    typedef RV (*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12);
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
	typedef A10 ArgType10;
	typedef A11 ArgType11;
	typedef A12 ArgType12;
};

template <typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11,  typename A12 >
struct FunctionSignature< RV (*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12) >
  : FunctionSignature< RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11,  typename A12 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12) > : SignatureBase< RV, 13 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12);
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
	typedef A10 ArgType10;
	typedef A11 ArgType11;
	typedef A12 ArgType12;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9,  typename A10,  typename A11,  typename A12 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12) const > : SignatureBase< RV, 13 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9,  A10,  A11,  A12) const;
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
	typedef A10 ArgType10;
	typedef A11 ArgType11;
	typedef A12 ArgType12;
};

