
#include <cassert>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

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
        CERR << "MyType::MyType() @ "<<this<<'\n';
    }
    MyType( int i, double d ) {
        CERR << "MyType::MyType("<<i<<", "<<d<<") @ "<<this<<'\n';
    }
    MyType( char const * str ) {
        CERR << "MyType::MyType("<<str<<") @ "<<this<<'\n';
    }
    MyType( v8::Arguments const & argv ) {
        CERR << "MyType::MyType("<<argv.Length()<<" arg(s)) @ "<<this<<'\n';
    }
    ~MyType() {
        CERR << "MyType::~MyType() @ "<<this<<'\n';
    }
    void aNonConstMethod() { CERR << "\n"; }
    void aConstMethod() const { CERR << "\n"; }
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
    template <>
    char const * TypeName< MyType >::Value = "MyType";

   
    // MyType constructors we want to bind to v8 (there are several other ways
    // to do this): This can be defined anywhere which is convenient for the
    // client.
    typedef cv::Signature<MyType (
        cv::CtorForwarder<MyType *()>,
        cv::CtorForwarder<MyType *(char const *)>,
        cv::CtorForwarder<MyType *( int, double )>,
        cv::CtorForwarder<MyType *( v8::Arguments const &)>
    )> MyCtors;
    // The policy which tells ClassCreator how to instantiate and
    // destroy native objects.
    template <>
    class ClassCreator_Factory<MyType>
     : public ClassCreator_Factory_CtorArityDispatcher< MyType, MyCtors >
    {};

    // A JSToNative specialization which makes use of the plumbing
    // installed by ClassCreator. This is required so that
    // CastFromJS<MyType>() will work, as the JS/native binding process
    // requires that we be able to convert (via CastFromJS()) a JS-side
    // MyType object to a C++-side MyType object.
    template <>
    struct JSToNative< MyType > : JSToNative_ClassCreator< MyType >
    {};
    

}

void SetupCvv8DemoBindings( v8::Handle<v8::Object> const & dest )
{
    typedef MyType T;
    typedef cv::ClassCreator<T> CC;
    CC & cc(CC::Instance());
    if( cc.IsSealed() ) { // the binding was already initialized.
        cc.AddClassTo( cv::TypeName<T>::Value, dest );
        return;
    }
    // Else initialize the bindings...
    cc
        ("destroy", CC::DestroyObjectCallback)
        ("nonMember", cv::FunctionToInCa< int (int), a_non_member>::Call)
        ("nonConstMethod", cv::MethodToInCa<T, void (), &T::aNonConstMethod>::Call)
        ("constMethod", cv::ConstMethodToInCa<T, void (), &T::aConstMethod>::Call)
        .AddClassTo( cv::TypeName<T>::Value, dest );
    CERR << "Finished binding " << cv::TypeName<T>::Value << ".\n";
}

void SetupCvv8DemoBindings2( v8::Handle<v8::Object> const & dest )
{
    typedef MyType T;
    typedef cv::ClassCreator<T> CC;
    CC & cc(CC::Instance());
    v8::Handle<v8::Object> obj;
    if( cc.IsSealed() ) { // the binding was already initialized.
        obj = cc.NewInstance(0,NULL);
        dest->Set(v8::String::New(cv::TypeName<T>::Value), obj);
        return;
    }
    // Else initialize the bindings...
    cc
        ("destroy", CC::DestroyObjectCallback)
        ("nonMember", cv::FunctionToInCa< int (int), a_non_member>::Call)
        ("nonConstMethod", cv::MethodToInCa<T, void (), &T::aNonConstMethod>::Call)
        ("constMethod", cv::ConstMethodToInCa<T, void (), &T::aConstMethod>::Call)
        ;
    obj = cc.NewInstance(0,NULL);
    dest->Set(v8::String::New(cv::TypeName<T>::Value), obj);
    CERR << "Finished binding " << cv::TypeName<T>::Value << ".\n";
}
