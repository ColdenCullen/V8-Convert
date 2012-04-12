#!/bin/bash
########################################################################
# Quick hack to generate cvv8::ClassCreator skeleton code for a native
# class. The output does not compile as-is: it has to be split up into
# header/C++ (if appropriate) and tweaked for the specific use case
########################################################################

function usage(){
    echo "Usage: $0 C++ClassName JSClassName" 1>&2
    exit 1
}
if [[ x = "x$1" ]] || [[ x = "x$2" ]]
then
    usage
fi

class=$1
name=$2

function gen_h() {
cat <<EOF

#include "cvv8/ClassCreator.hpp"

namespace cvv8 {
    CVV8_TypeName_DECL((${class}));

    template <>
    struct ClassCreator_InternalFields<${class}>
        : ClassCreator_InternalFields_Base<${class}>
    {};

    template <>
    struct ClassCreator_SearchPrototypeForThis<${class}> : Opt_Bool<true>
    {};

    template <>
    class ClassCreator_Factory<${class}>
    {
    public:
        typedef ${class} * ReturnType;
        static ReturnType Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv );
        static void Delete( ReturnType obj );
    };

    template <typename ${class}>
    struct ClassCreator_WeakWrap
    {
        typedef typename TypeInfo<${class}>::NativeHandle NativeHandle;
        static void PreWrap( v8::Persistent<v8::Object> const &, v8::Arguments const & );
        static void Wrap( v8::Persistent<v8::Object> const &, NativeHandle );
        static void Unwrap( v8::Handle<v8::Object> const &, NativeHandle );
    };

    template <typename ${class}>
    struct ClassCreator_SetupBindings
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };

    
    template <>
    struct JSToNative<${class}>
        : JSToNative_ClassCreator<${class}>
    {};

#if 0
    template <>
    struct NativeToJS<${class}> : NativeToJSMap<${class}>::NativeToJSImpl {};
#endif

} /* namespace */

EOF
}

function gen_cpp(){
cat <<EOF
#include "cvv8/XTo.hpp"
#include "cvv8/properties.hpp"
EOF


    echo "namespace cvv8 {"

cat <<EOF
    CVV8_TypeName_IMPL((${class}),"${name}");

#if 0 /* needed? */
    template <>
    const void * ClassCreator_TypeID<${class}>::Value = TypeName<${class}>::Value;
#endif
EOF

    local WW="ClassCreator_WeakWrap<${class}>"
cat <<EOF

    void ${WW}::PreWrap( v8::Persistent<v8::Object> const &, v8::Arguments const & ){
        return;
    }
    void ${WW}::Wrap( v8::Persistent<v8::Object> const &, NativeHandle ){
        return;
    }
    void ${WW}::Unwrap( v8::Handle<v8::Object> const &, NativeHandle ){
        return;
    }

EOF

    local FAC="ClassCreator_Factor<${class}>"
cat <<EOF
    static ${FAC}::ReturnType ${FAC}::Create( v8::Persistent<v8::Object> &, v8::Arguments const & argv ){
        return new ${class};
    }

    static void ${FAC}::Delete( ${class} * obj ){
        if(obj) delete obj;
    }
EOF

cat <<EOF
    void ClassCreator_SetupBindings<typename ${class}>::Initialize( v8::Handle<v8::Object> const & target );
        typedef ${class} T;
        typedef ClassCreator<T> CC:
        CC & cc( CC::Instance() );
        if( cc.IsSealed() ){
            cc.AddClassTo( TypeName<T>::Value, target );
            return;
        }
        
#if 0
        // if your type inherits another CC-bound type:
        cc.Inherit<ParentType>();
#endif

#define CATCHER InCaCatcher_std /* convenience macro */

#if 0
        // ADD YOUR BINDINGS HERE, e.g...
        cc
            ("destroy", CC::DestroyObjectCallback )
            ("foo",
            CATCHER< MethodTo< InCa, const T, int (double), &T::foo> >::Call )
            ("srand"
            FunctionTo< InCa, void (unsigned int), ::srand >::Call)
            ("rand"
            FunctionTo< InCa, int (), ::rand >::Call)
        ;
#endif

#if 0
        // Proxy accessor/mutator functions as JS properties
        AccessorAdder acc( cc.Prototype() );
        acc
            ("x",
                MethodTo< Getter, T const, uint32_t (), &T::getX >::Get,
                MethodTo< Setter, T, void (uint32_t), &T::setX >::Set )
            ;
#endif

#if 0
        // Set up properties on the ctor...
        v8::Handle<v8::Function> ctor( cc.CtorFunction() );
        // then use ctor->Set() and friends.
        // These MUST come after your prototype-level bindings (don't ask me why)
#endif
#undef CATCHER        
        cc.AddClassTo( TypeName<T>::Value, target );
        return;

    };
EOF

    echo "} /* namespace */"
}

gen_h
echo
echo '/* BEGIN IMPL... */'
gen_cpp
echo

