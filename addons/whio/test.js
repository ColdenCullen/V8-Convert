load('../test-common.js');

function testIODev()
{
    var d = new whio.IODev("/dev/null","r");

    assert( d instanceof whio.IODev, 'd is-a IODev' );
    assertThrows(function(){new whio.IODev(d,0);}, 'Invalid ctor args.');

    var s = new whio.IODev(d,10,50);
    assert( s instanceof whio.IODev, 's is-a IODev.' );
    assert( s.iomode(), 's.iomode() seems to work' );
    assert( s.close(), 's.close() seems to work' );

    assert( d.iomode(), 'd.iomode() seems to work' );
    assert( d.close(), 'd.close() seems to work' );
    assertThrows( function() {d.size();},
                  'Use after close() throws.');
}

function testOutStream()
{
    var d = new whio.OutStream("/dev/null",false);

    assert( d instanceof whio.OutStream, 'd is-a OutStream' );
    assert( d instanceof whio.StreamBase, 'd is-a StreamBase' );
    assertThrows(function(){new whio.OutStream(true);}, 'Invalid ctor args.');
    assert( d.iomode(), 'd.iomode() seems to work' );

    assert( d.close(), 'd.close() seems to work' );
    assertThrows( function() {d.flush();},
                  'Use after close() throws.');
}

function testInStream()
{
    var d = new whio.InStream("/dev/null");

    assert( d instanceof whio.InStream, 'd is-a InStream' );
    assert( d instanceof whio.StreamBase, 'd is-a StreamBase' );
    assertThrows(function(){new whio.InStream(true);}, 'Invalid ctor args.');
    assert( d.iomode(), 'd.iomode() seems to work' );

    assert( d.close(), 'd.close() seems to work' );
    assertThrows( function() {d.flush();},
                  'Use after close() throws.');
}

try {
    testIODev();
    testOutStream();
    testInStream();
    print("If you got this far then it seems to work.");
}
catch(e) {
    print("EXCEPTION: "+e);
}
