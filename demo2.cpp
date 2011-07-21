
#include <cassert>
#include <iostream>
#include <sstream>

#include "cvv8/v8-convert.hpp"
#include "cvv8/V8Shell.hpp"
#include "demo2.hpp"

#ifndef CERR
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << ":" <<__FUNCTION__ << "(): "
#endif
namespace cv = cvv8;

struct MyType
{
    MyType() {
        CERR << "MyType::MyType() @ "<<(void const *)this<<'\n';
    }
    MyType( int i, double d ) {
        CERR << "MyType::MyType("<<i<<", "<<d<<") @ "<<(void const *)this<<'\n';
    }
    MyType( char const * str ) {
        CERR << "MyType::MyType("<<str<<") @ "<<this<<'\n';
    }
    MyType( v8::Arguments const & argv ) {
        CERR << "MyType::MyType("<<argv.Length()<<" arg(s)) @ "<<(void const *)this<<'\n';
    }
    ~MyType() {
        CERR << "MyType::~MyType() @ "<<(void const *)this<<'\n';
    }
    void aNonConstMethod() { CERR << " @ "<<(void const *)this<<'\n'; }
    void aConstMethod() const { CERR << " @ "<<(void const *)this<<'\n'; }

    MyType * selfPtr() { return this; }
    MyType const * selfConstPtr() const { return this; }
    MyType & selfRef() { return *this; }
    MyType const & selfConstRef() const { return *this; }

    virtual std::string toString() const;
};

/**
    A subclass to bind. Subclassing currently has some notable
    limitations and corner-cases when it comes to class bindings.

    Most notably:

    When implementing NativeToJS in conjunction with subclasses, bound
    parent-class functions which return (BaseType*) objects will return NULL
    (or throw when returning (BaseType&)) when called on C++-derived
    JS-bound instances. Getting conversions to the derived type require that
    the NativeToJS bindings for the BaseType be made aware of the derivied
    type(s), such that NativeToJS<BaseType> can return a pointer to a derived
    type. Implementing this is not as straightforward as it might initially
    sound, but we have an implementation in the v8::juice tree which we can
    probably re-use here.

    There are probably other corner-cases, some of which depend on the exact
    combination of ClassCreator policies used to customize the binding.
*/
class MySubType : public MyType
{
    public:
    MySubType()
    {
        CERR << "MySubType() @ "<<(void const *)this<<'\n';
    }
    ~MySubType()
    {
        CERR << "MySubType::~MySubType() @ "<<(void const *)this<<'\n';
    }

    virtual std::string toString() const;
};

int a_non_member(int i)
{
    CERR << " arg=("<<i<<")\n";
    return i;
}

//-----------------------------------
// Policies used by cv::ClassCreator
namespace cvv8 {
    // Optional: used mostly for error reporting purposes but can
    // also be used to hold the class' JS-side name (which often differs
    // from its native name).
    // If used, it should be declared (and optionally defined) before other
    // ClassCreator policies.
    CVV8_TypeName_DECL((MyType));
    CVV8_TypeName_IMPL((MyType),"MyType");
    CVV8_TypeName_DECL((MySubType));
    CVV8_TypeName_IMPL((MySubType),"MySubType");

#if 1
    template <>
    struct ClassCreator_InternalFields<MyType> :
        ClassCreator_InternalFields_Base<MyType,1,-1,0> {};
    /**
        If the base-most type has customized internal fields then
        all subclasses must have the same layout.
    */
    template <>
    struct ClassCreator_InternalFields<MySubType> :
        ClassCreator_InternalFields<MyType> {};
#else
    /**
        This policy is required for SUBCLASSES _if_
        ClassCreator_InternalFields<BaseType>::TypeIDField is (>=0). It
        allows the JS objects to find their 'this' pointer when
        CastFromJS<MyType>() is called, e.g. to get the 'this' pointer for a
        member function dereference. This is a side-effect of the "extra"
        type-safety check the library optionally does.

        If ClassCreator_InternalFields<BaseType>::TypeIDField is negative
        then the extra type-safety check is turned off and this policy's
        Value is not used (the template is still instantiated but its Value
        is never evaluated, so the default specialization is fine).
    */
    template <>
    struct ClassCreator_TypeID<MySubType>
        : ClassCreator_TypeID<MyType>
    {};
#endif

