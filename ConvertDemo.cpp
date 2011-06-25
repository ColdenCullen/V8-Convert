#include "ConvertDemo.hpp"
#include "v8/convert/ClassCreator.hpp"
#include "v8/convert/properties.hpp"

#define TRY_UNLOCKED_FUNCTIONS 1

#if TRY_UNLOCKED_FUNCTIONS
#include <unistd.h> // only for sleep() in some test code
#endif


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
    return v8::Undefined();
}

namespace v8 { namespace convert {
    // A helper to support converting from BoundNative to its JS handle.
    typedef NativeToJSMap<BoundNative> BMap;
    typedef NativeToJSMap<BoundSubNative> BSubMap;
    BoundNative * ClassCreator_Factory<BoundNative>::Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv )
    {
        BoundNative * b = new BoundNative;
        BMap::Insert( jsSelf, b );
        return b;
    }
    void ClassCreator_Factory<BoundNative>::Delete( BoundNative * obj )
    {
        BMap::Remove( obj );
        delete obj;
    }
    BoundSubNative * ClassCreator_Factory<BoundSubNative>::Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv )
    {
        BoundSubNative * b = new BoundSubNative;
        BSubMap::Insert( jsSelf, b );
        return b;
    }
    void ClassCreator_Factory<BoundSubNative>::Delete( BoundSubNative * obj )
    {
        BSubMap::Remove( obj );
        delete obj;
    }

#if 0 // don't use this - it doesn't work
    // An experiment.
    v8::Handle<v8::Value> ICListEnd( v8::Arguments const & )
    {
        return v8::Undefined();
    }

    // An experiment.
    template <>
    struct FunctionPtr<v8::InvocationCallback,ICListEnd>
        : SignatureBase<v8::Handle<v8::Value>, -2>
    {
        public:
        typedef FunctionSignature<v8::InvocationCallback> SignatureType;
        typedef typename SignatureType::ReturnType ReturnType;
        typedef typename SignatureType::FunctionType FunctionType;
        static FunctionType GetFunction()
        {
            return ICListEnd;
        }
        static v8::Handle<v8::Value> Call( v8::Arguments const & args  )
        {
            return ICListEnd(args);
        }
    };
    typedef FunctionPtr<v8::InvocationCallback,ICListEnd> ICForwardEOL;
    template < typename Callable0,
               typename Callable1 = ICForwardEOL,
               typename Callable2 = ICForwardEOL
               >
    struct ICForwardByArity
    {
        static v8::Handle<v8::Value> Call( v8::Arguments const & args )
        {
            int const n = args.Length();
            CERR << "ICForwardByArity::Call(): args.Length=="<<n<<'\n';
#define CHECK(N)                 CERR << "Checking against arity " << Callable##N::Arity << '\n'; \
            if( Callable##N::Arity == n ) {                             \
                return Callable##N::GetFunction()(args);                \
            } (void)0
            CHECK(0); CHECK(1); CHECK(2);
            return v8::ThrowException(StringBuffer() << "This function was passed "<<n<<" arguments, "
                                      << "but no overload was found matching that number of "
                                      << "arguments.");
        }
    };
#endif

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
    return cv::StringBuffer() << "[object BoundNative@"<<f<<"]";
}

v8::Handle<v8::Value> bind_BoundSubNative( v8::Handle<v8::Object> dest );
char const * cstring_test( char const * c )
{
    std::cerr << "cstring_test( @"<<(void const *)c
              <<") ["<<(c ? c : "<NULL>")<<"]\n";
    return c;
}

std::string sharedString("hi, world") /* may not be static for templating reasons. */;
std::string getSharedString()
{
    CERR << "getSharedString()=="<<sharedString<<'\n';
    return sharedString;
}
void setSharedString(std::string const &s)
{
    CERR << "setSharedString("<<s<<")\n";
    sharedString = s;
}


