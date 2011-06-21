
function test1()
{
    var ba = new ByteArray(10);
    print('ba='+ba);
    ba[0] = 72; ba[1]=105;
    print('as string: '+ba.stringValue);
    ba.destroy();
    ba = new ByteArray("hi, world");
    print("new ba="+ba+': '+ba.stringValue);
    var i, b2;
    for( i = 0; i < 3; ++i ) {
        b2 = new ByteArray("!");
        ba.append(b2);
        b2.destroy();
    }
    print("Appended ba ("+ba.length+" bytes): "+ba.stringValue);
    for( i = 0; i < 3; ++i ) {
        ba.append("?");
    }
    print("Appended ba ("+ba.length+" bytes): "+ba.stringValue);
    for( i = 0; i < 3; ++i ) {
        ba.append(42 /* '*' */);
    }
    print("Appended ba ("+ba.length+" bytes): "+ba.stringValue);
}


try {
    test1();
}
catch(e) {
    print("EXCEPTION: "+e);
    throw e;
}
