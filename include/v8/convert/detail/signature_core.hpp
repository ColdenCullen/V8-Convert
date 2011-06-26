#if !defined(CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED)
#define CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED 1
#include "tmp.hpp"
namespace v8 { namespace convert {
/** @file signature_core.hpp

This file houses the core-most templates related to handling
function/method signatures as full-fleged types.
*/



/**
    Base (unimplemented) template for figuring out function argument types
    types at compile time. All implementations are generated code implementing
    the tmp::TypeList interface. They can be used with tmp::LengthOf,
    tmp::TypeAt, etc.
    
    Sig must be a function-signature-style parameter list.

    Require interface: it must implement the tmp::TypeList interface and
    the entries in the TypeList must be the function argument types
    (or an empty list for nullary functions). In addition it must have:
    
    @code
    typedef functionReturnType ReturnType;
    enum { Arity = FunctionArity, IsConst = True_Only_for_Const_Methods };
    typedef T Context; // void for non-member functions, T for all T members
    @endcode
    
    Reminder: we no longer really need the Arity member (we can calculate it
    at compile-time) but lots of code uses it for legacy reasons and
    it saves a small bit if typing (keyboard typing, not C++ typing).
    
    Arity values of less than 0 are reserved for use in functions
    taking v8::Arguments (which makes them N-arity).

    It is intended to be used like this:
    
    @code
    typedef Signature< int (char const *, double) > Sig;
    assert( Sig::Arity == 2 );
    assert( sl::Length<Sig>::Value == Sig::Arity )
    assert( (tmp::SameType< char const *, sl::At<0,Sig>::Type >::Value) );
    assert( (tmp::SameType< double, sl::At<0,Sig>::Type >::Value) );
    @endcode

    The IsConst bit is mildly unsettling but i needed it to implement ToInCa
    (i couldn't figure out how to figure that out with templates).
    
    Note that the length of the typelist does not include the return
    value type.
    
    Specializations have the following:
    
    - Arity enum value holding thier arity.
    - ReturnType defines the return type of the function signature.

   Functions taking one (v8::Arguments const &) argument and returning
   any type are considered to be "InvocationCallback-like" and are treated
   specially. They have an Arity value of "less than 0", which can be used
   as a hint by binding code that the function can accept any number of
   arguments.

*/
template <typename Sig> struct Signature;


/**
    The sl namespace exclusively holds template metafunctions for working
    with Signature typelists.
*/
namespace sl {

    /**
        Metafunction whose Value member evaluates to the length of the
        given Signature.
    */
    template < typename ListT >
    struct Length : tmp::IntVal<
            tmp::IsNil<typename ListT::Head>::Value ? 0 : (1 + Length<typename ListT::Tail>::Value)
            > {};

    template <>
    struct Length<tmp::nil> : tmp::IntVal<0> {};

    /**
        Metafunction whose Type member evaluates to the type of the
        I'th argument type in the given Signature. Fails to compile
        if I is out of range.
    */
    template < unsigned short I, typename ListT >
    struct At : At<I-1, typename ListT::Tail>
    {
        typedef char AssertIndex[ (I >= Length<ListT>::Value) ? -1 : 1 ];
    };
    template < typename ListT >
    struct At<0, ListT>
    { // reminder to self: We can't subclass Identity<ListT::Head> here b/c Type could be wrong.
         typedef typename ListT::Head Type;
    };

    template <unsigned short I>
    struct At<I, tmp::nil> : tmp::Identity<tmp::nil>
    {};

    /**
        Metafunction whose Type Value member evaluates to the 0-based
        index of the first occurrance of the the type T in the
        given Signature. Evaluates to -1 if T is not contained in the
        argument list.
    */
    template < typename T, typename ListT, unsigned short Internal = 0 >
    struct Index : tmp::IntVal< tmp::SameType<T, typename ListT::Head>::Value
                            ? Internal
                            : Index<T, typename ListT::Tail, Internal+1>::Value>
    {
    };
    
    template < typename T, unsigned short Internal >
    struct Index<T,tmp::nil,Internal> : tmp::IntVal<-1> {};
    
