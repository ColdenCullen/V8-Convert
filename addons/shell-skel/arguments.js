
arguments.parseArgs = function() {
    var i, m, l;
    var rxNonFlag = /^[^-]/; /* arg */
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

function applyValidation( func, rules ){
    return function(){
        var av = Array.prototype.slice.apply(arguments,[0]);
        rules( av );
        return func.apply( this, av );
    }
};

JSON.stringify = applyValidation( JSON.stringify,
                                  function(a){
                                      if(!a.length) throw new Error("!arguments.length");
                                  });
//print("Object: "+{});

(function(){
    function ArgValidator(){
        this.$state = {
        list:[]
        };
    }
    ArgValidator.prototype = {
        push:function(f){
            this.$state.list.push(f);
            return this;
        },
        argv:function(a){
            return Array.prototype.slice.apply(a,[0]);
        },
        $fwdValidate:function(f,args){
            if(f instanceof this.constructor) return f.validate(args);
            else return f(args);
        },
        aEq:function(ndx,val){
            this.push( function(a){return a[ndx] == val;} );
            return this;
        },
        aEqq:function(ndx,val){
            this.push( function(a){return a[ndx] === val;} );
            return this;
        },
        aLength:function(min,max){
            max = arguments.length==1 ? min : max;
            this.push( function(a){
                           if(max<min) return a.length>=min;
                           else return a.length>=min && a.length<=max;
                       });
            return this;
        },
        validate:function(){
            var li = this.$state.list, i = 0, r, l = li.length;
            if(!l) return true;
            var args = this.argv(arguments);
            for( ; i < l; ++i ){
                r = li[i];
                if(!this.$fwdValidate(r,args)) {
                    throw new Error("Argument validation failed.");
                }
            }
            return true;
        }
    };
})();


if( 0 === arguments.length ) {
    print("You can pass arguments to this script by passing them AFTER "+
            "an argument in the form '--'. Example:");
    print("\tshell script.js -- -a=1 --b=2 --c");
}
print('arguments ='+JSON.stringify(arguments));
print('arguments.parseArgs ='+JSON.stringify(arguments.parseArgs(),0,2));

function testV8ShellStuff()
{
    throw new Error("Hello, world!");
}

if(0) {
    try {
        testV8ShellStuff();
    }
    catch(e) {
        print("EXCEPTION: "+e);
        throw e;
    }
}
