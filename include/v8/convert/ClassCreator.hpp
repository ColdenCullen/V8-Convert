#if !defined(CODE_GOOGLE_COM_P_V8_CONVERT_CLASS_CREATOR_HPP_INCLUDED)
#define CODE_GOOGLE_COM_P_V8_CONVERT_CLASS_CREATOR_HPP_INCLUDED 1
/** LICENSE

    This software's source code, including accompanying documentation and
    demonstration applications, are licensed under the following
    conditions...

    The author (Stephan G. Beal [http://wanderinghorse.net/home/stephan/])
    explicitly disclaims copyright in all jurisdictions which recognize
    such a disclaimer. In such jurisdictions, this software is released
    into the Public Domain.

    In jurisdictions which do not recognize Public Domain property
    (e.g. Germany as of 2011), this software is Copyright (c) 2011
    by Stephan G. Beal, and is released under the terms of the MIT License
    (see below).

    In jurisdictions which recognize Public Domain property, the user of
    this software may choose to accept it either as 1) Public Domain, 2)
    under the conditions of the MIT License (see below), or 3) under the
    terms of dual Public Domain/MIT License conditions described here, as
    they choose.

    The MIT License is about as close to Public Domain as a license can
    get, and is described in clear, concise terms at:

    http://en.wikipedia.org/wiki/MIT_License

    The full text of the MIT License follows:

    --
    Copyright (c) 2011 Stephan G. Beal (http://wanderinghorse.net/home/stephan/)

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

    --END OF MIT LICENSE--

    For purposes of the above license, the term "Software" includes
    documentation and demonstration source code which accompanies
    this software. ("Accompanies" = is contained in the Software's
    primary public source code repository.)

*/

#include <cassert>
#include "convert.hpp"
//#include <iostream> // only for debuggering

namespace v8 { namespace convert {

    /**
       Policy template used by ClassCreator<T> for
       instantiating T objects.
    */
    template <typename T>
    class ClassCreator_Factory
    {
    public:
        typedef T * ReturnType;
        /**
           Must instantiate a new T object based on the given
           arguments. On error it should throw an exception (which the
           binding framework will convert to a JS-side exception). It
           may also return NULL on error, but the error message
           probably won't be as clear for the user.

           Ownership of the object is passed to the caller (the
           binding API internals), and eventually given to v8.

           jsSelf will be the newly-created JS-side 'this' object.  It
           is not normally required by this function but it is
           sometimes useful when we need to bind supplementary
           properties in the ctor, especially when binding a "pure
           C++" class which has no native place to store such
           properties.

           At the time this is called, jsSelf is not connected to the
           native (because it hasn't yet been created).
           Implementations must not perform the actual binding of the
           returned native to jsSelf - ClassCreator will do that
           immediately after Create() returns the new object.
           
           The default implementation simply return (new T).
        */
        static ReturnType Create( v8::Persistent<v8::Object> & jsSelf, v8::Arguments const & argv )
        {
            return new T;
        }

        /**
           Must destroy obj using a mechanism complementary to its
           construction via a prior call to Create().

           The default implementation simply calls (delete obj).
        */
        static void Delete( T * obj )
        {
            delete obj;
        }
    };

    /**
       Base class for static ClassCreator options.
     */
    template <typename ValT, ValT Val>
    struct Opt_ConstVal
    {
        typedef ValT Type;
        //static Type const Value = Val; // giving me an undefined ref error?
        static Type const Value;
    };
    template <typename ValT, ValT Val>
    const ValT Opt_ConstVal<ValT,Val>::Value = Val;

    /**
       Base class for static integer ClassCreator options.
    */
    template <int Val>
    struct Opt_Int : Opt_ConstVal<int,Val>
    {};

    /**
       Base class for static boolean ClassCreator options.
    */
    template <bool Val>
    struct Opt_Bool : Opt_ConstVal<bool,Val>
    {};

    /**
       A ClassCreator policy/option class responsible specifying whether
       or not a ClassCreator-bound class should allow "Foo()" and "new
       Foo()" to behave the same or not. If the Value member is false
       (the default) then "Foo()" is not allowed to behave as a
       constructor call (it will generate an error), otherwise it will
       be treated exactly as if "new Foo()" had been called.
    */
    template <typename T>
    struct ClassCreator_AllowCtorWithoutNew : Opt_Bool<false>
    {};

