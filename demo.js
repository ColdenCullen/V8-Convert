load("addons/test-common.js");

function f1()
{
    var m = new MyType();
    print( 'm = '+m );
    m.destroy();
    print("hi, world.");
}


f1();
print("If you got this far, it seems to have worked.");
