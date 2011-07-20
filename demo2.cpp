
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

void SetupCvv8DemoBindings( v8::Handle<v8::Object> const & obj )
{
    CERR << "If you made it this far then it seems to have worked.\n";
}