    /**
       ClassCreator policy which determines whether lookups for native
       types in JS objects should walk through the prototype
       chain. This can decrease the speed of JS-to-this operations and
       is necessary only if bound types will be subclassed (either from
       other bound native types or from JS classes).
    */
    template <typename T>
    struct ClassCreator_SearchPrototypeForThis : Opt_Bool<true>
    {};


    /**
       This policy is used by ClassCreator<T>::InitBindings()
       to "plug in" native bindings. This policy is only required
       if ClassCreator<T>::InitBindings() is used by the client,
       and the intention is to provide a single interface which
       clients of the T bindings can add the support to their
       JS engine.
    */
    template <typename T>
    struct ClassCreator_Init
    {
        /**
           Implementations must do something like this following:

           @code
           typedef ClassCreator<T> CC;
           CC & cc( CC::Instance() );
           if( cc.IsSealed() )
           {
              // assume primary bindings are already done, and add
              // the class to the new target:
              cc.AddClassTo( "BoundNative", target );
              return;
           }
           ... initialize the class bindings. End with:
           cc.AddClassTo( "BoundNative", dest );
           // or the logical equivalent for your plugin case.
           @endcode
        */
        static void InitBindings( v8::Handle<v8::Object> target );
    };

    
    /**
       Convenience base type for ClassCreator_InternalFields
       implementations.

       See the member documentation for the meaning of
       HowMany and Index.

       If any of the following conditions are met then
       a compile-time assertion is triggered:

       - (HowMany<0)
       - (Index<0)
       - (Index>=HowMany)
    */
    template <typename T,int HowMany = 1, int Index = 0>
    struct ClassCreator_InternalFields_Base
    {
        /**
           Total number of internal fields assigned to JS-side T
           objects.
        */
        static const int Count = HowMany;

        /**
           The internal field index at which ClassCreator policies should
           expect the native object to be found in any given JS object.
           It must be 0 or greater, and must be less than Value.
        */
        static const int NativeIndex = Index;
    private:
        typedef tmp::Assertion<
            (Count>0)
            && (NativeIndex>=0)
            && (NativeIndex<Count)
            ? 1 : -1> AssertFields;
    };

    /**
       The ClassCreator policy which sets the number of internal
       fields reserved for JS objects and the internal field index
       (0-based) at which the native object is stored . The Count
       value must be greater than 0 and greater than the NativeIndex
       member. Failing to meet these prerequisites will cause a
       compile-time assertion to be triggered.

       ACHTUNG SUBCLASSERS:

       When using a heirarchy of native types, more than one of which
       is bound using ClassCreator, conversions from subtype to base type
       will fail unless all use the same internal field placement. If
       this code can detect a mismatch then it will fail gracefully
       (e.g. a JS-side exception), and if not then it might mis-cast
       an object and cause Undefined Behaviour.

       If a given parent type uses a custom ClassCreator_InternalFields
       specialization then to ensure that subclasses always have the
       same placement, they "should" define their own policy like
       this:

       @code
       template <>
       struct ClassCreator_InternalFields< SubType >
           : ClassCreator_InternalFields< ParentType >
          {};
       @endcode

       That prohibits special internal field handling in the subtypes,
       but experience hasn't shown that subclasses need their own
       internal fields. Normaly a single internal field is all we need
       when binding native data. And when i say "normally", i mean
       "almost always." i haven't yet seen a use case which would benefit
       from more, though i can conceive of a couple.

       This must-match requirement is partially a side-effect of the
       library internally using the field count as a santiy check
       before trying to extract data from internal fields.
    */
    template <typename T>
    struct ClassCreator_InternalFields : ClassCreator_InternalFields_Base<T,1,0>
    {
    };


    /**
       The ClassCreator policy class responsible for doing optional
       class-specific binding-related work as part of the JS/Native
       object construction process.

       The default specialization does nothing (which is okay for the
       general case) but defines the interface which specializations
       must implement.
    */
    template <typename T>
    struct ClassCreator_WeakWrap
    {
        typedef typename TypeInfo<T>::NativeHandle NativeHandle;

