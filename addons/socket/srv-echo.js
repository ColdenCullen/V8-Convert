load('echo-config.inc.js');

function echoServer()
{
    var k,v;
    print("Socket members:");
    for( k in Socket )
    {
        print('\t'+k,'=',Socket[k]);
    }
    var s, c, n;
    try
    {
        s  = new Socket( echo.socketFamily, echo.socketType );
        print('s =',s);
        print('s.hostname =',s.hostname);
        var rc;
        rc = s.bind( echo.host, echo.port );
        print( "s.bind(",echo.host+":"+echo.port,") rc =",rc);
        rc = s.setTimeout( 3 );
        print("s.setTimeout() rc =",rc);
        if( Socket.SOCK_STREAM == s.type )
        {
            print("Running in stream mode...");
            rc = s.listen();
            print("s.listen() rc =",rc);
            for( ; ; )
            {
                c = s.accept();
                print('accept =',c);
                if( ! c )
                {
                    print("Presuming a timeout and continuing...");
                    continue;
                }
                print("Got peer: "+c.peerInfo.join(':'));
                function doit(conn) {
                    var buf = "";
                    var x;
                    while( undefined != (x = conn.read(1024)) ) {
                        buf += x;
                    }
                    print("Writing back "+buf.length+" bytes to the client:\n"+buf);
                    conn.write(buf, buf.length);
                    conn.close();
                    //},100);
                };
                if(1) {
                    //setTimeout(function(){doit(c);},1);
                    doit(c);
                }
                continue;
            }
        }
        else if( Socket.SOCK_DGRAM == s.type )
        {
            var len = 5;
            // Is it normal tha i can only read a dgram socket 1 time?
            for( ; ; ) {
                print("Waiting on datagram read...");
                var buf = "";
                while( undefined !== (rc = s.read(len)) ) {
                    buf += rc;
                }
                if( buf.length > 0 ) {
                    print("s.read() rc =",rc,"Content=[\n"+buf+'\n]');
                }
            }
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
        print("Closing server socket...");
        if( s ) s.close();
        print("Closed server socket.");
    }
        
}

try
{
    //spawnIntervalThread(function(){print("tick...");},1000);
    echoServer();
    print("Done!");
}
catch(e)
{
    print("EXCEPTION:",e);
    throw e;
}