/**
   This is an experiment...
*/
template < typename ExceptionT,
           typename SigGetMsg,
           typename v8::convert::ConstMethodSignature<ExceptionT,SigGetMsg>::FunctionType Getter,
           v8::Handle<v8::Value> (*ICB)( v8::Arguments const & )
>
v8::Handle<v8::Value> InvocationCallbackExceptionWrapper( v8::Arguments const & args )
{
    try
    {
        return ICB( args );
    }
    catch( ExceptionT const & e2 )
    {
        return v8::ThrowException(v8::convert::CastToJS((e2.*Getter)()));
    }
#if 0
    catch( std::exception const & ex )
    {
        return v8::convert::CastToJS(ex);
    }
#endif
    catch(...)
    {
        return v8::ThrowException(v8::String::New("Unknown native exception thrown!"));
    }
}

/**
   InvocationCallback wrapper which calls another InvocationCallback
   and translates native-level exceptions to JS. std::exception is caught
   explicitly and its what() method it used as the exception string. Other
   exceptions are caught and cause an unspecified exception message to be
   used.   
*/
template < v8::Handle<v8::Value> (*ICB)( v8::Arguments const & ) >
v8::Handle<v8::Value> InvocationCallbackToInvocationCallback( v8::Arguments const & args )
{
#if 1
    return InvocationCallbackExceptionWrapper<std::exception,
        char const *(),
        &std::exception::what,
        ICB>( args );
#else
    try
    {
        return ICB( args );
    }
    catch( std::exception const & ex )
    {
        return v8::convert::CastToJS(ex);
    }
    catch(...)
    {
        return v8::ThrowException(v8::String::New("Unknown native exception thrown!"));
    }
#endif
}

v8::Handle<v8::Value> test_anton_callback( v8::Arguments const & args )
{
    throw std::runtime_error("Testing Anton's callback.");
    return v8::Undefined();
}

template <bool IsUsingUnlock>
void test_using_locker()
{
    CERR << "Callback "<<(IsUsingUnlock?"with":"without") << " Unlocker support. Briefly locking v8...\n";
    // If something is broken in our locking setup then the following will likely assert in v8:
    v8::Locker lock();
    cv::StringBuffer msg;
    msg << "We're back...\n";
    CERR << msg;
}

namespace v8 { namespace convert {



    template <>
    struct ClassCreator_Init<BoundNative>
    {
        static void InitBindings( v8::Handle<v8::Object> & dest )
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
                return;
            }

            typedef cv::tmp::TypeList<
                cv::MethodToInCa<BoundNative, void(), &BoundNative::overload0>,
                cv::MethodToInCa<BoundNative, void(int), &BoundNative::overload1>,
                //cv::InCa< cv::MethodToInvocationCallback<BoundNative, void(int,int), &BoundNative::overload2>, 2 >
                cv::MethodToInCa<BoundNative, void(int,int), &BoundNative::overload2>,
                cv::MethodToInCa<BoundNative, void(v8::Arguments const &), &BoundNative::overloadN>
            > OverloadList;
            typedef cv::InCaOverloadList< OverloadList > OverloadInCas;

