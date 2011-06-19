function test1()
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
        c = new Socket( Socket.AF_INET,
                           Socket.SOCK_STREAM
                           //Socket.SOCK_DGRAM
                           );
        print('socket c ='+c);
        print('c.hostname ='+c.hostname);
        var host =
            'localhost'
            //'wh'
            //'127.0.0.1'
            //'www.google.de'
            ;
        var port = 80;
        var rc;
       
        var plist = ['ntp', 'tcp','udp'];
        for( k in plist )
        {
            v = plist[k];
            print('getProtoByName('+v+') =',
                  Socket.getProtoByName(v) );
        }
        var hlist = ['localhost'];//,'www.google.com'];
        if(1)
        {
            for( k in hlist )
            {
                var ao = Socket.nameToAddress( hlist[k] );
                print('nameToAddress(',hlist[k],') == ',ao);
                print('addressToName(',ao,') == ',Socket.addressToName(ao));
            }
        }

        //host = 'nosuchfuckinghost'
        var chost = Socket.nameToAddress( host );
        print("Connecting to",chost+":"+port,'...');
        rc = c.connect( chost, port );
        print("c.peerInfo =",c.peerInfo);
        rc = c.setTimeout( 3 );
        print("c.setTimeout() rc =",rc);
        var crnl = '\r\n';
        var header = ["GET / HTTP/1.1",
                      "Host: "+host
                      ].join(crnl)+crnl+crnl;
        rc = c.write( header );
        print('header =['+header+']');
        print("write() rc =",rc);
        function nukeRC(BA)
        {
            if( BA instanceof Socket.ByteArray ) BA.destroy();
            else BA.length = 0;
        }
        function rcVal(BA)
        {
            return ( BA instanceof Socket.ByteArray ) ? BA.stringValue : BA.toString();
        }
        if( c.type === Socket.SOCK_STREAM )
        {
            n = 128;
            print("Reading...");
            while( undefined !== (rc = c.read(n,true)) )
            {
                if( null === rc )
                {
                    print("Apparently ("+c.timeoutReached+") interrupted by timeout before data arrived.");
                    continue;
                }
                print("read("+n+") (type="+typeof rc+")=="+(rc.length)+"["+rcVal(rc)+"]");
                if( rc.length < n )
                {
                    /* corner case: we might have been interrupted by
                       a timeout here and got a short read. We need to
                       add a flag value to Socket to be able to
                       distinguish that here.

                       ...

                       it turns out we cannot recognize it in the native
                       code, either!                      
                    */
                    nukeRC(rc);
                    break;
                }
                nukeRC(rc);
            }
        }
        print("c.peerInfo =",c.peerInfo);
    }
    finally
    {
        print("Closing sockets...");
        if( c ) c.close();
        if( s ) s.close();
        print("Closed sockets.");
    }
        
}


try
{
    print('Socket.hostname='+Socket.hostname);
    test1();
    print("Done!");
}
catch(e)
{
    print("EXCEPTION:",e);
    throw e;
}