        /**
           Similar to Wrap(), but this is called before the native constructor is called.
           It is rarely needed, but is necessary if one needs to manipulate the JS
           "this" object before the native object is constructed, so that the native ctor
           can access information stored in the JS-side internal fields.

           If this throws a native exception, construction of the
           object will fail and Unwrap() is called, passed
           (jsSelf,NULL), to clean up any data which this function might have
           stored in jsSelf.

           The argv object is the arguments passed to the constructor.

           The default implementation does nothing.
        */
        static void PreWrap( v8::Persistent<v8::Object> const & jsSelf, v8::Arguments const & argv )
        {
            return;
        }


        /**
           This operation is called one time from ClassCreator for each
           new object, directly after the native has been connected to
           a Persistent handle.
   
           Note that the ClassCreator code which calls this has already
           taken care of connecting nativeSelf to jsSelf. Client
           specializations of this policy may opt to add their own
           binding mechanisms, e.g. to allow CastToJS<T>() to work.

           Clients should do any bindings-related cleanup in
           Factory::Destruct() or Unwrap(), as appropriate for their
           case.

           Ownership of the objects is unchanged by calling this.

           On error, this function may throw a native exception. If
           that happens, ClassCreator will call
           Unwrap(jsSelf,nativeHandle) and
           Factory<T>::Destruct(nativeSelf) to clean up, and will then
           propagate the exception.

           The default implementation does nothing.
        */
        static void Wrap( v8::Persistent<v8::Object> const & jsSelf, NativeHandle nativeSelf )
        {
            return;
        }
        
        /**
           This is called from the ClassCreator-generated destructor,
           just before the native destructor is called. If nativeSelf
           is NULL then it means that native construction failed,
           but implementations must (if necessary) clean up any data
           stored in jsSelf by the PreWrap() function.
        
           Specializations may use this to clean up data stored in
           other internal fields of the object (_not_ the field used
           to hold the native itself - that is removed by the
           framework). Optionally, such cleanup may be done in the
           corresponding Factory::Destruct() routine, and must be done
           there if the dtor will need access to such data.

           Note that when this is called, jsSelf and nativeSelf are
           about to be destroyed, so do not do anything crazy with the
           contents of jsSelf and DO NOT destroy nativeSelf (that is
           the job of the ClassCreator_Factory policy).

           Ownership of the objects is unchanged by calling this.

           Unwrap() is called during destruction or when construction
           fails (via a native exception), so any cleanup required for
           the jsSelf object can be delegated to this function, as
           opposed to being performed (and possibly duplicated) in
           PreWrap() and/or Wrap().
           
           The default implementation does nothing.
        */
        static void Unwrap( v8::Handle<v8::Object> const & jsSelf, NativeHandle nativeSelf )
        {
            return;
        }
    };

