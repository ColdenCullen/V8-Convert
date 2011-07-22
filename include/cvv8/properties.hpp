#if !defined(CODE_GOOGLE_COM_P_V8_CONVERT_PROPERTIES_HPP_INCLUDED)
#define CODE_GOOGLE_COM_P_V8_CONVERT_PROPERTIES_HPP_INCLUDED 1


#include "invocable.hpp"

namespace cvv8 {

    /**
        Marker class, primarily for documentation purposes.
        
        This class models the v8::AccessorGetter interface, and
        XyzToGetter classes inherit this type as a sign that they
        implement this interface.
        
        This class has no implemention - it only exists for 
        documentation purposes.
    */
    struct AccessorGetterType
    {
        /** The v8::AccessorGetter() interface.
        */
        static v8::Handle<v8::Value> Get(v8::Local<v8::String> property, const v8::AccessorInfo &info);
    };

    /**
        Marker class, primarily for documentation purposes.
        
        This class models the v8::AccessorSetter interface, and
        XyzToSetter classes inherit this type as a sign that they
        implement this interface.
        
        This class has no implemention - it only exists for 
        documentation purposes.
    */
    struct AccessorSetterType
    {
        /** The v8::AccessorSetter() interface. */
        static void Set(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    };

    /**
       This template create an v8::AccessorGetter from a static/shared
       variable.

       SharedVar must be pointer to a static variable and must not
       be NULL.

       CastToJS(*SharedVar) must be legal.
    */
    template <typename PropertyType, PropertyType * const SharedVar>
    struct VarToGetter : AccessorGetterType
    {
        /** Implements the v8::AccessorGetter() interface. */
        static v8::Handle<v8::Value> Get(v8::Local<v8::String> property, const v8::AccessorInfo &info)
        {
            return CastToJS( *SharedVar );
        }
    };

    /**
       The setter counterpart of StaticVarToGetter().

       SharedVar must be pointer to a static variable and must not
       be NULL.

       (*SharedVar = CastFromJS<PropertyType>()) must be legal.
       
       Reminder: this is not included in the StaticVarToGetter 
       template so that we can avoid either the Get or Set 
       conversion for cases where it is not legal (or not desired). 
       If they were both in one class, both Get and Set would _have_ 
       to be legal.
    */
    template <typename PropertyType, PropertyType * const SharedVar>
    struct VarToSetter : AccessorSetterType
    {
        /** Implements the v8::AccessorSetter() interface. */
        static void Set(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
        {
            *SharedVar = CastFromJS<PropertyType>( value );
        }
    };


    /**
       This template creates a v8::AcessorGetter which binds directly to
       a non-const native class member variable.

       Requirements:

       - T must be convertible to (T*) via CastFromJS<T>().
       - MemVar must be an accessible member of T.
       - PropertyType must be convertible via CastToJS<PropertyType>().

       If the underlying native 'this' object cannot be found (that
       is, if CastFromJS<T>() fails) then this routine will
       trigger a JS exception.
    */
    template <typename T, typename PropertyType, PropertyType T::*MemVar>
    struct MemberToGetter : AccessorGetterType
    {
        /** Implements the v8::AccessorGetter() interface. */
        static v8::Handle<v8::Value> Get(v8::Local<v8::String> property, const v8::AccessorInfo &info)
        {
            typedef typename TypeInfo<T>::Type Type;
            typedef typename JSToNative<T>::ResultType NativeHandle;
            NativeHandle self = CastFromJS<T>( info.This() );
            return ( ! self )
                ? Toss( StringBuffer() << "Native member property getter '"
                        << property << "' could not access native 'this' object!" )
                : CastToJS( (self->*MemVar) );
        }
    };
    
    /**
       This is the Setter counterpart of MemberToGetter.

       Requirements:

       - T must be convertible to (T*) via CastFromJS<T>().
       - PropertyType must be convertible via CastToJS<PropertyType>().
       - MemVar must be an accessible member of T.

       If the underlying native This object cannot be found then this
       routine will trigger a JS exception.
    */
    template <typename T, typename PropertyType, PropertyType T::*MemVar>
    struct MemberToSetter : AccessorSetterType
    {
        /** Implements the v8::AccessorSetter() interface. */
        static void Set(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
        {
            typedef typename TypeInfo<T>::Type Type;
            typedef typename JSToNative<T>::ResultType NativeHandle;
            NativeHandle self = CastFromJS<T>( info.This() );
            if( self ) self->*MemVar = CastFromJS<PropertyType>( value );
            else Toss( StringBuffer() << "Native member property setter '"
                        << property << "' could not access native 'this'his object!" );
        }
    };

