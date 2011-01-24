#if !defined(CODE_GOOGLE_COM_P_V8_CONVERT_PROPERTIES_HPP_INCLUDED)
#define CODE_GOOGLE_COM_P_V8_CONVERT_PROPERTIES_HPP_INCLUDED 1

#include "invocable.hpp"

namespace v8 { namespace convert {
    /**
       A helper class for binding JS properties to native code, in particular
       for when JS objects are bound to native T objects.

       It contains utility functions to simplify the process of binding
       JS properties to native member functions or native properties.
       
       Requirements:

       - T must be of class type.

       - JSToNative<T> must be implemented for T.

       - TypeInfo<T>::NativeHandle must be usable in a boolean context
       to determine whether the JS-to-Native converted object is null
       or not.

       - The JS class to which members are bound using this approach
       must be set up so that it is actually wrapping T objects.
       i.e. this class only works with "fully bound" native classes,
       and not with arbitrary JS objects.
    */
    template <typename T>
    struct PropertyBinder
    {
        typedef typename TypeInfo<T>::Type Type;
        typedef typename JSToNative<T>::ResultType NativeHandle;

        /**
           This template can be used as an argument to
           v8::ObjectTemplate::SetAccessor()'s Getter parameter to
           generically tie a native member variable to a named JS
           property.

           Requirements:

           - Type must be convertible to NativeHandle via CastFromJS<NativeHandle>().

           - PropertyType must be convertible via CastToJS<PropertyType>().

           If the underlying native This object cannot be found (that
           is, if CastFromJS<NativeHandle>() fails) then this routine will
           trigger a JS exception.

           Example:

           Assume we have a native type Foo with a std::string member
           called str. We can bind the member variable with:

           \code
           myObjectTemplate.SetAccessor("foo",
           MemVarGetter<Foo,std::string,&Foo::str>,
           MemVarSetter<Foo,std::string,&Foo::str> );
           \endcode

           In 10 years of C++ coding, this is the first time i've ever
           had a use for a pointer-to-member.
        */
        template <typename PropertyType, PropertyType Type::*MemVar>
        static v8::Handle<v8::Value> MemVarGetter(v8::Local<v8::String> property, const v8::AccessorInfo &info)
        {
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( ! self ) return v8::ThrowException( StringBuffer() << "Native member property setter '"
                                                    << property << "' could not access native This object!" );
            try
            {
                return CastToJS( (self->*MemVar) );
            }
            catch( std::exception const & ex )
            {
                return CastToJS( ex );
            }
            catch( ... )
            {
                return ::v8::ThrowException( ::v8::String::New("Native member property getter threw an unknown native exception type!"));
            }
        }

