#if !defined(CODE_GOOGLE_COM_CVV8_CURL_H_INCLUDED)
#define CODE_GOOGLE_COM_CVV8_CURL_H_INCLUDED 1
/************************************************************************
libcurl bindings for the v8 JavaScript engine, based on the v8-juice
library.

Author: Stephan Beal (http://wanderinghorse.net/home/stephan/)

License: Public Domain

************************************************************************/

#include <v8.h>
#include <curl/curl.h>
/**
   The curl namespace houses a JS binding for the libcurl "easy" API.
*/
namespace cvv8 { namespace curl {

    /**
       Class for binding basic libcurl functionality to JS.
       Intended for use with the v8::juice::cw API.

       JS API:

       See: http://code.google.com/p/v8-juice/wiki/PluginCurl
    */
    class CurlJS
    {
    public:
        /** Internal implementation detail. */
        struct Impl;
        /**
           Internal details. In the public API only so some internal
           binding routines can get at it.
        */
        Impl * impl;
        /**
           Initializes a new curl handle using curl_easy_init().
        */
        CurlJS();
        /**
           Frees up internal resources.
        */
        ~CurlJS();

        CURL * Curl();
        
        /**
           See curl_easy_perform().
        */
        int EasyPerform();

        /**
           Equivalent to Pause( CURLPAUSE_ALL ).
        */
        int Pause();
        /**
           Equivalent to curl_easy_pause( this->Curl(), mask ).
        */
        int Pause( int mask );
        /**
           Equivalent to Pause( CURLPAUSE_CONT ).
        */
        int Resume();
        
        /**
           Adds the JS/C++ bindings for this class to the given target.
           Returns target, for reasons lost unto history.
        */
        static void SetupBindings( v8::Handle<v8::Object> const & target );

        /**
           Returns this type's JS-side class name.
        */
        static const char * ClassName()
        {
            return "Curl";
        }

	/** JS-convnetional toString(). */
        v8::Handle<v8::Value> toString() const;

        
        /**
           Analog to curl_easy_setopt(), but curlID must be one of our
           internally-supported options so we know which type
           conversion to use on val.
        */
        v8::Handle<v8::Value> SetOpt( int curlID, v8::Handle<v8::Value> const & val );

	/**
	   Requires k to be either a CURLOPT_xxx value or one of the
	   mapped "friendly" property names for the corresponding
	   CURLOPT_xxx option. The exact type of 'val' must match the
	   exepectations for the given option key.

	   Returns 0 on success, throws JS exception on error.
	*/
        v8::Handle<v8::Value> SetOpt( v8::Handle<v8::Value> const & k, v8::Handle<v8::Value> const & val );
        /**
           JS usage:

           @code
           myCurl.setOpt( { url:"htt://foo.bar", verbose:"true" ... });
           @endcode

           Replaces all options with the given ones, but does not "undo"
           settings previously made to options which are not in the
           new list.
           
           Returns the number of properties set.
        */
        v8::Handle<v8::Value> SetOpts( v8::Handle<v8::Value> const & obj );
        /**
           Like setOption(), but does not clear the list of options
           list before applying the new options.
        */
        v8::Handle<v8::Value> AddOpts( v8::Handle<v8::Value> const & obj );

	/**
	   Analog to curl_easy_getinfo(), but throws on error.
	*/
	v8::Handle<v8::Value> GetInfo( int flag );

    };

    
} } // namespaces


#endif // CODE_GOOGLE_COM_CVV8_CURL_H_INCLUDED
