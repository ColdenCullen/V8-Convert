
arguments.parseArgs = function() {
    var i, k, v, m, l;
    var rxNonFlag = /^[^-]+$/; /* -arg */

    var rx0a = /^--?([^=]+)$/; /* -[-]arg */
    var rx1a = /^--?([^=]+)=(.*)$/; /* -[-]arg=val */
    var rc = {
        flags:{},
        nonFlags:[]
    };
    for( i = 0; i < this.length; ++i ) {
        l = this[i];
        //print("TRYING ["+i+"]="+l);
        if( ! l ) continue;
        else if( rxNonFlag.test(l) ) {
            rc.nonFlags.push(l);
        }
        else if( (m = rx0a.exec(l)) ) {
            rc.flags[ m[1] ] = true;
        }
        else if( (m = rx1a.exec(l)) ) {
            rc.flags[ m[1] ] = (m[2] || false);
        }
        else {
            // ??? wtf ???
        }
    }
    return rc;
};

print('arguments ='+JSON.stringify(arguments));
print('arguments.parseArgs ='+JSON.stringify(arguments.parseArgs()));
