#if !defined(V8_CONVERT_JSPDO_HPP_INCLUDED)
#define V8_CONVERT_JSPDO_HPP_INCLUDED

#include <v8.h>

namespace jspdo {
    void SetupV8Bindings( v8::Handle<v8::Object> & dest );
}

#endif
