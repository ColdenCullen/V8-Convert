/**
   This code gets compiled into JSPDO's binary and run as part of the
   class-binding process. This is used to add implementations of JSPDO
   features which are much simpler to implement in JS than C++.

   The 'this' pointer in the function call will be the JSPDO
   constructor function.

   The final expression in this file MUST evaluate to the anonymous
   function we're creating.
   
   Reminder to self: i wanted to pass the JSPDO ctor as the first
   argument but when i do that, ctor.prototype is empty (or seems
   to be?).
*/
(function(){
    var ctor = this; // === JSPDO ctor
    var jp = this.prototype;
    var sp = ctor.Statement.prototype;
    function stepA(st) { return st.stepArray(); }
    function stepO(st) { return st.stepObject(); }
    function step1(st) { return st.step(); }
    function debug() {
        if( ! ctor.enableDebug ) return;
        if( ! arguments.callee.hasWarned ) {
            arguments.callee.hasWarned = true;
            arguments.callee( "(To disable debug mode, set "+ctor.name+".enableDebug to false.)" );
        }
        var i, av = ['JSPDO DEBUG:'];
        for( i = 0; i < arguments.length; ++i ) av.push(arguments[i]);
        print.apply(ctor,av);
    }

    function argvToArray(argv) {
        return Array.prototype.slice.apply(argv,[0]);
    }

    var origImpls = {
        finalize:sp.finalize,
        close:jp.close,
        prepare:jp.prepare,
        exec:jp.exec,
        bind:sp.bind
    };
    
    sp.finalize = function() {
        debug("Finalizing JSPDO.Statement handle "+this);
        origImpls.finalize.apply(this,[]);
    };

    jp.close = function() {
        debug("Closing JSPDO handle "+this);
        origImpls.close.apply(this,[]);
    };
    
    jp.prepare = function() {
        var st = origImpls.prepare.apply(this,argvToArray(arguments));
        debug("Prepared statement: "+st);
        return st;        
    };

    /**
       exec({...}) takes an object parameter with the following
       properties:

       .sql (required): SQL code string to run. It may optionally be a
       Statement object which has already been prepared, but in that
       case this function DOES NOT finalize() it (regardless of
       success or failure!).

       .each: function(row,callbackData,statement) is called for
       each row.  If foreach() is not set then the query is executed
       (only one time) using step(). The exact type of the row param
       depends on the 'mode' option.

       .mode: 'object' means stepArray(), 'array' means stepArray(),
       and anything else means step(). In the case of object/array,
       foreach() is passed an object/array. In the case of step(), the
       statement object itself is passed as the first argument to
       foreach().

       .callbackData: optional arbitrary value passed as 2nd argument to
       foreach().

       .bind: Optional Array or Object containing values to bind() to
       the sql code. It may be a function, in which case
       bind(statement,bindOpt) is called to initialize the bindings.

       .bindData: Optional data to passed as the 2nd argument to bind().
    */
    jp.exec = function(opt) {
        if( 'string' === typeof opt ) return origImpls.exec.apply(this, argvToArray(arguments));
        else if( !opt || ('object' !== typeof opt) ){
            throw new Error("exec() requires a string or Object as its only parameter.");
        }
        try {
            var st = (opt.sql instanceof ctor.Statement) ? opt.sql : this.prepare(opt.sql);
            var bind;
            //var repeatBind = false;
            if( opt.bind ) {
                if( opt.bind instanceof Function ) {
                    /* todo: see if we can extend this model to support
                       this. This only seems to makes sense for INSERTs, but
                       then we need some semantics for the client to tell
                       us to stop looping.
                    */
                    //repeatBind = opt.bind(st, opt.bindData);
                    opt.bind(st, opt.bindData);
                }
                else {
                    st.bind(opt.bind);
                }
            }
            if( ! (opt.each instanceof Function) ) {
                st.step();
                return;
            }
            var step, cbArg;
            if('object'===opt.mode) {
                step = stepO;
            }
            else if('array'===opt.mode) {
                step = stepA;
            }
            else {
                step = step1;
                cbArg = sp;
            }
            var row;
            while( row = step(st) ) {
                opt.each( cbArg ? cbArg : row, opt.callbackData, st );
                /**if( true === repeatBind ) {
                    st.reset();
                    opt.bind(st, opt.bindData);
                }*/
            }
        }
        finally {
            if(st && (st !== opt.sql)) st.finalize();
        }
    };

    /**
        Extends bind() to accept a Statement as its input. If it is-a
        Statement then this.paramCount and opt.columnCount must match (and
        be greater than 0) or an exception is thrown. this.bind(N+1,opt.get(N))
        is called in a loop, where N is the set [0,opt.columnCount).
    */
    sp.bind = function(opt) {
        if( (1!==arguments.length) || !(opt instanceof ctor.Statement) )
            return origImpls.bind.apply(this, argvToArray(arguments));
        else if( ! opt.columnCount )
            throw new Error("Statement to bind from has no result columns.");
        else if( opt.columnCount !== this.paramCount )
            throw new Error("Source and destination column counts do not match "+
                            opt.columnCount+' vs. '+this.paramCount);
        var i;
        for( i = 0; i < opt.columnCount;++i ) {
            this.bind( 1+i, opt.get(i) );
        }
    };
            

    /**
       A wrapper around exec() which fetches all records
       matching the query opt.sql and returns them as a JS object
       with this structure:

       {columns:[column names],rows:[records...]}

       The opt parameter must be-a Object with the following properties:

       .sql, .bind, and .bindData are as documented for exec()

       .mode is as documented for exec() except that it must
       be one of ('array','object') and defaults to 'array'.

       Throws an exception if opt is-not-a Object, if opt.sql is not set,
       or if the underying query preparation/execution throws.
    */
    jp.fetchAll = function(opt) {
        if( ! (opt instanceof Object) ) {
            throw new Error("fetchAll() requires an Object as its first argument.");
        }
        else if( ! opt.sql ) {
            throw new Error("fetchAll(opt) requires that opt.sql be set.");
        }
        if( ! ('mode' in opt) ) opt.mode = 'array';
        else if( (opt.mode !== 'array') && (opt.mode !== 'object') )
            throw new Error("fetchAll(opt)'s opt.mode must be one of ('object','array').");
        var fo = {
            mode:opt.mode,
            sql:opt.sql,
            bind:opt.bind,
            bindData: opt.bindData,
            callbackData: {columns:[],rows:[]},
            each:function(row,data,st) {
                if( ! data.columns.length ) {
                    var k, i = 0;
                    for( ; i < st.columnCount; ++i ) {
                        k = st.columnName(i);
                        data.columns.push(k);
                    }
                }
                data.rows.push(row);
            }
        };
        this.exec(fo);
        return fo.callbackData;
    };

    jp.toJSON = function() {
        return {
            dsn:this.dsn,
            id:this.toString()
        }
    };

    sp.toJSON = function() {
        return {
            sql:this.sql,
            id:this.toString()
        };
    };
    
    return ctor;
});

