/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
#if !defined(DOXYGEN)

template <typename RV>
struct SignatureTypeList< RV () > : tmp::TypeList<>
{
    typedef RV ReturnType;
    enum { Arity = 0 };
};
template <typename RV>
struct SignatureTypeList< RV (*)() > : SignatureTypeList<RV ()>
{};
//! Specialization for 1 arg(s).
template <typename RV, typename A1>
struct SignatureTypeList< RV (A1) > : tmp::TypeList<A1>
{
    typedef RV ReturnType;
    enum { Arity = 1 };
};

//! Specialization for 1 arg(s).
template <typename RV, typename A1>
struct SignatureTypeList< RV (*)(A1) > : SignatureTypeList<RV (A1)>
{};

//! Specialization for T methods taking 1 arg(s).
template <typename T, typename RV, typename A1>
struct SignatureTypeList< RV (T::*)(A1) > : SignatureTypeList<RV (A1)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 1 arg(s).
template <typename T, typename RV, typename A1>
struct SignatureTypeList< RV (T::*)(A1) const > : SignatureTypeList<RV (A1)>
{
    typedef T ClassType;
};
//! Specialization for 2 arg(s).
template <typename RV, typename A1, typename A2>
struct SignatureTypeList< RV (A1, A2) > : tmp::TypeList<A1, A2>
{
    typedef RV ReturnType;
    enum { Arity = 2 };
};

//! Specialization for 2 arg(s).
template <typename RV, typename A1, typename A2>
struct SignatureTypeList< RV (*)(A1, A2) > : SignatureTypeList<RV (A1, A2)>
{};

//! Specialization for T methods taking 2 arg(s).
template <typename T, typename RV, typename A1, typename A2>
struct SignatureTypeList< RV (T::*)(A1, A2) > : SignatureTypeList<RV (A1, A2)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 2 arg(s).
template <typename T, typename RV, typename A1, typename A2>
struct SignatureTypeList< RV (T::*)(A1, A2) const > : SignatureTypeList<RV (A1, A2)>
{
    typedef T ClassType;
};
//! Specialization for 3 arg(s).
template <typename RV, typename A1, typename A2, typename A3>
struct SignatureTypeList< RV (A1, A2, A3) > : tmp::TypeList<A1, A2, A3>
{
    typedef RV ReturnType;
    enum { Arity = 3 };
};

//! Specialization for 3 arg(s).
template <typename RV, typename A1, typename A2, typename A3>
struct SignatureTypeList< RV (*)(A1, A2, A3) > : SignatureTypeList<RV (A1, A2, A3)>
{};

//! Specialization for T methods taking 3 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3>
struct SignatureTypeList< RV (T::*)(A1, A2, A3) > : SignatureTypeList<RV (A1, A2, A3)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 3 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3>
struct SignatureTypeList< RV (T::*)(A1, A2, A3) const > : SignatureTypeList<RV (A1, A2, A3)>
{
    typedef T ClassType;
};
//! Specialization for 4 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4>
struct SignatureTypeList< RV (A1, A2, A3, A4) > : tmp::TypeList<A1, A2, A3, A4>
{
    typedef RV ReturnType;
    enum { Arity = 4 };
};

//! Specialization for 4 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4) > : SignatureTypeList<RV (A1, A2, A3, A4)>
{};

//! Specialization for T methods taking 4 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4) > : SignatureTypeList<RV (A1, A2, A3, A4)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 4 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4) const > : SignatureTypeList<RV (A1, A2, A3, A4)>
{
    typedef T ClassType;
};
//! Specialization for 5 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5>
struct SignatureTypeList< RV (A1, A2, A3, A4, A5) > : tmp::TypeList<A1, A2, A3, A4, A5>
{
    typedef RV ReturnType;
    enum { Arity = 5 };
};

//! Specialization for 5 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4, A5) > : SignatureTypeList<RV (A1, A2, A3, A4, A5)>
{};

//! Specialization for T methods taking 5 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5) > : SignatureTypeList<RV (A1, A2, A3, A4, A5)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 5 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5) const > : SignatureTypeList<RV (A1, A2, A3, A4, A5)>
{
    typedef T ClassType;
};
//! Specialization for 6 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct SignatureTypeList< RV (A1, A2, A3, A4, A5, A6) > : tmp::TypeList<A1, A2, A3, A4, A5, A6>
{
    typedef RV ReturnType;
    enum { Arity = 6 };
};

//! Specialization for 6 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4, A5, A6) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6)>
{};

//! Specialization for T methods taking 6 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 6 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6) const > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6)>
{
    typedef T ClassType;
};
//! Specialization for 7 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct SignatureTypeList< RV (A1, A2, A3, A4, A5, A6, A7) > : tmp::TypeList<A1, A2, A3, A4, A5, A6, A7>
{
    typedef RV ReturnType;
    enum { Arity = 7 };
};

//! Specialization for 7 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4, A5, A6, A7) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7)>
{};

//! Specialization for T methods taking 7 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 7 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7) const > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7)>
{
    typedef T ClassType;
};
//! Specialization for 8 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
struct SignatureTypeList< RV (A1, A2, A3, A4, A5, A6, A7, A8) > : tmp::TypeList<A1, A2, A3, A4, A5, A6, A7, A8>
{
    typedef RV ReturnType;
    enum { Arity = 8 };
};

//! Specialization for 8 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4, A5, A6, A7, A8) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8)>
{};

//! Specialization for T methods taking 8 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7, A8) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 8 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7, A8) const > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8)>
{
    typedef T ClassType;
};
//! Specialization for 9 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
struct SignatureTypeList< RV (A1, A2, A3, A4, A5, A6, A7, A8, A9) > : tmp::TypeList<A1, A2, A3, A4, A5, A6, A7, A8, A9>
{
    typedef RV ReturnType;
    enum { Arity = 9 };
};

//! Specialization for 9 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4, A5, A6, A7, A8, A9) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8, A9)>
{};

//! Specialization for T methods taking 9 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8, A9)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 9 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8, A9)>
{
    typedef T ClassType;
};
//! Specialization for 10 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
struct SignatureTypeList< RV (A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) > : tmp::TypeList<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>
{
    typedef RV ReturnType;
    enum { Arity = 10 };
};

//! Specialization for 10 arg(s).
template <typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
struct SignatureTypeList< RV (*)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)>
{};

//! Specialization for T methods taking 10 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking 10 arg(s).
template <typename T, typename RV, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
struct SignatureTypeList< RV (T::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const > : SignatureTypeList<RV (A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)>
{
    typedef T ClassType;
};
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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5) > : SignatureBase< RV, 6 >
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
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5) > : SignatureBase< RV, 6 >
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6) > : SignatureBase< RV, 7 >
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
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6) > : SignatureBase< RV, 7 >
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) > : SignatureBase< RV, 8 >
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
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) > : SignatureBase< RV, 8 >
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) > : SignatureBase< RV, 9 >
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
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) > : SignatureBase< RV, 9 >
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8) >
{};

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
struct MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) > : SignatureBase< RV, 10 >
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
struct MethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) > :
    MethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) >
{};


template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) > : SignatureBase< RV, 10 >
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

template <typename T, typename RV,  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
struct ConstMethodSignature< T, RV (T::*)( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) const > :
    ConstMethodSignature< T, RV ( A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,  A9) >
{};

#endif // if !defined(DOXYGEN)
