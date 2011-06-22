#if !defined(V8_CONVERT_V8Shell_HPP_INCLUDED)
#define V8_CONVERT_V8Shell_HPP_INCLUDED

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace v8 { namespace convert {

    /**
        This class implements a very basic shell for v8. Its template
        type is ignored - it is only a class template so that we 
        can avoid potential linking problems with large non-template 
        classes in this header-only library.
    */
    template <typename ContextType = void>
    class V8Shell
    {
    public:
        /**
           A callback function signature for reporing JS-side
           exception messages to the native world.
        */
        typedef void (*ErrorMessageReporter)( char const * msg );
    private:
        // The declaration order of the v8-related objects is important!
        v8::Locker locker;
        v8::HandleScope hscope;
        //v8::Handle<v8::ObjectTemplate> globt;
        v8::Handle<v8::Context> context;
        v8::Context::Scope cxscope;
        v8::Handle<v8::Object> global;
        ErrorMessageReporter reporter;
        bool executeThrew;
        static void DefaultErrorMessageReporter( char const * msg )
        {
            if( msg && *msg ) std::cerr
                //<< "[V8Shell default exception reporter says:]\n"
                << msg << std::endl;
        }
        
    public:
        V8Shell( char const * globalObjectName = NULL ) :
            locker(),
            hscope(),
            //globt( v8::ObjectTemplate::New() ),
            context( v8::Context::New(NULL, v8::ObjectTemplate::New()) ),
            cxscope(context),
            global( context->Global() ),
            reporter( DefaultErrorMessageReporter ),
            executeThrew(false)
        {
            if( globalObjectName && *globalObjectName )
            {
                this->global->Set( v8::String::New(globalObjectName), this->global );
            }
        }

        /**
            Destructs all v8 resources used by this object, e.g. the JS context.
        */
        ~V8Shell()
        {
        }
        
        /**
           Sets the error reporter function used by
           ExecuteString(). Passing 0 will disable exception
           reporting. The default reporter sends its output to
           std::cerr.
        */
        void SetExecuteErrorReporter( ErrorMessageReporter r )
        {
            this->reporter = r;
        }
    
        /**
           Outputs an exception message using the current
           error reporter function.

           If try_catch or the current error reporter are
           null then nothing is done.
           
           @see SetExecuteErrorReporter().
        */
 
        void ReportException(v8::TryCatch* try_catch)
        {
            if( !try_catch || ! this->reporter ) return;
            v8::HandleScope handle_scope;
            v8::String::Utf8Value exception(try_catch->Exception());
#define TOCSTR(X) (*X ? *X : "<exception string conversion failed!>")
            const char* exception_string = TOCSTR(exception);
            v8::Handle<v8::Message> message = try_catch->Message();
            std::ostringstream os;
            os << "V8Shell Exception Reporter: ";
            if (message.IsEmpty())
            {
                // V8 didn't provide any extra information about this error; just
                // print the exception.
                os << exception_string << '\n';
            }
            else
            {
                // Print (filename):(line number): (message).
                v8::String::Utf8Value const filename(message->GetScriptResourceName());
                const char* filename_string = TOCSTR(filename);
                int linenum = message->GetLineNumber();
                os << filename_string << ':'
                   << linenum << ": "
                   << (exception_string ? exception_string : "") << '\n';
                // Print line of source code.
                v8::String::Utf8Value const sourceline(message->GetSourceLine());
                const char* sourceline_string = TOCSTR(sourceline);
#undef TOCSTR
                os << sourceline_string << '\n';
                // Print wavy underline (GetUnderline is deprecated).
                int start = message->GetStartColumn();
                for (int i = 0; i < start; i++) {
                    os << ' ';
                }
                int end = message->GetEndColumn();
                for (int i = start; i < end; i++) {
                    os << '^';
                }
                os << '\n';
            }
            std::string const & str = os.str();
            this->reporter( str.c_str() );
        }
        
        /**
            Adds the given function to the global object.
        */
        V8Shell & operator()( char const * name, v8::Handle<v8::Function> const & f )
        {
            this->global->Set( v8::String::New(name), f );
            return *this;
        }

        /**
            Adds the given function to the global object.
        */
        V8Shell & operator()( char const * name, v8::Handle<v8::FunctionTemplate> const & f )
        {
            return this->operator()( name, f->GetFunction() );
        }

        /**
            Adds the given function to the global object.
        */
        V8Shell & operator()( char const * name, v8::InvocationCallback f )
        {
            return this->operator()( name, FunctionTemplate::New(f) );
        }

        /**
            Returns the global object for this shell.
        */
        v8::Handle<v8::Object> Global()
        {
            return this->global;
        }

        /**
            Returns the context object for this shell.
        */
        v8::Handle<v8::Context> Context()
        {
            return this->context;
        }

#if 0 // changes made to global ObjectTemplate have no effect after cx is set up.
        v8::Handle<v8::ObjectTemplate> GlobalTemplate()
        {
            return this->globt;
        }
#endif

        /**
           Intended to be called from main() and passed the argc/argv
           which are passed to main. offset is the number of arguments
           to skip, and defaults to one to skip the argv[0] argument,
           which is conventionally the application name.

           It skips all arguments up to "--". For each argument after
           "--", it adds the argument to a list. At the end of the
           list, the global object is assigned a property named
           "arguments" which contains that list.
           
           If the argument list has no arguments after a "--" entry
           then the "arguments" global value will be an empty array,
           as opposed to null or undefined.

           This function does no interpretation of the arguments.
        */
        void ProcessMainArgv( int argc, char const * const * _argv, unsigned short offset = 1 )
        {
            if( (argc<1) || !_argv ) return;
            char const * endofargs = "--";
            v8::Handle<v8::Array> argv( v8::Array::New() );
            int i = (int)offset;
            for( ; i < argc; ++i )
            {
                if( 0 == strcmp(_argv[i],endofargs) )
                {
                    ++i;
                    break;
                }
            }
            int ndx = 0;
            for( ; i < argc; ++i )
            {
                char const * arg = _argv[i];
                if( arg )
                { // String::New() calls strlen(), which hates NULL
                    argv->Set( ndx++, v8::String::New(arg) );
                }
            }
            this->global->Set( v8::String::New("arguments"), argv );
        }
        
        /**
           Executes the given source string in the current
           context.

           If resultGoesTo is not null and the result is neither an
           error nor undefined, then the result is converted to a
           string and send to that stream.

           If reportExceptions is not null and the script throws an exception
           then that TryCatch object is used to build an error string, which
           is passed to this object's error reporter function. The default sends
           the output to std::cerr.

           Returns the result of the last expression evaluated in the script,
           or an empty handle on error.
        */
        v8::Handle<v8::Value> ExecuteString(v8::Handle<v8::String> const & source,
                                           v8::Handle<v8::Value> name,
                                           v8::TryCatch * reportExceptions = NULL,
                                           std::ostream * out = NULL )
        {
            this->executeThrew = false;
            v8::HandleScope scope;
            v8::Handle<v8::Script> script = v8::Script::Compile(source, name);
            if( reportExceptions && reportExceptions->HasCaught())//script.IsEmpty())
            {
                // Report errors that happened during compilation.
                this->executeThrew = true;
                if (reportExceptions)
                    this->ReportException(reportExceptions);
                return v8::Handle<v8::Value>();
            }
            else
            {
                v8::Handle<v8::Value> const & result( script->Run() );
                if( reportExceptions && reportExceptions->HasCaught())//(result.IsEmpty())
                {
                    this->executeThrew = true;
                    this->ReportException(reportExceptions);
                    return v8::Handle<v8::Value>();
                }
                else
                {
                    if (out && !result.IsEmpty())
                    {
                        (*out) << *v8::String::Utf8Value(result) << '\n';
                    }
                    return scope.Close(result/* is this legal if result.IsEmpty() (i.e. an Exception)? Probably not. */);
                }
            }
        }
        
#if 0
        bool ExecThrewException() const
        {
            return this->executeThrew;
        }
#endif

        /**
           Convenience form of ExecuteString(source,"some default name", reportExceptions, 0).
        */
        v8::Handle<v8::Value> ExecuteString(std::string const & source,
                                           std::string const & name,
                                           v8::TryCatch * reportExceptions,
                                           std::ostream * resultGoesTo )
        {
            v8::HandleScope scope;
            v8::Local<v8::String> const & s( v8::String::New( source.c_str(), static_cast<int>(source.size()) ) );
            v8::Local<v8::String> const & n( v8::String::New( name.c_str(), static_cast<int>(name.size()) ) );
            return this->ExecuteString( s, n, reportExceptions, resultGoesTo );
        }

        /**
           Convenience overload taking input from native strings.
        */
        v8::Handle<v8::Value> ExecuteString(std::string const & source, v8::TryCatch * reportExceptions = NULL )
        {
            return this->ExecuteString(source, "ExecuteString()", reportExceptions, 0);
        }

        /**
           Convenience form of ExecuteString(source,"some default name", 0, reportExceptions).
        */
        v8::Handle<v8::Value> ExecuteString(v8::Handle<v8::String> source, v8::TryCatch * reportExceptions = NULL )
        {
            return this->ExecuteString(source, v8::String::New("ExecuteString()"), reportExceptions, 0);
        }
        
        /**
           Convenience form of ExecuteString() reading from an opened input stream.
        */
        v8::Handle<v8::Value> ExecuteStream( std::istream & is, std::string const & name,
                            v8::TryCatch * reportExceptions = NULL,
                            std::ostream * resultGoesTo = NULL )
        {
            std::ostringstream os;
            is >> std::noskipws;
            std::copy( std::istream_iterator<char>(is), std::istream_iterator<char>(), std::ostream_iterator<char>(os) );
            return this->ExecuteString( os.str(), name, reportExceptions, resultGoesTo );
        }
        
        /**
           Convenience form of ExecuteString() reading from a local file.
        */
        v8::Handle<v8::Value> ExecuteFile( char const * filename,
                                            v8::TryCatch * reportExceptions = NULL,
                                            std::ostream * resultGoesTo = NULL )
        {
            std::ifstream inf(filename);
            if( ! inf.good() )
            {
                // FIXME: throw a v8 exception and report it via our reporter.
                // Nevermind: the result is useless b/c the exception has no proper vm state info here...
                StringBuffer msg;
                msg << "Could not open file ["<<filename<<"].";
                
                //v8::Handle<v8::Value> const & rc( v8::ThrowException(msg.toError()) );
                //if( reportExceptions ) this->ReportException(reportExceptions);
                return v8::ThrowException(msg.toError());
            }
            return this->ExecuteStream( inf, filename, reportExceptions, resultGoesTo );
        }
    };
    
}}
#endif /* V8_CONVERT_V8Shell_HPP_INCLUDED */
