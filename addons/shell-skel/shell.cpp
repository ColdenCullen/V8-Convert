/**
   Test/demo code for the v8-convert API.
*/
#if defined(NDEBUG)
#  undef NDEBUG  // force assert() to work
#endif

#include <cassert>
#include <iostream>

#ifndef CERR
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << ":" <<__FUNCTION__ << "(): "
#endif

#ifndef COUT
#define COUT std::cout << __FILE__ << ":" << std::dec << __LINE__ << " : "
#endif


#include "v8/convert/v8-convert.hpp"
#include "v8/convert/V8Shell.hpp"
namespace cv = ::v8::convert;

#if !defined(_WIN32)
#  include <unistd.h> /* only for sleep() */
#  define do_sleep ::sleep
#else
#  include <windows.h> /* only for Sleep() */
#  define do_sleep(N) ::Sleep((N)*1000)
#endif

#if defined(INCLUDE_SHELL_BINDINGS)
#  include INCLUDE_SHELL_BINDINGS
#endif

static int v8_main(int argc, char const * const * argv)
{
    typedef v8::Handle<v8::Value> ValueHandle;
    using namespace v8;
    cv::Shell shell(NULL, argc, argv);
    v8::Handle<v8::Object> global = shell.Global();
    shell.SetupDefaultBindings()
        ("gc", cv::FunctionToInvocationCallback<bool (),v8::V8::IdleNotification>)
    ;
    try
    {
#if defined(SETUP_SHELL_BINDINGS)
        SETUP_SHELL_BINDINGS(global);
#endif
        v8::TryCatch tryCatch;
        //for( int i = 1; i < argc; ++i ) {
            char const * fname = argv[1];
            //ValueHandle av[] = { cv::CastToJS(fname) };
            //ValueHandle rc = fnLoad->Call(global,1,av);
            ValueHandle rc = shell.ExecuteFile( fname, &tryCatch );
            if( rc.IsEmpty() )
            { // exception was reported by shell already
                return 2;
            }
        //}
    }
    catch(std::exception const & ex)
    {
        CERR << "EXCEPTION: " << ex.what() << '\n';
        return 3;
    }
    catch(...)
    {
        CERR << "UNKNOWN EXCEPTION!\n";
        return 4;
    }
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

    if( 1 == argc ) {
        CERR << "Usage:\n\t" << argv[0] << " script.js [-- [script arguments]]"
             << "\nAll arguments after '--' are available in the script via "
             << "the global 'arguments' Array object.\n";
        
        return 1;
    }
    int const rc = v8_main(argc, argv);
    CERR << "Done! rc="<<rc<<'\n';
    return rc;
}