    /**
       A utility function primarily intended to support various
       ClassCreator policy implementations.

       This function tries to extract a native handle from jo by
       looking in the internal field defined by
       ClassCreator_InternalFields<T>::NativeIndex.  If a native is
       found in that field and it is the same as nh, then jo is
       returned. If none is found, jo's prototype object is searched,
       recursively, until either nh is found in the prototype chain or
       the end of the chain is reached. If a match is found, the JS
       object in which the native was found is returned.

       If nh is not found anywhere in the chain, an empty handle is
       returned.

       Note that T must be non-cv qualified, so it is generally
       undesirable to allow the compiler to deduce its type from the
       parameter. Thus the T template parameter should not be omitted
       from calls to this function.
    */
    template <typename T>
    v8::Handle<v8::Object> FindHolder( v8::Handle<v8::Object> jo,
                                       T const * nh )
    {
        if( !nh || jo.IsEmpty() ) return v8::Handle<v8::Object>();
        typedef TypeInfo<T> TI;
        typedef T * NH;
        typedef ClassCreator_InternalFields<T> IFields;
        void const * ext = (jo->InternalFieldCount() == IFields::Count)
            ? jo->GetPointerFromInternalField(IFields::NativeIndex)
            : NULL;
        if( ext == nh ) return jo;
        else if( ! ext )
        {
            v8::Local<v8::Value> proto = jo->GetPrototype();
            return ( !proto.IsEmpty() && proto->IsObject() )
                ? FindHolder<T>( v8::Local<v8::Object>( v8::Object::Cast( *proto ) ), nh )
                : v8::Handle<v8::Object>();
        }
        else if( ext != nh )
        { // Bound native, but the wrong one. Keep looking...
            v8::Local<v8::Value> proto = jo->GetPrototype();
            return ( !proto.IsEmpty() && proto->IsObject() )
                ? FindHolder<T>( v8::Local<v8::Object>( v8::Object::Cast( *proto ) ), nh )
                : v8::Handle<v8::Object>();
        }
        else
        { // can this happen?
            v8::ThrowException(v8::String::New("UNHANDLED CONDITION IN native FindHolder<>()!\n"));
            return jo;
        }
    }

#if 0
    namespace Detail
    {
        template <typename Context>
        struct SharedType : public Context
        {
        private:
            SharedType(){}
        public:
            static SharedType & Instance()
            {
                static SharedType bob;
                return bob;
            }
        };
    }
#endif
    /**
       A basic Native-to-JS class binding mechanism. This class does
       not aim to be a monster framework, just something simple,
       mainly for purposes of showing (and testing) what the core
       v8::convert can do.

       The framework must know how to convert JS objects to T objects,
       and for this to work client code must define a JSToNative<T>
       specialization in this manner:

       @code
           template <>
           struct JSToNative<T>
           : JSToNative_ClassCreator<T>
           {};
       @endcode

       If the internal field configuration must be customized then the
       client must define the number of fields by
       specializing/customizing the ClassCreator_InternalFields<T>
       policy class. Additionally, if the client does NOT use the
       above JSToNative<T> implementation then he should create his
       implementation by subclassing
       JSToNative_ObjectWithInternalFields<T,N,M>, where (N,M) are the
       number of internals fields and the index of the field where the
       native object is to be stored. See JSToNative_ClassCreator
       for an example.
       
       TODOs:

       - Certain operations may not work properly when inheriting
       bound classes from JS space, and possibly not even when
       inheriting bound natives from one another. That depends on
       several factors too complex to summarize here.
       
       - See how much of the v8::juice::cw::ClassWrap 
       inheritance-related code we can salvage for re-use here.
       
       - There are known problems when trying to bind inherited methods
       when the parent class has no bound them to JS. i'm not sure how
       i can fix the templates to get this working.
    */
    template <typename T>
    class ClassCreator
    {
    private:
        typedef ClassCreator_InternalFields<T> InternalFields;
        typedef ClassCreator_WeakWrap<T> WeakWrap;
        v8::Persistent<v8::FunctionTemplate> ctorTmpl;
        v8::Handle<v8::ObjectTemplate> protoTmpl;
        bool isSealed;
        typedef ClassCreator_Factory<T> Factory;
        static void weak_dtor( v8::Persistent< v8::Value > pv, void *nobj )
        {
            using namespace v8;
            //std::cerr << "Entering weak_dtor<>(native="<<(void const *)nobj<<")\n";
            Local<Object> jobj( Object::Cast(*pv) );
            T * native = CastFromJS<T>( pv );
            if( !native )
            {
                /* see: http://code.google.com/p/v8-juice/issues/detail?id=27

                When i call pv.Dispose(), this function is getting called twice,
                and the second time won't work. i'm going to igore (return w/o
                side-effects) this for now for the sake of avoiding a crash
                which i'm seeing only on 64-bit platforms.

                However, even if i return here, v8 is crashing with a
                !NEAR_DEATH assertion right after the second call is made.

                The extra pair of Dispose()/Clear() calls seems to eliminate that
                crash, but the fact that this code block is hit AT ALL is a
                sign of a problem - the dtor shouldn't be called twice!
                */
                pv.Dispose();
                pv.Clear();
#if 0
                assert( 0 && "weak_dtor() got no native object!");
#endif
                return;
            }
            else
            {
                /**
                   Reminder: the FindHolder() bits are here to
                   assist when the bound native exists somewhere in the
                   prototype chain other than jobj itself. In that case,
                   jobj is valid but we cannot clear out the native handle
                   internal field on it because it has no internal fields
                   (or none that belong to us).

                   To fix this properly we have to be able to know
                   _exactly_ which JS object in the prototype chain nh is
                   bound to.
                */
                v8::Handle<v8::Object> nholder = FindHolder<Type>( jobj, native );
#if 1
                assert( ! nholder.IsEmpty() );
                WeakWrap::Unwrap( nholder /*jobj? subtle difference*/, native );
                if( nholder.IsEmpty() || (nholder->InternalFieldCount() != InternalFields::Count) )
                {
                    StringBuffer msg;
                    msg << "SERIOUS INTERNAL ERROR:\n"
                        << "ClassCreator<T>::weak_dtor() "
                        << "validated that the JS/Native belong together, but "
                        << "FindHolder() returned an "
                        << (nholder.IsEmpty() ? "empty" : "invalid")
                        << " handle!\n"
                        << "From JS=@"<<(void const *)nobj
                        << ", Converted to Native=@"<<(void const *)native
                        << ", nholder field count="<<nholder->InternalFieldCount()
                        << ", jobj field count="<<jobj->InternalFieldCount()
                        << "\nTHIS MAY LEAD TO A CRASH IF THIS JS HANDLE IS USED AGAIN!!!\n"
                        ;
                    Factory::Delete(native);
                    pv.Dispose(); pv.Clear(); /* see comments below!*/
                    v8::ThrowException(msg);
                    return;
                }
                else
                {
                    nholder->SetInternalField( InternalFields::NativeIndex, Null() );
                    Factory::Delete(native);
                }
#else
                WeakWrap::Unwrap( nholder, native );
                nholder->SetInternalField( InternalFields::NativeIndex, Null() );
                Factory::Delete(native);
#endif
            }
            /*
              According to the v8 gurus i need to call pv.Dispose()
              instead of pv.Clear(), but if i do then this dtor is
              being called twice. If i don't call it, v8 is crashing
              sometime after this function with a !NEAR_DEATH
              assertion.
            */
            pv.Dispose();
            pv.Clear();
        }