    template < typename T, typename ListT>
    struct Contains : tmp::BoolVal< Index<T,ListT>::Value >= 0  > {};
}

template <typename RV> struct Signature< Signature<RV> > : Signature<RV> {};

/**
    Specialization to give "InvacationCallback-like" functions
    an Arity value of less than 0.
*/
template <typename RV>
struct Signature<RV (v8::Arguments const &)>
{
    typedef RV ReturnType;
    //typedef RV (Fingerprint)(v8::Arguments const &);
    enum { Arity = -1, IsConst = 0 };
    typedef void Context;
    typedef v8::Arguments const & Head;
    typedef Signature<RV ()> Tail;
};


template <typename RV>
struct Signature<RV (*)(v8::Arguments const &)> : Signature<RV (v8::Arguments const &)>
{};

template <typename T, typename RV>
struct Signature<RV (T::*)(v8::Arguments const &)> : Signature<RV (v8::Arguments const &)>
{};

template <typename T, typename RV>
struct Signature<RV (T::*)(v8::Arguments const &) const> : Signature<RV (v8::Arguments const &)>
{
    enum { IsConst = 1 };
};


/**
   Base type for FunctionSignature, MethodSignature,
   and ConstMethodSignature.

    Sig must be a function-style parameter list in the form:
    
    ReturnType (args types...)
    
    e.g.
    
    double (int, double)

    Since some refactoring on 20110624 we don't really
    need this class - we could use Signature directly.
    However, i might later want to add another class-level detail
    or two which don't belong in that interface. We'll see.
*/
template <typename Sig>
struct SignatureBase : Signature<Sig>
{
    //typedef typename Signature<Sig>::ReturnType ReturnType;
    //enum { Arity = Signature<Sig>::Arity };
    //typedef Sig Signature;
    //typedef Sig FunctionType;
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

//template <typename T, typename Sig>
//struct ConstMethodSignature<const T,Sig> : ConstMethodSignature<T,Sig> {};

template <typename RV >
struct FunctionSignature< RV () > : SignatureBase< RV () >
{
    typedef RV (*FunctionType)();
    typedef void Context;
    typedef tmp::NilType Head;
    typedef Head Tail;
};

template <typename RV >
struct FunctionSignature< RV (*)() > : FunctionSignature< RV () >
{
};

template <typename T, typename RV >
struct MethodSignature< T, RV () > : SignatureBase< RV () >
{
    typedef T Context;
    typedef tmp::NilType Head;
    typedef Head Tail;
    typedef RV (T::*FunctionType)();
};

template <typename T, typename RV >
struct MethodSignature< T, RV (T::*)() > : MethodSignature<T, RV ()>
{
};

template <typename T, typename RV >
struct ConstMethodSignature< T, RV () > : SignatureBase< RV () >
{
    typedef T Context;
    typedef tmp::NilType Head;
    typedef Head Tail;
    typedef RV (T::*FunctionType)() const;
};


template <typename T, typename RV >
struct ConstMethodSignature< T, RV (T::*)() const > : ConstMethodSignature<T, RV ()>
{
};

template <typename T, typename RV >
struct ConstMethodSignature< T, RV () const > : SignatureBase< RV () const >
{
    typedef T Context;
    typedef tmp::NilType Head;
    typedef Head Tail;
    typedef RV (T::*FunctionType)() const;
};
#if 0
template <typename T, typename RV >
struct ConstMethodSignature< T, RV (T::*)() > : ConstMethodSignature<T, RV ()>
{
};
#endif
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

#if 0
/**
    A (slightly) convenience wrappar around tmp::TypeAt.
    
    SigLisType must derive from Signature (or be API-compatible).
    I is the 0-based index for which we want the type. The type is
    available via this class' Type typedef.
    
    e.g.
    
    @code
    SignatureParamAt< FunctionSignature< void (int,double) >, 1>::Type; // is double
    @endcode
*/
template <unsigned short I, typename SigListType>
struct SignatureParamAt : sl::At<I, SigListType> {};
#endif

#include "signature_generated.hpp"
}} // namespaces

#endif /* CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED */
