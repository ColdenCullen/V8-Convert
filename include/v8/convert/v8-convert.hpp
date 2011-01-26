#if !defined(CODE_GOOGLE_COM_P_V8_CONVERT_V8_CONVERT_HPP_INCLUDED)
#define CODE_GOOGLE_COM_P_V8_CONVERT_V8_CONVERT_HPP_INCLUDED 1

/** @mainpage v8::convert API

The v8::convert namespace houses APIs for handling the following

- Converting between v8 Value handles and "native types" using generic
interface. This allows us to write generic algorithms which convert
between JS/C++ without having to know the exact types we're dealing
with.  The basic POD types and some STL types are supported out of the
box and plugging in one's own types is normally quite simple.

- Converting free- and member functions into v8::InvocationCallback
functions. These generated functions convert the JavaScript-originated
function arguments into native counterparts, forward the data to the
original native function, and convert the return values back to
something JS can use.

Those two core features give us all we need in order to be able to
bind near-arbitrary C/C++ functions with JavaScript (where calling
conventions and type conversions allow us to do so). For cases where
the "automatic" function-to-InvocationCallback conversions are not
suitable, the type-conversion API can simplify the implementation of
custom v8::InvocationCallback functions.

All of the conversions are compile-time typesafe where possible and
fail gracefully when such a determination can only be made at runtime.

This code originated as the core-most component of the v8-juice
library (http://code.google.com/p/v8-juice). After a couple years
i felt compelled to refactor it into a toolkit usable by arbitrary
v8-using clients, doing a bit of cleanup along the way. The eventuall
intention is that this code will replace the v8::juice::convert
code.

Author: Stephan Beal (http://wanderinghorse.net/home/stephan/)

License: Same as v8 (BSD-like), but copyright 2011 Stephan Beal.


The most important functions and types, from a user's perspective,
include:

Converting types:

- CastToJS()
- CastFromJS()

Implementing custom conversions:

- NativeToJS<T>
- JSToNative<T>

Converting functions to v8::InvocationCallback:

- FunctionToInvocationCallback()
- MethodToInvocationCallback()
- ConstMethodToInvocationCallback()

By using only those 3 function templates clients can bind
near-arbitrary native functions arbitrary JS objects (where language
calling conventions and cross-language type conversions allow).

Most of the code in this library are internal template specializations
which take care of the dirty work. Typical clients won't typically need
more than what's listed above.

Notable TODOs:

- Yet another class-binding mechanism is in development for this lib,
but just something very basic (as opposed to v8-juice's monster
class-binding API).

- Binding object accessors to native variables/members. We have this
code in v8-juice but i'd like to re-implement it based on this API's
conventions.
*/
#include "convert.hpp"
#include "invocable.hpp"
#include "ClassCreator.hpp"

#endif /* CODE_GOOGLE_COM_P_V8_CONVERT_V8_CONVERT_HPP_INCLUDED */