        /**
           Gets installed as the NewInstance() handler for T.
         */
        static v8::Handle<v8::Value> ctor_proxy( v8::Arguments const & argv )
        {
            using namespace v8;
            if(ClassCreator_AllowCtorWithoutNew<T>::Value)
            {
                /**
                   Allow construction without 'new' by forcing this
                   function to be called in a ctor context...
                */
                if (!argv.IsConstructCall()) 
                {
                    const int argc = argv.Length();
                    Handle<Function> ctor( Function::Cast(*argv.Callee()));
                    std::vector< Handle<Value> > av(static_cast<size_t>(argc),Undefined());
                    for( int i = 0; i < argc; ++i ) av[i] = argv[i];
                    return ctor->NewInstance( argc, &av[0] );
                }
            }
            else
            {
                /**
                   Why have this limitation? If we don't, v8 pukes
                   when the ctor is called, with
                   "v8::Object::SetInternalField() Writing internal
                   field out of bounds".
                */
                if (!argv.IsConstructCall()) 
                {
                    return ThrowException(String::New("This constructor cannot be called as function!"));
                }
            }
            Local<Object> const & jobj( argv.This()
                                        /*CastToJS<T>(*nobj)
                                          
                                        We are not yet far enough
                                        along in the binding that
                                        CastToJS() can work. And it
                                        can't work for the generic
                                        case, anyway.
                                        */);
            if( jobj.IsEmpty() ) return jobj /* assume exception*/;
            Persistent<Object> self( Persistent<Object>::New(jobj) );
            T * nobj = NULL;
            try
            {
                WeakWrap::PreWrap( self, argv  );
                nobj = Factory::Create( self, argv );
                if( ! nobj )
                {
                    return CastToJS<std::exception>(std::runtime_error("Native constructor failed."));
                }
                WeakWrap::Wrap( self, nobj );
                self.MakeWeak( nobj, weak_dtor );
                self->SetPointerInInternalField( InternalFields::NativeIndex, nobj )
                    /* We do this after the call to Wrap() just in case the Wrap() impl
                       accidentally writes to this field. In that case we end up
                       losing the data they stored there. So this is just as evil as
                       adding the internal field before Wrap(), but only when the
                       client mis-uses the internal fields.
                    */
                    ;
            }
            catch(std::exception const &ex)
            {
                WeakWrap::Unwrap( self, nobj );
                if( nobj ) Factory::Delete( nobj );
                self.Clear();
                return CastToJS(ex);
            }
            catch(...)
            {
                WeakWrap::Unwrap( self, nobj );
                if( nobj ) Factory::Delete( nobj );
                self.Clear();
                return v8::ThrowException(v8::String::New("Native constructor threw an unknown exception!"));
            }
            return self;
        }