            if(1) // just an experiment
            {
                typedef Signature<void (int,double)> AL2;
                assert( 2 == AL2::Arity );
                assert( 2 == tmp::LengthOf<AL2>::Value );
                assert( (tmp::SameType< void, AL2::ReturnType >::Value) );
                assert( (tmp::SameType< int, tmp::TypeAt<AL2,0>::Type >::Value) );
                assert( (tmp::SameType< double, tmp::TypeAt<AL2,1>::Type >::Value) );
                //assert( (tmp::SameType< double, AL2::TypeAt<1>::Type >::Value) );
                
                typedef cv::FunctionPtr< int(char const *), ::puts> FPPuts;
                FPPuts::Function("Hi, world.");
                typedef Signature< FPPuts::FunctionType > ALPuts;
                assert( 1 == ALPuts::Arity );
                
                typedef Signature< int (BoundNative::*)(char const *) const > BNPutsC;
                typedef Signature< int (BoundNative::*)(char const *) > BNPuts;
                assert( 1 == tmp::LengthOf<BNPutsC>::Value );
                assert( 1 == tmp::LengthOf<BNPuts>::Value );
                assert( 0 != (tmp::SameType< char const *, tmp::TypeAt<BNPuts,0>::Type >::Value) );
            }
#define CATCHER cv::InCaCatcher_std
#define F2I cv::FunctionToInvocationCallback
            ////////////////////////////////////////////////////////////
            // Bind some member functions...
            cc("cputs",
               cv::FunctionToInCa<int (char const *),::puts>::Call )
                ("overloaded",
                  OverloadInCas::Call )
                ("doFoo",
                 cv::ToInCa<BoundNative,void (),&BoundNative::doFoo>::Call)
                ("doFoo2",
                 cv::ToInCa<BoundNative,double (int,double),&BoundNative::doFoo2>::Call)
                ("toString",
                 F2I<ValueHandle (v8::Arguments const &),BoundNative_toString>)
                ("puts",
                 cv::ToInCa<BoundNative,void (char const *) const,&BoundNative::puts>::Call)
                ("doFooConst",
                 cv::ToInCa<BoundNative,void () const,&BoundNative::doFooConst>::Call)
                ("invoInt",
                 cv::ToInCa<BoundNative, int (v8::Arguments const &), &BoundNative::invoInt>::Call)
                 //cv::ToInCa<BoundNative, int (v8::Arguments const &), &BoundNative::invoInt,true>::Call) // this must fail to compile
                ("nativeParam",
                 cv::ToInCa<BoundNative, void (BoundNative const *), &BoundNative::nativeParam>::Call)
                ("nativeParamRef",
                 CATCHER< cv::ToInCa<BoundNative, void (BoundNative &), &BoundNative::nativeParamRef>::Call >::Call)
                ("nativeParamConstRef",
                 CATCHER< cv::ToInCa<BoundNative, void (BoundNative const &) const, &BoundNative::nativeParamConstRef>::Call >::Call)
                ("cstr",
                 //cv::FunctionToInvocationCallback< char const * (char const *), cstring_test>)
                 cv::ToInCa< void, char const * (char const *), cstring_test>::Call)
                ("destroy", CC::DestroyObjectCallback )
                ("message", "hi, world")
                ("answer", 42)
                ("anton", InvocationCallbackToInvocationCallback<test_anton_callback>)
                ("anton2", InvocationCallbackExceptionWrapper<std::exception,char const *(), &std::exception::what,
                 test_anton_callback> )
#if 1 // converting natives to JS requires more lower-level plumbing...
                 ("nativeReturn",
                 cv::ToInCa<BoundNative, BoundNative * (), &BoundNative::nativeReturn, true>::Call)
                 ("nativeReturnConst",
                 cv::ToInCa<BoundNative, BoundNative const * () const, &BoundNative::nativeReturnConst, true>::Call)
                 ("nativeReturnRef",
                 CATCHER< cv::ToInCa<BoundNative, BoundNative & (), &BoundNative::nativeReturnRef, true>::Call >::Call)
                 ("nativeReturnConstRef",
                 CATCHER< cv::ToInCa<BoundNative, BoundNative const & () const, &BoundNative::nativeReturnConstRef, true>::Call >::Call)
#endif
                ;
#undef CATCHER
            ////////////////////////////////////////////////////////////////////////
            // We can of course bind them directly to the prototype, instead
            // of via the cc object:
            Handle<ObjectTemplate> const & proto( cc.Prototype() );
            proto->Set(JSTR("bogo"),
                       cv::CastToJS(cv::FunctionToInCa<ValueHandle (v8::Arguments const &), bogo_callback>::Call)
                       );
            proto->Set(JSTR("bogo2"),
                       cv::CastToJS(cv::FunctionToInCa<int (v8::Arguments const &),bogo_callback2>::Call)
                       );
            proto->Set(JSTR("runGC"),
                       cv::CastToJS(cv::FunctionToInCa<bool (),v8::V8::IdleNotification>::Call)
                       );
            ////////////////////////////////////////////////////////////////////////
            // Bind some JS properties to native properties:
            typedef cv::MemberPropertyBinder<BoundNative> PB;
            PB::BindMemVar<int,&BoundNative::publicInt>( "publicIntRW", proto );
            PB::BindMemVarRO<int,&BoundNative::publicInt>( "publicIntRO", proto, true );
            PB::BindSharedVar<int,&BoundNative::publicStaticInt>("publicStaticIntRW", proto );
            PB::BindSharedVarRO<int,&BoundNative::publicStaticInt>("publicStaticIntRO", proto );
            PB::BindSharedVar<std::string,&sharedString>("staticString", proto );
            PB::BindSharedVarRO<std::string,&sharedString>("staticStringRO", proto, true );
            // More generically, accessors can be bound using this approach:
            proto->SetAccessor( JSTR("self"),
                                PB::MethodToAccessorGetter< BoundNative * (), &BoundNative::self>,
                                PB::AccessorSetterThrow );
            proto->SetAccessor( JSTR("selfRef"),
                                PB::MethodToAccessorGetter< BoundNative & (), &BoundNative::selfRef>,
                                PB::AccessorSetterThrow );
            proto->SetAccessor( JSTR("selfConst"),
                                PB::ConstMethodToAccessorGetter< BoundNative const * (), &BoundNative::self>,
                                PB::AccessorSetterThrow );
            proto->SetAccessor( JSTR("selfConstRef"),
                                PB::ConstMethodToAccessorGetter< BoundNative const & (), &BoundNative::selfRefConst>,
                                PB::AccessorSetterThrow );
                                
            
#if 0
            PB::BindGetterFunction<std::string (), getSharedString>("sharedString2", proto);
#else
            PB::BindGetterSetterFunctions<std::string (),
                getSharedString,
                void (std::string const &),
                setSharedString>("sharedString2", proto);
#endif
            PB::BindGetterSetterMethods<int (), &BoundNative::getInt,
                void (int), &BoundNative::setInt
                >("theInt", proto);
            PB::BindNonConstGetterSetterMethods<int (), &BoundNative::getIntNonConst,
                void (int), &BoundNative::setInt
                >("theIntNC", proto);

#if TRY_UNLOCKED_FUNCTIONS
            v8::Handle<v8::Function> ctor( cc.CtorFunction() );
            ctor->Set(JSTR("sleep"),
                    cv::CastToJS(cv::FunctionToInCa< unsigned int (unsigned int), ::sleep, true>::Call)
            );
#endif
            ctor->Set(JSTR("testLocker"),
                cv::CastToJS(cv::ToInCa<void, void (), test_using_locker<true>, true >::Call)
            );
            ctor->Set(JSTR("testLockerNoUnlocking"),
                cv::CastToJS(cv::ToInCa<void, void (), test_using_locker<false>, false>::Call)
            );

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
        }
    };
} }

