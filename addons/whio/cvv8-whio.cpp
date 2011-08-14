#include "cvv8-whio.hpp"
#include <cassert>
#include "cvv8/XTo.hpp"

namespace cvv8 { 
    //CVV8_TypeName_IMPL((whio::IOBase),"IOBase");

    CVV8_TypeName_IMPL((whio::StreamBase),"StreamBase");
    CVV8_TypeName_IMPL((whio::InStream),"InStream");
    //CVV8_TypeName_IMPL((whio::FileInStream),"FileInStream");
    CVV8_TypeName_IMPL((whio::OutStream),"OutStream");
    //CVV8_TypeName_IMPL((whio::FileOutStream),"FileOutStream");

    CVV8_TypeName_IMPL((whio::IODev),"IODev");
    //CVV8_TypeName_IMPL((whio::FileIODev),"FileIODev");
    //CVV8_TypeName_IMPL((whio::MemoryIODev),"MemoryIODev");
    //CVV8_TypeName_IMPL((whio::Subdevice),"Subdevice");
    //CVV8_TypeName_IMPL((whio::EPFS::PseudoFile),"PseudoFile");

    CVV8_TypeName_IMPL((whio::EPFS),"EPFS");

#if 0
    const void * ClassCreator_TypeID<whio::IODev>::Value = TypeName<whio::IODev>::Value;
    const void * ClassCreator_TypeID<whio::StreamBase>::Value = TypeName<whio::StreamBase>::Value;
#endif

    void ClassCreator_SetupBindings<whio::IODev>::Initialize( v8::Handle<v8::Object> const & dest )
    {
        typedef whio::IODev IOD;
        typedef ClassCreator<IOD> CCDev;
        CCDev & cc(CCDev::Instance());
        if( cc.IsSealed() )
        {
            cc.AddClassTo(TypeName<IOD>::Value, dest);
            return;
        }

#define CATCHER InCaCatcher_std
        cc
            ("clearError",
             CATCHER< MethodTo<InCa, IOD, int (), &IOD::clearError> >::Call )
            ("close", CCDev::DestroyObjectCallback )
            ("eof",
             CATCHER< MethodTo<InCa, IOD, bool (), &IOD::eof> >::Call )
            ("flush",
             CATCHER< MethodTo<InCa, IOD, int (), &IOD::flush> >::Call )
            ("iomode",
             CATCHER< MethodTo<InCa, IOD, whio_iomode_mask (), &IOD::iomode> >::Call )
            ("isClosed",
             MethodTo<InCa, const IOD, bool (), &IOD::isClosed>::Call )
            ("seek",
             CATCHER< MethodTo<InCa, IOD, whio_size_t (whio_off_t,int), &IOD::seek> >::Call )
            ("size",
             CATCHER< MethodTo<InCa, IOD, whio_size_t (), &IOD::size> >::Call )
            ("tell",
             CATCHER< MethodTo<InCa, IOD, whio_size_t (), &IOD::tell> >::Call )
            ("truncate",
             CATCHER< MethodTo<InCa, IOD, int (whio_off_t), &IOD::truncate> >::Call )
            ;
#undef CATCHER
        cc.AddClassTo(TypeName<IOD>::Value, dest);
        return;
    }

    template <typename StreamT>
    void SetupStreamBase(ClassCreator<StreamT> & cc)
    {
        typedef whio::StreamBase ST;
        typedef ClassCreator<ST> CC;
#define CATCHER InCaCatcher_std
        cc
            ("close", CC::DestroyObjectCallback )
            ("isGood",
             CATCHER< MethodTo<InCa, ST, bool (), &ST::isGood> >::Call )
            ("iomode",
             CATCHER< MethodTo<InCa, ST, whio_iomode_mask (), &ST::iomode> >::Call )
            ("isClosed",
             MethodTo<InCa, const ST, bool (), &ST::isClosed>::Call )
            ;
#undef CATCHER
        return;
    }

