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
    assertThrows(function(){new whio.OutStream(true);}, 'Invalid ctor args.');
    var d = new whio.OutStream("/dev/stdout",false);
    assert( d instanceof whio.OutStream, 'd is-a OutStream' );
    assert( d instanceof whio.StreamBase, 'd is-a StreamBase' );
    asserteq( 10, d.write("hi, world\n"), 'write(String) seems to work.');

    var ba = new whio.ByteArray("hi, world\n");
    asserteq( ba.length, d.write(ba), 'write(ByteArray) seems to work.' );
    ba.destroy();

    assert( d.iomode(), 'd.iomode() seems to work' );
    assert( 0 == d.flush(), 'd.flush() seems to work' );

    assert( d.close(), 'd.close() seems to work' );
    assertThrows( function() {d.flush();},
                  'Use after close() throws.');

}

function testInStream()
{
    var d = new whio.InStream("/etc/hosts");

    assert( d instanceof whio.InStream, 'd is-a InStream' );
    assert( d instanceof whio.StreamBase, 'd is-a StreamBase' );
    assertThrows(function(){new whio.InStream(true);}, 'Invalid ctor args.');
    assert( d.iomode(), 'd.iomode() seems to work' );

    var rdLen = 20;
    var got = d.read(rdLen,false);
    asserteq(rdLen, got.length);
    print("Read in ["+got+"]");
    got = d.read(rdLen,true);
    assert( got instanceof whio.ByteArray, 'Read in ByteArray.');
    asserteq(rdLen, got.length);
    print("Read in ["+got.stringValue()+"]");
    got.destroy();
    assert( d.close(), 'd.close() seems to work' );
    assertThrows( function() {d.iomode();},
                  'Use after close() throws.');
}

function testEPFS()
{
    print("Testing EPFS...");
    var fname = "my.epfs";
    var opt = {
    inodeCount:10,
    blockSize:1024 * 8,
    maxBlocks:13
    };
    var fs = new whio.EPFS(fname,true,opt);
    var fsOpt = fs.fsOptions();
    var label = "Test from JavaScript "+(new Date());
    asserteq( fsOpt.inodeCount, opt.inodeCount );
    asserteq( fsOpt.maxBlocks, opt.maxBlocks );
    asserteq( fsOpt.blockSize, opt.blockSize );
    fs.label(label);
    fs.installNamer("ht");
    asserteq( fs.label(), label );

    var inodeId = 3;
    var d = fs.open(inodeId, whio.iomode.RWC);
    assert( d instanceof whio.EPFS.PseudoFile, 'd is-a whio.EPFS.PseudoFile' );
    var hiMsg = "hi, world.";
    var msg = hiMsg;
    asserteq( msg.length, d.write(msg), 'PseudoFile.write() appears to work.' );
    asserteq( 0, d.seek(0,whio.SEEK_SET) );
    var gotMsg = d.read( msg.length, false );
    asserteq( gotMsg, msg );
    asserteq( inodeId, d.inodeId );
    assertThrows(function(){d.inodeId=4;},'Cannot set inodeId.');

    msg = 0xcafe;
    d.clientFlags = msg;
    asserteq( msg, d.clientFlags );

    msg = 6;
    d.mtime = msg;
    asserteq( msg, d.mtime );

    var pname = "my name";
    d.name = pname;
    asserteq( d.name, pname );

    assert( d.close(), 'PseudoFile.close() appears to work.' );
    assert( fs.close(), 'EPFS.close() appears to work.' );
    d = fs = null;
    
    fs = new whio.EPFS(fname,false);
    assert( fs instanceof whio.EPFS, 'is-a EPFS' );

    d = fs.open( pname, whio.iomode.READ );
    assert( d instanceof whio.EPFS.PseudoFile, 'is-a PseudoFile' );
    assert( d instanceof whio.IODev, 'is-a IODev' );
    gotMsg = d.read( hiMsg.length, false );
    asserteq( hiMsg, gotMsg );

    d.close();
    fs.close();
    
}

try {
    testIODev();
    testOutStream();
    testInStream();
    testEPFS();
    print("If you got this far then it seems to work.");
}
catch(e) {
    print("EXCEPTION: "+e);
}
