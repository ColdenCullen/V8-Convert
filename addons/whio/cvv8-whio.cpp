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

    whio::IODev * ClassCreator_Factory<whio::IODev>::Create( v8::Persistent<v8::Object> jself, v8::Arguments const &  argv )
    {
        typedef Signature< whio::IODev *(
                                         io::Ctor_IODev_Memory,
                                         io::Ctor_IODev_Subdev,
                                         io::Ctor_IODev_File
                                         ) >
            CtorList;
        typedef PredicatedCtorDispatcher< CtorList > Ctor;
        return Ctor::Call(argv);
    }

namespace io {
    whio::IODev * Ctor_IODev_Memory::Call( v8::Arguments const &argv )
    {
        assert( Ctor_IODev_Memory()(argv) );
        uint32_t const sz = CastFromJS<uint32_t>(argv[0]);
        float const factor = CastFromJS<float>(argv[1]);
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
        {// (name,mode)
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
        {// (name,mode,permissions)
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


    void SetupBindings( v8::Handle<v8::Object> dest )
    {
        typedef whio::IODev IOD;
        typedef ClassCreator<IOD> CCDev;
        char const * nsName = "whio";
        v8::Handle<v8::Object> ioObj( v8::Object::New() );
        
        CCDev & ccDev(CCDev::Instance());
        if( ccDev.IsSealed() )
        {
            ccDev.AddClassTo(TypeName<IOD>::Value, ioObj);
            dest->Set( v8::String::New(nsName),ioObj );
            return;
        }

#define CATCHER InCaCatcher_std
        ccDev
            ("close", CCDev::DestroyObjectCallback )
            ("eof",
             CATCHER< MethodTo<InCa, IOD, bool (), &IOD::eof> >::Call )
            ("flush",
             MethodTo<InCa, IOD, int (), &IOD::flush>::Call )
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
        ccDev.AddClassTo(TypeName<IOD>::Value, ioObj);
        dest->Set( v8::String::New(nsName), ioObj );
        return;
    }

    
} // io namespace
} // cvv8 namespace


