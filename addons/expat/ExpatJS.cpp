#include "ExpatJS.h"

#include <cvv8/ClassCreator.hpp>
#include <cvv8/XTo.hpp>
#include <map>
#include <iostream>
#ifndef CERR
#define CERR std::cerr << __FILE__ << ":" << std::dec << __LINE__ << " : "
#endif

typedef v8::Persistent<v8::Function> PFuncHnd;
typedef v8::Persistent<v8::Value> PValHnd;
typedef v8::Handle<v8::Function> FuncHnd;
typedef v8::Handle<v8::Value> ValHnd;

#define JSTR(X) v8::String::New(X)
#define TOSS(X) v8::ThrowException(JSTR(X))
#define TOSSV(X) v8::ThrowException(X)

namespace cvv8 {
    CVV8_TypeName_DECL((expat::ExpatJS));
    CVV8_TypeName_IMPL((expat::ExpatJS),"ExpatParser");

namespace expat {
    /** Forwards XML StartNode events to JS space. ud MUST be-a (ExpatJS::Impl*). */
    static void XMLCALL start_node( void * ud, const char * name, const char ** attr );
    /** Forwards XML EndNode events to JS space. ud MUST be-a (ExpatJS::Impl*). */
    static void XMLCALL end_node( void * ud, const char * );
    /** Forwards XML CharHandler events to JS space. ud MUST be-a (ExpatJS::Impl*). */
    static void XMLCALL char_handler( void * ud, const char * txt, int len );
    /** No-op event handler. */
//     static v8::Handle<v8::Value> NoopEventHandler( v8::Arguments const & argv )
//     {
//         return v8::Undefined();
//     }

    /**
       Holder for names of standard callback functions and data.
    */
    struct Strings
    {
        static char const * startNode;
        static char const * endNode;
        static char const * charHandler;
        static char const * userData;
    };
    char const * Strings::startNode = "startNode";
    char const * Strings::endNode = "endNode";
    char const * Strings::charHandler = "charHandler";
    char const * Strings::userData = "userData";
    
    struct ExpatJS::Impl
    {
        /** libexpat parser object. */
        XML_Parser ps;
        /** The JS-side 'this' object for the ExpatJS object holding this object. */
        v8::Handle<v8::Object> jself; // we assume this is Persistent elsewhere
        Impl()
            : ps(0),
              jself()
        {
            this->reset();
            //CERR << "Impl() @"<<(void const *)this<<'\n';
        }
        ~Impl()
        {
            //CERR << "~Impl() @"<<(void const *)this<<'\n';
            XML_ParserFree(ps);
        }
        /**
            Returns jself->Get(Strings::userData), or v8::Undefined()
            if it is not set.
        */
        v8::Handle<v8::Value> userData()
        {
            const v8::Handle<v8::Value> rc = this->jself->Get( JSTR(Strings::userData) );
            if( rc.IsEmpty() ) return v8::Undefined();
            else return rc;
        }
        /** Initializes or resets this->ps. */
        void reset()
        {
            if( ! this->ps )
            {
                this->ps = XML_ParserCreate(NULL);
                if( ! this->ps )
                {
                    throw std::runtime_error("XML_ParserCreate() failed (OOM?)");
                }
            }
            else
            {
                XML_ParserReset( this->ps, NULL );
            }
            XML_SetElementHandler( this->ps, start_node, end_node );
            XML_SetCharacterDataHandler( this->ps, char_handler );
            XML_SetUserData( this->ps, this );
        }

        /**
           Installs the handler for a given callback routine. If
           !func->IsFunction() it throws a JS-side exception.
        */
        void setHandler( char const * n, v8::Handle<v8::Value> func )
        {
            if( func.IsEmpty() || !func->IsFunction() )
            {
                StringBuffer msg;
                msg << TypeName<ExpatJS>::Value << '.' << n
                    << " must be-a Function!";
                TOSSV(msg);
                return;
            }
            this->jself->Set( JSTR(n), FuncHnd( v8::Function::Cast(*func) ) );
        }
        /**
           Gets the handler callback function associated with n, or an
           empty handle if n is not set or is not-a Function.
        */
        FuncHnd getHandler( char const * n )
        {
            ValHnd const h = this->jself->Get( JSTR(n) );
            return (!h.IsEmpty() && h->IsFunction() )
                ? FuncHnd( v8::Function::Cast(*h) )
                : FuncHnd();
        }
    };

}} // v8::juice::expat

namespace cvv8 {
    using expat::ExpatJS;

    template <>
    struct ClassCreator_WeakWrap<ExpatJS> {
        typedef ExpatJS * NativeHandle;
        static void PreWrap( v8::Persistent<v8::Object> const &, v8::Arguments const & )
        {
            return;
        }
        
        static void Wrap( v8::Persistent<v8::Object> const & jsSelf, NativeHandle nativeSelf )
        {
            nativeSelf->impl->jself = jsSelf;
        }

        static void Unwrap( v8::Handle<v8::Object> const & jsSelf, NativeHandle nativeSelf )
        {
            nativeSelf->impl->jself.Clear();
        }
    };

