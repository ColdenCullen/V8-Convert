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
    Local<Value> myref /* to keep v8 from prematurly cleaning my object. */;
    Local<Function> jf;
    BoundNative * fooPtr;
    Local<Object> myobj;
    {
        BoundNative::bindJSClass( v8::Context::GetCurrent()->Global() );
        //v8::HandleScope scope;
        Handle<Function> const & ctor( cv::ClassCreator<BoundSubNative>::Instance().CtorFunction() );
        CERR << "Calling NewInstance()\n";
        myref = ctor->NewInstance(0, NULL);
        CERR << "Called NewInstance()\n";
        fooPtr = cv::CastFromJS<BoundNative>(myref);
        CERR << "NewInstance() == @"<<(void const *)fooPtr<<'\n';
        assert( 0 != fooPtr );
        myobj = Object::Cast(*myref);
        ValueHandle varg[] = {
          JSTR("Example of binding functions taking (char const *) arguments.")
        };
        int const argc = 1;
        jf = Function::Cast( *(myobj->Get(JSTR("puts"))) );
        jf->Call( myobj, argc, varg );
        jf = Function::Cast( *(myobj->Get(JSTR("bogo"))) );
        jf->Call( myobj, argc, varg );
        jf = Function::Cast( *(myobj->Get(JSTR("bogo2"))) );
        jf->Call( myobj, argc, varg );
        jf = Function::Cast( *(myobj->Get(JSTR("nativeParam"))) );
        varg[0] = myobj;
        jf->Call( myobj, argc, varg );
#if 1
        jf = Function::Cast( *(myobj->Get(JSTR("runGC"))) );
        CERR << "runGC handle isEmpty?=="<<jf.IsEmpty()<<'\n';
        jf->Call( myobj, 0, varg );
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

#if 0
     jf = Function::Cast( *(myobj->Get(JSTR("destroy"))) );
     CERR << "Calling myObject.destroy()...\n";
     jf->Call( Local<Object>(Object::Cast(*myref)), 0, NULL );
#endif

     
     CERR << "Done\n";
     CERR << "NOTE: you may see an exception message directly before or after this "
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

/**
   Implements the v8::InvocationCallback interface and has the
   following JS interface:

   @code
   Array stracktrace([unsigned int limit = some reasonable default])
   @endcode

   Each element in the returned array represents a stack frame and
   is a plain object with the following properties:

   column = 1-based column number (note that this is different from most editors,
   but this is how v8 returns this value.)
       
   line = 1-based line number

   scriptName = name of the script

   functionName = name of the function

   isConstructor = true if this is a constructor call

   isEval = true if this is part of an eval()

   TODO:

   - Add a toString() member to the returned array which creates a
   conventional-looking stacktrace string.
*/
v8::Handle<v8::Value> GetV8StackTrace( v8::Arguments const & argv )
{
    using namespace v8;
    // Lame hack to distinguish between v8::juice::convert and v8::convert APIs:
#if defined(CODE_GOOGLE_COM_V8_CONVERT_SIGNATURE_CORE_V8_HPP_INCLUDED)
    namespace cv = v8::convert;
#else
    namespace cv = v8::juice::convert;
#endif
    uint32_t limit = (argv.Length() > 0) ? cv::CastFromJS<uint32_t>(argv[0]) : 0;
    if( limit == 0 ) limit = 8;
    else if( limit > 100 ) limit = 100;

    Local<StackTrace> const st = StackTrace::CurrentStackTrace( limit, StackTrace::kDetailed );
    int const fcountI = st->GetFrameCount();
    // Who the hell designed the StackTrace API to return an int in GetFrameCount() but take
    // an unsigned int in GetFrame()???
    uint32_t const fcount = static_cast<uint32_t>(fcountI);
    Local<Array> jst = Array::New(fcount);
#define STR(X) v8::String::New(X)
    for( uint32_t i = 0; (i < fcount) && (i<limit); ++i )
    {
        Local<StackFrame> const & sf( st->GetFrame(i) );
        Local<Object> jsf = Object::New();
        jsf->Set(STR("column"), cv::CastToJS(sf->GetColumn()));
        jsf->Set(STR("functionName"), sf->GetFunctionName());
        jsf->Set(STR("line"), cv::CastToJS(sf->GetLineNumber()));
        jsf->Set(STR("scriptName"), sf->GetScriptName());
        jsf->Set(STR("isConstructor"), cv::CastToJS(sf->IsConstructor()));
        jsf->Set(STR("isEval"), cv::CastToJS(sf->IsEval()));
        jst->Set(i,jsf);
    }
    return jst;
#undef STR
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
    v8::Persistent<v8::Context> context;
    v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();
    global->Set(JSTR("load"), v8::FunctionTemplate::New(Load) )
        /* Reminder: Calling CastToJS(Load) this early in the v8
           startup process apparently segfaults v8.
        */
        ;
    global->Set(JSTR("print"), v8::FunctionTemplate::New( Print ));
    global->Set(JSTR("getStacktrace"), v8::FunctionTemplate::New( GetV8StackTrace ));
    global->Set(JSTR("gc"),
                v8::FunctionTemplate::New(cv::FunctionToInvocationCallback<bool (),v8::V8::IdleNotification>)
                );
    global->Set(JSTR("sleep"),
#if !defined(_WIN32)
                v8::FunctionTemplate::New(cv::FunctionToInvocationCallback<unsigned int (unsigned int), ::sleep>)
#else
                v8::FunctionTemplate::New(cv::FunctionToInvocationCallback<void (DWORD), Sleep /*UNTESTED!*/> )
#endif
                );

    /**
       Reminder to self: changes to global template must apparently
       come before the context is created, otherwise they appear to
       have no effect.
       
       GODDAMMIT, GOOGLE, DOCUMENT V8 SO THAT PEOPLE CAN USE IT
       PRODUCTIVELY INSTEAD OF HAVING TO FIGHT WITH IT!!!
    */
    context = v8::Context::New(NULL, global);
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
    context.Dispose();
    if(1)
    {
        CERR << "Trying to force GC... This will likely take 5-10 seconds... "
             << "wait for it to see the weak pointer callbacks in action...\n"
#if 0 // this appears to have been fixed...
             << "ON SOME MACHINES THIS IS CRASHING ON ME IN V8 at some point "
             << "on 64-bit builds, but not on 32-bit...\n"
#endif
            ;
        while( !v8::V8::IdleNotification() )
        {
            CERR << "sleeping briefly before trying again...\n";
            do_sleep(1);
        }
        CERR << "v8 says GC is done.\n";
    }
    return 0;
}

int main(int argc, char const * const * argv)
{

    int const rc = v8_main(argc, argv);
    CERR << "Done! rc="<<rc<<'\n';
    return rc;
}

