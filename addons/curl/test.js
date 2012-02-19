var banner = {
    start:'>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>',
      end:'<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<'
        };

function testOne()
{
    print(banner.start);
    print( arguments.callee.name+"()" );
    var c = new Curl();
    var inBody = new Curl.ByteArray();
    var inHead = new Curl.ByteArray();
    c.setOpt({
        url:'http://code.google.com/p/v8-juice/wiki/PluginCurl',
        userAgent:"Google Chrome, kind of.",
        //verbose:true,
        //noBody:true,
        writeFunction:function writeFunction(data,ud)
        {
            var len = data.length;
            print(arguments.callee.name+"() "+len+" bytes: ["+data+"]");
            ++ud.count;
            inBody.append(data);
            data.destroy();
            return len;
        },
        writeData:{count:0},
        //header:true,
        headerFunction:function headerFunction(data,ud)
        {
            var len = data.length;
            print(arguments.callee.name+"() "+len+
                  " bytes: ["+data+"]");
            ++ud.count;
            inHead.append(data);
            data.destroy();
            return len;
        },
        headerData:{count:0}
    });
    var rc = c.easyPerform();
    print( "c.easyPerform() rc =",rc);
    print(c,'=',JSON.stringify(c,undefined,2));
    if(!rc){
        print("Fetched headers: "+inHead);
        print("Fetched body: "+inBody);
    }
    if(inHead) inHead.destroy();
    if(inBody) inBody.destroy();
    c.destroy();
    print(banner.end);
};


function testFour()
{
    /**
       v8 weirdness/bug:

       If we set an slist property, e.g. httpHeader to an invalid
       value (e.g. an integer) as part of setOpt(object), v8 crashes
       when the function throws. If we do it as part of
       setOpt(key,val), it does not.
    */
    print(banner.start);
    print( arguments.callee.name+"()" );
    var c = new Curl();
    var o = {
        port:80,
        verbose:true,
        httpHeader:["Host: www.google.com","Accept-Encoding: gzip","Accept: text/html"],
        //httpHeader:3, // v8 crash or "secondary" throw, depending on the workarounds in the native code
        url:'http://www.google.com'
    };
    rc = c.addOpt(o);
    print( "setOpt RC =",rc);
    rc = c.setOpt( Curl.OPT_HTTPHEADER,
                   //"" // causes error code or throws
                   ["Host: localhost","Accept-Encoding: gzip","Accept: text/html"]
                   );
    print( "setOpt RC =",rc);
    print( "c =",JSON.stringify(c,undefined,2));
    c.easyPerform();
    c.destroy();
    print(banner.end);
}

function testCurlInfo()
{
    print(banner.start);
    print( arguments.callee.name+"()" );
//     for( var i = Curl.INFO_NONE; i < Curl.INFO_LASTONE; ++i )
//     {
//         print( i );
//     }
    var c = new Curl();
    var irc = c.getInfo( Curl.INFO_OS_ERRNO );
    print( 'irc =',irc);
    irc = c.getInfo( Curl.INFO_PRIMARY_IP );
    print( 'irc =',typeof irc,irc);
    c.destroy();
    print(banner.end);
}
function listProperties()
{
    print(banner.start);
    print( arguments.callee.name+"()" );
    for( var k in Curl )
    {
        print("Curl."+k,"= ["+Curl[k]+"]");
    }
    print(banner.end);
}

function testReader()
{
    Curl.ByteArray.enableDestructorDebug(true);
    print(banner.start);
    print( arguments.callee.name+"()" );
    var envelope = {
        "command": "wiki/list"
    };
    var postData = new Curl.ByteArray(JSON.stringify(envelope));
    var contentLength = postData.length;
    var baResponse;
    var c = new Curl();
    c.setOpt({
            url:'http://fossil.wanderinghorse.net/repos/cpdo/index.cgi/json',
            verbose:true,
            post:true,
            httpHeader:['Content-Length: '+contentLength,
                        'Content-Type: application/json'],
            writeFunction:function(data,ud){
                if(!baResponse) baResponse = new Curl.ByteArray();
                baResponse.append(data);
                var len = data.length;
                data.destroy();
                return len;
            },
            readFunction:function(len,ud)
            {
                print("readFunction("+len+") pos="+ud.pos);
                if( ud.pos >= contentLength ) return null;
                var clen = contentLength - ud.pos;
                var xlen = (len > clen) ? clen : len;
                var s = postData.slice( ud.pos, xlen );
                print("readFunction(",len,") sending",s.length,'bytes');
                ud.pos += xlen;
                return s;
            },
            readData:{
                pos:0
            }
        });
    var rc = c.easyPerform();
    postData.destroy();
    c.destroy();
    print("Response: "+baResponse);
    if(baResponse) {
        print(baResponse.stringValue());
        baResponse.destroy();
    }
    print(banner.end);

}

//listProperties();
testOne();
testFour();
testCurlInfo();
testReader();