    template <>
    struct JSToNative<ExpatJS> : JSToNative_ClassCreator<ExpatJS> {};
    
} // ::cvv8

namespace cvv8 { namespace expat {

    ExpatJS::ExpatJS()
        : impl(new ExpatJS::Impl)
    {
    }
    ExpatJS::~ExpatJS()
    {
        delete this->impl;
    }
    
    void ExpatJS::Reset()
    {
        this->impl->reset();
    }

    bool ExpatJS::Parse( std::string const & chunk, bool finished )
    {
        if( chunk.empty() ) return true;
        char const * inp = chunk.c_str();
        bool rc = true;
        if( XML_STATUS_ERROR == XML_Parse( this->impl->ps,
                                           inp,
                                           static_cast<int>(chunk.size()),
                                           finished ? 1 : 0 ) )
        {
            rc = false;
            StringBuffer msg;
            msg << "XML parse error at input line "
                << XML_GetCurrentLineNumber(this->impl->ps)
                << ": "
                << XML_ErrorString(XML_GetErrorCode(this->impl->ps))
                //<< ": input=["<<chunk<<"]"
                << '.'
                ;
            TOSSV(msg);
            this->impl->reset();
        }
        if( rc && finished )
        {
            this->impl->reset();
        }
        return rc;
    }
    

    static void XMLCALL start_node( void * ud, const char * name, const char ** attr )
    {
        //CERR << "start_node()\n";
        ExpatJS::Impl * impl;
        impl = static_cast<ExpatJS::Impl *>( ud );
        //if( impl->startNode.IsEmpty() ) return;
        FuncHnd const & cb = impl->getHandler(Strings::startNode);
        if( cb.IsEmpty() ) return;
        typedef std::map< std::string, std::string > MapT;
        v8::Handle<v8::Object> oattr;
        char const * key = 0;
        char const * val = 0;
        if( attr && attr[0] )
        {
            oattr = v8::Handle<v8::Object>( v8::Object::New() );
            ObjectPropSetter<> set(oattr);
            for( int i = 0; attr[i]; i += 2 )
            {
                key = attr[i];
                val = attr[1+i];
                set( key, val ? val : "");
            }
        }
        enum { avlen = 3 };
        ValHnd av[avlen] = {
            impl->userData(),
            CastToJS( name ),
            v8::Undefined()
        };
        if( ! oattr.IsEmpty() ) av[2] = oattr;
        cb->Call( impl->jself, avlen, av );
    }

    static void XMLCALL end_node( void * ud, const char * name )
    {
        ExpatJS::Impl * impl;
        impl = static_cast<ExpatJS::Impl *>( ud );
        FuncHnd const & cb = impl->getHandler(Strings::endNode);
        if( cb.IsEmpty() ) return;
        enum { avlen = 2 };
        ValHnd av[avlen] = {
            impl->userData(),
            CastToJS( name )
        };
        cb->Call( impl->jself, avlen, av );
    }

    static void XMLCALL char_handler( void * ud, const char * txt, int len )
    {
        ExpatJS::Impl * impl;
        impl = static_cast<ExpatJS::Impl *>( ud );
        FuncHnd const & cb = impl->getHandler(Strings::charHandler);
        if( cb.IsEmpty() ) return;
        enum { avlen = 3 };
        ValHnd av[avlen] = {
            impl->userData(),
            v8::String::New(txt,len),
            CastToJS( len )
        };
        cb->Call( impl->jself, avlen, av );
    }

//     template <char const *&PropName>
//     v8::Handle<v8::Value> ExpatJS::jsCBGetter()
//     {
//         Impl::CBMap::const_iterator it = this->impl->cb.find( PropName );
//         if( this->impl->cb.end() == it ) return v8::Undefined();
//         return it->second;
//     }
//     template <char const *&PropName>
//     void ExpatJS::jsCBSetter( v8::Handle<v8::Value> const & v )
//     {
//         this->impl->setHandler( PropName, v );
//     }

    void ExpatJS::SetupBindings( v8::Handle<v8::Object> const & target )
    {
        typedef ExpatJS N;
        typedef ClassCreator<N> CC;
        CC & cc( CC::Instance() );
        if( cc.IsSealed() )
        {
            cc.AddClassTo(TypeName<N>::Value, target);
            return;
        }
        {
            v8::Handle<v8::ObjectTemplate> proto = cc.Prototype();
            proto->Set( JSTR(Strings::userData), v8::Undefined() );

        }

        cc("destroy", CC::DestroyObjectCallback)
            ("parse", MethodTo<InCa, N, bool (std::string const &,bool), &N::Parse>::Call)
            //ICM::M2::Invocable<bool,std::string const &,bool,&N::Parse>
            ("reset", MethodTo<InCa, N, void (), &N::Reset>::Call)
            //cb = ICM::M0::Invocable<void,&N::Reset>
            ;

        cc.AddClassTo( TypeName<N>::Value, target);
    }

} } // cvv8::expat


#undef JSTR
#undef TOSS
#undef TOSSV