        ClassCreator()
            : ctorTmpl(v8::Persistent<v8::FunctionTemplate>::New( v8::FunctionTemplate::New(ctor_proxy) )),
              protoTmpl(v8::Persistent<v8::ObjectTemplate>::New( ctorTmpl->PrototypeTemplate() )),
              isSealed(false)
        {
            if( InternalFields::Count > 0 )
            {
                ctorTmpl->InstanceTemplate()->SetInternalFieldCount(InternalFields::Count);
            }
        }
    public:
        /**
           The native type being bound to JS.
        */
        typedef T Type;

        /**
           Returns the shared instance of this class.
        */
        static ClassCreator & Instance()
        {
            static ClassCreator bob;
            return bob;
        }

        /**
           Returns this class' prototype object.
        */
        inline v8::Handle<v8::ObjectTemplate> Prototype()
        {
            return this->protoTmpl;
        }

        /**
           Returns this class' constructor template object.
        */
        inline v8::Handle<v8::FunctionTemplate> CtorTemplate()
        {
            return this->ctorTmpl;
        }

        /**
           Returns this class' constructor template.

           ACHTUNG: after this is called, changes made to the Prototype()
           object might not have any effect. Thus this should only be
           called after the prototype object has been fully set up.
           (i have no idea why v8 behaves this way.)

           After calling this, IsSealed() will return true.
        */
        inline v8::Handle<v8::Function> CtorFunction()
        {
            // In my experience, if GetFunction() is called BEFORE setting up
            // the Prototype object, v8 gets very unhappy (class member lookups don't work?).
            this->isSealed = true;
            return this->ctorTmpl->GetFunction();
        }

        /**
           Returns true if CtorFunction() has been called. See that
           function for why.
        */
        inline bool IsSealed() const
        {
            return this->isSealed;
        }

        /**
           Creates a new instanced of the object via the JS API.
           It calls ClassCreator_Factory<T>::Create(), passing it argv,
           to instantiate the object. On success a JS handle to the object
           is returned, and the caller can do:

           @code
           T * t = CastFromJS<T>(theHandle);
           @endcode

           To get the native object (which is owned by v8).
        */
        inline v8::Handle<v8::Object> NewInstance( int argc, v8::Handle<v8::Value> argv[] )
        {
            return this->CtorFunction()->NewInstance(argc, argv);
        }
        /**
           Convenience method to add the given property to the
           prototype. Returns this object, for call chaining.

           CastToJS<ValueT>(val) must be valid or a compile-time
           error will be triggered.
        */
        template <typename ValueT>
        inline ClassCreator & Set( char const * name, ValueT val )
        {
            this->protoTmpl->Set(v8::String::New(name), CastToJS<ValueT>(val));
            return *this;
        }
        /**
           Equivalent to Set().
        */
        template <typename ValueT>
        inline ClassCreator & operator()( char const * name, ValueT val )
        {
            return this->Set(name, val);
        }
        /**
           Overload to avoid an ambiguity.
        */
        inline ClassCreator & operator()( char const * name, v8::InvocationCallback val )
        {
            return this->Set(name, val);
        }

        /**
           Adds CtorFunction() to dest using the given property name.
           This implicitly "seals" the class (see CtorFunction() for
           details).
        */
        inline void AddClassTo( char const * thisClassName, v8::Handle<v8::Object> & dest )
        {
            dest->Set(v8::String::New(thisClassName),
                      this->CtorFunction());
        }

