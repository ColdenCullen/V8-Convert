/**
   Test/demo code for the v8-convert API.
*/
#if defined(NDEBUG)
#  undef NDEBUG  // force assert() to work
#endif

#include <cassert>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

#ifndef CERR
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << ":" <<__FUNCTION__ << "(): "
#endif

#ifndef COUT
#define COUT std::cout << __FILE__ << ":" << std::dec << __LINE__ << " : "
#endif

#include <iostream>

#include "v8/convert/v8-convert.hpp"
namespace cv = ::v8::convert;
typedef v8::Handle<v8::Value> ValueHandle;

#include "ConvertDemo.hpp"
#define JSTR(X) v8::String::New(X)

#include <cstdio> /* puts() */
ValueHandle test1_callback( v8::Arguments const & argv )
{
    using namespace v8;
    BoundNative * fooPtr;
    Local<Value> myref /* just to keep JS from gc'ing my BoundNative object */;
    {
        BoundNative::bindJSClass( v8::Context::GetCurrent()->Global() );
        Handle<Function> const & ctor( cv::ClassCreator<BoundSubNative>::Instance().CtorFunction() );
        CERR << "Calling NewInstance()\n";
        myref = ctor->NewInstance(0, NULL);
        CERR << "Called NewInstance()\n";
        fooPtr = cv::CastFromJS<BoundNative>(myref);
        CERR << "NewInstance() == @"<<(void const *)fooPtr<<'\n';
        assert( 0 != fooPtr );
        Local<Object> jfoo( Object::Cast(*myref) );
        ValueHandle varg[] = {
          JSTR("Example of binding functions taking (char const *) arguments.")
        };
        int const argc = 1;
        Local<Function> jf( Function::Cast( *(jfoo->Get(JSTR("puts"))) ) );
        jf->Call( jfoo, argc, varg );
        jf = Function::Cast( *(jfoo->Get(JSTR("bogo"))) );
        jf->Call( jfoo, argc, varg );
        jf = Function::Cast( *(jfoo->Get(JSTR("bogo2"))) );
        jf->Call( jfoo, argc, varg );
        jf = Function::Cast( *(jfoo->Get(JSTR("nativeParam"))) );
        varg[0] = jfoo;
        jf->Call( jfoo, argc, varg );
#if 1
        jf = Function::Cast( *(jfoo->Get(JSTR("runGC"))) );
        CERR << "runGC handle isEmpty?=="<<jf.IsEmpty()<<'\n';
        jf->Call( jfoo, 0, varg );
#endif
    }

    typedef cv::FunctionPtr< int (char const *), ::puts > PUTS;
    PUTS::FunctionType putstr = PUTS::GetFunction();
    putstr("roundabout use of puts()");
    
    typedef cv::FunctionPtr< void (), doNothing > DoNothingFP;
    DoNothingFP::GetFunction()();
    typedef cv::FunctionPtr< void (), doNothing > DoNothingFP2;
    DoNothingFP2::GetFunction()();
    typedef cv::FunctionPtr< int (int), doSomething > DoSomething;
    DoSomething::GetFunction()(13);

    
    typedef cv::MethodPtr< BoundNative, void (void), &BoundNative::doFoo > DoFoo;
    typedef cv::MethodPtr< BoundNative, double (int,double), &BoundNative::doFoo2 > DoFoo2;

    typedef cv::ConstMethodPtr< BoundNative, double (int,double), &BoundNative::operator() > DoFooOp2;

    v8::InvocationCallback cb;
    CERR << "Calling doNothing():\n";
    cb = cv::FunctionToInvocationCallback< void (), doNothing >;
    cb(argv);

  
    CERR << "Calling doSomething():\n";
    cb = cv::FunctionToInvocationCallback< int (int), doSomething >;
    cb(argv);
    BoundNative & foo = *fooPtr;
    CERR << "Calling foo.doFoo2():\n";
    cv::MethodToInvocable< BoundNative, double (int, double), &BoundNative::doFoo2 >::Call(foo, argv);

    
    CERR << "Calling foo.operator():\n";
    cv::ConstMethodToInvocable< BoundNative, double (int, double), &BoundNative::operator() >::Call(foo, argv);

    CERR << "Calling foo.invo() (non-const):\n";
    cv::MethodToInvocable< BoundNative, ValueHandle(v8::Arguments const &), &BoundNative::invo >::Call(foo, argv);


    CERR << "Calling foo.invo() (const):\n";
    cv::ConstMethodToInvocable< BoundNative, ValueHandle(v8::Arguments const &), &BoundNative::invo >::Call(foo, argv);


    CERR << "Calling sampleCallback():\n";
    cb = cv::FunctionToInvocable< ValueHandle(v8::Arguments const &), sampleCallback >::Call;
    cb(argv);


    CERR << "Calling foo.invo() (static):\n";
    cb = cv::FunctionToInvocable< ValueHandle(v8::Arguments const &), BoundNative::invoStatic >::Call;
    cb(argv);

    CERR << "argv-forwarder (void):\n";
    cv::ArgsToFunctionForwarder< void () >::Call( doNothing, argv );
    CERR << "argv-forwarder (int):\n";
    cv::ArgsToFunctionForwarder< int (int) >::Call( doSomething, argv );

    CERR << "argv-forwarder (int) via forwardFunction():\n";
    cv::forwardFunction( doSomething, argv );
    CERR << "argv-forwarder (void) via forwardFunction():\n";
    cv::forwardFunction( doNothing, argv );

    CERR << "argv-method-forwarder (void):\n";
    cv::ArgsToMethodForwarder< BoundNative, void () >::Call( foo, &BoundNative::doFoo, argv );

     CERR << "argv-method-forwarder (int,double):\n";
     cv::ArgsToMethodForwarder< BoundNative, double (int,double) >::Call( foo, &BoundNative::doFoo2, argv );
     CERR << "same thing using forwardMethod(T, MemFunc, Arguments):\n";
     cv::forwardMethod( foo, &BoundNative::doFoo2, argv );
     cv::forwardMethod( foo, &BoundNative::doFoo, argv );
     cv::forwardMethod<BoundNative>( &BoundNative::doFoo, argv )
         /* won't actually work b/c argv.This() is-not-a BoundNative */
         ;

     CERR << "argv-const-method-forwarder (void):\n";
     cv::ArgsToConstMethodForwarder< BoundNative, void () >::Call( foo, &BoundNative::doFooConst, argv );

     CERR << "Calling forwardConstMethod(T, MemFunc, Arguments):\n";
     cv::forwardConstMethod( foo, &BoundNative::doFooConst, argv );
     cv::forwardConstMethod( foo, &BoundNative::doFooConstInt, argv );
     cv::forwardConstMethod<BoundNative>( &BoundNative::doFooConstInt, argv )
         /* won't actually work b/c argv.This() is-not-a BoundNative */
         ;

     CERR << "Done\n";
     CERR << "NOTE: you may see an exception message directly after this "
          << "function returns regarding a missing native 'this' pointer. Don't "
          << "panic - it is _expected_ here.\n"
         ;
     return v8::Undefined();
}
#include "demo_shellfuncs.cpp"