    // A JSToNative specialization which makes use of the plumbing
    // installed by ClassCreator. This is required so that
    // CastFromJS<MyType>() will work, as the JS/native binding process
    // requires that we be able to convert (via CastFromJS()) a JS-side
    // MyType object to a C++-side MyType object.
    template <>
    struct JSToNative< MyType >
        : JSToNative_ClassCreator< MyType >
    {};
    template <>
    struct JSToNative< MySubType >
        : JSToNative_ClassCreator< MySubType >
    {};

    /**
        This NativeToJS variation uses plumbing installed by
        ClassCreator_Factory_NativeToJSMap to implement the NativeToJS
        conversion.
    */
    template <>
    struct NativeToJS< MyType >
        : NativeToJSMap< MyType >::NativeToJSImpl
    {};

    template <>
    struct NativeToJS< MySubType >
        : NativeToJSMap< MySubType >::NativeToJSImpl
    {};

    /**
        The MyType constructors we want to bind to v8 (there are several
        other ways to do this): This can be defined anywhere which is
        convenient for the client.
    */
    typedef Signature<MyType (
        CtorForwarder<MyType *()>,
        CtorForwarder<MyType *( char const * )>,
        CtorForwarder<MyType *( int, double )>,
        CtorForwarder<MyType *( v8::Arguments const & )>
    )> MyCtors;

    // The policy which tells ClassCreator how to instantiate and
    // destroy MyType objects.
    template <>
    struct ClassCreator_Factory<MyType>
        : ClassCreator_Factory_NativeToJSMap< MyType, CtorArityDispatcher<MyCtors> >
    {};

    template <>
    struct ClassCreator_Factory<MySubType>
        : ClassCreator_Factory_NativeToJSMap< MySubType, CtorForwarder<MySubType *()> >
    {};
}

template <typename T>
static std::string toString_impl( T const * self )
{
    std::ostringstream os;
    os << "[object "<< cvv8::TypeName<T>::Value <<"@"<<(void const *)self<<']';
    return os.str();
}
std::string MyType::toString() const
{
    return toString_impl<MyType>(this);
}
std::string MySubType::toString() const
{
    return toString_impl<MySubType>(this);
}

void SetupCvv8DemoBindings( v8::Handle<v8::Object> const & dest )
{
    typedef MyType T;
    typedef cv::ClassCreator<T> CC;
    typedef MySubType T2;
    typedef cv::ClassCreator<T2> CSub;
    CSub & csub(CSub::Instance());
    CC & cc(CC::Instance());
    if( cc.IsSealed() ) { // the binding was already initialized.
        cc.AddClassTo( cv::TypeName<T>::Value, dest );
        csub.AddClassTo( cv::TypeName<T2>::Value, dest );
        return;
    }
    // Else initialize the bindings...
    cc
        ("destroy", CC::DestroyObjectCallback)
        ("nonMember", cv::FunctionToInCa< int (int), a_non_member>::Call)
        ("nonConstMethod", cv::MethodToInCa<T, void (), &T::aNonConstMethod>::Call)
        ("constMethod", cv::ConstMethodToInCa<T, void (), &T::aConstMethod>::Call)
        ("nonConstPtr", cv::MethodToInCa<T, T * (), &T::selfPtr>::Call)
        ("nonConstRef", cv::MethodToInCa<T, T & (), &T::selfRef>::Call)
        ("constPtr", cv::ConstMethodToInCa<T, T const * (), &T::selfConstPtr>::Call)
        ("constRef", cv::ConstMethodToInCa<T, T const & (), &T::selfConstRef>::Call)
        ("toString", cv::ConstMethodToInCa<T, std::string (), &T::toString>::Call)       
        .AddClassTo( cv::TypeName<T>::Value, dest );
    CERR << "Finished binding " << cv::TypeName<T>::Value << ".\n";
    

    // ACHTUNG: inheritance support is broken in some ways (e.g. conversion to base type).
    csub.Inherit<MyType>();
    csub.AddClassTo( cv::TypeName<T2>::Value, dest );
}
