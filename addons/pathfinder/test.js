load('../test-common.js');
//ByteArray.enableDestructorDebug(true);
function test1()
{
    var pf = new PathFinder();
    print('pf='+pf);

    pf.setPathArray(['/usr/local/bin','/usr/bin','/bin','/usr/sbin','/sbin']);
    assert(pf.search('ls'), 'found ls' );
    assert(pf.search('gzip'), 'found gzip' );
    assert(!pf.search('bogoappdoesnotexist'), 'did not find imaginary file.' );
    pf.destroy();
}


test1();
print("If you made it this far without an exception then you win!");
