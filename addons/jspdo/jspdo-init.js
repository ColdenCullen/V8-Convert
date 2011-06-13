/**
   This code gets compiled into JSPDO's binary and run as part of the
   class-binding process. This is used to add implementations of JSPDO
   features which are much simpler to implement in JS than C++.

   The 'this' pointer in the function call will be the JSPDO
   constructor function.

   The final expression in this file MUST evaluate to the anonymous
   function we're creating.
*/
(function(){
    var ctor = this; // === JSPDO
    var jp = this.prototype;
    var sp = ctor.Statement.prototype;
    function stepA(st) { return st.stepArray(); }
    function stepO(st) { return st.stepObject(); }
    function step1(st) { return st.step(); }
    function debug() {
        if( ! ctor.enableDebug ) return;
        if( ! arguments.callee.hasWarned ) {
            arguments.callee.hasWarned = true;
            arguments.callee( "(To disable debug mode, set the constructor's enableDebug to false.)" );
        }
        var i, av = ['JSPDO DEBUG:'];
        for( i = 0; i < arguments.length; ++i ) av.push(arguments[i]);
        print.apply(ctor,av);
    }

    var origImpls = {
        finalize:sp.finalize,
        close:jp.close
    };
    sp.finalize = function() {
        debug("Finalizing JSPDO.Statement handle "+this);
        origImpls.finalize.apply(this,[]);
    };

    jp.close = function() {
        debug("Closing JSPDO handle "+this);
        origImpls.close.apply(this,[]);
    };

    /**
       execForeach() takes an object parameter with the following
       properties:

       .sql (required): SQL code string to run. It may optionally be a
       Statement object which has already been prepared, but in that
       case this function DOES NOT finalize() it (regardless of
       success or failure!).

       .foreach: function(row,callbackData,statement) is called for
       each row.  If foreach() is not set then the query is executed
       (only one time) using step(). The exact type of the row param
       depends on the 'mode' option.

       .mode: 'object' means stepArray(), 'array' means stepArray(),
       and anything else means step(). In the case of object/array,
       foreach() is passed an object/array. In the case of step(), the
       statement object itself is passed as the first argument to
       foreach().

       .foreachData: optional arbitrary value passed as 2nd argument to
       foreach().

       .bind: Optional Array or Object containing values to bind() to
       the sql code. It may be a function, in which case
       bind(statement,bindOpt) is called to initialize the bindings.

       .bindData: Optional data to passed as the 2nd argument to bind().
    */
    jp.execForeach = function(opt) {
        try {
            var st = (opt.sql instanceof ctor.Statement) ? opt.sql : this.prepare(opt.sql);
            var bind;
            //var repeatBind = false;
            if( opt.bind ) {
                if( opt.bind instanceof Function ) {
                    /* todo: see if we can extend this model to support
                       this. This only makes sense for INSERTs, but then
                       we need some semantics for the client to tell
                       us to stop looping.
                    */
                    //repeatBind = opt.bind(st, opt.bindData);
                }
                else {
                    st.bind(opt.bind);
                }
            }
            if( ! (opt.foreach instanceof Function) ) {
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
                opt.foreach( cbArg ? cbArg : row, opt.foreachData, st );
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
       A wrapper around execForeach() which fetches all records
       matching the query opt.sql and returns them as a JS object
       with this structure:

       {columns:[column names],rows:[records...]}

       The opt parameter must be-a Object with the following properties:

       .sql, .bind, and .bindData are as documented for execForeach()

       .mode is as documented for execForeach() except that it must
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
            foreachData: {columns:[],rows:[]},
            foreach:function(row,data,st) {
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
        this.execForeach(fo);
        return fo.foreachData;

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