    void ClassCreator_SetupBindings<whio::StreamBase>::Initialize( v8::Handle<v8::Object> const & dest )
    {
        typedef whio::StreamBase ST;
        typedef ClassCreator<ST> CC;
        CC & cc(CC::Instance());
        if( cc.IsSealed() )
        {
            cc.AddClassTo(TypeName<ST>::Value, dest);
            return;
        }

#define CATCHER InCaCatcher_std
        cc
            ("close", CC::DestroyObjectCallback )
            ("isGood",
             CATCHER< MethodTo<InCa, ST, bool (), &ST::isGood> >::Call )
            ("iomode",
             CATCHER< MethodTo<InCa, ST, whio_iomode_mask (), &ST::iomode> >::Call )
            ("isClosed",
             MethodTo<InCa, const ST, bool (), &ST::isClosed>::Call )
            ;
#undef CATCHER
        cc.AddClassTo(TypeName<ST>::Value, dest);
        return;
    }
    
    
    void ClassCreator_SetupBindings<whio::OutStream>::Initialize( v8::Handle<v8::Object> const & dest )
    {
        typedef whio::OutStream ST;
        typedef ClassCreator<ST> CC;
        CC & cc(CC::Instance());
        if( cc.IsSealed() )
        {
            cc.AddClassTo(TypeName<ST>::Value, dest);
            return;
        }

        cc.Inherit<whio::StreamBase>();
#define CATCHER InCaCatcher_std
        cc
            ("flush",
             CATCHER< MethodTo<InCa, ST, int (), &ST::flush> >::Call )
            // TODO: write()
            ;
#undef CATCHER
        cc.AddClassTo(TypeName<ST>::Value, dest);
        return;
    }

    void ClassCreator_SetupBindings<whio::InStream>::Initialize( v8::Handle<v8::Object> const & dest )
    {
        typedef whio::InStream ST;
        typedef ClassCreator<ST> CC;
        CC & cc(CC::Instance());
        if( cc.IsSealed() )
        {
            cc.AddClassTo(TypeName<ST>::Value, dest);
            return;
        }
        cc.Inherit<whio::StreamBase>();
#define CATCHER InCaCatcher_std
        // TODO: read()
#undef CATCHER
        cc.AddClassTo(TypeName<ST>::Value, dest);
        return;
    }
    
    
namespace io {
    whio::IODev * Ctor_IODev_Memory::Call( v8::Arguments const &argv )
    {
        assert( Ctor_IODev_Memory()(argv) );
        uint32_t const sz = CastFromJS<uint32_t>(argv[0]);
        float const factor = (argv.Length()>1)
            ? CastFromJS<float>(argv[1])
            : 1.5;
        return new whio::MemoryIODev( sz, factor );
    }

    whio::IODev * Ctor_IODev_Subdev::Call( v8::Arguments const & argv )
    {
        assert( Ctor_IODev_Subdev()(argv) );
        whio::IODev * parent = CastFromJS<whio::IODev*>(argv[0]);
        assert( (NULL != parent) && "Argument validation should have failed!" );
        whio_size_t const low = CastFromJS<whio_size_t>(argv[1]);
        whio_size_t const high = CastFromJS<whio_size_t>(argv[2]);
        return new whio::Subdevice( *parent, low, high );
    }

    whio::IODev * Ctor_IODev_File::Call( v8::Arguments const & argv )
    {
        assert( Ctor_IODev_File()(argv) );
        ArgCaster<char const *> ac;
        char const * fn = ac.ToNative(argv[0]);
        if( !fn || !*fn )
        {
            throw new std::runtime_error("Filename ctor argument may not be empty.");
        }
        else if( 2 == argv.Length() )
        {// (String name, int mode)
            v8::Handle<v8::Value> const & a1( argv[1] );
            if( ValIs<v8::String>()( a1 ) )
            {
                ArgCaster<char const *> modeString;
                return new whio::FileIODev( fn, modeString.ToNative(a1) );
            }
            else
            {
                return new whio::FileIODev( fn, JSToInt32(a1) );
            }
        }
        else if( 3 == argv.Length() )
        {// (String name, int mode, ushort permissions)
            return new whio::FileIODev( fn,
                                        CastFromJS<int32_t>(argv[1]),
                                        CastFromJS<uint16_t>(argv[2]) );
        }
        else
        {
            throw std::runtime_error("Internal error: Ctor_IODev_File got arguments which should not have passed validation.");
        }
        return NULL /* cannot be reached but gcc apparently cannot see that. */;
    }