        /**
           Destroys the given object by disconnecting its associated
           native object and calling the native destructor function
           for it.

           If jo cannot be converted to a T then false is
           returned. Otherwise the true is returned and the native
           object referenced by jo is no longer valid (it should not
           be used by JS code).

           Native functions bound to that object should take care to
           bail out with an exception once the native pointer is gone,
           as opposed to blindly stepping on its null/dangling pointer
           (which _might_ have been re-allocated to a different
           object, even of a different type, in the mean time).
        */
        static bool DestroyObject( Handle<Object> const & jo )
        {
            T * t = CastFromJS<T>(jo);
            if( ! t ) return false;
            else
            {
                v8::Persistent<v8::Object> p( v8::Persistent<v8::Object>::New( jo ) );
                p.ClearWeak(); // avoid a second call to weak_dtor() via gc!
                weak_dtor( p, t );
                return true;
            }
        }
        /**
           If jv is empty or !jv->IsObject() then false is returned,
           otherwise it returns the result of
           DestroyObject(Handle<Object>).
        */
        static bool DestroyObject( v8::Handle<v8::Value> const & jv )
        {
            return (jv.IsEmpty() || !jv->IsObject())
                ? false
                : DestroyObject( v8::Handle<v8::Object>( v8::Object::Cast(*jv) ) );
        }

        /**
           A v8::InvocationCallback implementation which calls
           DestroyObject( argv.This() ).

           It is intended to be used as a "manual destructor" for
           classes which need it. The canonical examples are
           Stream.close() and Database.close().

           This function is not called DestroyObject to avoid name
           collisions during binding using Set(...,DestroyCallback).
        */
        static v8::Handle<v8::Value> DestroyObjectCallback( v8::Arguments const & argv )
        {
                return DestroyObject(argv.This()) ? v8::True() : v8::False();
        }

        /**
           Class ClassCreator_Init<T>::Setup(dest) to initialize the
           class bindings for the native class. If that function
           throws then the exception is converted to a JS exception,
           otherwise success is assumed and dest is returned. We do
           not return the new class' constructor because the bindings
           may actually set up things other than the actual class, and
           that return value wouldn't give access to them to the
           caller.
        */
        v8::Handle<v8::Value> InitBindings( v8::Handle<v8::Object> dest )
        {
            try
            {
                typedef ClassCreator_Init<T> S;
                S::InitBindings( dest );
                return dest;
            }
            catch(std::exception const & ex)
            {
                return CastToJS(ex);
            }
            catch(...)
            {
                return v8::ThrowException(v8::Exception::Error(v8::String::New("Native class bindings threw an unspecified exception during setup.")));
            }
        }

        /**
            Tells v8 that this bound type inherits ParentType. 
            ParentType _must_ be a class wrapped by ClassCreator. 
            This function throws if it believes something evil is 
            afoot (e.g. ClassCreator<ParentType>::Instance() has not 
            yet been sealed). We require that the parent class be 
            sealed to avoid accidental mis-use caused by registering
            a subclass of a class which has not yet been bound (and may
            may never be bound).
        */
        template <typename ParentType>
        void Inherit()
        {
            typedef ClassCreator<ParentType> PT;
            PT & p(PT::Instance());
            if( ! p.IsSealed() )
            {
                throw std::runtime_error("ClassCreator<ParentType> has not been sealed yet!");
            }
            this->CtorTemplate()->Inherit( p.CtorTemplate() );
        }
        
    };

