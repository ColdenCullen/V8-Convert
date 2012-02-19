#if !defined(CODE_GOOGLE_COM_CVV8_EXPAT_H_INCLUDED)
#define CODE_GOOGLE_COM_CVV8_EXPAT_H_INCLUDED 1

#include <expat.h>
#include <v8.h>
#include <string>

/**
   The expat namespace houses a libexpat-based XML parser class for
   binding to JS.
*/
namespace cvv8 {
    template <typename T>
    struct ClassCreator_WeakWrap;

namespace expat {

    /**
       Class for binding basic libexpat functionality to JS.
       Intended for use with the v8::juice::cw API.

       JS API:

       Class name = ExpatParser

       Properties:

       - userData = arbitrary client data used by the callback
       routines.


       Functions:

       - parse(string xml,bool finished)

       Parses the given XML, triggering the handler callbacks as it
       parses.  When parsing XML incrementally (e.g. line by line),
       pass false as the second parameter EXCEPT for the last
       line of input, where true must be passed. If all XML is to
       be parsed in one go, pass true.


       Callback functions which the client should override:
       
       - startNode(userData,string name,array attr)

       Is called when an XML node is opened. attr is a set of
       key/value pairs containing the node's attributes.

       - endNode( userData, string name )

       Is called when an XML node is closed.
       
       - charHandler( userData, string text, int textLength )

       Is called when CDATA is read.
       
    */
    class ExpatJS
    {
    public:
        /** Internal implementation detail. */
        struct Impl;
        ExpatJS();
        ~ExpatJS();

        /**
           Parses the given XML string. If finished is false then xml
           need not be complete XML. This can be called many times as
           XML input becomes available. Pass a true value for finished
           at the end of collecting input.

           This function throws a JS-side exception on error, so the
           return value is only relevant if this is called from C++
           code, as opposed to JS.

           On error, or if finished is true, the internal XML
           parser state is reset, so it may be used again
           to parse another XML tree.
        */
        bool Parse( std::string const & xml, bool finished );

        /**
           Resets the XML parser state, but keeps the existing
           callback handlers. It is not normally necessary to call
           this - it would only be needed when you would like to
           explicitly discard the results of an ongoing incremental
           parse.
        */
        void Reset();
        
        /**
           Adds the JS/C++ bindings for this class to the given target.
           Returns target, for reasons lost unto history.
        */
        static void SetupBindings( v8::Handle<v8::Object> const & target );
    private:
        friend class ClassCreator_WeakWrap<ExpatJS>;
        Impl * impl;
    };
} }


#endif // CODE_GOOGLE_COM_CVV8_EXPAT_H_INCLUDED
