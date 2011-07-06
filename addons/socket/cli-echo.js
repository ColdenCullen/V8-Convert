load('echo-config.inc.js');

function echoClient()
{
    var k,v;
    print("Socket members:");
    for( k in Socket )
    {
        print('\t'+k,'=',Socket[k]);
    }
    var s, c, n;
    
    function readAll(sock, bufsz, binary, callback) {
        var x, len;
        v
        while( x = sock.read(bufsz,binary) ) {
            len = x.length;
            callback(x);
            if(len < bufsz) break /* assume EOF, though this is not correct for UTF8 in non-binary mode */;
        }
        if( sock.timeoutReached ) throw new Error("Timeout reached while reading.");
    }
    try
    {
        var rc;
        s  = new Socket( echo.socketFamily, echo.socketType );
        print('s =',s);
        print('s.hostname =',s.hostname);
        rc = s.setTimeout( 10 );
        print("s.setTimeout() rc =",rc);
        var host, port;
        if( echo.socketFamily===Socket.AF_UNIX) {
            host = echo.socketPath;
            port = 0;
        } else {
            host = echo.host;
            port = echo.port;
        }
        var msg;
        
        if(0) msg = ["GET / HTTP/1.1",
                   "Host: "+echo.host
                   ].join(echo.crnl)+echo.crnl+echo.crnl;
        else msg = 'Äöü';
                   
        if( (Socket.SOCK_STREAM == s.type) )
        {
            var bufs = [];
            print("Running in stream mode...");
            rc = s.connect( host, port );
            print('s.connect() rc =',rc);
            print('s.peerInfo: '+JSON.stringify(s.peerInfo));
            rc = s.write( msg );
            print( "s.write() rc =",rc);
            // ACHTUNG: this code is NOT safe vis-a-vis utf8 because we can end
            // a read block in the middle of a multi-byte character!
            var buf = new Socket.ByteArray();
            readAll(s, 20, true, function(x) { print("Read in: "+x); buf.append(x); x.destroy(); });
            print("Read in "+buf.length+" bytes:\n"+buf.stringValue());
        }
        else if( Socket.SOCK_DGRAM == s.type )
        {
            rc = s.sendTo( host, port, msg, msg.length );
            print('s.sendTo() rc =',rc);
        }
        else
        {
            throw new Error("Unknown socket type!");
        }
    }
    catch(e) {
        print("EXCEPTION: "+e);
    }
    finally
    {
        print("Closing client socket...");
        if( s ) s.close();
        print("Closed client socket.");
    }
        
}

try
{
    if(0) { // is crashing on me :(
        for( var i = 1; i < 4; ++i ) {
            setTimeout( echoClient, 1 );
        }
        sleep(7);
    }
    else {
        echoClient();
    }
    print("Done!");
}
catch(e)
{
    print("EXCEPTION:",e);
    throw e;
}
