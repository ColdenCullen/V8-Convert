#if !defined(CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED)
#define CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED 1
#include "tmp.hpp"
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
   static const int Arity = num_args_in_func_sig; // or enum
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
   static const int Arity = num_args_in_func_sig; // or enum
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
   static const int Arity = num_args_in_func_sig; // or enum
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
    
    /** The function specifies in the template arguments. */
    static const FunctionType Function;
};
template <typename Sig, typename FunctionSignature<Sig>::FunctionType FuncPtr>
typename FunctionPtr<Sig,FuncPtr>::FunctionType const FunctionPtr<Sig,FuncPtr>::Function = FuncPtr;

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
    static const FunctionType Function;
};
template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType FuncPtr>
typename MethodPtr<T,Sig,FuncPtr>::FunctionType const MethodPtr<T,Sig,FuncPtr>::Function = FuncPtr;

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
    static const FunctionType Function;
};
template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType FuncPtr>
typename ConstMethodPtr<T,Sig,FuncPtr>::FunctionType const ConstMethodPtr<T,Sig,FuncPtr>::Function = FuncPtr;

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
    Base (unimplemented) template for figuring out function argument types
    types at compile time. All implementations are generated code implementing
    the tmp::TypeList interface. They can be used with tmp::LengthOf,
    tmp::TypeAt, etc.
    
    Sig must be a function-signature-style parameter list.

    It is intended to be used like this:
    
    @code
    typedef SignatureTypeList< int (char const *, double) > ListType;
    assert( ListType::Arity == 2 );
    assert( tmp::LengthOf<ListType>::Value == 2  );
    assert( (tmp::SameType< char const *, tmp::TypeAt<ListType,0>::Type >::Value) );
    assert( (tmp::SameType< double, tmp::TypeAt<ListType,1>::Type >::Value) );
    @endcode
    
    Note that the length of the typelist does not include the return
    value type.
    
    Specializations have the following:
    
    - Arity enum value holding thier arity.
    - ReturnType defines the return type of the function signature.
*/
template <typename Sig> struct SignatureTypeList;

/**
    Specialization to give "InvacationCallback-like" functions
    an Arity value of less than 0.
*/
template <typename RV>
struct SignatureTypeList<RV (v8::Arguments const &)>
{
    typedef RV ReturnType;
    enum { Arity = -1 };
};

template <typename RV>
struct SignatureTypeList<RV (*)(v8::Arguments const &)> : SignatureTypeList<RV (v8::Arguments const &)>
{};

template <typename T, typename RV>
struct SignatureTypeList<RV (T::*)(v8::Arguments const &)> : SignatureTypeList<RV (v8::Arguments const &)>
{};

template <typename T, typename RV>
struct SignatureTypeList<RV (T::*)(v8::Arguments const &) const> : SignatureTypeList<RV (v8::Arguments const &)>
{};


#include "signature_generated.hpp"
}} // namespaces

#endif /* CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED */
