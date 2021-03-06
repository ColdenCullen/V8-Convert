/*
Source derived from: http://code.google.com/p/v8cgi/wiki/API_Query
License: New BSD (???)
*/

(function(Namespace){
    
    var Query = Namespace.Query = function(type) {
        this._cache = {};
        this._type = type;
        this._table = [];
        this._field = []; 
        this._value = []; 
        this._where = [];
        this._order = [];
        this._limit = null;
        this._offset = 0;
        this._group = [];
        this._having = [];
    }

    Query.SELECT = 0;
    Query.INSERT = 1;
    Query.UPDATE = 2;
    Query.DELETE = 3;
    Query._relations = [];
    Query._db = null;

    Query.setDB = function(db) {
        this._db = db;
    }

    Query.addRelation = function(t1,f1,t2,f2) {
        this._relations.push([t1,f1,t2,f2]);
    }

    Query.findRelation = function(t1, t2, joinfield) {
        for (var i=0;i<this._relations.length;i++) {
            var rel = this._relations[i];
            if (
                (rel[0] == t1 && rel[2] == t2) ||
                (rel[2] == t1 && rel[0] == t2)
            ) { 
                if (joinfield && joinfield != rel[1] && joinfield != rel[3]) { continue; }
                return rel;
            } else { continue; }
        }
        return null;
    }

    var qp = Query.prototype;
    qp.table = function(name, jointype, joinfield) {
        var obj = {
            name:name,
            jointype:jointype,
            joinfield:joinfield
        }
        this._table.push(obj);
        return this;
    }

    qp.join = qp.table;

    qp.field = function(fieldDef) {
        var str = "";
        if (arguments.length == 1) {
            str = this._qualify(fieldDef);
        } else {
            str = this._expand.apply(this, arguments);
        }
        this._field.push(str);
        return this;
    }

    qp.value = function(value, noescape) {
        var val = value;
        if (!noescape) { val = this._quote(val); }
        this._value.push(val);
        return this;
    }

    qp.where = function(conditionDef) {
        this._where.push(this._expand.apply(this, arguments));
        return this;
    }

    qp.order = function(fieldDef) {
        this._order.push(this._expand.apply(this, arguments));
        return this;
    }

    qp.limit = function(limit) {
        this._limit = limit;
        return this;
    }

    qp.offset = function(offset) {
        this._offset = offset;
        return this;
    }

    qp.group = function(field) {
        this._group.push(this._qualify(field));
        return this;
    }

    qp.having = function(conditionDef) {
        this._where.push(this._expand.apply(this, arguments));
        return this;
    }

    qp.toString = function() {
        this._cache = {};
        if (!this._field.length && this._type == Query.SELECT) { this.field("*"); }
        switch (this._type) {
            case Query.SELECT: return this._toStringSelect();
            case Query.INSERT: return this._toStringInsert();
            case Query.UPDATE: return this._toStringUpdate();
            case Query.DELETE: return this._toStringDelete();
            default: return false;
        }
    }

    qp.execute = function() {
        var str = this.toString();
        return Query._db.query(str);
    }

    qp._toStringSelect = function() {
        var arr = [];
        arr.push("SELECT");
        arr.push(this._toStringField());
        arr.push(this._toStringTable());
        arr.push(this._toStringWhere());
        arr.push(this._toStringGroup());
        arr.push(this._toStringHaving());
        arr.push(this._toStringOrder());
        arr.push(this._toStringLimit());
        arr.push(this._toStringOffset());
        return arr.join(" ");
    }

    qp._toStringInsert = function() {
        var arr = [];
        arr.push("INSERT");
        arr.push(this._toStringTable());
        arr.push(this._toStringField());
        return arr.join(" ");
    }

    qp._toStringUpdate = function() {
        var arr = [];
        arr.push("UPDATE");
        arr.push(this._toStringTable());
        arr.push(this._toStringField());
        arr.push(this._toStringWhere());
        arr.push(this._toStringOrder());
        arr.push(this._toStringLimit());
        arr.push(this._toStringOffset());
        return arr.join(" ");
    }

    qp._toStringDelete = function() {
        var arr = [];
        arr.push("DELETE");
        arr.push(this._toStringTable());
        arr.push(this._toStringWhere());
        arr.push(this._toStringOrder());
        arr.push(this._toStringLimit());
        arr.push(this._toStringOffset());
        return arr.join(" ");
    }

    qp._toStringOffset = function() {
        return (this._offset ? "OFFSET "+this._offset : "");
    }

    qp._toStringLimit = function() {
        return (this._limit !== null ? "LIMIT "+this._limit : "");
    }

    qp._toStringOrder = function() {
        return (this._order.length ? "ORDER BY "+this._order.join(", ") : "");
    }

    qp._toStringHaving = function() {
        var str = "";
        if (this._having.length) {
            str += "HAVING "+this._having.join(" ");
        }
        return str;
    }

    qp._toStringWhere = function() {
        var str = "";
        if (this._where.length) {
            str += "WHERE "+this._where.join(" ");
        }
        return str;
    }

    qp._toStringGroup = function() {
        if (this._group.length) {
            return "GROUP BY "+this._group.join(", ");
        } else {
            return "";
        }
    }

    qp._toStringTable = function() {
        var cache = {};
        switch (this._type) {
            case Query.SELECT:
                var arr = [];
                for (var i=0;i<this._table.length;i++) {
                    var item = this._table[i];
                    var name = item.name;
                    if (name in cache) {
                        cache[name]++;
                    } else {
                        cache[name] = 1;
                    }
                    var alias = this._qualify(this._setAlias(name));
                    var full = this._qualify(name) + " AS "+alias;
                    
                    if (!i) {
                        arr.push(full);
                    } else {
                        var str = "";
                        if (item.jointype) { str += item.jointype+" "; }
                        str += "JOIN "+full;
                        
                        var rel = false;
                        for (var j=0;j<i;j++) {
                            var t2 = this._table[j].name;
                            rel = rel || Query.findRelation(name, t2, item.joinfield);
                        }
                        if (rel) {
                            var tmp1 = this._getAlias(rel[0]) + "." + rel[1];
                            var tmp2 = this._getAlias(rel[2]) + "." + rel[3];
                            str += " ON "+this._qualify(tmp1)+" = "+this._qualify(tmp2);
                        }
                        arr.push(str);
                    }
                }
                return "FROM "+arr.join(" ");
            break;
            
            case Query.INSERT:
                return "INTO "+this._qualify(this._table[0].name);
            break;
            
            case Query.UPDATE:
                return this._qualify(this._table[0].name);
            break;
            
            case Query.DELETE: 
                return "FROM "+this._qualify(this._table[0].name);
            break;
        }
    }

    qp._toStringField = function() {
        switch (this._type) {
            case Query.SELECT:
                return this._field.join(", ");
            break;
            
            case Query.INSERT:
                return "("+this._field.join(", ")+") VALUES ("+this._value.join(", ")+")";
            break;
            
            case Query.UPDATE:
                var arr = [];
                for (var i=0;i<this._field.length;i++) {
                    arr.push(this._field[i]+"="+this._value[i]);
                }
                return "SET "+arr.join(", ");
            break;
        }
    }

    qp._qualify = function(str) {
        var parts = str.split(".");
        var arr = [];
        for (var i=0;i<parts.length;i++) {
            var val = parts[i];
            arr.push(val == "*" ? val : Query._db.qualify(val));
        }
        return arr.join(".");
    }

    qp._escape = function(str) {
        return Query._db.escape(str);
    }

    qp._quote = function(str) {
        var v = Query._db.escape(str);
            return ( 'string' === typeof v ) ?
                "'"+v+"'"
                : ((null===v) ? 'NULL' : v);
    }
        
    qp._expand = function(str) {
        if (arguments.length == 1) { return str; }
        var s = "";
        var argptr = 1;
        var index = 0;
        var start = false;
        
        while (index < str.length) {
            var ch = str.charAt(index);
            switch (ch) {
                case "%":
                    start = !start;
                    if (!start) { s += ch; }
                break;
                
                case "f":
                    if (start) {
                        start = false;
                        s += this._qualify(arguments[argptr++]);
                    } else {
                        s += ch;
                    }
                break;
                
                case "s":
                    if (start) {
                        start = false;
                        s += this._quote(arguments[argptr++]);
                    } else {
                        s += ch;
                    }
                break;
                
                case "n":
                    if (start) {
                        start = false;
                        var num = parseFloat(arguments[argptr++]);
                        if (isNaN(num)) { num = 0; }
                        s += num;
                    } else {
                        s += ch;
                    }
                break;
                
                default:
                    s += ch;
                break;
            }
            index++;
        }
        return s;
    }

    qp._setAlias = function(name) {
        if (name in this._cache) {
            this._cache[name]++;
        } else {
            this._cache[name] = 1;
        }
        return this._getAlias(name);
    }

    qp._getAlias = function(name) {
        if (name in this._cache && this._cache[name] > 1) {
            return name+"#"+this._cache[name];
        } else {
            return name;
        }
    }

    var Table = Namespace.Table = function(name) {
        this._name = name;
    }

    var tp = Table.prototype;
    tp.select = function() {
        var q = new Query(Query.SELECT);
        q.table(this._name);
        for (var i=0;i<arguments.length;i++) {
            q.field(arguments[i]);
        }
        return q;
    }

    tp.insert = function(values) {
        var q = new Query(Query.INSERT);
        q.table(this._name);
        for (var name in values) {
            var value = values[name];
            q.field(name);
            q.value(value);
        }
        return q;
    }

    tp.update = function(values) {
        var q = new Query(Query.UPDATE);
        q.table(this._name);
        for (var name in values) {
            var value = values[name];
            q.field(name);
            q.value(value);
        }
        return q;
    }

    tp["delete"] = function(values) {
        var q = new Query(Query.DELETE);
        q.table(this._name);
        return q;
    }

    tp.remove = tp["delete"];

    //exports.Query = Query;
    //exports.Table = Table;
})(this);

if(1) (function test1(){
    
})();