    /**
       An AccessorSetter() implementation which always triggers a JS exception.
       Can be used to enforce "pedantically read-only" variables. Note that
       JS does not allow us to assign an AccessorSetter _without_ assigning
       an AccessorGetter. Also note that there is no AccessorGetterThrow,
       because a write-only var doesn't make all that much sense (use
       methods for those use cases).
    */
    struct ThrowingSetter : AccessorSetterType
    {
        static void Set(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
        {
             Toss(StringBuffer() <<
                  "Native member property setter '"
                  << property
                  << "' is configured to throw an exception when modifying "
                  << "this read-only member!");
        }
    };

    /**
       Implements the v8::AccessorGetter interface to bind a JS
       member property to a native getter function. This function
       can be used as the getter parameter to
       v8::ObjectTemplate::SetAccessor().

       Sig must be a function-signature-style type and Getter must
       capable of being called with no arguments and returning a
       value which can be CastToJS() to a JS value.

       If Getter() throws a native exception it is converted to a JS
       exception.
    */
    template <typename Sig, typename FunctionSignature<Sig>::FunctionType Getter>
    struct FunctionToGetter : AccessorGetterType
    {
        static v8::Handle<v8::Value> Get( v8::Local< v8::String > property, const v8::AccessorInfo & info )
        {
            /*
                FIXME: remove the try/catch and move it into a higher-level wrapper
                analog to InCaCatcher. e.g SetterCatcher and GetterCatcher.
            */
            try
            {
                return CastToJS( (*Getter)() );
            }
            catch( std::exception const & ex )
            {
                return Toss(CastToJS(ex));
            }
            catch( ... )
            {
                return Toss( StringBuffer() << "Native value property getter '"
                             << property << "' threw an unknown native exception type!");
            }
        }
    };
       
    /**
       Implements the v8::AccessorSetter interface to bind a JS
       member property to a native getter function. This function
       can be used as the getter parameter to
       v8::ObjectTemplate::SetAccessor().

       SigSet must be function-signature-style pattern
       for the setter function. The native
       function must follow conventional mutator signature:

       ReturnType ( PropertyType )

       PropertyType may differ from the return type. PropertyType
       may not be void but the ReturnType may be. Any return value
       from the setter is ignored by the JS engine.

       Note that the v8 API appears to not allow us to just set
       a setter, but not a getter. We have to set a getter without
       a setter, a getter with a setter, or neither. At least that's
       been my experience.

       If Setter() throws a native exception it is converted to a JS
       exception.
    */
    template <typename Sig, typename FunctionSignature<Sig>::FunctionType Func>
    struct FunctionToSetter : AccessorSetterType
    {
        static void Set( v8::Local< v8::String > property, v8::Local< v8::Value > value, const v8::AccessorInfo &info)
        {
            /* FIXME: see FunctionToGetter::Get for info about the future of this exception handling. */
            try
            {
                typedef FunctionSignature<Sig> FT;
                (*Func)( CastFromJS<typename sl::At<0,FT>::Type>( value ) );
            }
            catch( std::exception const & ex )
            {
                Toss(CastToJS(ex));
            }
            catch( ... )
            {
                Toss( StringBuffer() << "Native member property setter '"
                      << property << "' threw an unknown native exception type!");
            }
            return;
        }
    };



    /**
       Implements the v8::AccessorGetter interface to bind a JS
       member property to a native getter function. This function
       can be used as the getter parameter to
       v8::ObjectTemplate::SetAccessor().

       Sig must be a function-pointer-style argument with a
       non-void return type convertible to v8 via CastToJS(), and
       Getter must be function capable of being called with 0
       arguments (either because it has none or they have
       defaults).
    */
    template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Getter>
    struct MethodToGetter : AccessorGetterType
    {
        static v8::Handle<v8::Value> Get( v8::Local< v8::String > property, const v8::AccessorInfo & info )
        {
            typedef typename TypeInfo<T>::Type Type;
            typedef typename JSToNative<T>::ResultType NativeHandle;
            NativeHandle self = CastFromJS<T>( info.This() );
            if( ! self ) return Toss( StringBuffer() << "Native member property getter '"
                                      << property << "' could not access native This object!" );
            /* FIXME: see FunctionToGetter::Get regarding the exception handling. */
            try
            {
                return CastToJS( (self->*Getter)() );
            }
            catch( std::exception const & ex )
            {
                return CastToJS(ex);
            }
            catch( ... )
            {
                return Toss( StringBuffer() << "Native member property getter '"
                             << property
                             << "' threw an unknown native exception type!" );
            }
        }
    };

