#!/bin/bash
########################################################################
# Generates code for the the # v8::convert API (and friends).
count=${1-0}

test "$count" -gt 0 || {
    echo "Usage: $0 NUMBER (>=1) COMMAND(s)"
cat <<EOF
Commands:
  FunctionSignature
  MethodSignature
  ConstMethodSignature
  MethodForwarder
  FunctionForwarder
EOF
    echo "Generates specializations for operations taking exactly NUMBER arguments."
    exit 1
}
shift

ValHnd="v8::Handle<v8::Value>"
aTDecl="" # typename A0, typename A1,...
aTParam="" # A0, A1 ...
castCalls="" # CastFromJS<A0>(argv[0]), ...
castTypedefs="" # typedef ArgCaster<A#> AC#, ...
castInits="" # AC# ac#; ...
callArgs="" # a0, ... aN
sigTypeDecls="" # SignatureType::ArgType# A#...
at=0

########################################################
# must be called first to populate the shared vars
function makeLists()
{
    for (( at = 0; at < count; at = at + 1)); do
    #echo "at=$at"
	local AT="A${at}"
	aTDecl="${aTDecl} typename ${AT}"
	aTParam="${aTParam} ${AT}"
	callArgs="${callArgs}${AT}"
        #sigTypeDecls="${sigTypeDecls}typedef typename SignatureType::ArgType${at} ${AT};"
        sigTypeDecls="${sigTypeDecls}typedef typename sl::At< ${at}, Signature<Sig> >::Type ${AT};\n"
	#castCalls="${castCalls} CastFromJS< ${AT} >(argv[${at}])"
        castTypedefs="${castTypedefs} typedef ArgCaster<${AT}> AC${at};\n"
        #castInits="${castInits} AC${at} ac${at};"
        #castCalls="${castCalls} ac${at}.ToNative(argv[${at}])"
        castInits="${castInits} AC${at} ac${at}; A${at} arg${at}(ac${at}.ToNative(argv[${at}]));\n"
        castCalls="${castCalls} arg${at}"
	test $at -ne $((count-1)) && {
	    aTDecl="${aTDecl}, "
	    aTParam="${aTParam}, "
	    castCalls="${castCalls}, "
        callArgs="${callArgs}, "
	}
    done
    #tmplsig="${tmplsig} RV (WrappedType::*Func)(${aTParam})";
    castOps="${castTypedefs} ${castInits}"
}

function mycat()
{
    perl -pe 's|\\n|\n\t\t|g'
}

#######################################################
# Creates CtorForwarder specializations.
function makeCtorForwarder()
{

    local err_too_few_args="CtorForwarder<T,${count}>::Ctor() expects at least ${count} JS arguments!"
    local err_exception="CtorForwarder<T,${count}>::Ctor() Native ctor threw an unknown native exception type!"

    mycat <<EOF
namespace Detail {
template <>
struct CtorForwarderProxy<${count}> // todo: subclass Signature<Sig>
{
    enum { Arity = ${count} };
    template <typename Sig>
    static typename Signature<Sig>::ReturnType Call( v8::Arguments const & argv )
    {
        if( argv.Length() < Arity )
        {
            throw std::range_error("${err_too_few_args}");
        }
        else
        {
            typedef typename Signature<Sig>::ReturnType Type_;
            typedef typename TypeInfo<Type_>::Type Type;
            ${sigTypeDecls}
            ${castTypedefs}
            ${castInits}
            return new Type( ${castCalls} );
        }
    }
};
}
EOF

} # makeCtorForwarder


########################################################################
# Create FunctionSignature<> and friends...
function makeFunctionSignature()
{
    return # this code is no longer needed
    mycat <<EOF
template <typename RV, ${aTDecl} >
struct FunctionSignature< RV (${aTParam}) > : SignatureBase< RV (${aTParam}) >
{
};

template <typename RV, ${aTDecl} >
struct FunctionSignature< RV (*)(${aTParam}) >
  : FunctionSignature< RV (${aTParam}) >
{};

EOF
}

