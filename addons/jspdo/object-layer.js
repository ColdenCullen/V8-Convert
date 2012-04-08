/**
    Experimenting with high-level helpers for JSPDO...
*/
(function(JSPDO){
    var $ = JSPDO.Lol /*=Little Object Layer*/ = {};

    $.Table = function(db, name){
        if(!(db instanceof JSPDO)){
            throw new Error("Table's first ctor arg must be-a JSPDO instance.");
        }
        if('string'!==typeof name){
            throw new Error("Table's second ctor arg must be-a string.");
        }
        this.db = db;
        this.name = name;
        this.idField = 'id';
        return this;
    };


    var cache = {};
    function dsnCache(db){
        var dsn = db.dsn;
        var ca = cache[dsn];
        if( !ca ){
            ca = cache[dsn] = {};
        }
        return ca;
    };

    $.Table.setFactory = function (db, name, fac){
        var ca = dsnCache(db);;
        if(!ca.factories) ca.factories = {};
        if(fac) ca.factories[name] = fac;
        else delete ca.factories[name];
    };

    $.Table.getFactory = function(db,name){
        var ca = dsnCache(db);
        return ca.factories ? ca.factories[name] : undefined;
    };

    $.Table.prototype = {
        getRowPrototype: function(){
            return new $.Row(this);
        },
        indexOfColumn:function(name){
            var rc = -1;
            if(this.columns) for( var i = 0, l = this.columns.length; i < l; ++i ){
                if(name===this.columns[i]) {
                    rc = i;
                    break;
                }
            }
            return rc;
        },
        getRowCreateInfo: function(){
            var o = { bind:[], sql:'', f:{}},
                i, l, k, v;
            var set = [];
            var names = [];
            o.bind.push(null);
            set.push('?');
            names.push(this.db.qualify(this.idField));
            for( i = 0, l = this.columns.length; i < l; ++i ){
                k = this.columns[i];
                if(this.idField===k) continue;
                v = this.defaults[k];
                if(undefined===v) continue;
                o.bind.push(v);
                o.f[k] = v;
                set.push('?');
                names.push(this.db.qualify(k));
            }
            o.sql = "INSERT INTO "+this.db.qualify(this.name)+
                "("+names.join(', ')+')'+
                " VALUES("+set.join(', ')+')';
            return o; 
        },
        createNewRow: function(){
            var d = this.getRowCreateInfo();
            var s = this.db.prepare( d );
            var r;
            try {
                s.step();
                r =  new $.Row(this, d.f);
            }
            finally {
                s.finalize();
            }
            r.id( this.db.lastInsertId(this.name) );
            return r;
        },
        toJSON:function(){
            return {
                name:this.name,
                idField:this.idField,
                columns:this.columns,
                defaults:this.defaults
            };
        },
        getRowById: function(id){
            var r = new $.Row(this);
            return r.populateFromId(id);
        },
        qualifiedColumnNames: function(addAs){
            var i, l;
            var names = [];
            for( i = 0, l = this.columns.length; i < l; ++i ){
                names.push( this.db.qualify(this.columns[i])+
                            (addAs ? (' AS '+this.columns[i]) : ''));
            }
            return names;
        },
        fetchRows:function(prep){
            var rc = [];
            if(!prep) prep = {};
            var self = this;
            this.db.exec({
                sql: prep.sql || ("SELECT * FROM "+self.db.qualify(self.name)),
                bind: prep.bind,
                mode: 'object',
                each:function(row){
                    rc.push( new $.Row(self,row) );
                }
            });
            return rc.length ? rc : null;
        }
    }/*Table.prototype*/;


    $.getTableDef = function(db,name){
        var ce = arguments.callee;
        if(!ce.cache){
            ce.cache = {};
        }
        var ca = ce.cache[db.dsn];
        if(!ca) {
            ca = ce.cache[db.dsn] = {};
        }
        var t = ca[name];
        if(t) return t;
        t = new $.Table(db,name);
        var s;
        try {
            s = db.prepare("SELECT * FROM "+db.qualify(name));
            t.columns = s.columnNames;
            t.defaults = {};
            var i, l;
            for( i = 0, l=t.columns.length; i < l; ++i ){
                t.defaults[t.columns[i]] = undefined;
            }
        }
        finally{
            if(s) s.finalize();
        }
        ca[name] = t;
        return t;
    };

    $.getTableDefs = function(db,obj){
        var k, v, t, rc = {};
        for( k in obj ){
            t = this.getTableDef(db, k);
            v = obj[k];
            t.idField = v.idField || 'id';
            t.defaults = v.defaults || {};
            t.defaults[t.idField] = null;
            rc[k] = t;
        }
        return rc;
    };

    $.Row = function(table,f){
        if(!(table instanceof $.Table)){
            throw new Error("Row ctor argument must be-a Table.");
        }
        this.table = table;
        this.f = f || {};
        /*
        var cn;
        for( i = 0, l = this.table.columns.length; i < l; ++i ){
            cn = this.table.columns[i];
            //this.f[cn] = table.defaults[cn];
            this.f[cn] = undefined;
        }
        */
        return this;
    };

    $.Row.prototype = {
        getUpdateInfo:function(){
            if(!this.id()){
                throw new Error("The value for this.id() (field "+this.table.idField+") is not set. UPDATE not possible.");
            }
            var o = { bind:[] },
                db = this.table.db,
                k, v;
            var set = [];
            for( k in this.f ){
                if(this.table.idField===k) continue;
                v = this.f[k];
                if(undefined===v) continue;
                o.bind.push(v);
                set.push(db.qualify(k)+'=?');
            }
            o.bind.push(this.id());
            o.sql = "UPDATE "+db.qualify(this.table.name)+
                " SET "+set.join(', ')+
                ' WHERE '+db.qualify(this.table.idField)+'=?';
            return o;
        },
        val: function(){
            if(1==arguments.length){
                return this.f[arguments[0]];
            }
            else if(2==arguments.length){
                var v = arguments[1];
                if(undefined===v) delete this.f[arguments[0]];
                else this.f[arguments[0]] = v;
                return this;
            }
        },
        save: function(){
            var d = this.getUpdateInfo();
            var s = this.table.db.prepare(d);
            try {
                s.step();
            }
            finally {
                s.finalize();
            }
            return this;
        },
        toJSON:function(){
            return this.f;
        },
        id:function(){
            if(0==arguments.length){
                return this.f[this.table.idField];
            }
            else {
                this.f[this.table.idField] = arguments[0];
                return this;
            }
        },
        getPopulateByIdInfo:function(id){
            var names = this.table.qualifiedColumnNames(true);
            var rc = {};
            rc.sql = "SELECT "+names.join(',')+
                      " FROM "+this.table.db.qualify(this.table.name)+
                      " WHERE "+this.table.db.qualify(this.table.idField)+"=?";
            rc.bind = [id];
            return rc;
        },
        populateFromId:function(id){
            var s = this.table.db.prepare(this.getPopulateByIdInfo(id));
            var r;
            try{
                s.bind(1,id);
                this.f = {};
                if((r = s.stepObject())) {
                    this.f = r;
                }
            }
            finally {
                s.finalize();
            }
            return r ? this : undefined;
        }
    }/*Row.prototype*/;

    $.Expr = function(){
        this.$parts = [];
        this.$state = {
            paramCount: 0
        };
    };
    
    function exFwd(key){
        return function(ex){
            this.$parts.push(key);
            if(arguments.length) this.$parts.push(ex);
            return this;
        }
    }
    
    function aliasedFwd(n,a){
        if(n instanceof Array){
            var i = 0, l = n.length, v;
            for( ; i < l; ++i ){
                v = n[i];
                if(i>0) this.$push(',');
                if( v instanceof Array ){
                    aliasedFwd.apply(this,[ v[0],v[1] ]);
                }else{
                    aliasedFwd.apply(this, [v]);
                }
            }
            return this;
        }
        this.$push(this.qualify(n));
        if(a){
            this.$push('AS').$push(a);
        }
        return this;
    }
    function flatten(dest,ar){
        var v, i = 0, l = ar.length;
        for( ; i < l; ++i ){
            v = ar[i];
            if( v instanceof Array ) {
                arguments.callee.apply(this,[dest,v]);
                continue;
            }
            else if(null ===v){
                v = 'NULL';
            }
            dest.push(v);
        }
    }
    $.Expr.prototype = {
        $push:function(v){
            this.$parts.push(v);
            return this;
        },
        qualify:function(n){
            if( this.db && this.db.qualify ) {
                return this.db.qualify(n);
            }
            else {
                return ('string'===typeof n) ? '`'+n+'`' : ''+n;
            }
        },
        escape:function(s){
            if(null===s) return 'NULL';
            else if('number' === typeof s) return s;
            else return (''+s).replace(/'/g, "''");
        },
        quote:function(s){
            s = this.escape(s);
            return ('string'===typeof s) ? "'"+s+"'" : s;
        },
        
        and:exFwd('AND'),
        asc:function(){
            return this.$push('ASC');
        },
        between:function(l,r){
            return this.$push(['BETWEEN',l,'AND',r]);
        },
        boundParam:function(name){
            this.$parts.push(name || '?');
            ++this.$state.paramCount;
            return this;
        },
        comma:function(){
            return this.$push(',');
        },
        clear:function(){
            this.$parts = [];
            this.$state = {
                paramCount: 0
            };
            return this;
        },
        clone:function(){
            var ctor = this.constructor;
            var e = new ctor;
            e.db = this.db;
            e.$parts = JSON.parse(JSON.stringify(this.$parts));
            e.$state = JSON.parse(JSON.stringify(this.$state));
            return e;
        },
        desc:function(){
            return this.$push('DESC');
        },
        eq:exFwd('='),
        gt:exFwd('>'),
        field:aliasedFwd,
        from:exFwd('FROM'),
        IN:function(list){
            var i = 0, v, l = list.length;
            this.$push('IN').$push('(');
            for( ; i < l; ++i ){
                v = this.quote(list[i]);
                if(i>0) this.$push(',');
                this.$push(v);
            }
            return this.$push(')');
        },
        is:exFwd('IS'),
        isNot:exFwd('IS NOT'),
        isNull:exFwd('IS NULL'),
        isNotNull:exFwd('IS NOT NULL'),
        like:exFwd('LIKE'),
        limit:function(n,m){
            if(1==arguments.length) {
                m = n;
                n = 0;
            }
            return this.$push(['LIMIT',n,',',m]);
        },
        lt:exFwd('<'),
        neq:exFwd('<>'),
        not:exFwd('NOT'),
        NULL:function(){
            return this.$push('NULL');
        },
        or:exFwd('OR'),
        order:exFwd('ORDER BY'),
        raw:function(){
            var av = Array.prototype.slice.apply(arguments,[0]);
            return this.$push(av);
        },
        select:exFwd('SELECT'),
        set:function(obj){
            this.$push('SET');
            var ce = arguments.callee;
            if(!ce.rxParam){
                ce.rxParam = /^((:\w+)|\?)$/;
            }
            var k, v, i = 0;
            for( k in obj) {
                v = obj[k];
                if(1 < ++i){
                    this.$push(',');
                }
                this.$push(k).$push('=');
                if( ce.rxParam.test(v) ) this.boundParam(v);
                else this.value(v);
            }
            return this;
        },
        sub:function(ex){
            var e = ex || new Expr();
            this.$push(['(',e,')']);
            return ex ? this: e;
        },
        table:aliasedFwd,
        update:function(tbl){
            this.$push('UPDATE');
            if(arguments.length){
                this.$push(this.qualify(arguments[0]));
            }
            return this;
        },
        value:function(v){
            v = v ? this.escape(v) : v;
            if(null === v) v = 'NULL';
            else if('string'===typeof v){
                v = "'"+v+"'";
            }
            return this.$push( v );
        },
        where:exFwd('WHERE'),

        toJSON:function(){
            return {
                paramCount:this.$state.paramCount,
                parts:this.$parts
            };
        },
        toString:function(){
            var x = [];
            flatten.apply(this, [x, this.$parts]);
            return x.join(' ');
        }
    };
})(JSPDO);

if(1) (function (){
    var db = new JSPDO("sqlite3::memory:");
    var idField = 'myId';
    var lol = JSPDO.Lol;
    function objout(o){
        var lbl;
        if(2==arguments.length){
            lbl = arguments[0];
            o = arguments[1];
        }
        if(lbl) print(lbl);
        print(JSON.stringify(o,0,0));
    }

    try{
        var tables = {
            't':{
                idField:idField,
                defaults:{
                    a:'hi, world',
                    b:-1
                }
            }
        };
        var sql = "CREATE TABLE "+db.qualify('t')+"("+db.qualify(tables.t.idField||'id')+" INTEGER PRIMARY KEY,a,b,c)"
        print("SQL:\n"+sql);
        db.exec(sql);
        objout('tables:',tables);
        tables = lol.getTableDefs(db,tables);

        (function test1(){
            objout('tables:',tables);
            var t = tables.t;
            
            objout('Table:',t);
            var r = t.getRowPrototype();
            r.f.a = 'xyz';
            r.id(1);
            objout('new row from prototype:',r);
            objout('UPDATE sql:',r.getUpdateInfo());
            r.f.a = 'def';
            r.id(null);
            
            objout('create SQL:',t.getRowCreateInfo());
            r = t.createNewRow();
            objout('new row:',r);
            r = t.createNewRow();
            r.f.b = 17;
            r.f.c = (new Date()).toLocaleString();
            r.save();
            objout('Another new row:',r);
            var res = db.fetchAll({sql:"SELECT * FROM "+t.name, mode:'array'});
            objout('fetchAll:',res);
            objout('getPopulateByIdInfo(7)',r.getPopulateByIdInfo(7));
            r.populateFromId(1);
            objout('getRowById 1:',r);
            r = t.getRowById(2);
            objout('t.getRowById 2:',r);
            r = t.getRowById(3);
            objout('t.getRowById 3:',r);
        })();

        (function test2(){
            load('query.js');
            Query._db = db;
            var t = new Table('t');
            var q = t.select(idField||'id','a','c').where(1);
            print('query='+q.toString());
            objout('from Query interface:',
                    db.fetchAll({sql:q.toString()})
            );
        })();

        (function test3(){
            var Expr = JSPDO.Lol.Expr;

            var e = new Expr();
            objout('expr:',e);
            e.field('a').eq().boundParam(':aVal');
            objout('expr:',e);
            var e2 = new Expr();
            e2.where(e);
            objout('expr:',e2);
            print('toString: '+e2)
            e2.order().field('b').desc();
            print('toString: '+e2);
            var sel = new Expr().select();
            var sub = new Expr().
                select().
                value("he's a good dog").isNot().NULL();
                
            sel.sub( sub ).
                comma().
                //field('a').
                field([['a','AA'],['u','UU']]).
                //field(['a','z','u',['h','HH']]).
                //field('a','z').
                //field('u','UU').
                comma().
                from().
                table('x','y').
                where(e).
                    and().sub(sub).
                    and( new Expr().raw('AA').not().IN([1,3,'x15']) ).
                order('z').
                limit(3);
            objout('expr:',sel);
            print('toString: '+sel);
            e = new Expr().field('a').like( new Expr().field('b') );
            objout('another expr:',e);
            print(e);

            e = new Expr().update('x')/*.table('x')*/.set({
                a:3, z:"hi'ya", y:null, d:'?', e:':hi'
            }).where(0).neq(1);
            objout('UPDATE expr:',e);
            print(e);
            e = e.clone();
            objout('CLONEd expr:',e);

        })();

        (function test4(){
            var t = tables.t;
            var rc = t.fetchRows();
            objout("fetchRows():",rc);
        })();
    }
    finally{ db.close(); }
})();
