var banner = {
    start:'>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>',
      end:'<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<'
        };

function testOne()
{
    print(banner.start);
    print( arguments.callee.name+"()" );
    var c = new Curl();
    c.setOpt({
        url:'http://code.google.com/p/v8-juice/wiki/PluginCurl',
        userAgent:"Google Chrome, kind of.",
        //verbose:true,
        //noBody:true,
        writeFunction:function writeFunction(data,len,ud)
        {
            print(arguments.callee.name+"()",data.length,"of",len,"bytes");
            ++ud.count;
            return data.length;
        },
        writeData:{count:0},
        //header:true,
        headerFunction:function headerFunction(data,len,ud)
        {
            print(arguments.callee.name+"()",data.length,"of",len,
                  "bytes:","["+data.substring(0,data.length-2)+"]");
            ++ud.count;
            return data.length;
        },
        headerData:{count:0}
    });
    var rc = c.easyPerform();
    print( "c.easyPerform() rc =",rc);
    print(c,'=',JSON.stringify(c,undefined,2));
    c.destroy();
    print(banner.end);
};
function testTwo()
{
    print(banner.start);
    print( arguments.callee.name+"()" );
    var c = new Curl();
    print( "Curl obj =",JSON.stringify( c, undefined, 2 ) );
    c.setOpt({
        //verbose:true,
        port:80,
        url:"http://s11n",
        writeFunction:function writeFunction(data,len,ud)
        {
            print(arguments.callee.name+"()",data.length,"of",len,"bytes");
            ++ud.count;
            return data.length;
        },
        writeData:{count:0},
        headerFunction:function headerFunction(data,len,ud)
        {
            print(arguments.callee.name+"()",data.length,"of",len,"bytes:","["+data.substring(0,data.length-2)+"]");
            return data.length;
        },
        headerData:{count:0},
        userAgent:"cvv8-curl"
    });
    print( "port =",c.opt.port);
    print( "timeout =",c.opt.timeout);
    var rc = c.easyPerform();
    print("perform rc =",rc);
    print("Curl obj =",JSON.stringify(c,undefined,2));
    //print("Curl.opt obj =",JSON.stringify(c.opt,undefined,2));
    c.destroy();
    print(banner.end);
}
function testThree()
{
    print(banner.start);
    print( arguments.callee.name+"()" );
    var c = new Curl();
    var o = {
        url:'http://localhost',
        //verbose:true,
        port:80,
        timeout:11,
        connectionTimeout:17,
        headerFunction:function headerFunction(data,len,ud)
        {
            print(arguments.callee.name+"()",data.length,"of",len,"bytes:","["+data.substring(0,data.length-2)+"]");
            return data.length;
        },
        headerData:{count:0},
        httpHeader:["Host: s11n","Accept-Encoding: gzip","Accept: text/html"],
        http200Aliases:['wh','s11n']
    };
    rc = c.setOpt(o);
    print( "setOpt RC =",rc);
    rc = c.setOpt( Curl.OPT_HTTPHEADER,
                   ["Host: wh","Accept-Encoding: gzip","Accept: text/html"]
                   );
    print( "setOpt RC =",rc);
    var rc = c.setOpt( Curl.OPT_CRLF, 0 )
    print( "setOpt RC =",rc);
    rc = c.setOpt( 'userAgent', "v8-juice" );
    print( "setOpt RC =",rc);
    var rc = c.setOpt( Curl.OPT_URL, 'http://wh' )
    print( "setOpt RC =",rc);
    print('c.opt.url ==',c.opt.url);
    c.setOpt( Curl.OPT_WRITEFUNCTION, function writeFunction(data,len,ud)
    {
        print(arguments.callee.name+"()",data.length,"of",len,"bytes");
        ++ud.count;
        return data.length;
    } );
    c.setOpt( Curl.OPT_WRITEDATA, {count:0} );

    print( "c =",JSON.stringify(c,undefined,2));
    c.easyPerform();
    if(1)
    {
        var ar = c.getInfo( Curl.INFO_HTTPAUTH_AVAIL );
        print('CURLINFO_HTTPAUTH_AVAIL =\n\t',(ar ? ar.join('\n\t') : null));
        ar = c.getInfo( Curl.INFO_SSL_ENGINES );
        print('CURLINFO_SSL_ENGINES =\n\t',(ar ? ar.join('\n\t') : null));
    }
    c.destroy();
    print(banner.end);
}

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
    print(banner.start);
    print( arguments.callee.name+"()" );
    var c = new Curl();
    var content = "";
    for( var i = 0; i < 20000; ++i )
    {
        content += '*';
    }
    c.setOpt({
            url:'http://localhost',
            port:8080,
            verbose:true,
            post:true,
            httpHeader:['Content-Length: '+content.length],
            readFunction:function(len,ud)
            {
                if( ud.pos >= ud.content.length ) return "";
                var clen = ud.content.length - ud.pos;
                var xlen = (len > clen) ? clen : len;
                var s = ud.content.substr( ud.pos, xlen );
                print("readFunction(",len,") sending",s.length,'bytes.');
                ud.pos += xlen;
                return s;
            },
            readData:{
                pos:0,
                content:content
            }
        });
    var rc = c.easyPerform();
    c.destroy();
    print(banner.end);

}

//listProperties();
testOne();
//testTwo();
//testThree();
//testFour();
//testCurlInfo();
//testReader();
