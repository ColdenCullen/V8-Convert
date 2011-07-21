load("addons/test-common.js");

function runTestsOn(m)
{
    print("Running generic tests on object "+m);
    var rc = -3;
    rc = m.nonMember(11);
    asserteq( rc, 11 );
    m.nonConstMethod();
    m.constMethod();
    if( !m.constPtr() ) {
        print("SKIPPING tests which are known to be problematic for subclassing cases.");
    }
    else {
        /*
            Reminder to self: the problem is in the conversion from
            MySubType to MyType for purposes of NativeToJS<MyType>. In order
            to do that we'd need to port in something like the heavy-weight
            v8::juice solution which registers subclasses with their parent
            class binder, which checks those handlers when the BaseType
            lookup fails.
        */
        asserteq( m, m.constPtr() );
        asserteq( m, m.nonConstPtr() );
        asserteq( m, m.nonConstRef() );
        asserteq( m, m.constRef() );
    }
    print("Done running generic tests.");
}
function f1()
{
    print("hi, world.");
    var m = new MyType();
    runTestsOn( m );
    assert( m.destroy(), 'destroy() works.' );
    print("bye, world.");
}

function testSubclass()
{
    var m = new MySubType();
    print( 'subclass instance = '+m );
    assert( m instanceof MyType, 'm instanceof MyType' );
    assert( /MySubType/.test( m.toString() ), 'toString() finds subclass reimplementation.' );
    runTestsOn( m );
    assert( m.destroy(), 'destroy() works.' );}

f1();
testSubclass();
print("If you got this far, it seems to have worked.");
