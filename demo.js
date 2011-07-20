load("addons/test-common.js");

function f1()
{
    print("hi, world.");
    var m = new MyType();
    print( 'm = '+m );
    var rc = -3;
    rc = m.nonMember(11);
    asserteq( rc, 11 );
    m.nonConstMethod();
    m.constMethod();
    m.destroy();
    print("bye, world.");
}


f1();
print("If you got this far, it seems to have worked.");
