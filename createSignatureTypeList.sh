#!/bin/bash
########################################################################
# A quick hack to generate SignatureTypeList templates.

from=${1-0}
to=$2

if [[ 'x' = "x${to}" ]]; then
    to=$from
    from=0
fi

tparam='typename RV'
targs=''

if [[ 0 = $from ]]; then
#template <typename Sig> struct SignatureTypeList;

cat <<EOF

template <typename RV>
struct SignatureTypeList< RV () > : tmp::TypeList<>
{
    typedef RV ReturnType;
    enum { Arity = 0 };
};
template <typename RV>
struct SignatureTypeList< RV (*)() > : SignatureTypeList<RV ()>
{};
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
struct SignatureTypeList< RV (${targs}) > : tmp::TypeList<${targs}>
{
    typedef RV ReturnType;
    enum { Arity = ${i} };
};

//! Specialization for ${i} arg(s).
template <$tparam>
struct SignatureTypeList< RV (*)(${targs}) > : SignatureTypeList<RV (${targs})>
{};

//! Specialization for T methods taking ${i} arg(s).
template <typename T, $tparam>
struct SignatureTypeList< RV (T::*)(${targs}) > : SignatureTypeList<RV (${targs})>
{
    typedef T ClassType;
};

//! Specialization for T const methods taking ${i} arg(s).
template <typename T, $tparam>
struct SignatureTypeList< RV (T::*)(${targs}) const > : SignatureTypeList<RV (${targs})>
{
    typedef T ClassType;
};
EOF
    #echo $tparam
    #echo $targs
    i=$((i + 1))
done

