
#include "cvv8-PathFinder.hpp"
#include "cvv8/XTo.hpp"
#include "cvv8/properties.hpp"
namespace cvv8 {
    CVV8_TypeName_IMPL((PathFinder),"PathFinder");

#if 0 /* needed? */
    template <>
    const void * ClassCreator_TypeID<PathFinder>::Value = TypeName<PathFinder>::Value;
#endif

    void ClassCreator_WeakWrap<PathFinder>::PreWrap( v8::Persistent<v8::Object> const &, v8::Arguments const & ){
        return;
    }
    void ClassCreator_WeakWrap<PathFinder>::Wrap( v8::Persistent<v8::Object> const &, NativeHandle ){
        return;
    }
    void ClassCreator_WeakWrap<PathFinder>::Unwrap( v8::Handle<v8::Object> const &, NativeHandle ){
        return;
    }

    ClassCreator_Factory<PathFinder>::ReturnType
    ClassCreator_Factory<PathFinder>::Create(v8::Persistent<v8::Object> &, v8::Arguments const & argv ){
        int argc = argv.Length();
        std::string a0 = (argc>0) ? CastFromJS<std::string>(argv[0]) : "";
        std::string a1 = (argc>1) ? CastFromJS<std::string>(argv[1]) : "";
        std::string a2 = (argc>2) ? CastFromJS<std::string>(argv[2]) : ":";
        PathFinder * pf = new PathFinder(a0, a1, a2);
        return pf;
    }

    void ClassCreator_Factory<PathFinder>::Delete( PathFinder * obj ){
        if(obj) delete obj;
    }

    static v8::Handle<v8::Value> pf_toString( v8::Arguments const & argv )
    {
        typedef PathFinder T;
        T * p = CastFromJS<T>( argv.This() );
        StringBuffer sb;
        sb << "[object "<<TypeName<T>::Value<<"@"<<p<<"]";
        return sb;
    }


    template <>
    struct JSToNative<PathFinder::StringList> : JSToNative_list<PathFinder::StringList> {};
    template <>
    struct NativeToJS<PathFinder::StringList const &> : NativeToJS<PathFinder::StringList> {};
    
    void ClassCreator_SetupBindings<PathFinder>::Initialize( v8::Handle<v8::Object> const & target ) {
        typedef PathFinder T;
        typedef ClassCreator<T> CC;
        CC & cc( CC::Instance() );
        if( cc.IsSealed() ){
            cc.AddClassTo( TypeName<T>::Value, target );
            return;
        }

        typedef T::StringList SL;
        typedef SL const & SLCR;
#define CATCHER InCaCatcher_std /* convenience macro */

        // ADD YOUR BINDINGS HERE, e.g...
        cc
            ("destroy", CC::DestroyObjectCallback )
            ("addExtensionString",
             MethodTo<InCa, T, void (std::string const &), &T::AddExtension>::Call)
            ( "addPathString",
              MethodTo<InCa, T, void (std::string const &), &T::AddPath>::Call )
            ( "baseName",
              FunctionTo<InCa, std::string (std::string const &), T::BaseName>::Call )
            ( "clearCache",
              MethodTo<InCa, T, void (), &T::ClearCache>::Call )
            ( "search",
              MethodTo<InCa, T const, std::string (std::string const &), &T::Find>::Call )
            ( "isAccessible",
              FunctionTo<InCa, bool (std::string const &), T::IsAccessible>::Call )
            ( "isEmpty",
              MethodTo<InCa, T const, bool (), &T::IsEmpty>::Call )
            ( "getPathSeparator",
              MethodTo<InCa, T const, std::string (),&T::PathSeparator>::Call )
            ( "setPathSeparator",
              MethodTo<InCa, T, void (std::string const &) ,&T::PathSeparator>::Call )
            ( "getPathString",
              MethodTo<InCa, T const, std::string (),&T::PathString>::Call )
            ( "setPathString",
              MethodTo<InCa, T, size_t (std::string const &),&T::Path>::Call )
            ( "getPathArray",
              MethodTo<InCa, T const, SL (),&T::Path>::Call )
            ( "setPathArray",
              MethodTo<InCa, T, size_t (SLCR), &T::Path>::Call )
            ( "getExtensionsArray",
              MethodTo<InCa, T const, SL (),&T::Extensions>::Call )
            ( "setExtensionsArray",
              MethodTo<InCa, T, size_t (SLCR), &T::Extensions>::Call )
            ( "getExtensionsString",
              MethodTo<InCa, T const, std::string (),&T::ExtensionsString>::Call )
            ( "setExtensionsString",
              MethodTo<InCa, T, size_t (std::string const &),&T::Extensions>::Call )
            ( "toString",
              pf_toString)
            ;

#if 0
        // Proxy accessor/mutator functions as JS properties
        AccessorAdder acc( cc.Prototype() );
        acc
            ("x",
                MethodTo< Getter, T const, uint32_t (), &T::getX >::Get,
                MethodTo< Setter, T, void (uint32_t), &T::setX >::Set )
            ;
#endif

#if 0
        // Set up properties on the ctor...
        v8::Handle<v8::Function> ctor( cc.CtorFunction() );
        // then use ctor->Set() and friends.
        // These MUST come after your prototype-level bindings (don't ask me why)
#endif
#undef CATCHER        
        cc.AddClassTo( TypeName<T>::Value, target );
        return;

    }

    void SetupPathFinderBindings( v8::Handle<v8::Object> const & target) {
        ClassCreator_SetupBindings<PathFinder>::Initialize(target);
    }
} /* namespace */