void test1()
{

    using namespace v8;
    HandleScope scope;
    Handle<Function> hf = FunctionTemplate::New(test1_callback)->GetFunction();
    Handle<Value> args[] = {
    Integer::New(3),
    Number::New(5.1),
    Undefined()
    };
    CERR << "Calling binding function...\n";
    hf->Call( v8::Context::GetCurrent()->Global(), 3, args );
    CERR << "Returned from binding function.\n";

    char const * extScr = "./test.js";
    CERR << "Calling external script ["<<extScr<<"]...\n";
    if(0)
    {
        Local<Object> global( v8::Context::GetCurrent()->Global() );
        assert( ! global.IsEmpty() );
        Local<Function> jf( Function::Cast( *(global->Get(JSTR("load"))) ) );
        assert( ! jf.IsEmpty() );
        ValueHandle varg[] = { v8::String::New(extScr), cv::CastToJS(extScr) };
        jf->Call( global, 1, varg );
    }
    else if(1)
    {
        cv::StringBuffer code;
        code << "load(\"" << extScr << "\")";
        ExecuteString( JSTR(code.Content().c_str()), JSTR(extScr),
                       false, true);
    }
    CERR << "Returned from external script\n";
}

#if !defined(_WIN32)
#  include <unistd.h> /* only for sleep() */
#  define do_sleep sleep
#else
#  include <windows.h>
#  define do_sleep(N) Sleep((N)*1000)
#endif

static int v8_main(int argc, char const * const * argv)
{
    v8::Locker locker;
    v8::HandleScope handle_scope;
    v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();
    global->Set(JSTR("load"), v8::FunctionTemplate::New(Load) )
        /* Reminder: Calling CastToJS(Load) this early in the v8
           startup process apparently segfaults v8.
        */
        ;
    global->Set(JSTR("print"), v8::FunctionTemplate::New( Print ));
    global->Set(JSTR("sleep"), v8::FunctionTemplate::New(
                                                         cv::FunctionToInvocationCallback<
#if !defined(_WIN32)
                                                         unsigned int (unsigned int), sleep
#else
                                                         void (DWORD), Sleep // UNTESTED!
#endif
                                                         >
));
    /**
       Reminder to self: changes to global object must apparently come
       before the context is created, otherwise they appear to have no
       effect.

       GODDAMMIT, GOOGLE, DOCUMENT V8 SO THAT PEOPLE CAN USE IT
       PRODUCTIVELY INSTEAD OF HAVING TO FIGHT WITH IT!!!
    */
    v8::Persistent<v8::Context> context = v8::Context::New(NULL, global);
    v8::Context::Scope context_scope(context);
    try
    {
        test1();
    }
    catch(std::exception const & ex)
    {
        CERR << "EXCEPTION: " << ex.what() << '\n';
        return 1;
    }
    catch(...)
    {
        CERR << "UNKNOWN EXCEPTION!\n";
        return 1;
    }

    if(1)
    {
        CERR << "Trying to force GC... This will likely take 5-10 seconds... "
             << "wait for it to see the weak pointer callbacks in action...\n"
             << "ON SOME MACHINES THIS IS CRASHING ON ME IN V8 at some point "
             << "on 64-bit builds, but not on 32-bit...\n"
            ;
        while( !v8::V8::IdleNotification() )
        {
            CERR << "sleeping briefly before trying again...\n";
            do_sleep(1);
        }
        CERR << "v8 says GC is done.\n";
    }
    context.Dispose();
    return 0;
}

int main(int argc, char const * const * argv)
{

    int const rc = v8_main(argc, argv);
    CERR << "Done! rc="<<rc<<'\n';
    return rc;
}

