#if !defined(CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED)
#define CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED 1
namespace v8 { namespace convert {
/** @file signature_core.hpp

This file houses the core-most templates related to handling
function/method signatures as full-fleged types.
*/

/**
   Base type for FunctionSignature, MethodSignature,
   and ConstMethodSignature.

   The Arity argument must specify how many arguments the function
   requires. Values less than 0 are reserved for the special case of
   passing v8::Arguments (which represent any number of arguments)
   (value=-1) or potential future use (e.g. using -2 as an end-of-list
   marker for an overload-by-arity handler).
*/
template <typename T, int Arity_>
struct SignatureBase
{
    static const int Arity = Arity_;
    typedef T ReturnType;
};

/**
   Base (unimplemented) signature for FunctionSignature
   specializations. The type passed to it must be a function
   signature.

   All implementations must define:

   @code
   static const int Arity = num_args_in_func_sig;
   typedef FunctionSig FunctionType;
   @endcode

   Examples:

   @code
   // void func_foo():
   typedef FunctionSignature< void () > NoArgsReturnsVoid;

   // int func_foo(double):
   typedef FunctionSignature< int (double) > OneArgReturnsInt;

   // double func_foo(int,int):
   typedef FunctionSignature< double (int,int) > TwoArgsReturnsDouble;
   @endcode
   
*/
template <typename FunctionSig>
struct FunctionSignature;

/**
   Base (unimplemented) signature for MethodSignature
   specializations. The Sig type passed to it must be a member method
   signature of a function from the class T.
   e.g. (void (T::*)(int))

   All implementations must define:

   @code
   typedef T Type;
   static const int Arity = num_args_in_func_sig;
   typedef Sig FunctionType;
   @endcode

   Examples: 

   @code
   // void MyType::func():
   typedef MethodSignature< MyType, void () > NoArgsReturnsVoid;

   // int MyType::func(double):
   typedef MethodSignature< MyType, int (double) > OneArgReturnsInt;

   // double MyType::func(int,int):
   typedef MethodSignature< MyType, double (int,int) > TwoArgsReturnsDouble;
   @endcode

*/
template <typename T, typename Sig>
struct MethodSignature;

/**
   Base (unimplemented) signature for ConstMethodSignature
   specializations. The Sig type passed to it must be a member
   method signature of a const function from the class T.
   e.g. (void (T::*)(int) const)

   All implementations must define:

   @code
   typedef T Type;
   static const int Arity = num_args_in_func_sig;
   typedef Sig FunctionType;
   @endcode


   Examples: 

   @code
   // void MyType::func() const:
   typedef ConstMethodSignature< MyType, void () > NoArgsReturnsVoid;

   // int MyType::func(double) const:
   typedef ConstMethodSignature< MyType, int (double) > OneArgReturnsInt;

   // double MyType::func(int,int) const:
   typedef ConstMethodSignature< MyType, double (int,int) > TwoArgsReturnsDouble;
   @endcode

*/
template <typename T, typename Sig>
struct ConstMethodSignature;

template <typename RV >
struct FunctionSignature< RV () > : SignatureBase< RV, 0 >
{
    typedef RV (*FunctionType)();
};

template <typename RV >
struct FunctionSignature< RV (*)() > : FunctionSignature< RV () >
{
};

template <typename T, typename RV >
struct MethodSignature< T, RV () > : SignatureBase< RV, 0 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)();
};
template <typename T, typename RV >
struct MethodSignature< T, RV (T::*)() > : MethodSignature<T, RV ()>
{
};


template <typename T, typename RV >
struct ConstMethodSignature< T, RV () > : SignatureBase< RV, 0 >
{
    typedef T Type;
    typedef RV (T::*FunctionType)() const;
};
template <typename T, typename RV >
struct ConstMethodSignature< T, RV (T::*)() const > : ConstMethodSignature<T, RV ()>
{
};

/**
   A "type-rich" function pointer.

   Sig must be a function signature type usable in the construct
   FunctionSignature<Sig>. FuncPtr must be a function of that type.
*/
template <typename Sig, typename FunctionSignature<Sig>::FunctionType FuncPtr>
struct FunctionPtr : FunctionSignature<Sig>
{
    /**
       This type's full "signature" type.
    */
    typedef FunctionSignature<Sig> SignatureType;
    /**
       The return type of FuncPtr.
    */
    typedef typename SignatureType::ReturnType ReturnType;
    /**
       The data type of FuncPtr.
     */
    typedef typename SignatureType::FunctionType FunctionType;
    
    /** Returns the function specifies in the template arguments.

        This really should be accessible via a const FunctionType
        member, instead of a callable function, but for certain odd
        (but necessary) template specializations i can't seem to get
        an out-of-line definition of FuncPtr to compile.
    */
    static FunctionType GetFunction()
    {
        return FuncPtr;
    }
};

/**
   Used like FunctionPtr, but in conjunction with non-const
   member functions ("methods") of the T class. See FunctionPtr
   for the requirements of the Sig type.
*/
template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType FuncPtr>
struct MethodPtr : MethodSignature<T,Sig>
{
    typedef MethodSignature<T,Sig> SignatureType;
    typedef typename SignatureType::ReturnType ReturnType;
    typedef typename SignatureType::FunctionType FunctionType;
    static const FunctionType GetFunction()
    {
        return FuncPtr;
    }
};

/**
   Used like MethodPtr, but in conjunction with const methods of the T
   class.
*/
template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType FuncPtr>
struct ConstMethodPtr : ConstMethodSignature<T,Sig>
{
    typedef ConstMethodSignature<T,Sig> SignatureType;
    typedef typename SignatureType::ReturnType ReturnType;
    typedef typename SignatureType::FunctionType FunctionType;
    static const FunctionType GetFunction()
    {
        return FuncPtr;
    }
};

namespace Detail
{
    /** Base type for SignatureArgAt specializations. */
    template <typename Signature, int Pos>
    struct SignatureArgAt_Base
    {
    private:
        typedef char AssertPosition[tmp::Assertion<(Pos>=0) && (Pos< Signature::Arity)>::Value ? 1 : -1 ];
    public:
        typedef Signature SignatureType;
        typedef typename Signature::FunctionType FunctionType;
        enum { N = Pos };
    };
}

/**
   Metatemplate to get the type of the function argument at the given
   (0-based) position. Signature must be one of FunctionSignature,
   MethodSignature, or ConstMethodSignature (or
   compatible). Specializations of this type will have the following
   members:

   @code
   typedef Signature::ArgType### Type; // ###==Pos
   typedef Signature::FunctionType FunctionType;
   (const) unsigned_numeric_type N = Pos;
   @endcode

   The ArgType### entry does not exist in the 0-arity variants of the
   classes.

   If my brain was bigger we'd use a TypeList instead of
   sequentially-numbered type names.
*/
template <typename Signature, unsigned int Pos>
struct SignatureArgAt;

#define ARGAT(N) template <typename Signature> struct SignatureArgAt<Signature,N> : \
    Detail::SignatureArgAt_Base<Signature,N> { typedef typename Signature::ArgType##N Type; }
ARGAT(0); ARGAT(1);
ARGAT(2); ARGAT(3);
ARGAT(4); ARGAT(5);
ARGAT(6); ARGAT(7);
ARGAT(8); ARGAT(9);
ARGAT(10); ARGAT(11);
#undef ARGAT

#include "signature_generated.hpp"
}} // namespaces

#endif /* CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED */
