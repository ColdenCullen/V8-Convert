/**
    v8 bindings for various i/o facilities provided by libwhio.

    Most of the whio C++ API is wrapped, but there are still a few
    gaps to fill.

    Notable TODOs:

    - whio::HashTable (but we'll restrict it to String keys/values).

    - A for-each-inode operation on whio::EPFS.

    License: Public Domain

    Author: Stephan Beal (http://wanderinghorse.net/home/stephan/)
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
    CVV8_TypeName_DECL((whio::EPFS::PseudoFile));

    CVV8_TypeName_DECL((whio::EPFS));


    /**
       whio/v8 bindings.
    */
    namespace io {

        /**
           Adds an object named "whio" to dest and adds all of the
           various whio bindings to the "whio" object. Throws a native
           exception for serious errors.
        */
        void SetupBindings( v8::Handle<v8::Object> dest );

        /**
           whio::MemoryIODev constructor wrapper.

           Accepts calls in these forms:

           (uint size [, float expansionFactor=some value >1.0])
        */
        struct Ctor_IODev_Memory
            : Argv_OrN< CVV8_TYPELIST((
                                       Argv_TypesMatch< CVV8_TYPELIST((whio_size_t,float)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((whio_size_t)) >
                                       )) >
        {
            static whio::IODev * Call( v8::Arguments const & );
        };

        /**
           whio::Subdevice constructor wrapper.

           Accepts calls in this form:

           (IODev parent, uint low, uint high)

        */
        struct Ctor_IODev_Subdev
            : Argv_TypesMatch< CVV8_TYPELIST((whio::IODev *,whio_size_t, whio_size_t)) >
        {
            static whio::IODev * Call( v8::Arguments const & );
        };

        /**
           whio::FileIODev constructor wrapper.

           Accepts calls in these forms:

           (String fname, String mode)

           (String fname, int mode [,int unixPermissions] )

           The String mode should be as for fopen(3). The int mode
           must be a mask of WHIO_MODE_xxx flags (available in JS via
           whio.iomode).
        */
        struct Ctor_IODev_File
            : Argv_OrN< CVV8_TYPELIST((
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String,v8::String/*mode string*/)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String,int32_t/*mode flags*/)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String,int32_t/*mode flags*/, uint16_t/*permissions*/)) >
                                       )) >
        {
            static whio::IODev * Call( v8::Arguments const & );
        };

        /**
           whio::InStream constructor wrapper.

           Accepts calls in these forms:

           (String fname)

           (IODev dev, bool takeOwnership)

           For the (IODev,bool) form, if takeOwnership is true,
           ownership of the underlying device handle is passed to the
           new stream object and the "origin" device (which is just a
           thin wrapper around the underlying handle) is destroyed
           immediately (to keep the client from having to
           (non-intuitively) close() it after passing on ownership).
           Note that this behaviour is different from the C++ API.
        */
        struct Ctor_InStream
            : Argv_OrN< CVV8_TYPELIST((
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((whio::IODev *,bool)) >
                                       )) >
        {
            static whio::InStream * Call( v8::Arguments const & );
        };

        /**
           whio::OutStream constructor wrapper.

           Accepts calls in these forms:

           (String fname, bool truncate)

           (IODev dev, bool takeOwnership)

           For the (IODev,bool) form, if takeOwnership is true,
           ownership of the underlying device handle is passed to the
           new stream object and the "origin" device (which is just a
           thin wrapper around the underlying handle) is destroyed
           immediately (to keep the client from having to
           (non-intuitively) close() it after passing on ownership).
           Note that this behaviour is different from the C++ API.
        */
        struct Ctor_OutStream
            : Argv_OrN< CVV8_TYPELIST((
                                       Argv_TypesMatch< CVV8_TYPELIST((v8::String, bool)) >,
                                       Argv_TypesMatch< CVV8_TYPELIST((whio::IODev *,bool)) >
                                       )) >
        {
            static whio::OutStream * Call( v8::Arguments const & );
        };


    } /* namespace io */

    template <>
    struct ClassCreator_InternalFields< whio::IODev >
        : ClassCreator_InternalFields_Base< whio::IODev, 1, -1, 0 >
    {};

    template <>
    struct ClassCreator_InternalFields< whio::StreamBase >
        : ClassCreator_InternalFields_Base< whio::IODev, 1, -1, 0 >
    {};

    template <>
    struct ClassCreator_InternalFields< whio::InStream >
        : ClassCreator_InternalFields< whio::StreamBase >
    {};

    template <>
    struct ClassCreator_InternalFields< whio::OutStream >
        : ClassCreator_InternalFields< whio::StreamBase >
    {};

    template <>
    struct ClassCreator_InternalFields< whio::EPFS >
        : ClassCreator_InternalFields_Base< whio::EPFS >
    {};

    template <>
    struct ClassCreator_InternalFields< whio::EPFS::PseudoFile >
        : ClassCreator_InternalFields< whio::IODev >
    {};

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
        : ClassCreator_Factory_Dispatcher<
        whio::IODev,
        PredicatedCtorDispatcher<
            Signature< whio::IODev *(
                                     io::Ctor_IODev_Memory,
                                     io::Ctor_IODev_Subdev,
                                     io::Ctor_IODev_File
                                     )
                >
            >
        >
    {};

    template <>
    struct JSToNative<whio::IODev>
        : JSToNative_ClassCreator<whio::IODev>
    {};

    template <>
    struct ClassCreator_SetupBindings<whio::IODev>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };

    template <>
    struct ClassCreator_Factory<whio::StreamBase>
        : ClassCreator_Factory_Abstract<whio::StreamBase>
    {};

    template <>
    struct JSToNative<whio::StreamBase>
        : JSToNative_ClassCreator<whio::StreamBase>
    {};

    template <>
    struct ClassCreator_SetupBindings<whio::StreamBase>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };
    
    template <>
    struct ClassCreator_Factory<whio::InStream>
        : ClassCreator_Factory_Dispatcher<
        whio::InStream,
        PredicatedCtorDispatcher< Signature<whio::InStream *(io::Ctor_InStream)> >
        >
    {};

    template <>
    struct JSToNative<whio::InStream>
        : JSToNative_ClassCreator<whio::InStream>
    {};

    template <>
    struct ClassCreator_SetupBindings<whio::InStream>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };


    template <>
    struct ClassCreator_Factory<whio::OutStream>
        : ClassCreator_Factory_Dispatcher<
        whio::OutStream,
        PredicatedCtorDispatcher< Signature<whio::OutStream *(io::Ctor_OutStream)> >
        >
    {};

    template <>
    struct JSToNative<whio::OutStream>
        : JSToNative_ClassCreator<whio::OutStream>
    {};

    template <>
    struct ClassCreator_SetupBindings<whio::OutStream>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };

    
    template <>
    class ClassCreator_Factory<whio::EPFS>
    {
    public:
        typedef whio::EPFS * ReturnType;
        static ReturnType Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv );
        static void Delete( whio::EPFS * obj );
    };

    template <>
    struct JSToNative<whio::EPFS>
        : JSToNative_ClassCreator<whio::EPFS>
    {};

    template <>
    struct ClassCreator_SetupBindings<whio::EPFS>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };

    template <>
    class ClassCreator_Factory<whio::EPFS::PseudoFile>
    {
    public:
        typedef whio::EPFS::PseudoFile * ReturnType;
        static ReturnType Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv );
        static void Delete( whio::EPFS::PseudoFile * obj );
    };

    template <>
    struct JSToNative<whio::EPFS::PseudoFile>
        : JSToNative_ClassCreator<whio::EPFS::PseudoFile>
    {};

    template <>
    struct ClassCreator_SetupBindings<whio::EPFS::PseudoFile>
    {
        static void Initialize( v8::Handle<v8::Object> const & target );
    };

    
    template <>
    struct NativeToJS<whio_epfs_fsopt>
    {
        /**
           Creates a new Object containing the properties (inodeCount,
           maxBlocks, blockSize), taken from opt. Note that changes to
           the returned object do not modify the native copy.
        */
        v8::Handle<v8::Value> operator()( whio_epfs_fsopt const & opt ) const;
        v8::Handle<v8::Value> operator()( whio_epfs_fsopt const * opt ) const
        {
            if( opt ) return this->operator()( *opt );
            else return v8::Null();
        }
    };

    template <>
    struct JSToNative<whio_epfs_fsopt>
    {
        typedef whio_epfs_fsopt ResultType;
        /**
           If h is-a Object then the properties (inodeCount,
           maxBlocks, blockSize) are extracted and copied into a
           whio_epfs_fsopt object, which is returned. Remember that a
           value of 0 for either the whio_epfs_fsopt::inodeCount or
           the whio_epfs_fsopt::blockSize is illegal, and probably
           means that the given handle did not contain the given
           properties.
        */
        ResultType operator()( v8::Handle<v8::Value> const & h ) const;
    };
    
} /* namespace cvv8 */

#endif /* include guard */
