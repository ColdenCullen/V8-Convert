#if defined(NDEBUG)
#  undef NDEBUG
#endif

#include <cassert>
#include "cpdo_amalgamation.hpp"

#include "v8/convert/ClassCreator.hpp"
#include "v8/convert/properties.hpp"


#include <iostream> /* only for debuggering */
#ifndef CERR
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << ":" <<__FUNCTION__ << "(): "
#endif

#define JSTR(X) v8::String::New(X)

namespace cv = v8::convert;

/**
   The following code is mostly here for use with ClassCreator<>, a
   class-binding mechanism which is demonstrated in
   ConvertDemo.cpp. It mostly shows how to use ClassCreator<> policies
   to customize the ClassCreator bindings for a particular class.
*/
namespace v8 { namespace convert {
    /*
      This class is required unless you just want to bind to the
      default constructor. It creates native objects for the
      underlying binding code.
     */
    template <>
    class ClassCreator_Factory<cpdo::driver>
    {
    public:
        typedef cpdo::driver * ReturnType;
        static ReturnType Create( v8::Arguments const & argv );
        static void Delete( cpdo::driver * obj );
    };

    template <>
    class ClassCreator_Factory<cpdo::statement>
    {
    public:
        typedef cpdo::statement * ReturnType;
        static ReturnType Create( v8::Arguments const & argv );
        static void Delete( cpdo::statement * obj );
    };
    
    /**
       Required specialization so that the conversion API can derive
       the native 'this' object from v8::Arguments::This() and from
       function arguments of our bound type.
    */
    template <>
    struct JSToNative<cpdo::driver>
        : JSToNative_ClassCreator<cpdo::driver>
    {};
    template <>
    struct JSToNative<cpdo::statement>
        : JSToNative_ClassCreator<cpdo::statement>
    {};

    template <>
    struct NativeToJS<cpdo_data_type> : NativeToJS<int32_t> {};

} }

namespace v8 { namespace convert {
    cpdo::driver * ClassCreator_Factory<cpdo::driver>::Create( v8::Arguments const & argv )
    {
        if( argv.Length() < 1 )
        {
            throw std::range_error("The JSPDO constructor requires 1-3 arguments.");
        }
        std::string dsn = cv::CastFromJS<std::string>(argv[0]);
        std::string user = (argv.Length()>1) ? cv::CastFromJS<std::string>(argv[1]) : std::string();
        std::string pass = (argv.Length()>2) ? cv::CastFromJS<std::string>(argv[2]) : std::string();
        return new cpdo::driver( dsn.c_str(), user.c_str(), pass.c_str() );
    }
    void ClassCreator_Factory<cpdo::driver>::Delete( cpdo::driver * drv )
    {
        delete drv;
    }
    cpdo::statement * ClassCreator_Factory<cpdo::statement>::Create( v8::Arguments const & argv )
    {
        if( argv.Length() < 2 )
        {
            throw std::range_error("The JSPDO constructor requires 1-3 arguments.");
        }
        cpdo::driver * drv = cv::CastFromJS<cpdo::driver>(argv[0]);
        if( ! drv )
        {
            throw std::range_error("The Statement ctor must not be called directly from client code.");
        }
        return drv->prepare( cv::CastFromJS<std::string>(argv[1]) );
    }
    void ClassCreator_Factory<cpdo::statement>::Delete( cpdo::statement * drv )
    {
        delete drv;
    }

}}

namespace v8 { namespace convert {
}}

#define STMT_DECL(JVAL) cpdo::statement * st = cv::CastFromJS<cpdo::statement>(JVAL)
#define ASSERT_STMT_DECL(JVAL) STMT_DECL(JVAL); \
    if( ! st ) return v8::ThrowException(v8::Exception::Error(JSTR("Could not find native cpdo::statement 'this' object.")))
