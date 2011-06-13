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

#define JSTR(X) v8::String::New(X)

#include <cstdio> /* puts() */

#include "../../demo_shellfuncs.cpp"


/* manual declarations of code from jspdo.cpp */
//namespace jspdo { void SetupV8Bindings( v8::Handle<v8::Object> & dest ); }
#if defined(INCLUDE_SHELL_BINDINGS)
#  include INCLUDE_SHELL_BINDINGS // "shell_bindings.hpp"
#endif

static int v8_main(int argc, char const * const * argv)
{
    using namespace v8;
    Locker locker;
    HandleScope handle_scope;
    Persistent<Context> context;
    Handle<ObjectTemplate> global = ObjectTemplate::New();
    Handle<FunctionTemplate> fntmLoad = FunctionTemplate::New(Load);
    global->Set(JSTR("load"), fntmLoad )
        /* Reminder: Calling CastToJS(Load) this early in the v8
           startup process apparently segfaults v8.
        */
        ;
    global->Set(JSTR("print"), FunctionTemplate::New( Print ));
    global->Set(JSTR("sleep"), FunctionTemplate::New( JsSleep ));
    global->Set(JSTR("getStacktrace"), FunctionTemplate::New( GetV8StackTrace ));
    global->Set(JSTR("gc"),
                FunctionTemplate::New(cv::FunctionToInvocationCallback<bool (),v8::V8::IdleNotification>)
                );

    /**
       Reminder to self: changes to global template must apparently
       come before the context is created, otherwise they appear to
       have no effect.
       
       GODDAMMIT, GOOGLE, DOCUMENT V8 SO THAT PEOPLE CAN USE IT
       PRODUCTIVELY INSTEAD OF HAVING TO FIGHT WITH IT!!!
    */
    context = Context::New(NULL, global);
    Context::Scope context_scope(context);
    Handle<Object> gobj = context->Global();
    try
    {
#if defined(SETUP_SHELL_BINDINGS)
        SETUP_SHELL_BINDINGS(gobj);
#endif
        v8::TryCatch tryCatch;
        for( int i = 1; i < argc; ++i ) {
            char const * fname = argv[i];
            ValueHandle av[] = {
                cv::CastToJS(fname)
            };
            ValueHandle rc = fntmLoad->GetFunction()->Call(gobj,1,av);
            if( rc.IsEmpty() )
            {
                ReportException(&tryCatch, std::cerr);
                return 1;
            }
        }
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
    if(0)
    {
        CERR << "Trying to force GC... This will likely take 5-10 seconds...\n";
        while( !V8::IdleNotification() )
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