v8::Handle<v8::Value> BoundNative::bindJSClass( v8::Handle<v8::Object> dest )
{
    return cv::ClassCreator<BoundNative>::Instance().InitBindings(dest);
}

v8::Handle<v8::Value> bind_BoundSubNative( v8::Handle<v8::Object> dest )
{
    using namespace v8;
    typedef cv::ClassCreator<BoundSubNative> CC;
    CC & cc( CC::Instance() );
    if( cc.IsSealed() )
    {
        cc.AddClassTo( "BoundSubNative", dest );
        return cc.CtorFunction();
    }

    cc
        ("subFunc",
         cv::ToInCa<BoundSubNative,void () const,&BoundSubNative::subFunc>::Call)
        ("toString",
         cv::ToInCa<BoundSubNative,ValueHandle () const,&BoundSubNative::toString>::Call)
         ("nonBoundNative",
         cv::ToInCaVoid<BoundSubNative, BoundSubNative::NonBoundType & (), &BoundSubNative::nonBoundNative>::Call)
         ("nonBoundNativeConst",
         cv::ToInCaVoid<BoundSubNative, BoundSubNative::NonBoundType const& () const, &BoundSubNative::nonBoundNative>::Call)
         //cv::ToInCa<BoundSubNative, BoundSubNative::NonBoundType &(), &BoundSubNative::nonBoundNative>::Call) // must fail to compile OR link
         ("puts",
         cv::ToInCaVoid<void, int (char const *),::puts>::Call)
        ;

    typedef cv::ClassCreator<BoundNative> CCFoo;
    //cc.CtorTemplate()->Inherit( CCFoo::Instance().CtorTemplate() );
    cc.Inherit<BoundNative>();

    cc.AddClassTo("BoundSubNative",dest);
    return dest;
}
#undef JSTR


