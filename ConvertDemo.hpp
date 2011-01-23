/**
   Test/demo code for the v8::convert API.
   
*/
#if defined(NDEBUG)
#  undef NDEBUG  // force assert() to work
#endif

#include <cassert>
#include <v8.h>

/*
  The following macros and typedefs are only for the convenience
  of the test code author, and do not necessarily reflect
  best practices.
*/
#include "v8/convert/v8-convert.hpp"
#ifndef CERR
#include <iostream> /* only for debuggering */
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << ":" << __FUNCTION__<< "(): "
#endif
#define JSTR(X) v8::String::New(X)
namespace cv = v8::convert;
typedef v8::Handle<v8::Value> ValueHandle;

void doFoo();
void doNothing();
int doSomething(int x);
ValueHandle sampleCallback( v8::Arguments const & argv );

/**
   Class to bind to JS space.
*/
struct BoundNative
{
    BoundNative()
    {
        CERR << "@"<<(void const *)this<<" is constructing.\n";
    }
    /*
      dtor MUST be virtual if we want to subclass this type, or the
      bindings mechanism will only call the base-most dtor at cleanup
      time. (Been there, debuggered that.)
     */
    virtual ~BoundNative()
    {
        CERR << "@"<<(void const *)this<<" is destructing.\n";
    }

    void puts(char const *str) const
    {
        CERR << "@"<<(void const *)this<<"->puts(\""<<str<<"\")\n";
    }
    
    void doFoo()
    {
        assert( 0 != this )/*YES, i have seen that happen during initial development. */;
        CERR << "@"<<(void const *)this<<"->doFoo()!\n";
    }
    void doFoo1(int i)
    {
        assert( 0 != this );
        CERR << "@"<<(void const *)this<<"->doFoo1("<<i<<")!\n";
    }
    double doFoo2(int i, double x)
    {
        assert( 0 != this );
        CERR << "@"<<(void const *)this<<"->doFoo2("<<i<<", "<<x<<")!\n";
        return x * i;
    }

    double operator()( int i, double x ) const
    {
        assert( 0 != this );
        CERR << "@"<<(void const *)this<<"->operator()("<<i<<", "<<x<<")!\n";
        return x * i;
    }
    ValueHandle invo( v8::Arguments const & argv )
    {
        assert( 0 != this );
        CERR << "@"<<(void const *)this<<"->invo()  (non-static, non-const)\n";
        return ValueHandle();
    }
    int invoInt( v8::Arguments const & argv )
    {
        assert( 0 != this );
        CERR << "@"<<(void const *)this<<"->invoInt()  (non-static, non-const)\n";
        return 3;
    }

    ValueHandle invo( v8::Arguments const & argv ) const
    {
        assert( 0 != this );
        CERR << "@"<<(void const *)this<<"->invo()  (const)\n";
        return ValueHandle();
    }

    static ValueHandle invoStatic( v8::Arguments const & argv )
    {
        CERR << "invo() (static)\n";
        return ValueHandle();
    }

    /**
       Adds a JS binding of this class, called "BoundNative", to the given
       object. It also installs the BoundSubNative class.

       Returns dest. 
    */
    static v8::Handle<v8::Value> bindJSClass( v8::Handle<v8::Object> dest );
};

/**
   A class for testing/demonstrating subclassing of bound types.
 */
struct BoundSubNative : public BoundNative
{
    BoundSubNative()
    {
        CERR << "@"<<(void const *)this<<" is constructing\n";
    }
    virtual ~BoundSubNative()
    {
        CERR << "@"<<(void const *)this<<" is destructing\n";
    }

    void subFunc() const
    {
        CERR << "@"<<(void const *)this<<"->subFunc()\n";
    }

    /**
       See the demo impl code for how we override BoundNative'
       toString with this one.
     */
    v8::Handle<v8::Value> toString() const
    {
        return v8::convert::StringBuffer() << "[BoundSubNative Object@"<<(void const *)this<<"]";
    }
};

/**
   The following code is mostly here for use with ClassCreator<>, a
   class-binding mechanism which is demonstrated in
   ConvertDemo.cpp. It mostly shows how to use ClassCreator<> policies
   to customize the ClassCreator bindings for a particular class.
*/
namespace v8 { namespace convert {
#if 0
    /**
       Optional: customize internal field layout for the JS class.

       When subclassing bound types from other bound types, all must
       have the same layout or native object lookups won't work
       properly.
    */
    template <>
    struct ClassCreator_InternalFields<BoundNative>
        : ClassCreator_InternalFields_Base<BoundNative,3,1>
    {
    };
    /**
       Required only when subclassing BoundNative and customizing
       ClassCreator_InternalFields<BoundNative>.
       
       The BoundSubNative bound type requires the same internal field layout
       as its parent class, and we do that like this. If we never
       customize the field layout for our type then even subclasses
       can use the default implementation of this policy (i.e. they
       need not explicitly specialize it).
    */
    template <>
    struct ClassCreator_InternalFields<BoundSubNative>
        : ClassCreator_InternalFields<BoundNative>
    {
    };
#endif

    /*
      This class is required unless you just want to bind to the
      default constructor. It creates native objects for the
      underlying binding code.
     */
    template <>
    class ClassCreator_Factory<BoundNative>
    {
    public:
        typedef BoundNative * ReturnType;
        static ReturnType Create( v8::Arguments const & argv );
        static void Delete( BoundNative * obj );
    };

    /**
       Optional: enable function calls to BoundNative() to work like a
       constructor call. Without this, calling BoundNative() without
       'new' will cause a JS-side exception.
    */
    template <>
    struct ClassCreator_AllowCtorWithoutNew<BoundNative> : Opt_Bool<true>
    {};
    template <>
    struct ClassCreator_AllowCtorWithoutNew<BoundSubNative>
        : ClassCreator_AllowCtorWithoutNew<BoundNative>
    {};

    /**
       Required specialization so that the conversion API can derive
       the native 'this' object from v8::Arguments::This() and from
       function arguments of our bound type.
    */
    template <>
    struct JSToNative<BoundNative>
        : JSToNative_ClassCreator<BoundNative>
    {};

    /**
       Required: Install js-to-native conversion for BoundSubNative.
    */
    template <>
    struct JSToNative<BoundSubNative>
        : JSToNative_ClassCreator<BoundSubNative>
    {};
} }