    /**
       Intended to be the base class for JSToNative<T> specializations
       when T is JS-bound using ClassCreator.

       This particular implementation must be defined _after_
       ClassCreator_InternalFields<T> is defined. If the caller will
       not specialize that type then this is irrelevant, but when
       specializing it, it must come before this JSToNative
       implementation is instantiated.
    */
    template <typename T>
    struct JSToNative_ClassCreator :
        JSToNative_ObjectWithInternalFields<T,
                                            ClassCreator_InternalFields<T>::Count,
                                            ClassCreator_InternalFields<T>::NativeIndex,
                                            ClassCreator_SearchPrototypeForThis<T>::Value
                                            >
    {
    };

#if !defined(DOXYGEN)
    namespace Detail
    {
        namespace cv = v8::convert;
        namespace tmp = cv::tmp;
        /**
           A base class for the Factory_CtorForwarder#
           family of classes.
        */
        template <typename T>
        struct Factory_CtorForwarder_Base
        {
            typedef typename cv::TypeInfo<T>::Type Type;
            typedef typename cv::TypeInfo<T>::NativeHandle NativeHandle;
            static void Destroy( NativeHandle nself )
            {
                delete nself;
            }
        protected:
            /**
               If argv.Length() >= Arity then this function ignores errmsg and
               returns true, otherwise it writes a descriptive error message
               to errmsg and return false.
            */
            static bool argv_check( v8::Arguments const & argv, int Arity )
            {
                if( argv.Length() >= Arity ) return true;
                else
                {
                    cv::StringBuffer msg;
                    msg << "constructor requires " << Arity << " arguments!";
                    throw std::range_error(msg.Content().c_str());
                    return false;
                }
            }
        };

        /**
           Internal dispatch routine. CTOR _must_ be a convert::CtorForwardN implementation,
           where N is 0..N.
        */
        template <typename T,typename CTOR>
        struct CtorFwdDispatch
        {
            typedef typename cv::TypeInfo<T>::NativeHandle NativeHandle;
            static NativeHandle Instantiate( v8::Arguments const &  argv )
            {
                return CTOR::Ctor( argv );
            }
        };
        /**
           Internal dispatch end-of-list routine.
        */
        template <typename T>
        struct CtorFwdDispatch<T,tmp::NilType>
        {
            typedef typename cv::TypeInfo<T>::NativeHandle NativeHandle;
            static NativeHandle Instantiate( Arguments const &  argv )
            {
                return 0;
            }
        };
        /**
           Internal type to dispatch a v8::Arguments list to one of
           several a bound native constructors, depending on on the
           argument count.
        
           List MUST be a tmp::TypeList< ... > containing ONLY
           convert::CtorFowarderXXX implementations, where XXX is an
           integer value.
        */
        template <typename T,typename List>
        struct CtorFwdDispatchList
        {
            typedef typename cv::TypeInfo<T>::NativeHandle NativeHandle;
            /**
               Tries to dispatch Arguments to one of the constructors
               in the List type, based on the argument count.
             */
            static NativeHandle Instantiate( Arguments const &  argv )
            {
                typedef typename List::Head CTOR;
                typedef typename List::Tail Tail;
                return ( (CTOR::Arity < 0) || (CTOR::Arity == argv.Length()) )
                    ?  CtorFwdDispatch< T, CTOR >::Instantiate(argv )
                    : CtorFwdDispatchList<T,Tail>::Instantiate(argv);
            }
        };
        /**
           End-of-list specialization.
        */
        template <typename T>
        struct CtorFwdDispatchList<T,tmp::NilType>
        {
            typedef typename cv::TypeInfo<T>::NativeHandle NativeHandle;
            /** Writes an error message to errmsg and returns 0. */
            static NativeHandle Instantiate( Arguments const &  argv )
            {
                cv::StringBuffer msg;
                msg << "No native constructor was defined for "<<argv.Length()<<" arguments!\n";
                throw std::range_error(msg.Content().c_str());
                return 0;
            }
        };
    }
#endif // !DOXYGEN

    template <typename T,typename CtorForwarderList>
    struct ClassCreator_Factory_CtorForwarder : Detail::Factory_CtorForwarder_Base<T>
    {
        typedef typename TypeInfo<T>::Type Type;
        typedef typename TypeInfo<T>::NativeHandle NativeHandle;
        static NativeHandle Create( v8::Persistent<v8::Object> jself, Arguments const &  argv )
        {
            return Detail::CtorFwdDispatchList<T,CtorForwarderList>::Instantiate( argv );
        }
        static void Delete( NativeHandle obj )
        {
            delete obj;
        }
    };

}}// namespaces

#endif /* CODE_GOOGLE_COM_P_V8_CONVERT_CLASS_CREATOR_HPP_INCLUDED */
