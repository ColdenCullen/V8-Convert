load("../addons/test-common.js");

function runTestsOn(m)
{
    print("Running generic tests on object "+m);
    var rc = -3;
    rc = m.nonMember(11);
    asserteq( rc, 11 );
    m.anInt = 17;
    rc = m.anInt;
    asserteq( m.anInt, rc, 'rc == m.anInt');

    assertThrows( function() { m.aDouble = 7.3; } );
    assert( 'number' === typeof m.aDouble, 'm.aDouble is-a Number.');

    m.nonConstMethod();
    m.constMethod();

    assert( undefined == m.nonConvertibleReturn(), 'm.nonConvertibleReturn() works.');
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
    var i = 19, d = 33.17;
    var m = new MyType(i,d);
    asserteq( i, m.anInt, 'm.anInt initialized properly');
    asserteq( d, m.aDouble, 'm.aDouble initialized properly');
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
    assert( m.destroy(), 'destroy() works.' );
}

function try0ArgCtor()
{
    var m = new MyType();
    print('m = '+m);
    m.destroy();
}

f1();
testSubclass();
try0ArgCtor();
print("If you got this far, it seems to have worked.");