        /**
           This is the Setter counterpart of MemVarGetter(). See
           that function for most of the details.

           Requirements:

           - MemVar must be an accessible member of Type.
           - PropertyType must be convertible via CastFromJS<PropertyType>().

           If the underlying native This object cannot be found then this
           routine will trigger a JS exception, though it is currently
           unclear whether this is actually legal in v8 (and difficult to
           test, since the native bindings work so well ;).
        */
        template <typename PropertyType, PropertyType Type::*MemVar>
        static void MemVarSetter(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
        {
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( self )
            {
                self->*MemVar = CastFromJS<PropertyType>( value );
            }
            else
            {
                v8::ThrowException( StringBuffer() << "Native member property setter '"
                                    << property << "' could not access native This object!" );
            }
        }

        /**
           This template can be used as an argument to
           v8::ObjectTemplate::SetAccessor()'s Getter parameter to
           generically tie a static variable to a named JS property.

           SharedVar must be pointer to a static variable and must not
           be 0.

           CastToJS<PropertyType>() must be legal.
        */
        template <typename PropertyType, PropertyType const * SharedVar>
        static v8::Handle<v8::Value> StaticVarGetter(v8::Local<v8::String> property, const AccessorInfo &info)
        {
            return CastToJS<PropertyType>( *SharedVar );
        }
        /**
           The setter counterpart of StaticVarGetter().

           SharedVar must be pointer to a static variable and must not
           be 0.

           CastFromJS<PropertyType> must be legal.
        */
        template <typename PropertyType, PropertyType * SharedVar>
        static void StaticVarSetter(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
        {
            *SharedVar = CastFromJS<PropertyType>( value );
        }

        /**
           Binds the given static variable to a JS property, such that
           get/set access will go through
           StaticVarGetter<VarType,SharedVar> and
           StaticVarSetter<VarType,SharedVar>.
        */
        template <typename VarType, VarType * SharedVar>
        static void BindStaticVar( char const * name,
                                   v8::Handle<v8::ObjectTemplate> const & prototype,
                                   v8::AccessControl settings = v8::PROHIBITS_OVERWRITING,
                                   v8::PropertyAttribute attribute = v8::DontDelete
                         )
        {
            if( ! prototype.IsEmpty() )
            {
                prototype->SetAccessor( v8::String::New(name),
                                        StaticVarGetter<VarType,SharedVar>,
                                        StaticVarSetter<VarType,SharedVar>,
                                        v8::Handle< v8::Value >(),
                                        settings,
                                        attribute );
            }
        }

        /**
           A Setter implementation which always triggers a JS exception.
        */
        static void AccessorSetterThrow(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
        {
             ::v8::ThrowException(StringBuffer() <<
                                  "Native member property setter '"
                                  << property
                                  << "' is configured to throw an exception whem modifying "
                                  << "this read-only member.!");
        }

        /**
           Binds the given static variable to a JS property, such that
           read access will go through
           StaticVarGetter<VarType,SharedVar> and set access will be
           ignored (it will not change SharedVar).

           See BindMemVarRO() for the semantics of the throwOnSet
           parameter.
        */
        template <typename VarType, VarType const * SharedVar>
        static void BindStaticVarRO( char const * name,
                                     v8::Handle<v8::ObjectTemplate> const & prototype,
                                     bool throwOnSet = false,
                                     v8::AccessControl settings = v8::PROHIBITS_OVERWRITING,
                                     v8::PropertyAttribute attribute = v8::DontDelete
                         )
        {
            if( ! prototype.IsEmpty() )
            {
                prototype->SetAccessor( v8::String::New(name),
                                        StaticVarGetter<VarType,SharedVar>,
                                        throwOnSet ? AccessorSetterThrow : (v8::AccessorSetter)NULL,
                                        v8::Handle< v8::Value >(),
                                        throwOnSet ? v8::DEFAULT : v8::PROHIBITS_OVERWRITING,
                                        attribute );
            }
        }

        
        /**
           Binds automatically-generated getter/setter functions to the given
           member variable. See MemVarGetter() and MemVarSetter()
           for the requirements of the templatized types.

           If you only want to bind one of the getter OR the setter then
           use the 5-argument variant of Set() instead and pass MemVarGetter
           or MemVarGetter, as appropriate, to that function.
        */
        template <typename VarType, VarType Type::*MemVar>
        static void BindMemVar( char const * name,
                                v8::Handle<v8::ObjectTemplate> const & prototype,
                                v8::AccessControl settings = v8::PROHIBITS_OVERWRITING,
                                v8::PropertyAttribute attribute = v8::DontDelete
                         )
        {
            if( ! prototype.IsEmpty() )
            {
                prototype->SetAccessor( v8::String::New(name),
                                        MemVarGetter<VarType,MemVar>,
                                        MemVarSetter<VarType,MemVar>,
                                        v8::Handle< v8::Value >(),
                                        settings,
                                        attribute );
            }
        }

        /**
           Binds the given JS property to MemVar, such that read/get
           operations will work but write/set operations will be
           ignored (that is, will not affect the value returned by the
           getter).

           The throwOnSet parameter installs a custom setter which,
           when triggered, always throws a JS exception. If this value
           is false, no setter will be installed (and see the notes
           below). If you want v8-specified behaviours, pass false
           for this value.
           
           Achtung: the JS engine exhibits the following, slightly
           unintuitive behaviour, for values bound in this way. Assume
           that we have bound an integer member to JS with the name
           "roVar" and we do the following in JS:

           @code
           ++myobj.roVar;
           @endcode

           The return value of that statement is actually the
           incremented value, but myobj.roVar is not actually modified
           and its accessor-setter is not called. Since the exact
           semantics of things like how native accessor proxies work
           are an unspecified part of the ECMAScript standard, we
           cannot complain that what v8 does here is "wrong" (it could
           arguably throw a JS exception in that case).
        */
        template <typename VarType, VarType Type::*MemVar>
        static void BindMemVarRO( char const * name,
                                  v8::Handle<v8::ObjectTemplate> const & prototype,
                                  bool throwOnSet = false )
        {
            if( ! prototype.IsEmpty() )
            {
                prototype->SetAccessor( v8::String::New(name),
                                        MemVarGetter<VarType,MemVar>,
                                        throwOnSet ? AccessorSetterThrow : (v8::AccessorSetter)NULL,
                                        v8::Handle< v8::Value >(),
                                        throwOnSet ? v8::DEFAULT : v8::PROHIBITS_OVERWRITING,
                                        v8::DontDelete );
            }
        }
        /**
           Implements the v8::AccessorGetter interface to bind a JS
           member property to a native getter function. This function
           can be used as the getter parameter to
           v8::ObjectTemplate::SetAccessor().
        */
	template <typename RV, RV (Type::*Func)()>
        static v8::Handle<v8::Value> PropGetterFunc( Local< String > property, const AccessorInfo & info )
        {
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( ! self ) return v8::ThrowException( StringBuffer() << "Native member property setter '"
                                                    << property << "' could not access native This object!" );
            try
            {
                return convert::CastToJS( (self->*Func)() );
            }
            catch( std::exception const & ex )
            {
                return ::v8::ThrowException( ::v8::String::New(ex.what()) );
            }
            catch( ... )
            {
                ::v8::ThrowException( StringBuffer() << "Native member property setter '"
                                      << property << " threw an unknown native exception type!");
            }
        }
        /**
           Overload for const native getter functions.
        */
	template <typename RV, RV (Type::*Func)() const>
        static v8::Handle<v8::Value> PropGetterFunc( Local< String > property, const AccessorInfo & info )
        {
            NativeHandle const self = CastFromJS<NativeHandle>( info.This() );
            if( ! self ) return v8::ThrowException( StringBuffer() << "Native member property setter '"
                                                    << property << "' could not access native This object!" );
            try
            {
                return convert::CastToJS( (self->*Func)() );
            }
            catch( std::exception const & ex )
            {
                return ::v8::ThrowException( ::v8::String::New(ex.what()) );
            }
            catch( ... )
            {
                ::v8::ThrowException( StringBuffer() << "Native member property setter '"
                                      << property << " threw an unknown native exception type!");
            }
        }

        /** Overload which takes a free function as the getter. */
	template <typename RV, RV (*Func)()>
        static v8::Handle<v8::Value> PropGetterFunc( Local< String > property, const AccessorInfo & info )
        {
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( ! self ) return v8::ThrowException( StringBuffer() << "Native member property setter '"
                                                    << property << "' could not access native This object!" );
            try
            {
                return convert::CastToJS( Func() );
            }
            catch( std::exception const & ex )
            {
                return ::v8::ThrowException( ::v8::String::New(ex.what()) );
            }
            catch( ... )
            {
                return ::v8::ThrowException( ::v8::String::New("Native property getter function threw an unknown native exception type!"));
            }
        }

#if 0 // TODO port this to v8::convert's conventions (the tmpl args should use function-ptr-style templates)
        /**
            Implements v8::AccessorSetter interface to proxy a JS
            member property through a native member setter function.

            The RV parameter is ignored by the conversion, and does
            not invoke a conversion operation.

             This function can be used as the setter parameter to
             v8::ObjectTemplate::SetAccessor().
        */
        template <typename RV, typename ArgT, RV (Type::*Func)(ArgT)>
        static void PropSetterFunc(v8::Local< v8::String > property, v8::Local< v8::Value > value, const v8::AccessorInfo &info)
        {
            NativeHandle self = CastFromJS<NativeHandle>( info.This() );
            if( ! self )
            {
                v8::ThrowException( StringBuffer() << "Native member property setter '"
                                    << property << "' could not access native This object!" ) );
                return;
            }
            else try
            { 
                (self->*Func)( CastFromJS<ArgT>( value ) );
            }
            catch( std::exception const & ex )
            {
                ::v8::ThrowException( ::v8::String::New(ex.what()) );
            }
            catch( ... )
            {
                ::v8::ThrowException( StringBuffer() << "Native member property setter '"
                                      << property << " threw an unknown native exception type!"));
            }
            return;
        }

        /**
           Binds the given JS property to a pair of T member
           functions, such that these functions will be called in
           place of get/set operations for the property.
           
           The native member functions must follow conventional
           accessor signatures:

           - Getter: T1 getter() [const]
           - Setter: [AnyType] setter( T2 )

           For the setter, T1 may differ from T2. T1 may be void but
           T2 may not be. Any return value from the setter is ignored
           by the JS engine.

           For the getter, an overload of this function is provided which
           supports a non-const getter.
         */
        template <typename RV,
                  RV (Type::*Getter)(),
                  typename SetRV,
                  typename ArgV,
                  SetRV (Type::*Setter)(ArgV)
            >
        static void BindGetterSetter( char const * propName, v8::Handle<v8::ObjectTemplate> const & prototype )
	{
            if( ! prototype.IsEmpty() )
                prototype->SetAccessor( v8::String::New( propName ),
                                        PropGetterFunc<RV,Getter>,
                                        PropSetterFunc<SetRV,ArgV,Setter>
                                        );
	}

        /**
           Overload to allow a const getter function. Member setter functions
           are not, by nature, const.
         */
        template <typename RV,
                  RV (Type::*Getter)() const,
                  typename SetRV,
                  typename ArgV,
                  SetRV (Type::*Setter)(ArgV)
            >
        static void BindGetterSetter( char const * propName, v8::Handle<v8::ObjectTemplate> const & prototype )
	{
            if( ! prototype.IsEmpty() )
                prototype->SetAccessor( v8::String::New( propName ),
                                        PropGetterFunc<RV,Getter>,
                                        PropSetterFunc<SetRV,ArgV,Setter>
                                        );
	}
#endif
        /**
           Binds the templatized getter function to the given JS property of the
           given prototype object, such that JS-side read access to the property
           will return the value of that member function.
         */
        template <typename RV, RV (Type::*Getter)()>
        static void BindGetter( char const * propName, v8::Handle<v8::ObjectTemplate> const & prototype )
	{
	    prototype->SetAccessor( v8::String::New( propName ),
                                   PropGetterFunc<RV,Getter> );
	}

        /**
           Overload too support const getters.
        */
        template <typename RV, RV (Type::*Getter)() const>
        static void BindGetter( char const * propName, v8::Handle<v8::ObjectTemplate> const & prototype )
	{
	    prototype->SetAccessor( v8::String::New( propName ),
                                   PropGetterFunc<RV,Getter> );
	}

        /**
           Overload too support free-function getters.
        */
        template <typename RV, RV (*Getter)()>
        static void BindGetter( char const * propName, v8::Handle<v8::ObjectTemplate> const & prototype )
	{
	    prototype->SetAccessor( v8::String::New( propName ),
                                    PropGetterFunc<RV,Getter> );
	}
    };

}} // namespaces

#endif /* CODE_GOOGLE_COM_P_V8_CONVERT_PROPERTIES_HPP_INCLUDED */
