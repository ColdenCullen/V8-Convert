/*****************************************************
Demonstration of using cvv8 (a.k.a. v8-convert).

Author: Stephan Beal (http://wanderinghorse.net)

License: Public Domain
*****************************************************/
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

/**
    This type exists to demonstrate how we can bind functions which return
    non-convertible types.
*/
struct NonConvertibleType {};

/**
    A class we want to bind. All of its public members will be bound to JS.
*/
class MyType
{
private:
    void init()
    {
        this->anInt = 42;
        this->aDouble = 42.24;
    }
    mutable v8::Handle<v8::Object> jsSelf;
    double aDouble;
public:
    int anInt;
    MyType() {
        this->init();
        CERR << "MyType::MyType() @ "<<(void const *)this<<'\n';
    }
    MyType( int i, double d ) {
        this->init();
        this->anInt = i;
        this->aDouble = d;
        CERR << "MyType::MyType("<<i<<", "<<d<<") @ "<<(void const *)this<<'\n';
    }
    MyType( char const * str ) {
        this->init();
        CERR << "MyType::MyType("<<str<<") @ "<<this<<'\n';
    }
    MyType( v8::Arguments const & argv ) {
        CERR << "MyType::MyType("<<argv.Length()<<" arg(s)) @ "<<(void const *)this<<'\n';
        this->init();
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

    NonConvertibleType nonConvertibleReturn() const
    { return NonConvertibleType(); }

    double getDouble() const { return this->aDouble; }
    void setDouble(double d) { this->aDouble = d; }

    v8::Handle<v8::Object> & jsThis() const { return this->jsSelf; }
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
    /**
        Optional TypeName<> specialization: used mostly for error reporting
        purposes but can also be used to hold the class' JS-side name (which
        often differs from its native name). If used, it should be declared
        (and optionally defined) before (many) other ClassCreator policies,
        as many policies will instantiate (possibly indirectly) TypeName<T>.

        The IMPL parts should go in the implementation file, not the header,
        to avoid ODR violations.
    */
    CVV8_TypeName_DECL((MyType));
    CVV8_TypeName_IMPL((MyType),"MyType");
    CVV8_TypeName_DECL((MySubType));
    CVV8_TypeName_IMPL((MySubType),"MySubType");


    /**
        This NativeToJS variation uses custom plumbing we install
        via ClassCreator_WeakWrap to implement the NativeToJS
        conversion.

        There is no single generic solution to the NativeToJS problem, and
        there is no default implementation.

        Note that a NativeToJS is ONLY necessary when:

        - CastToJS<T> is called by client code.

        - Bound functions _return_ native T pointers or references

        It is _not_ necessary when functions take such arguments as parameters.

        The majority of class conversions do not require this overhead, and
        we do it here just for demonstration/test purposes.
    */
    template <>
    struct NativeToJS< MyType >
    {
        typedef MyType const * ArgType;
        v8::Handle<v8::Value> operator()( ArgType n ) const
        {
            if( n ) return n->jsThis();
            else return v8::Null();
        }
        // i'm not quite sure why i need this overload :/
        v8::Handle<v8::Value> operator()( MyType const & n ) const
        {
            if( !n.jsThis().IsEmpty() ) return n.jsThis();
            else return v8::Null();
        }
    };

    template <>
    struct NativeToJS< MySubType > : NativeToJS< MyType >
    {
    };

#if 0
    /**
        We can customize the v8::Object internal field layout by
        specializing this policy. It's rarely needed/useful, and we do it
        here only for demonstration purposes.
    */
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
        type-safety check the library optionally does (and this approach
        partially bypasses/foils that check).

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

    /**
        A JSToNative specialization which makes use of the plumbing
        installed by ClassCreator. JSToNative is required so that
        CastFromJS<MyType>() will work. The JS/native binding process
        requires that we be able to convert (via CastFromJS()) a JS-side
        MyType object to a C++-side MyType object.
    */
    template <>
    struct JSToNative< MyType >
        : JSToNative_ClassCreator< MyType >
    {};
    template <>
    struct JSToNative< MySubType >
        : JSToNative_ClassCreator< MySubType >
    {};


    /**
        A custom MyType ctor/factor which actually returns a MySubType.
    */
    struct MyCustomCtor : Signature<MyType *()>// we subclass to upgrade to a type-list
    {
        //! ReturnType is required by CtorForwarder interface.
        typedef MyType * ReturnType;
        //! ReturnType is required by CtorForwarder interface.
        static ReturnType Call( v8::Arguments const & argv )
        {
            CERR << "Called custom MyType (MySubType) factory.\n";
            return new MySubType;
        }
    };


    /** We reimplement this to demonstrate one relatively simple way to wire
        up a NativeToJS binding.
    */
    template <>
    struct ClassCreator_WeakWrap<MyType>
    {
        typedef MyType * NativeHandle;
        static void PreWrap( v8::Persistent<v8::Object> const & jsSelf, v8::Arguments const & argv )
        {
            return;
        }
        static void Wrap( v8::Persistent<v8::Object> const & jsSelf, NativeHandle nativeSelf )
        {
            if( nativeSelf ) nativeSelf->jsThis() = jsSelf;
            return;
        }
        static void Unwrap( v8::Handle<v8::Object> const & jsSelf, NativeHandle nativeSelf )
        {
            if( nativeSelf ) nativeSelf->jsThis() = v8::Handle<v8::Object>();
            return;
        }
    };

    template <>
    struct ClassCreator_WeakWrap<MySubType> : ClassCreator_WeakWrap<MyType> {};
    
    /**
        The MyType constructors we want to bind to v8 (there are several
        other ways to do this): This can be defined anywhere which is
        convenient for the client.
    */
    typedef Signature<MyType (
#if 0
        CtorForwarder<MyType *()>,
        CtorForwarder<MyType *( char const * )>,
        CtorForwarder<MyType *( int, double )>,
        CtorForwarder<MyType *( v8::Arguments const & )>
#else // equivalent except for the 0-arg ctor:
        PredicatedCtorForwarder<Argv_Length< sl::Arity<MyCustomCtor>::Value >,
                                MyCustomCtor
                                //CtorForwarder<MyType *()>
                                >,
        PredicatedCtorForwarder<Argv_Length<1>, CtorForwarder<MyType *( char const * )> >,
        PredicatedCtorForwarder<Argv_Length<2>, CtorForwarder<MyType *( int, double )> >,
        PredicatedCtorForwarder<Argv_Length<3>, CtorForwarder<MyType *( v8::Arguments const & )> >
#endif
    )> MyCtors;

    /**
        The policy which tells ClassCreator how to instantiate and
        destroy MyType objects.

        See the NativeToJS specializations for a few more details
        about NativeToJSMap.
    */
    template <>
    struct ClassCreator_Factory<MyType>
        : ClassCreator_Factory_Dispatcher< MyType,
            //CtorArityDispatcher<MyCtors>
            PredicatedCtorDispatcher<MyCtors>
            >
    {};

    template <>
    struct ClassCreator_Factory<MySubType>
        : ClassCreator_Factory_Dispatcher< MySubType, CtorForwarder<MySubType *()> >
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
    using namespace cvv8;
    typedef MyType T;
    typedef ClassCreator<T> CC;
    typedef MySubType T2;
    typedef ClassCreator<T2> CSub;
    CSub & csub(CSub::Instance());
    CC & cc(CC::Instance());
    if( cc.IsSealed() ) // the bindings were already initialized.
    {
        cc.AddClassTo( TypeName<T>::Value, dest );
        csub.AddClassTo( TypeName<T2>::Value, dest );
        return;
    }
    // Else initialize the bindings...
    cc
        ("destroy", CC::DestroyObjectCallback)
        ("nonMember", FunctionToInCa< int (int), a_non_member>::Call)
        ("nonConstMethod", MethodToInCa<T, void (), &T::aNonConstMethod>::Call)
        ("constMethod", ConstMethodToInCa<T, void (), &T::aConstMethod>::Call)
        ("nonConstPtr", MethodToInCa<T, T * (), &T::selfPtr>::Call)
        ("nonConstRef", MethodToInCa<T, T & (), &T::selfRef>::Call)
        ("constPtr", ConstMethodToInCa<T, T const * (), &T::selfConstPtr>::Call)
        ("constRef", ConstMethodToInCa<T, T const & (), &T::selfConstRef>::Call)
        ("toString", ConstMethodToInCa<T, std::string (), &T::toString>::Call)
        ("nonConvertibleReturn", ConstMethodToInCaVoid<T, NonConvertibleType (), &T::nonConvertibleReturn>::Call)
        ;

    // Bind some non-function properties...
#define JSTR v8::String::New
    typedef MemberPropertyBinder<T> PB;
    v8::Handle<v8::ObjectTemplate> const & proto( cc.Prototype() );
    proto->SetAccessor( JSTR("aDouble"),
                        PB::ConstMethodToAccessorGetter< double (), &T::getDouble>,
                        PB::AccessorSetterThrow );
    proto->SetAccessor( JSTR("anInt"),
                        PB::MemberToAccessorGetter< int, &T::anInt>,
                        PB::MemberToAccessorSetter< int, &T::anInt> );
#undef JSTR

    cc.AddClassTo( TypeName<T>::Value, dest ) /* this or Seal() must be the last op performed */;
    CERR << "Finished binding " << TypeName<T>::Value << ".\n";
    
    /**
        ACHTUNG: inheritance support is broken in some ways e.g. derived
        funcs returning (MyType [*&]) cannot convert the return value at
        runtime. Even though the return type is technically correct, the
        type-strict templates can't figure that out without us adding more
        plumbing/overhead to the bindings.
    */
    csub.Inherit<MyType>();
    csub.AddClassTo( TypeName<T2>::Value, dest );
    CERR << "Finished binding " << TypeName<T2>::Value << ".\n";
}