########################################################################
# Create MethodSignature<> and friends...
function makeMethodSignature()
{
    #return
    mycat <<EOF
template <typename T, typename RV, ${aTDecl} >
struct MethodSignature< T, RV (${aTParam}) > : Signature< RV (T::*)(${aTParam}) >
{
};
template <typename T, typename RV, ${aTDecl} >
struct MethodSignature< T, RV (*)(${aTParam}) > : MethodSignature< T, RV (${aTParam}) >
{
};

template <typename T, typename RV, ${aTDecl} >
struct MethodSignature< T, RV (T::*)(${aTParam}) > :
    MethodSignature< T, RV (${aTParam}) >
{};

#if defined(V8_CONVERT_ENABLE_CONST_OVERLOADS) && V8_CONVERT_ENABLE_CONST_OVERLOADS
template <typename T, typename RV, ${aTDecl} >
struct MethodSignature< T, RV (${aTParam}) const > : Signature< RV (T::*)(${aTParam}) const >
{
    enum { IsConst = 1 };
};
template <typename T, typename RV, ${aTDecl} >
struct MethodSignature< T, RV (T::*)(${aTParam}) const > :
    MethodSignature< T, RV (${aTParam}) const >
{};
#endif /*V8_CONVERT_ENABLE_CONST_OVERLOADS*/

EOF
}

########################################################################
# Create ConstMethodSignature<> and friends...
# TODO: move this into makeMethodSignature.
function makeConstMethodSignature()
{
# reminder: role of const overloading is reversed for ConstMethodSignature.
    mycat <<EOF
template <typename T, typename RV, ${aTDecl} >
struct ConstMethodSignature< T, RV (${aTParam}) const > :
#if defined(V8_CONVERT_ENABLE_CONST_OVERLOADS) && V8_CONVERT_ENABLE_CONST_OVERLOADS
    Signature< RV (T::*)(${aTParam}) const > {};
#else
    Signature< RV (T::*)(${aTParam}) >
{
    //enum { IsConst = 1 };
    static const bool IsConst = true;
    typedef RV (T::*FunctionType)(${aTParam}) const;
};
#endif

#if defined(V8_CONVERT_ENABLE_CONST_OVERLOADS) && V8_CONVERT_ENABLE_CONST_OVERLOADS
template <typename T, typename RV, ${aTDecl} >
struct ConstMethodSignature< T, RV (${aTParam}) > : ConstMethodSignature< T, RV (${aTParam}) const >
{
};
#endif

template <typename T, typename RV, ${aTDecl} >
struct ConstMethodSignature< T, RV (T::*)(${aTParam}) const > :
    ConstMethodSignature< T, RV (${aTParam}) const >
{};

EOF

}


########################################################################
# Generates FunctionForwarder<>
function makeFunctionForwarder()
{

mycat <<EOF
namespace Detail {
    template <typename Sig, bool UnlockV8>
    struct FunctionForwarder<${count},Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef char AssertArity[ (${count} == sl::Arity<SignatureType>::Value) ? 1 : -1];
        typedef typename SignatureType::FunctionType FunctionType;
        typedef typename SignatureType::ReturnType ReturnType;
        static ReturnType CallNative( FunctionType func, v8::Arguments const & argv )
        {
            ${sigTypeDecls}
            ${castTypedefs}
            ${castInits}
            V8Unlocker<UnlockV8> const unlocker();
            return (ReturnType)(*func)( ${castCalls} );
        }
        static ${ValHnd} Call( FunctionType func, v8::Arguments const & argv )
        {
            return CastToJS( CallNative( func, argv ) );
        }
    };

    template <typename Sig, bool UnlockV8>
    struct FunctionForwarderVoid<${count},Sig,UnlockV8> : FunctionSignature<Sig>
    {
        typedef FunctionSignature<Sig> SignatureType;
        typedef char AssertArity[ (${count} == sl::Arity<SignatureType>::Value) ? 1 : -1];
        typedef typename SignatureType::FunctionType FunctionType;
        typedef typename SignatureType::ReturnType ReturnType;
        static ReturnType CallNative( FunctionType func, v8::Arguments const & argv )
        {
            ${sigTypeDecls}
            ${castTypedefs}
            ${castInits}
            V8Unlocker<UnlockV8> const unlocker();
            return (ReturnType)(*func)( ${castCalls} );
        }
        static ${ValHnd} Call( FunctionType func, v8::Arguments const & argv )
        {
            CallNative( func, argv );
            return v8::Undefined();
        }
    };
}
EOF

}

