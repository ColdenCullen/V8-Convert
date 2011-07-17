#!/bin/bash
########################################################################
# A quick hack to generate Signature templates.

from=${1-0}
to=$2

if [[ 'x' = "x${to}" ]]; then
    to=$from
    from=0
fi

tparam='typename RV'
targs=''

if [[ 0 = $from ]]; then
#template <typename Sig> struct Signature;

cat <<EOF

template <typename RV>
struct Signature< RV () >
{
    typedef RV ReturnType;
    enum { IsConst = 0 };
    typedef void Context;
    typedef RV (*FunctionType)();
    typedef tmp::NilType Head;
    typedef Head Tail;
};
template <typename RV>
struct Signature< RV (*)() > : Signature<RV ()>
{};

template <typename T, typename RV>
struct Signature< RV (T::*)() > : Signature<RV ()>
{
    typedef T Context;
    typedef RV (T::*FunctionType)();
};

#if defined(V8_CONVERT_ENABLE_CONST_OVERLOADS) && V8_CONVERT_ENABLE_CONST_OVERLOADS

template <typename RV>
struct Signature< RV () const > : Signature<RV ()>
{
    enum { IsConst = 1 };
};
template <typename T, typename RV>
struct Signature< RV (T::*)() const > : Signature<RV () const>
{
    typedef T Context;
    typedef RV (T::*FunctionType)() const;
};

#endif /* V8_CONVERT_ENABLE_CONST_OVERLOADS */
EOF
from=$((from + 1))
fi
i=$from
while [[ $i -le $to ]]; do
    tparam="${tparam}, typename A${i}"
    if [[ "X" != "X${targs}" ]]; then
        targs="${targs}, A${i}"
    else
        targs="A1"
    fi

    head="${targs%%,*}"
    tail="${targs#*,}"
    if [[ "$tail" = "$head" ]]; then # happens on 1-arity form
        #if [[ $i -eq 0 ]]; then
            tail="tmp::NilType"
        #else
        #    tail="Signature< RV () >"
        #fi
    else
        tail="Signature<RV (${tail})>"
    fi
    
    cat <<EOF
//! Specialization for ${i} arg(s).
template <$tparam>
struct Signature< RV (${targs}) >
{
    typedef RV ReturnType;
    static const bool IsConst = false;
    typedef void Context;
    typedef RV (*FunctionType)(${targs});
    typedef ${head} Head;
    typedef ${tail} Tail;
};

//! Specialization for ${i} arg(s).
template <$tparam>
struct Signature< RV (*)(${targs}) > : Signature<RV (${targs})>
{};

//! Specialization for T non-const methods taking ${i} arg(s).
template <typename T, $tparam>
struct Signature< RV (T::*)(${targs}) > : Signature<RV (${targs})>
{
    typedef T Context;
    typedef RV (T::*FunctionType)(${targs});
};

#if defined(V8_CONVERT_ENABLE_CONST_OVERLOADS) && V8_CONVERT_ENABLE_CONST_OVERLOADS
//! Specialization for ${i} arg(s).
template <$tparam>
struct Signature< RV (${targs}) const > : Signature<RV (${targs})>
{
    static const bool IsConst = true;
};

//! Specialization for T const methods taking ${i} arg(s).
template <typename T, $tparam>
struct Signature< RV (T::*)(${targs}) const > : Signature<RV (${targs}) const>
{
    typedef T Context;
    typedef RV (T::*FunctionType)(${targs}) const;
};
#endif /*V8_CONVERT_ENABLE_CONST_OVERLOADS*/
EOF
    #echo $tparam
    #echo $targs
    i=$((i + 1))
done

