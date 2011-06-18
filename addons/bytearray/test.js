
function test1()
{
    var ba = new ByteArray(10);
    print('ba='+ba);
    ba[0] = 72; ba[1]=105;
    print('as string: '+ba.stringValue);
    ba.destroy();
    ba = new ByteArray("hi, world");
    print("new ba="+ba+': '+ba.stringValue);
}


try {
    test1();
}
catch(e) {
    print("EXCEPTION: "+e);
    throw e;
}