#define DRV_DECL(JVAL) cpdo::driver * drv = cv::CastFromJS<cpdo::driver>(JVAL)
#define ASSERT_DRV_DECL(JVAL) DRV_DECL(JVAL); \
    if( ! drv ) return v8::ThrowException(v8::Exception::Error(JSTR("Could not find native cpdo::driver 'this' object.")))
#define ASSERT_ARGV(COND) if( ! (COND) ) return v8::ThrowException(v8::Exception::Error(JSTR("Arguments condition failed: "#COND)))

static v8::Handle<v8::Value> JSPDO_toString( v8::Arguments const & argv )
{
    DRV_DECL(argv.This());
    cv::StringBuffer buf;
    buf << "[cpdo::driver@"<<(void const *)drv;
    if( drv )
    {
        buf << ", driver="<<drv->driver_name();
    }
    return buf << ']';
}

v8::Handle<v8::Value> Statement_toString( v8::Arguments const & argv )
{
    STMT_DECL(argv.This());
    return cv::StringBuffer()
        << "[cpdo::statement@"<<(void const *)st << ']';
}

v8::Handle<v8::Value> Statement_getNumber(cpdo::statement * st,
                                          uint16_t ndx )
{
    switch( st->col_type(ndx) )
    {
      case CPDO_TYPE_INT8:
          return v8::Integer::New( st->get_int8(ndx) );
      case CPDO_TYPE_INT16:
          return v8::Integer::New( st->get_int16(ndx) );
      case CPDO_TYPE_INT32:
          return v8::Integer::New( st->get_int32(ndx) );
      case CPDO_TYPE_INT64:
          /* This is somewhat evil. v8 doesn't support 64-bit integers, so we'll
             upgrade them to doubles.
          */
          return v8::Number::New( static_cast<double>(st->get_int64(ndx)) );
      case CPDO_TYPE_FLOAT:
          return v8::Number::New( st->get_float(ndx) );
      case CPDO_TYPE_DOUBLE:
          return v8::Number::New( st->get_double(ndx) );
      default:
          return v8::Integer::New(0);
    }
}

v8::Handle<v8::Value> Statement_getNumber(v8::Arguments const & argv)
{
    ASSERT_ARGV(argv.Length()>0);
    ASSERT_STMT_DECL(argv.This());
    return Statement_getNumber( st, cv::CastFromJS<uint16_t>(argv[0]) );
}

static v8::Handle<v8::Value> Statement_getString(cpdo::statement * st,
                                                 uint16_t ndx )
{
    switch( st->col_type(ndx) )
    {
      case CPDO_TYPE_NULL:
          return v8::Null();
      case CPDO_TYPE_INT8:
          return cv::StringBuffer() << st->get_int8(ndx);
      case CPDO_TYPE_INT16:
          return cv::StringBuffer() << st->get_int16(ndx);
      case CPDO_TYPE_INT32:
          return cv::StringBuffer() << st->get_int32(ndx);
      case CPDO_TYPE_INT64:
          /*this is evil b/c v8 doesn't support 64-bit integers.*/
          return cv::StringBuffer() << st->get_int64(ndx);
      case CPDO_TYPE_FLOAT:
          return cv::StringBuffer() << st->get_float(ndx);
      case CPDO_TYPE_DOUBLE:
          return cv::StringBuffer() << st->get_double(ndx);
      default: {
          /** We will assume that blob fields contain string data, as
              there are very valid reason for generically storing
              string data in BLOB format (i do it a lot in the whiki
              project for storing JSON data). If the client tries to
              read image data, or similar, this way, results are of
              course completely undefined. v8 makes assumptions about
              encoding, and binary image data certainly won't pass
              those assumptions.
          */
          unsigned char const * str = NULL;
          void const * blob = NULL;
          str = reinterpret_cast<unsigned char const *>(st->get_string(ndx));
          uint32_t slen = 0;
          if( ! str )
          {
              blob = st->get_blob(ndx, &slen);
              if( blob ) str = reinterpret_cast<unsigned char const *>(blob);
          }
          else slen = strlen((char const *)str);
          return str
              ? v8::String::New(reinterpret_cast<char const *>(str), slen)
              : v8::Null();
      }
    }
}

