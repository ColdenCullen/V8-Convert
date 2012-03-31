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
            var r = new $.Row(this, d.f);
            try {
                s.step();
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
        loadById: function(id){
            var r = new $.Row(this);
            return r.populateFromId(id) ? r : null;
        },
        qualifiedColumnNames: function(addAs){
            var i, l;
            var names = [];
            for( i = 0, l = this.columns.length; i < l; ++i ){
                names.push( this.db.qualify(this.columns[i])+
                            (addAs ? (' AS '+this.columns[i]) : ''));
            }
            return names;
        }
    }/*Table.prototype*/;

    $.getTableDef = function(db,name){
        var t = new $.Table(db,name);
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
        save: function(){
            var d = this.getUpdateInfo();
            var s = this.table.db.prepare(d.sql);
            try {
                s.bind(d.bind);
                s.step();
            }
            finally {
                s.finalize();
            }
        },
        toJSON:function(){
            return {
                //idField:this.table.idField,
                f:this.f
            };
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
            this.f = {};
            var r;
            try{
                s.bind(1,id);
                if((r = s.stepObject())) {
                    this.f = r;
                }
            }
            finally {
                s.finalize();
            }
            return !!r;
        }
    }/*Row.prototype*/;

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
            objout('loadById 1:',r);
            r = t.loadById(2);
            objout('t.loadById 2:',r);
            r = t.loadById(3);
            objout('t.loadById 3:',r);
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
            function Expr(){
                this.$parts = [];
                this.$state = {
                    paramCount: 0
                };
            }
            function exFwd(key){
                return function(ex){
                    this.$parts.push(key);
                    if(ex) this.$parts.push(ex);
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
                        flatten(dest,v);
                    }
                    else {
                        dest.push(''+v);
                    }
                }
            }
            Expr.prototype = {
                $push:function(v){
                    this.$parts.push(v);
                    return this;
                },
                qualify:function(n){
                    return ('string'===typeof n) ? '`'+n+'`' : ''+n;
                },
                escape:function(s){
                    if(null===s) return 'NULL';
                    else if('number' === typeof s) return s;
                    else return (''+s).replace(/'/g, "''");
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
                    var x = JSON.parse(JSON.stringify(this));
                    var e = new Expr();
                    e.$parts = x.$parts;
                    e.$state = x.$state;
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
                    this.$push('IN').$push('(');
                    this.$push(list.join(', '));
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
                    return this.$push(av.join(' '));
                },
                select:exFwd('SELECT'),
                sub:function(ex){
                    var e = ex || new Expr();
                    this.$push(['(',e,')']);
                    return ex ? this: e;
                },
                table:aliasedFwd,
                update:exFwd('UPDATE'),
                value:function(v){
                    v = this.escape(v);
                    if('string'===typeof v){
                        v = "'"+v+"'";
                    }
                    return this.$push( v );
                },
                where:exFwd('WHERE'),

                toJSON:function(){
                    return this.$parts;
                },
                toString:function(){
                    var x = [];
                    flatten(x, this.$parts);
                    return x.join(' ');
                }
            };

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
                    and( new Expr().raw('AA').not().IN([1,3,5]) ).
                order('z').
                limit(3);
            objout('expr:',sel);
            print('toString: '+sel);
            e = new Expr().field('a').like( new Expr().field('b') );
            objout('another expr:',e);
            print(e);
            
        })();
    }
    finally{ db.close(); }
})();
