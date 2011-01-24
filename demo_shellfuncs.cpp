// utility code for test/demo apps. Mostly taken from the v8 sample shell

void ReportException(v8::TryCatch* try_catch) {
    // code taken from v8 sample shell
  v8::HandleScope handle_scope;
  //v8::String::Utf8Value exception();
  std::string exception_string( cv::CastFromJS<std::string>(try_catch->Exception()) ) ;
  v8::Handle<v8::Message> message = try_catch->Message();
  std::ostream & out( std::cerr );
  if (message.IsEmpty()) {
      // V8 didn't provide any extra information about this error; just
      // print the exception.
      out << exception_string << '\n';
  } else {
    // Print (filename):(line number): (message).
    std::string filename_string = cv::JSToStdString(message->GetScriptResourceName());
    int linenum = message->GetLineNumber();
    out << filename_string << ':' << linenum
         << ": "<< exception_string
         << '\n';
    // Print line of source code.
    std::string sourceline_string = cv::JSToStdString(message->GetSourceLine());
    out << sourceline_string << '\n';
    // Print wavy underline (GetUnderline is deprecated).
    int start = message->GetStartColumn();
    for (int i = 0; i < start; i++) {
        out << ' ';
    }
    int end = message->GetEndColumn();
    for (int i = start; i < end; i++) {
        out << '^';
    }
    out << std::endl;
    v8::String::Utf8Value stack_trace(try_catch->StackTrace());
    if (stack_trace.length() > 0) {
        std::string stack_trace_string = cv::JSToStdString(try_catch->StackTrace());
        out << stack_trace_string << '\n';
    }
  }
}

// Executes a string within the current v8 context.
bool ExecuteString(v8::Handle<v8::String> source,
                   v8::Handle<v8::Value> name,
                   bool print_result,
                   bool report_exceptions) {
    // code taken from v8 sample shell
    v8::HandleScope handle_scope;
    v8::TryCatch try_catch;
    v8::Handle<v8::Script> script = v8::Script::Compile(source, name);
    std::ostream & out = std::cout;
    if (script.IsEmpty()) {
        // Print errors that happened during compilation.
        if (report_exceptions)
            ReportException(&try_catch);
        return false;
    } else {
        v8::Handle<v8::Value> result = script->Run();
        if (result.IsEmpty()) {
            // Print errors that happened during execution.
            if (report_exceptions)
                ReportException(&try_catch);
            return false;
        } else {
            if (print_result && !result->IsUndefined()) {
                // If all went well and the result wasn't undefined then print
                // the returned value.
                out << cv::JSToStdString(result) << '\n';
            }
            return true;
        }
    }
}

v8::Handle<v8::Value> Load(const v8::Arguments& args)
{
    // code taken from v8 sample shell
    //CERR << "load(...)ing...\n";
    for (int i = 0; i < args.Length(); i++) {
        v8::HandleScope handle_scope;
        v8::String::Utf8Value file(args[i]);
        if (*file == NULL) {
            return v8::ThrowException(v8::String::New("Error loading file"));
        }
        std::ifstream istr(*file);
        istr >> std::noskipws;
        std::ostringstream os;
        std::copy( std::istream_iterator<char>(istr),
                   std::istream_iterator<char>(),
                   std::ostream_iterator<char>(os) );
        v8::Handle<v8::String> source =
            JSTR(os.str().c_str());
        os.clear();
        if (source.IsEmpty()) {
            return v8::ThrowException(v8::String::New("Error loading file"));
        }
        if (!ExecuteString(source, v8::String::New(*file), false, false)) {
            return v8::ThrowException(v8::String::New("Error executing file"));
        }
    }
    return v8::Undefined();
}
