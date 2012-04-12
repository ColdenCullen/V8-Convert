#include "cvv8/ClassCreator.hpp"
#include "PathFinder.hpp"
namespace cvv8 {
    CVV8_TypeName_DECL((PathFinder));

    template <>
    struct ClassCreator_InternalFields<PathFinder>
        : ClassCreator_InternalFields_Base<PathFinder>
    {};

    template <>
    struct ClassCreator_SearchPrototypeForThis<PathFinder> : Opt_Bool<true>
    {};

    template <>
    class ClassCreator_Factory<PathFinder>
    {
    public:
        typedef PathFinder * ReturnType;
        static ReturnType Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv );
        static void Delete( ReturnType obj );
    };

    template <>
    struct ClassCreator_WeakWrap<PathFinder>
    {
        typedef typename TypeInfo<PathFinder>::NativeHandle NativeHandle;
        static void PreWrap( v8::Persistent<v8::Object> const &, v8::Arguments const & );
        static void Wrap( v8::Persistent<v8::Object> const &, NativeHandle );
        static void Unwrap( v8::Handle<v8::Object> const &, NativeHandle );
    };

    template <>
    struct ClassCreator_SetupBindings<PathFinder>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };

    
    template <>
    struct JSToNative<PathFinder>
        : JSToNative_ClassCreator<PathFinder>
    {};

#if 0
    template <>
    struct NativeToJS<PathFinder> : NativeToJSMap<PathFinder>::NativeToJSImpl {};
#endif

    void SetupPathFinderBindings( v8::Handle<v8::Object> const & );
} /* namespace */

