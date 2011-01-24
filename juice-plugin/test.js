// v8::convert test/demo app for use with v8-juice-shell (or compatible)
loadPlugin("v8-juice-ConvertDemo");

function assert(cond,msg)
{
    if( ! cond ) throw new Error(msg);
    else
    {
        print("Assertion OK: "+msg);
    }
}

function asserteq(got,expect,msg)
{
    if( got != expect ) throw new Error('Assertion: '+(msg || (got+' != '+expect)));
    else
    {
        print("Assertion OK: "+(msg || (got+' == '+expect)));
    }
}

function test1()
{
    var f = new BoundNative();
    print('f='+f);
    f.puts("hi, world");
    f.cputs("hi, world");
    f.doFoo();
    f.doFoo2(1,3.3);
    f.invoInt(1,2,3,4);
    f.doFooConst();
    f.nativeParam(f);
    f.runGC();

    var ex;
    try{f.publicIntRO = 1;}
    catch(e){ex = e;}
    assert( !!ex, "Expecting exception: "+ex);

    /* Note the arguably unintuitive behaviour when incrementing
       f.publicIntRO: the return value of the ++ op is the incremented
       value, but we do not actually modify the underlying native int.
       This is v8's behaviour, not mine.
    */
    asserteq( ++f.publicIntRW, 43 );
    asserteq( f.publicIntRO, f.publicIntRW );

    ++f.publicStaticIntRW;
    asserteq( f.publicStaticIntRW, f.publicStaticIntRO );
    asserteq( ++f.publicStaticIntRO, 1+f.publicStaticIntRW );
    asserteq( f.publicStaticIntRW, f.publicStaticIntRO );
    asserteq( ++f.publicStaticIntRO, 1+f.publicStaticIntRW );
    asserteq( f.publicStaticIntRW, 43 );
    asserteq( f.publicStaticIntRO, f.publicStaticIntRW );
    asserteq('hi, world', f.message);
    asserteq(42, f.answer);
    assert( /BoundNative/.exec(f.toString()), 'toString() seems to work: '+f);

    assert( f.destroy(), 'f.destroy() seems to work');

    ex = undefined;
    try{f.doFoo();}
    catch(e){ex = e;}
    assert( !!ex, "Expecting exception: "+ex);

    
}

function test2()
{
    var s = new BoundSubNative();
    assert(s instanceof BoundNative, "BoundSubNative is-a BoundNative");
    print('s='+s);
    assert( /BoundSubNative/.exec(s.toString()), 'toString() seems to work: '+s);

    assert(s.destroy(), 's.destroy()');

    // DO NOT TRY THIS AT HOME, kids: i'm testing weird stuff here...
    var f = new BoundNative();
    s.toString = f.toString;
    //print('f='+f);
    print('s='+s);
}

function test3()
{
    function MySub()
    {
        this.prototype = this.__proto__ = new BoundSubNative();
    }
    //MySub.constructor.prototype = BoundSubNative;
    var m = new MySub();
    assert(m instanceof BoundNative,'m is-a BoundNative');
    assert(m instanceof BoundSubNative,'m is-a BoundSubNative');
    m.puts("Hi from JS-side subclass");
    assert( /BoundSubNative/.exec(m.toString()), 'toString() seems to work: '+m);
    assert(m.destroy(), 'm.destroy()');
    var ex;
    try{m.doFoo();}
    catch(e){ex = e;}
    assert( !!ex, "Caught EXPECTED exception: "+ex);

}

function test4()
{
    var i =0;
    for( ; i < 10; ++i ) new BoundSubNative();
}

test1();
test2();
test3();
//test4();

print("Done!");
