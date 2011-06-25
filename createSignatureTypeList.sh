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
struct Signature< RV () > : tmp::TypeList<>
{
    typedef RV ReturnType;
    enum { Arity = 0, IsConst = 0 };
    typedef void ClassType;
};
template <typename RV>
struct Signature< RV (*)() > : Signature<RV ()>
{};
template <typename RV>
struct Signature< RV () const > : Signature<RV ()>
{
    enum { IsConst = 1 };
};
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

    cat <<EOF
//! Specialization for ${i} arg(s).
template <$tparam>
struct Signature< RV (${targs}) > : tmp::TypeList<${targs}>
{
    typedef RV ReturnType;
    //typedef RV (*Signature)(${targs});
    enum { Arity = ${i}, IsConst = 0 };
    typedef void ClassType;
};

//! Specialization for ${i} arg(s).
template <$tparam>
struct Signature< RV (${targs}) const > : Signature<RV (${targs})>
{
    enum { IsConst = 1 };
};

//! Specialization for ${i} arg(s).
template <$tparam>
struct Signature< RV (*)(${targs}) > : Signature<RV (${targs})>
{};

//! Specialization for T methods taking ${i} arg(s).
template <typename T, $tparam>
struct Signature< RV (T::*)(${targs}) > : Signature<RV (${targs})>
{
    //typedef RV (T::*Signature)(${targs});
    typedef T ClassType;
};

//! Specialization for T const methods taking ${i} arg(s).
template <typename T, $tparam>
struct Signature< RV (T::*)(${targs}) const > : Signature<RV (${targs})>
{
    //typedef RV (T::*Signature)(${targs}) const;
    typedef T ClassType;
    enum { IsConst = 1 };
};
EOF
    #echo $tparam
    #echo $targs
    i=$((i + 1))
done

