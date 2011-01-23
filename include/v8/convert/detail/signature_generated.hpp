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
struct MethodSignature< T, RV ( A0) > : SignatureBase< RV, 1 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0);
	typedef A0 ArgType0;
};
template <typename T, typename RV,  typename A0 >
struct MethodSignature< T, RV (T::*)( A0) > :
    MethodSignature< T, RV ( A0) >
{};


template <typename T, typename RV,  typename A0 >
struct ConstMethodSignature< T, RV ( A0) > : SignatureBase< RV, 1 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0) const;
	typedef A0 ArgType0;
};

template <typename T, typename RV,  typename A0 >
struct ConstMethodSignature< T, RV (T::*)( A0) const > :
    ConstMethodSignature< T, RV ( A0) >
{};

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
struct MethodSignature< T, RV ( A0,  A1) > : SignatureBase< RV, 2 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
};
template <typename T, typename RV,  typename A0,  typename A1 >
struct MethodSignature< T, RV (T::*)( A0,  A1) > :
    MethodSignature< T, RV ( A0,  A1) >
{};


template <typename T, typename RV,  typename A0,  typename A1 >
struct ConstMethodSignature< T, RV ( A0,  A1) > : SignatureBase< RV, 2 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
};

template <typename T, typename RV,  typename A0,  typename A1 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1) const > :
    ConstMethodSignature< T, RV ( A0,  A1) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2) > : SignatureBase< RV, 3 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
};
template <typename T, typename RV,  typename A0,  typename A1,  typename A2 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2) > :
    MethodSignature< T, RV ( A0,  A1,  A2) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2) > : SignatureBase< RV, 3 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3) > : SignatureBase< RV, 4 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3);
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
};
template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3) > : SignatureBase< RV, 4 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4) > : SignatureBase< RV, 5 >
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
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4) > : SignatureBase< RV, 5 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)( A0,  A1,  A2,  A3,  A4) const;
	typedef A0 ArgType0;
	typedef A1 ArgType1;
	typedef A2 ArgType2;
	typedef A3 ArgType3;
	typedef A4 ArgType4;
};

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4) >
{};