v8::Handle<v8::Value> Statement_getString(v8::Arguments const & argv)
{
    ASSERT_ARGV(argv.Length()>0);
    ASSERT_STMT_DECL(argv.This());
    return Statement_getString( st, cv::CastFromJS<uint16_t>(argv[0]) );
}

static v8::Handle<v8::Value> Statement_getGeneric( cpdo::statement * st,
                                                   uint16_t ndx )
{
    switch( st->col_type(ndx) )
    {
      case CPDO_TYPE_INT8:
      case CPDO_TYPE_INT16:
      case CPDO_TYPE_INT32:
      case CPDO_TYPE_INT64:
      case CPDO_TYPE_FLOAT:
      case CPDO_TYPE_DOUBLE:
          return Statement_getNumber(st, ndx);
      default:
          return Statement_getString(st, ndx);
    }
}

v8::Handle<v8::Value> Statement_getGeneric(v8::Arguments const & argv)
{
    ASSERT_ARGV(argv.Length()>0);
    ASSERT_STMT_DECL(argv.This());
    return Statement_getGeneric( st, cv::CastFromJS<uint16_t>(argv[0]) );
}

static v8::Handle<v8::Value> Statement_bind(cpdo::statement * st,
                                            uint16_t ndx,
                                            v8::Handle<v8::Value> const & val )
{
    assert( st && !val.IsEmpty() );
    if( val->IsNull() || val->IsUndefined() )
    {
        st->bind( ndx );
    }
    else if( val->IsNumber() )
    {
        if( val->IsInt32() )
        {
            st->bind( ndx, val->Int32Value() );
        }
        else if( val->IsUint32() )
        {
            st->bind( ndx, static_cast<int64_t>(val->Uint32Value()) );
        }
        else
        {
            st->bind( ndx, val->NumberValue() );
        }
    }
    else if( val->IsString() )
    {
        v8::String::Utf8Value const ustr(val);
        char const * cstr = *ustr;
        if( !cstr )
        {
            st->bind(ndx);
        }
        else
        {/**
            TODO: try to bind as a blob and if that fails then bind as
            a string (or the other way around). To do that without
            adding a try/catch block we have to use the low-level cpdo
            API.
          */
            st->bind( ndx, cstr, static_cast<uint32_t>(ustr.length()) );
        }
    }
    else if( val->IsBoolean() )
    {
        st->bind( ndx, static_cast<int8_t>(val->BooleanValue() ? 1 : 0) );
    }
    else
    {
        return v8::ThrowException(cv::StringBuffer()
                                  << "bind() was given an invalid parameter "
                                  << "type for column "<<ndx<<".");
    }
    return v8::Undefined();
}

static v8::Handle<v8::Value> Statement_bind(cpdo::statement * st,
                                            std::string const & pname,
                                            v8::Handle<v8::Value> const & val )
{
    char const * cstr = pname.empty() ? NULL : pname.c_str();
    return Statement_bind( st, st->param_index( cstr ), val );
}

static v8::Handle<v8::Value> Statement_bind(cpdo::statement * st,
                                            v8::Handle<v8::Value> const & index,
                                            v8::Handle<v8::Value> const & val )
{
    return index->IsString()
        ? Statement_bind( st, cv::JSToStdString(index), val )
        : Statement_bind( st, cv::CastFromJS<uint16_t>(index), val )
        ;
}

static v8::Handle<v8::Value> Statement_bind(cpdo::statement * st,
                                            v8::Handle<v8::Array> & ar )
{
    uint32_t const alen = ar->Length();
    uint16_t ndx = 1;
    for( ; ndx <= alen; ++ndx )
    {
        v8::Handle<v8::Value> const & rc( Statement_bind( st, ndx, ar->Get( ndx - 1 ) ) );
        if( rc.IsEmpty() )
        {
            // JS exception was thrown.
            return rc;
        }
    }
    return v8::Undefined();
}

