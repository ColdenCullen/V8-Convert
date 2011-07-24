#if !defined (CVV8_TO_X_HPP_INCLUDED)
#define CVV8_TO_X_HPP_INCLUDED
#include "invocable.hpp"
#include "properties.hpp"
/** @file XTo.hpp

    This file provides an alternate approach to the function
    conversion API. It covers:

    - Converting functions and methods to to v8::InvocationCallback,
    v8::AccessorGetter, and v8::AccessorSetter.

    - Converting variables to v8::AccessorGetter and v8::AccessorSetter.

    All conversions of a given category, e.g. FunctionToXYZ or MethodToXYZ
    have a common template, e.g. FunctionTo or MethodTo. The first type
    passed to that template is a "tag" type which tells us what conversion
    to perform. e.g. a function can be used as an v8::InvocationCallback,
    v8::AccessorGetter, or v8::AccessorSetter.

    An example probably explains it best:

    @code
        int aBoundInt = 3;
    void test_to_bindings()
    {
        v8::InvocationCallback cb;
        v8::AccessorGetter g;
        v8::AccessorSetter s;

        using namespace cvv8;

        typedef FunctionTo< InCa, int(char const *), ::puts> FPuts;
        typedef FunctionTo< Getter, int(void), ::getchar> GetChar;
        typedef FunctionTo< Setter, int(int), ::putchar> SetChar;
        cb = FPuts::Call;
        g = GetChar::Get;
        s = SetChar::Set;

        typedef VarTo< Getter, int, &aBoundInt > VarGet;
        typedef VarTo< Setter, int, &aBoundInt > VarSet;
        g = VarGet::Get;
        s = VarSet::Set;
        typedef VarTo< Accessors, int, &aBoundInt > VarGetSet;
        g = VarGetSet::Get;
        s = VarGetSet::Set;

        typedef BoundNative T;
        typedef MethodTo< InCa, const T, int (), &T::getInt > MemInCa;
        typedef MethodTo< Getter, const T, int (), &T::getInt > MemGet;
        typedef MethodTo< Setter, T, void (int), &T::setInt > MemSet;
        cb = MemInCa::Call;
        g = MemGet::Get;
        s = MemSet::Set;
    }
    @endcode

    This unconventional, but nonetheless interesting and arguably
    very readable/writable approach was first proposed by Coen
    Campman.
*/


namespace cvv8 {

    /** Convenience typedef, primarily to simplify usage of
        FunctionTo and friends.
    */
    typedef AccessorGetterType Getter;

    /** Convenience typedef, primarily to simplify usage of
        FunctionTo and friends.
    */
    typedef AccessorSetterType Setter;

    /**
        A tag type for use with VarTo.
    */
    struct Accessors : AccessorGetterType, AccessorSetterType {};

    /**
        A tag type for use with FunctionTo and friends.
    */
    struct InCaVoid {};

    /**
        Acts as a proxy for FunctionToInCa, FunctionToGetter and
        FunctionToSetter. Tag must be one of (InCa, InCaVoid,
        Getter, Setter). The other args are as documented for the
        aforementioned proxied types.
    */
    template <typename Tag, typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionTo;

    template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionTo< InCa, Sig, Func > : FunctionToInCa<Sig, Func>
    {};

    template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionTo< InCaVoid, Sig, Func > : FunctionToInCaVoid<Sig, Func>
    {};

    template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionTo< Getter, Sig, Func > : FunctionToGetter<Sig,Func>
    {};

    template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionTo< Setter, Sig, Func > : FunctionToSetter<Sig,Func>
    {};

    /**
        Acts as a proxy for VarToGetter and VarToSetter. Tag
        must be one of (Getter, Setter). The other args are
        as documented for VarToGetter and VarToSetter.
    */
    template <typename Tag, typename PropertyType, PropertyType * const SharedVar>
    struct VarTo;

    //! Behaves like VarToGetter.
    template <typename PropertyType, PropertyType * const SharedVar>
    struct VarTo< Getter, PropertyType,SharedVar> : VarToGetter<PropertyType,SharedVar>
    {};

    //! Behaves like VarToSetter.
    template <typename PropertyType, PropertyType * const SharedVar>
    struct VarTo< Setter, PropertyType,SharedVar> : VarToSetter<PropertyType,SharedVar>
    {};

    //! Behaves like VarToAccessors.
    template <typename PropertyType, PropertyType * const SharedVar>
    struct VarTo< Accessors, PropertyType,SharedVar> : VarToAccessors<PropertyType,SharedVar>
    {};

    /**
        Acts as a proxy for MethodToInCa, MethodToGetter and
        MethodToSetter (or their const cousins if T is
        const-qualified). Tag must be one of (InCa, InCaVoid,
        Getter, Setter). The other args are as documented for the
        aforementioned proxied types.
    */
    template <typename Tag, typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodTo;

    //! Behaves like MethodToInCa.
    template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodTo< InCa, T, Sig, Func > : MethodToInCa<T, Sig, Func>
    {};

    //! Behaves like MethodToInCaVoid.
    template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodTo< InCaVoid, T, Sig, Func > : MethodToInCaVoid<T, Sig, Func>
    {};

    //! Behaves like MethodToGetter.
    template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodTo< Getter, T, Sig, Func > : MethodToGetter<T,Sig,Func>
    {};

    //! Behaves like MethodToSetter.
    template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Func>
    struct MethodTo< Setter, T, Sig, Func > : MethodToSetter<T,Sig,Func>
    {};
}
/** LICENSE

    This software's source code, including accompanying documentation and
    demonstration applications, are licensed under the following
    conditions...

    The author (Stephan G. Beal [http://wanderinghorse.net/home/stephan/])
    explicitly disclaims copyright in all jurisdictions which recognize
    such a disclaimer. In such jurisdictions, this software is released
    into the Public Domain.

    In jurisdictions which do not recognize Public Domain property
    (e.g. Germany as of 2011), this software is Copyright (c) 2011
    by Stephan G. Beal, and is released under the terms of the MIT License
    (see below).

    In jurisdictions which recognize Public Domain property, the user of
    this software may choose to accept it either as 1) Public Domain, 2)
    under the conditions of the MIT License (see below), or 3) under the
    terms of dual Public Domain/MIT License conditions described here, as
    they choose.

    The MIT License is about as close to Public Domain as a license can
    get, and is described in clear, concise terms at:

    http://en.wikipedia.org/wiki/MIT_License

    The full text of the MIT License follows:

    --
    Copyright (c) 2011 Stephan G. Beal (http://wanderinghorse.net/home/stephan/)

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

    --END OF MIT LICENSE--

    For purposes of the above license, the term "Software" includes
    documentation and demonstration source code which accompanies
    this software. ("Accompanies" = is contained in the Software's
    primary public source code repository.)

*/

#endif /* CVV8_TO_X_HPP_INCLUDED */