########################################################################
# Generates MethodForwarder<>
function makeMethodForwarder_impl()
{
    local class=MethodForwarder
    local parent=MethodSignature
    local constness=""
    if [[ "x$1" = "xconst" ]]; then
        parent=ConstMethodSignature
        class=ConstMethodForwarder
        constness="const"
    fi
mycat <<EOF
namespace Detail {
    template <typename T, typename Sig, bool UnlockV8>
    struct ${class}<T, ${count},Sig, UnlockV8> : ${parent}<T,Sig>
    {
        typedef ${parent}<T,Sig> SignatureType;
        typedef char AssertArity[ (${count} == sl::Arity<SignatureType>::Value) ? 1 : -1];
        typedef typename SignatureType::FunctionType FunctionType;
        typedef typename SignatureType::ReturnType ReturnType;
        static ReturnType CallNative( T ${constness} & self, FunctionType func, v8::Arguments const & argv )
        {
            ${sigTypeDecls}
            ${castTypedefs}
            ${castInits}
            V8Unlocker<UnlockV8> const unlocker();
            return (ReturnType)(self.*func)( ${castCalls} );
        }
        static ${ValHnd} Call( T ${constness} & self, FunctionType func, v8::Arguments const & argv )
        {
            try { return CastToJS( CallNative( self, func, argv ) ); }
            HANDLE_PROPAGATE_EXCEPTION;
        }
        static ReturnType CallNative( FunctionType func, v8::Arguments const & argv )
        {
            T ${constness} * self = CastFromJS<T>(argv.This());
            if( ! self ) throw MissingThisExceptionT<T>();
            return (ReturnType)CallNative(*self, func, argv);
        }
        static ${ValHnd} Call( FunctionType func, v8::Arguments const & argv )
        {
            try { return CastToJS( CallNative(func, argv) ); }
            HANDLE_PROPAGATE_EXCEPTION;
        }
    };

    template <typename T, typename Sig, bool UnlockV8>
    struct ${class}Void<T, ${count},Sig, UnlockV8> : ${parent}<T,Sig>
    {
        typedef ${parent}<T,Sig> SignatureType;
        typedef char AssertArity[ (${count} == sl::Arity<SignatureType>::Value) ? 1 : -1];
        typedef typename SignatureType::FunctionType FunctionType;
        typedef typename SignatureType::ReturnType ReturnType;
        static ReturnType CallNative( T ${constness} & self, FunctionType func, v8::Arguments const & argv )
        {
            ${sigTypeDecls}
            ${castTypedefs}
            ${castInits}
            V8Unlocker<UnlockV8> const unlocker();
            return (ReturnType)(self.*func)( ${castCalls} );
        }
        static ${ValHnd} Call( T ${constness} & self, FunctionType func, v8::Arguments const & argv )
        {
            try
            {
                CallNative( self, func, argv );
                return v8::Undefined();
            }
            HANDLE_PROPAGATE_EXCEPTION;
        }
        static ReturnType CallNative( FunctionType func, v8::Arguments const & argv )
        {
            T ${constness} * self = CastFromJS<T>(argv.This());
            if( ! self ) throw MissingThisExceptionT<T>();
            return (ReturnType)CallNative(*self, func, argv);
        }
        static ${ValHnd} Call( FunctionType func, v8::Arguments const & argv )
        {
            try
            {
                CallNative(func, argv);
                return v8::Undefined();
            }
            HANDLE_PROPAGATE_EXCEPTION;
        }
    };
}
EOF
}

function makeMethodForwarder()
{
    makeMethodForwarder_impl
    makeMethodForwarder_impl const
}

##########################################################
# here we go...
makeLists

for command in $@; do
case $command in
    *Signature|*Forwarder|CtorForwarder)
	make${command} || {
        rc=$?
        echo "make${command} failed with rc $rc" 1>&2
        exit $rc
    }
	;;
    *)
	echo "Unhandled command: ${command}"
	exit 2
    ;;
esac
done