static v8::Handle<v8::Value> Statement_bind(cpdo::statement * st,
                                            v8::Handle<v8::Object> & obj )
{
    v8::Local<v8::Array> plist( obj->GetPropertyNames() );
    v8::Handle<v8::Value> rc;
    uint32_t const alen = plist->Length();
    uint32_t i = 0;
    for( ; i < alen; ++i )
    {
        v8::Local<v8::Value> const key = plist->Get( i );
        if( key.IsEmpty() ) continue;
        v8::Local<v8::String> const skey( v8::String::Cast(*key) );
        if( ! obj->HasOwnProperty(skey) ) continue;
        rc = Statement_bind( st, skey, obj->Get(skey) );
        if( rc.IsEmpty() )
        { // JS exception
            return rc;
        }
    }
    return v8::Undefined();
}


/**
   Potential TODOs:

   bind({':namedParam1':val, ':namedParam2':val})

   bind( [ col0Val, col1Val... ] )
*/
v8::Handle<v8::Value> Statement_bind(v8::Arguments const & argv)
{
    ASSERT_STMT_DECL(argv.This());
    v8::Handle<v8::Value> val;
    int const argc = argv.Length();
    if( !argc || (argc > 2) )
    {
        return v8::ThrowException(JSTR("bind() requires 1 or 2 arguments."));
    }
    if( 2 == argc )
    {
        return Statement_bind( st, argv[0], argv[1] );
    }
    else /* one argument */
    {
        val = argv[0];
        if( val->IsArray() )
        {
            v8::Handle<v8::Array> ar((v8::Array::Cast(*val)));
            return Statement_bind( st, ar );
        }
        else if( val->IsObject() )
        {
            v8::Handle<v8::Object> obj((v8::Object::Cast(*val)));
            return Statement_bind( st, obj );
        }
        else
        {
            return Statement_bind( st, val, v8::Null() );
        }
    }
}

v8::Handle<v8::Value> Statement_stepArray( v8::Arguments const & argv )
{
    v8::HandleScope hscope;
    ASSERT_STMT_DECL(argv.This());
    if( ! st->step() ) return v8::Null();
    uint16_t const colCount = st->col_count();
    if( ! colCount ) return v8::Null() /* fixme: throw here. */;
    v8::Handle<v8::Array> arh( v8::Array::New(colCount) );
    uint16_t i = 0;
    for( ; i < colCount; ++i )
    {
        arh->Set( i, Statement_getGeneric(st, i) );
    }
    return arh;
}


v8::Handle<v8::Value> JSPDO_prepare( v8::Arguments const & argv )
{
    if( argv.Length() < 1 )
    {
        throw std::range_error("prepare() requires 1 argument (the SQL to prepare).");
    }
    ASSERT_DRV_DECL(argv.This());
    try
    {
        typedef cv::ClassCreator<cpdo::statement> WST;
        WST & wst( WST::Instance() );
        v8::Handle<v8::Value> stArgs[] = {
        argv.This(),
        argv[0]
        };
        v8::Handle<v8::Value> jSt = wst.NewInstance( 2, stArgs );
        if( jSt.IsEmpty() || ! jSt->IsObject() ) {
            /* i'm assuming this is an exception for now */
            return jSt;
        }
        cpdo::statement * st = cv::CastFromJS<cpdo::statement>(jSt);
        assert( (NULL != st) && "Probable bug in the binding code." );
        return jSt;
    }
    catch(std::exception const &ex)
    {
        return cv::CastToJS(ex);
    }
}

v8::Handle<v8::Value> JSPDO_exec( v8::Arguments const & argv )
{
    if( argv.Length() < 1 ) {
        throw std::range_error("exec() requires 1 argument.");
    }
    ASSERT_DRV_DECL(argv.This());
    std::string sql = cv::JSToStdString(argv[0]);
    drv->exec( sql.c_str(), sql.size() );
    return v8::Undefined();
}

