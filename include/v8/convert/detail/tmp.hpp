#ifndef CODE_GOOGLE_COM_P_V8_CONVERT_TMP_HPP_INCLUDED
#define CODE_GOOGLE_COM_P_V8_CONVERT_TMP_HPP_INCLUDED

namespace v8 { namespace convert {
/**
   The tmp namespace contains code related to template metaprogramming,
   a-la Alexandrescu's Loki library or Boost MPL.

   All of it is independent of the core library.
*/
namespace tmp {


    /**
       An utmost most-basic compile-time assertion template.
       If Condition is false, an incomplete specialization of
       this type is invoced, causing a compile-time error.
    */
    template <bool Condition>
    struct Assertion
    {
        enum { Value = 1 };
    };
    /** Unimplemented - causes a compile-time error if used. */
    template <>
    struct Assertion<false>;


    /** A convenience base type for metafunctions holding a constant value. */
    template <typename ValType,ValType Val>
    struct ConstVal
    {
        enum { Value = Val };
    };
    /** A metafunction holding an integer constant. */
    template <int Val>
    struct IntVal : ConstVal<int,Val> {};
    /** A metafunction holding a bool constant. */
    template <bool Val>
    struct BoolVal : ConstVal<bool,Val> {};

    /** A metatype whos Value member is true if X and Y are the same type. */
    template <typename X,typename Y>
    struct SameType
    {
        enum { Value = 0 };
    };
    /** Specialization for X==Y. */
    template <typename X>
    struct SameType<X,X>
    {
        enum { Value = 1 };
    };


    template <typename T>
    struct IsConst
    {
        enum { Value = 0 };
    };
    template <typename T>
    struct IsConst<T const>
    {
        enum { Value = 1 };
    };
    
}}} // namespaces
#endif // CODE_GOOGLE_COM_P_V8_CONVERT_TMP_HPP_INCLUDED