namespace { // testing ground for some compile-time assertions...
    struct CtorFwdTest
    {
        CtorFwdTest(int){}
        CtorFwdTest(){}
        CtorFwdTest(int,int){}
        CtorFwdTest(v8::Arguments const &) {}
        virtual ~CtorFwdTest() {}
        
        int afunc(int);
        int bfunc(int,int) const;
    };

    struct CtorFwdTestSub : CtorFwdTest
    {
        CtorFwdTestSub(){}
        virtual ~CtorFwdTestSub() {}
    };

    void compile_time_assertions()
    {
        namespace tmp = cv::tmp;
#define ASS ass = cv::tmp::Assertion
        tmp::Assertion<true> ass;
        ASS< (0 > cv::ToInCa<BoundNative, int (v8::Arguments const &), &BoundNative::invoInt>::Arity)>();
        typedef CtorFwdTest CFT;
        typedef cv::CtorForwarder<CFT * ()> C0;
        //typedef cv::CtorForwarder<CFT, CtorFwdTestSub *()> C0Sub;
        typedef cv::CtorForwarder<CFT * (int)> C1;
        typedef cv::CtorForwarder<CFT * (int,int)> C2;
        typedef cv::CtorForwarder<CFT * (v8::Arguments const &)> Cn;
        ASS<( Cn::Arity < 0 )>();
        typedef CFT * (*CFTCtor)( v8::Arguments const & );
        CFTCtor ctor;
        ctor = C0::Ctor;
        ctor = C1::Ctor;
        ctor = C2::Ctor;
        //ctor = C0Sub::Ctor;
        typedef cv::tmp::TypeList< C0, C1, C2 > CtorList;
        //typedef ClassCreator_Factory_CtorForwarder<CtorList> CFTFactory;
        typedef cv::CtorForwarderDispatcher<CtorList> CDispatch;
        typedef CtorFwdTest * (*FacT)( v8::Arguments const &  argv );
        FacT fac;
        fac = CDispatch::Ctor;
        typedef int (CFT::*M1)(int) ;
        typedef int (CFT::*M2)(int,int) const;
        ASS<( !(tmp::IsConst<CFT>::Value) )>();
        ASS<( (tmp::IsConst<CFT const>::Value) )>();
        ASS<( 1 == (cv::ToInCa<CFT, int (int), &CFT::afunc>::Arity) )>();
        ASS<( 2 == (cv::ConstMethodToInCa<CFT, int (int,int), &CFT::bfunc>::Arity) )>();
        typedef int (CFT::*X2)(int,int) const;
        ASS<( 2 == (cv::Signature<X2>::Arity) )>();

        ASS<( !(cv::Signature< M1 >::IsConst) )>();
        ASS<( (cv::Signature< M2 >::IsConst) )>();
        ASS<( !(cv::Signature< int (int) >::IsConst) )>();
        ASS<( (cv::Signature< int () const >::IsConst) )>();
        ASS<( (cv::Signature<X2>::IsConst) )>();
        ASS<( !(cv::Signature<int (int)>::IsConst) )>();
        ASS<( 1 == (cv::ToInCa<CFT,M1,&CFT::afunc>::Arity) )>();
        ASS<( 1 == (cv::ToInCa<CFT,int (int),&CFT::afunc>::Arity) )>();
        ASS<( 2 == (cv::ToInCa<CFT,M2,&CFT::bfunc>::Arity) )>();
        ASS<( 2 == (cv::ToInCa<CFT,int (int,int) const,&CFT::bfunc>::Arity) )>();
        //ASS<( 2 == (cv::ToInCa<CFT,int (int,int),&CFT::bfunc>::Arity) )>();
        ASS<( 1 == (cv::MethodToInCa<CFT,M1,&CFT::afunc>::Arity) )>();
        ASS<( 2 == (cv::ConstMethodToInCa<CFT,M2,&CFT::bfunc>::Arity) )>();
        //ASS<( 2 == (cv::ToInCa<CFT,M2,&CFT::bfunc>::Arity) )>();
        typedef cv::FunctionSignature<FacT> FacSig;
        ASS<( FacSig::Arity < 0 )>();
        typedef cv::ArgTypeAt< cv::FunctionSignature<int (int)>, 0 >::Type A0;
        ASS<( (tmp::SameType< int, A0>::Value))>();
        typedef cv::ArgTypeAt< cv::ToInCa<void, int (char const *),::puts>,0 >::Type A1;
        ASS<( (tmp::SameType< char const *, A1>::Value))>();
        ASS<( (tmp::IsConst<cv::ArgTypeAt< FacSig, 0 >::Type>::Value) )>();
        ASS<( (tmp::SameType< v8::Arguments const &, cv::ArgTypeAt< FacSig, 0 >::Type>::Value))>();

        typedef cv::tmp::TypeList< int, double, char const * > CanUnlock;
        typedef cv::tmp::TypeList< int, v8::Handle<v8::Value>, double > CannotUnlock;
        typedef cv::tmp::TypeList< v8::Handle<v8::Value>, double, int > CannotUnlock2;
        ASS< 3 == cv::tmp::LengthOf< CannotUnlock >::Value >();
        ASS< 3 == cv::tmp::LengthOf< CannotUnlock2 >::Value >();
        ASS<cv::TypeListIsUnlockable<CanUnlock>::Value>();
        ASS< cv::IsUnlockable<void>::Value >();
        ASS< cv::IsUnlockable<double>::Value>();
        ASS< cv::IsUnlockable<int>::Value>();
        ASS< !cv::IsUnlockable< v8::Handle<v8::Value> >::Value >();
        //assert( (cv::tmp::Assertion<!cv::TypeListIsUnlockable<CannotUnlock>::Value>::Value) );
        ASS<cv::TypeListIsUnlockable<CanUnlock>::Value>();
        ASS<!cv::TypeListIsUnlockable<CannotUnlock2>::Value>();
        ASS<!cv::TypeListIsUnlockable<CannotUnlock>::Value>();

#define SIU cv::SignatureIsUnlockable
        ASS< SIU< cv::Signature<int (int, double, char)> >::Value >();
        ASS< !SIU< cv::Signature<int (int, double, v8::Arguments)> >::Value >();
        ASS< !SIU< cv::Signature<v8::Handle<v8::Object> (int, double)> >::Value >();
        ASS< !SIU< 
                cv::MethodPtr<
                    BoundNative,
                    int (v8::Arguments const &),
                    &BoundNative::invoInt
                > >::Value >();
        ASS< !SIU< cv::ToInCa<BoundNative, int (v8::Arguments const &), &BoundNative::invoInt > >::Value>();
#undef SIU
#undef ASS
    }                
} // namespace


#undef TRY_UNLOCKED_FUNCTIONS
#undef CERR
#undef JSTR