v8::Handle<v8::Value> JSPDO_lastInsertId( v8::Arguments const & argv )
{
    ASSERT_DRV_DECL(argv.This());
    std::string const hint = (argv.Length()>0)
        ? cv::JSToStdString(argv[0])
        : std::string();
    return cv::CastToJS( drv->last_insert_id( hint.empty() ? NULL : hint.c_str() ) );
}

v8::Local<v8::Array> JSPDO_driverList()
{
    char const * const * dlist = cpdo_available_drivers();
    v8::Local<v8::Array> ar( v8::Array::New() );
    uint32_t ndx = 0;
    for( ; *dlist; ++dlist )
    {
        ar->Set( ndx++, v8::String::New(*dlist) );
    }
    return ar;
}

namespace v8 { namespace convert {

    template <>
    struct ClassCreator_Init<cpdo::driver>
    {
        static void InitBindings( v8::Handle<v8::Object> & dest )
        {
            using namespace v8;
            //CERR << "Binding cpdo::driver...\n";
            ////////////////////////////////////////////////////////////
            // Bootstrap class-wrapping code...
            typedef cpdo::driver DRV;
            typedef cv::ClassCreator<DRV> WDRV;
            typedef cpdo::statement ST;
            typedef cv::ClassCreator<ST> WST;
            WDRV & wdrv( WDRV::Instance() );
            if( wdrv.IsSealed() )
            {
                wdrv.AddClassTo( "JSPDO", dest );
                return;
            }
            WST & wst( WST::Instance() );
            assert( ! wst.IsSealed() );

            ////////////////////////////////////////////////////////////////////////
            // cpdo::statement bindings...
#define CATCHER cv::InCaCatcher_std
#define M2I cv::MethodToInvocationCallback
            Handle<ObjectTemplate> const & stProto( wst.Prototype() );
            wst("finalize", WST::DestroyObject )
                ("step", CATCHER< M2I<ST, bool (),&ST::step> >::Call)
                ("stepArray", CATCHER< Statement_stepArray >::Call)
                ("columnName", CATCHER< M2I<ST, char const * (uint16_t),&ST::col_name> >::Call )
                ("columnType", CATCHER< M2I<ST, cpdo_data_type (uint16_t),&ST::col_type> >::Call )
                ("getNumber", CATCHER<Statement_getNumber>::Call)
                ("getString", CATCHER<Statement_getString>::Call)
                ("get", CATCHER<Statement_getGeneric>::Call)
                ("bind", CATCHER<Statement_bind>::Call)
                ("reset", CATCHER< M2I<ST, void (void),&ST::reset> >::Call)
                ("toString", Statement_toString)
                ("paramIndex", InCaCatcher_std<M2I<ST, uint16_t (char const *),&ST::param_index> >::Call )
                ;

            typedef cv::MemberPropertyBinder<ST> SPB;
            SPB::BindGetterMethod<std::string (),&ST::error_text>( "errorText", stProto );
            SPB::BindGetterMethod<int (),&ST::error_code>( "errorCode", stProto );
            SPB::BindGetterMethod<uint16_t (),&ST::param_count>( "paramCount", stProto );
            SPB::BindGetterMethod<uint16_t (),&ST::col_count>( "columnCount", stProto );

            
            // Just an experiment:
            typedef InCaCatcher<
                std::runtime_error,
                char const * (),
                &std::runtime_error::what,
                JSPDO_prepare,
                true> CatchPrepare_RTE;
            typedef InCaCatcher_std<CatchPrepare_RTE::Call,false> CatchPrepare;


#if 0
            typedef InCa< M2I<DRV,uint64_t (char const *),&DRV::last_insert_id> > CbLastInsId;
            typedef InCaCatcher_std<
                cv::InCaOverloader<1, CbLastInsId::Call,
                    cv::InCaOverloader<0, JSPDO_lastInsertId>::Call
                    >::Call
                > LastInsId;
#endif       

            
            ////////////////////////////////////////////////////////////////////////
            // cpdo::driver bindings...
            Handle<ObjectTemplate> const & dProto( wdrv.Prototype() );
            wdrv("close", WDRV::DestroyObject )
                ("begin", CATCHER< M2I<DRV,void (),&DRV::begin> >::Call )
                ("commit", CATCHER< M2I<DRV,void (),&DRV::commit> >::Call )
                ("rollback", CATCHER< M2I<DRV,void (),&DRV::rollback> >::Call)
                ("exec", CATCHER< M2I<DRV,void (std::string const &),&DRV::exec> >::Call)
                ("prepare", CATCHER< JSPDO_prepare >::Call )
                ("exec", CATCHER<JSPDO_exec>::Call )
                ("XlastInsertId",
                 CATCHER<JSPDO_lastInsertId>::Call
                 //LastInsId::Call
                 )
                ("lastInsertId", InCa< CATCHER<JSPDO_lastInsertId>::Call >() )
                ("toString", JSPDO_toString)
                ;
#undef M2I
#undef CATCHER
            typedef cv::MemberPropertyBinder<DRV> PB;
            PB::BindGetterConstMethod<char const * (),&DRV::driver_name>( "driverName", dProto );
            PB::BindGetterMethod<std::string (),&DRV::error_text>( "errorText", dProto );
            PB::BindGetterMethod<int (),&DRV::error_code>( "errorCode", dProto );

            ////////////////////////////////////////////////////////////////////////
            // The following changes have to be made after the
            // prototype-level changes are made or they appear to have
            // no effect.
            v8::Handle<v8::Function> dCtor = wdrv.CtorFunction();
            /**
               We don't want clients to instantiate Statement objects
               except via JSPDO.prepare(). So we don't add its
               constructor to the destination object, but we do store
               it internally in a hidden field so that we can be 100%
               certain (i hope!) v8 doesn't GC it.
             */
            dCtor->SetHiddenValue( JSTR("Statement"), wst.CtorFunction() );
            dCtor->Set(JSTR("driverList"), JSPDO_driverList() );

            if(0)
            { /* the C++ API hides the cpdo_step_code values from the
                 client, replacing them with a bool or an exception.
              */
                v8::Handle<v8::Object> dstep( Object::New() );
                dCtor->Set(JSTR("stepCodes"),dstep);
                dstep->Set(JSTR("OK"), cv::CastToJS<int>(CPDO_STEP_OK) );
                dstep->Set(JSTR("DONE"), cv::CastToJS<int>(CPDO_STEP_DONE) );
                dstep->Set(JSTR("ERROR"), cv::CastToJS<int>(CPDO_STEP_ERROR) );
            }


            { // Set up a map of cpdo_data_type enum entries...
                v8::Handle<v8::Object> dtypes( Object::New() );
                dCtor->Set(JSTR("columnTypes"),dtypes);
#define COLTYPE(X) dtypes->Set(JSTR(#X), Integer::New(CPDO_TYPE_##X))
                COLTYPE(ERROR);
                COLTYPE(NULL);
                COLTYPE(INT8);
                COLTYPE(INT16);
                COLTYPE(INT32);
                COLTYPE(INT64);
                COLTYPE(FLOAT);
                COLTYPE(DOUBLE);
                COLTYPE(STRING);
                COLTYPE(BLOB);
                COLTYPE(CUSTOM);
#undef COLTYPE
            }
           
            ////////////////////////////////////////////////////////////////////////
            // Add the new class to the engine...
            wdrv.AddClassTo( "JSPDO", dest );
            //CERR << "Finished binding cpdo::driver.\n";
        }
    };

} }


namespace jspdo {
    /**
       Pass the JS engine's global object (or a "virtual" global
       object of your choice) to add the JSPDO class to it.
    */
    void SetupV8Bindings( v8::Handle<v8::Object> & dest )
    {
        cv::ClassCreator_Init<cpdo::driver>::InitBindings(dest);
    }

}
#undef ASSERT_ARGV
#undef DRV_DECL
#undef ASSERT_DRV_DECL
#undef STMT_DECL
#undef ASSERT_STMT_DECL
