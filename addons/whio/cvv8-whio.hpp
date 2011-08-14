/**
   INCOMPLETE! NOT YET EVEN CLOSE TO FINISHED!

   v8 bindings for various i/o facilities provided by libwhio.
*/
#if !defined(CVV8_WHIO_HPP_INCLUDED)
#define CVV8_WHIO_HPP_INCLUDED
#include <v8.h>
#include "whio_amalgamation_cpp.hpp"
#include "cvv8/convert.hpp"
#include "cvv8/arguments.hpp"
#include "cvv8/ClassCreator.hpp"
namespace cvv8 {


    //CVV8_TypeName_DECL((whio::IOBase));
   
    CVV8_TypeName_DECL((whio::StreamBase));
    CVV8_TypeName_DECL((whio::InStream));
    //CVV8_TypeName_DECL((whio::FileInStream));
    CVV8_TypeName_DECL((whio::OutStream));
    //CVV8_TypeName_DECL((whio::FileOutStream));

    CVV8_TypeName_DECL((whio::IODev));
    //CVV8_TypeName_DECL((whio::FileIODev));
    //CVV8_TypeName_DECL((whio::MemoryIODev));
    //CVV8_TypeName_DECL((whio::Subdevice));
    //CVV8_TypeName_DECL((whio::EPFS::PseudoFile));

    CVV8_TypeName_DECL((whio::EPFS));

    
    namespace io {
        void SetupBindings( v8::Handle<v8::Object> dest );
        template <typename T>
        struct ClassCreator_InternalFields_whio
            : ClassCreator_InternalFields_Base< T, 1, -1, 0 >
        {
        };

        struct Ctor_IODev_Memory
            : Argv_TypesMatch< CVV8_TYPELIST((whio_size_t,float)) >
        {
            static whio::IODev * Call( v8::Arguments const & );
        };

        struct Ctor_IODev_Subdev
            : Argv_TypesMatch< CVV8_TYPELIST((whio::IODev *,whio_size_t, whio_size_t)) >
        {
            static whio::IODev * Call( v8::Arguments const & );
        };

        struct Ctor_IODev_File
            : Argv_OrN< CVV8_TYPELIST((
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String,v8::String/*mode string*/)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String,int32_t/*mode flags*/)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String,int32_t/*mode flags*/, uint16_t/*permissions*/)) >
                                       )) >
        {
            static whio::IODev * Call( v8::Arguments const & );
        };
    } /* namespace io */

#define WHIO_INTERNAL_FIELDS(T) template <> \
    struct ClassCreator_InternalFields< T > \
        : io::ClassCreator_InternalFields_whio< T > \
    {}
    WHIO_INTERNAL_FIELDS(whio::IODev);
    WHIO_INTERNAL_FIELDS(whio::StreamBase);
    WHIO_INTERNAL_FIELDS(whio::InStream);
    WHIO_INTERNAL_FIELDS(whio::OutStream);
    WHIO_INTERNAL_FIELDS(whio::EPFS);

#undef WHIO_INTERNAL_FIELDS

#if 0
    template <>
    struct ClassCreator_TypeID< whio::IODev >
    {
        static const void * Value;
    };

    template <>
    struct ClassCreator_TypeID< whio::StreamBase >
    {
        static const void * Value;
    };
#endif


    template <>
    struct ClassCreator_Factory<whio::IODev>
        : Detail::Factory_CtorForwarder_Base<whio::IODev>
    {
        static whio::IODev * Create( v8::Persistent<v8::Object> jself, v8::Arguments const &  argv );
    };

    template <>
    struct JSToNative<whio::IODev>
        : JSToNative_ClassCreator<whio::IODev>
    {};
    
} /* namespace cvv8 */

#endif /* include guard */

