#if !defined(CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED)
#define CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED 1
namespace v8 { namespace convert {
/** @file signature_core.hpp

This file houses the core-most templates related to
handling function/method signatures as.
*/

/**
   Base type for FunctionSignature, MethodSignature,
   and ConstMethodSignature.

   The Arity argument must specify how many arguments
   the function requires. Values less than 0 are reserved
   for the special case of passing v8::Arguments (which represent
   any number of arguments).
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

*/
template <typename T, typename F>
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
   member functions ("methods") of the T class.
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

#include "signature_generated.hpp"
}} // namespaces

#endif /* CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED */
