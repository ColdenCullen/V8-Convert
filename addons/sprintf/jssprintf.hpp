#if !defined(V8_CONVERT_SPRINTF_H_INCLUDED)
#define V8_CONVERT_SPRINTF_H_INCLUDED
#include <v8.h>

namespace v8 { namespace convert {
    void SetupJSPrintf( v8::Handle<v8::Object> dest );
    v8::Handle< v8::Value > sprintf( ::v8::Arguments const & argv );
}}
#endif
