load('../test-common.js');

function test1()
{
    var d = new whio.IODev("/dev/null","r");
    assert( d instanceof whio.IODev, 'd is-a IODev' );
    assert( d.close(), 'close() seems to works' );
    assertThrows( function() {d.size();},
                  'Use after close() throws.');
}


try {
    test1();
}
catch(e) {
    print("EXCEPTION: "+e);
}
