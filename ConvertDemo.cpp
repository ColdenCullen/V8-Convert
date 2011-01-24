#include "ConvertDemo.hpp"
#include "v8/convert/ClassCreator.hpp"
#include "v8/convert/properties.hpp"

int BoundNative::publicStaticInt = 42;

void doFoo()
{
    CERR << "hi!\n";
}


void doNothing()
{
    CERR << "doNothing()!\n";
}

int doSomething(int x)
{
    CERR << "doSomething("<<x<<")!\n";
    return x;
}

ValueHandle sampleCallback( v8::Arguments const & argv )
{
    CERR << "sampleCallback() Arity=-1\n";
    return ValueHandle();
}

namespace v8 { namespace convert {
    BoundNative * ClassCreator_Factory<BoundNative>::Create( v8::Arguments const & argv )
    {
        return new BoundNative;
    }
    void ClassCreator_Factory<BoundNative>::Delete( BoundNative * obj )
    {
        delete obj;
    }
} }


ValueHandle bogo_callback( v8::Arguments const & )
{
    return v8::Undefined();
}

int bogo_callback2( v8::Arguments const & argv )
{
    CERR << "native this=@"<< (void const *) cv::CastFromJS<BoundNative>(argv.This())
         << '\n';
    return 1;
}


ValueHandle BoundNative_toString( v8::Arguments const & argv )
{
    /*
      INTERESTING: the following JS code calls this function but we
      have a NULL 'this'.

      function test2()
      {
          var s = new BoundSubNative();
          assert(s instanceof BoundNative, "BoundSubNative is-a BoundNative");
          print('s='+s);
          s.destroy();
          // do not do this at home, kids: i'm testing weird stuff here...
          var f = new BoundNative();
          s.toString = f.toString;
          print('f='+f);
          print('s='+s); // <---- HERE
      }

      That happens because CastFromJS<BoundNative>()
      does not recognize BoundSubNative objects. Why not? To be honest, i'm
      not certain.
      
    */
    BoundNative * f = cv::CastFromJS<BoundNative>(argv.This());
    return cv::StringBuffer() << "[BoundNative Object@"<<f<<"]";
}

v8::Handle<v8::Value> bind_BoundSubNative( v8::Handle<v8::Object> dest );
char const * cstring_test( char const * c )
{
    std::cerr << "cstring_test( @"<<(void const *)c
              <<") ["<<(c ? c : "<NULL>")<<"]\n";
    return c;
}

v8::Handle<v8::Value> BoundNative::bindJSClass( v8::Handle<v8::Object> dest )
{
    using namespace v8;

    ////////////////////////////////////////////////////////////
    // Bootstrap class-wrapping code...
    typedef cv::ClassCreator<BoundNative> CC;
    CC & cc( CC::Instance() );
    if( cc.IsSealed() )
    {
        cc.AddClassTo( "BoundNative", dest );
        bind_BoundSubNative(dest);
        return cc.CtorFunction();
    }

    ////////////////////////////////////////////////////////////
    // Bind members...

    cc("cputs",
       cv::FunctionToInvocationCallback<int (char const *),::puts>)
        ("doFoo",
         cv::MethodToInvocationCallback<BoundNative,void (void),&BoundNative::doFoo>)
        ("doFoo2",
         cv::MethodToInvocationCallback<BoundNative,double (int,double),&BoundNative::doFoo2>)
        ("toString",
         cv::FunctionToInvocationCallback<ValueHandle (v8::Arguments const &),BoundNative_toString>)
        ("puts",
          cv::ConstMethodToInvocationCallback<BoundNative,void (char const *),&BoundNative::puts>)
        ("doFooConst",
          cv::ConstMethodToInvocationCallback<BoundNative,void (),&BoundNative::doFooConst>)
        ("invoInt",
         cv::MethodToInvocationCallback<BoundNative, int (v8::Arguments const &), &BoundNative::invoInt>)
        ("nativeParam",
         cv::MethodToInvocationCallback<BoundNative, void (BoundNative const *), &BoundNative::nativeParam>)
        ("cstr",
         cv::FunctionToInvocationCallback< char const * (char const *), cstring_test>)
        ("destroy", CC::DestroyObject )
        ("message", "hi, world")
        ("answer", 42)
        ;

    // We can of course bind them directly to the prototype, instead
    // of via the cc object:
     Handle<ObjectTemplate> const & proto( cc.Prototype() );
     proto->Set(JSTR("bogo"),
                cv::CastToJS(cv::FunctionToInvocationCallback<ValueHandle (v8::Arguments const &), bogo_callback>)
                );
     proto->Set(JSTR("bogo2"),
                cv::CastToJS(cv::FunctionToInvocationCallback<int (v8::Arguments const &),bogo_callback2>)
                );
     proto->Set(JSTR("runGC"),
                cv::CastToJS(cv::FunctionToInvocationCallback<bool (),v8::V8::IdleNotification>)
                );

     // Bind some properties:
     typedef cv::PropertyBinder<BoundNative> PB;
     PB::BindMemVar<int,&BoundNative::publicInt>( "publicIntRW", proto );
     PB::BindMemVarRO<int,&BoundNative::publicInt>( "publicIntRO", proto, true );
     PB::BindStaticVar<int,&BoundNative::publicStaticInt>("publicStaticIntRW", proto );
     PB::BindStaticVarRO<int,&BoundNative::publicStaticInt>("publicStaticIntRO", proto );     

    ////////////////////////////////////////////////////////////
    // Add class to the destination object...
    //dest->Set( JSTR("BoundNative"), cc.CtorFunction() );
    cc.AddClassTo( "BoundNative", dest );

    CERR << "Added BoundNative to JS.\n";
    if(1)
    { // sanity checking. This code should crash if the basic stuff is horribly wrong
        Handle<Value> vinst = cc.NewInstance(0,NULL);
        BoundNative * native = cv::CastFromJS<BoundNative>(vinst);
        assert( 0 != native );
        CERR << "Instantiated native BoundNative@"<<(void const *)native
             << " via JS.\n";
        CC::DestroyObject( vinst );
    }
    bind_BoundSubNative(dest);
    CERR << "Finished binding BoundNative.\n";
    return dest;
}

v8::Handle<v8::Value> bind_BoundSubNative( v8::Handle<v8::Object> dest )
{
    using namespace v8;
    typedef cv::ClassCreator<BoundNative> CCFoo;
    typedef cv::ClassCreator<BoundSubNative> CC;
    CC & cc( CC::Instance() );
    if( cc.IsSealed() )
    {
        cc.AddClassTo( "BoundSubNative", dest );
        return cc.CtorFunction();
    }

    cc
        ("subFunc",
         cv::ConstMethodToInvocationCallback<BoundSubNative,void (),&BoundSubNative::subFunc>)
        ("toString",
         cv::ConstMethodToInvocationCallback<BoundSubNative,ValueHandle (),&BoundSubNative::toString>)
        ;

    //Handle<ObjectTemplate> const & proto( cc.Prototype() );
    cc.CtorTemplate()->Inherit( CCFoo::Instance().CtorTemplate() );
    
    cc.AddClassTo("BoundSubNative",dest);
    return dest;
}
#undef JSTR


#if 0
#include <v8/juice/juice.h>
#include <v8/juice/plugin.h>
static v8::Handle<v8::Value> plugin_init( v8::Handle<v8::Object> dest )
{
    CERR << "PLUGGING IN!\n";
    return BoundNative::bindJSClass( dest );
}


V8_JUICE_PLUGIN_STATIC_INIT(plugin_init);
#endif