    whio::OutStream * Ctor_OutStream::Call( v8::Arguments const &argv )
    {
        assert( Ctor_OutStream()(argv) );
        v8::Handle<v8::Value> arg( argv[0] );
        if( ValIs<v8::String>()(arg) )
        { /* (String name, bool truncate) */
            ArgCaster<char const *> ac;
            char const * fileName = ac.ToNative(arg);
            return new whio::FileOutStream(fileName,
                                           JSToBool(argv[1]) );

        }
        else
        {/* (IODev ioDevice, bool takeOwnership) */
            whio::IODev * d = CastFromJS<whio::IODev>( arg );
            if( ! d )
            {
                throw std::runtime_error("Internal error: Ctor_OutStream got arguments which should not have passed validation.");
            }
            bool const take = JSToBool(argv[1]);
            whio::OutStream * rc = new whio::OutStream( *d, take );
            if( take )
            { /* d was disconnected from its handle by the ctor,
                 but now we apply slightly different ownership
                 semantics than for the C/C++ APIs...
              */
                typedef ClassCreator<whio::IODev> CCDev;
                CCDev::DestroyObject( arg );
            }
            return rc;
        }
    }

    whio::InStream * Ctor_InStream::Call( v8::Arguments const &argv )
    {
        assert( Ctor_InStream()(argv) );
        v8::Handle<v8::Value> arg( argv[0] );
        if( ValIs<v8::String>()(arg) )
        { /* (String name) */
            ArgCaster<char const *> ac;
            char const * fileName = ac.ToNative(arg);
            return new whio::FileInStream(fileName);
        }
        else
        {/* (IODev ioDevice, bool takeOwnership) */
            whio::IODev * d = CastFromJS<whio::IODev>( arg );
            if( ! d )
            {
                throw std::runtime_error("Internal error: Ctor_InStream got arguments which should not have passed validation.");
            }
            bool const take = JSToBool(argv[1]);
            whio::InStream * rc = new whio::InStream( *d, JSToBool(argv[1]) );
            if( take )
            { /* d was disconnected from its handle by the ctor,
                 but now we apply slightly different ownership
                 semantics than for the C/C++ APIs...
              */
                typedef ClassCreator<whio::IODev> CCDev;
                CCDev::DestroyObject( arg );
            }
            return rc;
        }
    }

    void SetupBindings( v8::Handle<v8::Object> dest )
    {
        char const * nsName = "whio";
        v8::Handle<v8::Object> ioObj( v8::Object::New() );
        v8::Handle<v8::Object> ioModes( v8::Object::New() );
#define JSTR(X) v8::String::New(X)

        ioObj->Set(JSTR("iomode"),ioModes);

#define M(X) ioObj->Set(JSTR(#X), v8::Integer::New(WHIO_MODE_ ## X))
        M(INVALID);
        M(UNKNOWN);
        M(READ);
        M(WRITE);
        M(RO);
        M(RW);
        M(WO);
        M(RWC);
        M(FLAG_ONLY);
        M(FLAG_CREATE);
        M(FLAG_EXCL);
        M(FLAG_TRUNCATE);
        M(FLAG_FAIL_IF_EXISTS);
        M(FLAG_APPEND);
#undef M
        ClassCreator<whio::StreamBase>::SetupBindings(ioObj);
        ClassCreator<whio::OutStream>::SetupBindings(ioObj);
        ClassCreator<whio::InStream>::SetupBindings(ioObj);
        ClassCreator<whio::IODev>::SetupBindings(ioObj);
#undef JSTR
        dest->Set( JSTR(nsName), ioObj );
        return;
    }

    
} // io namespace
} // cvv8 namespace