   /**
       Overload for const native getter functions.
    */
    template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType Getter>
    struct ConstMethodToGetter : AccessorGetterType
    {
        static v8::Handle<v8::Value> Get( v8::Local< v8::String > property, const v8::AccessorInfo & info )
        {
            typedef typename TypeInfo<T>::Type Type;
            typedef typename JSToNative<T>::ResultType NativeHandle;
            NativeHandle const self = CastFromJS<T>( info.This() );
            if( ! self ) return Toss( (StringBuffer() << "Native member property getter '"
                                       << property << "' could not access native This object!").toError() );
            /* FIXME: see FunctionToGetter::Get regarding the exception handling. */
            try
            {
                return CastToJS( (self->*Getter)() );
            }
            catch( std::exception const & ex )
            {
                return Toss(CastToJS(ex));
            }
            catch( ... )
            {
                return Toss( StringBuffer()
                             << "Native member property getter '"
                             << property
                             << "' threw an unknown native exception type!" );
            }
        }
    };
    
    /**
        Implements v8::AccessorSetter interface to proxy a JS
        member property through a native member setter function.

        This function can be used as the setter parameter to
        v8::ObjectTemplate::SetAccessor().

        Sig must be a function-pointer-style type and Getter must
        be a T member function of that type. The function must be
        capable of being called with only 1 argument (either
        because it only accepts 1 or has defaults for the others),
        and its return value is discarded (not converted to v8)
        because that's how v8's native setters work.

        Exceptions thrown by the underlying function are
        translated to JS exceptions.
        
        FIXME: code is 100% identical to ConstMethodToSetter except 
        for FunctionType typedef. Consolidate them in a base class.
    */
    template <typename T, typename Sig, typename MethodSignature<T,Sig>::FunctionType Setter>
    struct MethodToSetter : AccessorSetterType
    {
        static void Set(v8::Local< v8::String > property, v8::Local< v8::Value > value, const v8::AccessorInfo &info)
        {
            typedef typename TypeInfo<T>::Type Type;
            typedef typename JSToNative<T>::ResultType NativeHandle;
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( ! self )
            {
                Toss( StringBuffer() << "Native member property setter '"
                     << property << "' could not access native This object!" );
                return;
            }
            else try /* FIXME: see FunctionToGetter for details about exception handling. */
            {

                typedef typename sl::At< 0, Signature<Sig> >::Type ArgT;
                (self->*Setter)( CastFromJS<ArgT>( value ) );
            }
            catch( std::exception const & ex )
            {
                Toss(CastToJS(ex));
            }
            catch( ... )
            {
                Toss( StringBuffer() << "Native member property setter '"
                      << property << "' threw an unknown native exception type!");
            }
            return;
        }
    };
    /**
        Const-method equivalent of MethodToSetter.
    
        FIXME: code is 100% identical to ConstMethodToSetter except 
        for FunctionType typedef. Consolidate them in a base class.
    */
    template <typename T, typename Sig, typename ConstMethodSignature<T,Sig>::FunctionType Setter>
    struct ConstMethodToSetter : AccessorSetterType
    {
        static void Set(v8::Local< v8::String > property, v8::Local< v8::Value > value, const v8::AccessorInfo &info)
        {
            typedef typename TypeInfo<T>::Type Type;
            typedef typename JSToNative<T>::ResultType NativeHandle;
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( ! self )
            {
                Toss( StringBuffer() << "Native member property setter '"
                     << property << "' could not access native This object!" );
                return;
            }
            else try /* FIXME: see FunctionToGetter for details about exception handling. */
            {

                typedef typename sl::At< 0, Signature<Sig> >::Type ArgT;
                (self->*Setter)( CastFromJS<ArgT>( value ) );
            }
            catch( std::exception const & ex )
            {
                Toss(CastToJS(ex));
            }
            catch( ... )
            {
                Toss( StringBuffer() << "Native member property setter '"
                      << property << "' threw an unknown native exception type!");
            }
            return;
        }
    };

} // namespaces
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
#endif /* CODE_GOOGLE_COM_P_V8_CONVERT_PROPERTIES_HPP_INCLUDED */
