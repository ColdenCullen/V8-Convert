/**
   This code gets compiled into JSPDO's binary and run as part of the
   class-binding process. This is used to add implementations of JSPDO
   features which are much simpler to implement in JS than C++.

   The 'this' pointer in the function call will be the JSPDO
   constructor function.
*/
(function(){
    var ctor = this;
    var jp = this.prototype;
    //print("RUNNING INIT CODE!!!! prototype:",typeof jp,jp);
    //print('ctor:',typeof ctor,ctor);
    //jp.hi = "hi!"; ctor.hi = "hi!!";

    function stepA(st) { return st.stepArray(); }
    function stepO(st) { return st.stepObject(); }
    function step1(st) { return st.step(); }
    var doDebug = false;
    function debug() {
        if( ! doDebug ) return;
        print.call(ctor,Array.prototype.slice.apply(arguments,[0]));
    }
    /**
       execForeach() takes an object parameter with the following
       properties:

       .sql (required): SQL code to run. It may optionally be a
       Statement object which has already been prepared (but note that
       this function will finalize() it).

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
            if( opt.bind ) {
                if( opt.bind instanceof Function ) {
                    /* todo: see if we can extend this model to support
                       this. This only makes sense for INSERTs, but then
                       we need some semantics for the client to tell
                       us to stop looping.

                       bind = function() {
                        return opt.bind(st, opt.bindData);
                       }
                    */
                    opt.bind(st, opt.bindData);
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
                if( false && bind ) {
                    st.reset();
                    bind();
                }
            }
        }
        finally {
            if(st) {
                debug("Closing statement handle "+st);
                st.finalize();
            }
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
        try {
            if( ! (opt instanceof Object) ) {
                throw new Error("fetchAll() requires an Object as its first argument.");
            }
            else if( ! opt.sql ) {
                throw new Error("fetchAll(opt) requires that opt.sql be set.");
            }
        }
        finally {
            /** For consistency with the on-success behaviour, since
                the client can't generically tell if the error came
                before or during the db operations.
            */
            if( opt.sql instanceof ctor.Statement ) {
                opt.sql.finalize();
                delete opt.sql;
            }
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
            id:this.toString(),
            dsn:this.dsn
        }
    };
    var sp = ctor.Statement.prototype;
    sp.toJSON = function() {
        return {
            id:this.toString(),
            sql:this.sql
        };
    };
    
    return ctor;
});
