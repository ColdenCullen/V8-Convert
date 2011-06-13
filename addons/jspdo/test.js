print("Starting tests...");

load('../test-common.js');

//JSPDO.enableDebug = true;
var App = {
drv:null,
user:"",
password:"",
tableName:'mytbl'
};
if(1) {
    App.dsn = 'sqlite3::memory:';
}
else {
    App.dsn = 'mysql5:host=localhost;dbname=cpdo';
    App.user = App.password = 'cpdo';
}

function testConnect() {
    var drv = App.drv = new JSPDO(App.dsn,App.user,App.password);
    print("Driver: "+JSON.stringify(drv,0,4));
    print('JSPDO.columnTypes: '+JSON.stringify(JSPDO.columnTypes,0,4));
    print("Available db drivers: "+JSON.stringify(JSPDO.driverList));
    
    if(drv.driverName==='sqlite3') {
        drv.exec("CREATE TABLE IF NOT EXISTS "+App.tableName+"("+
             "id INTEGER PRIMARY KEY DEFAULT NULL,"+
             "a INTEGER DEFAULT NULL,"+
             "b DOUBLE DEFAULT NULL,"+
             "c VARCHAR(127) DEFAULT NULL"+
             ")");
    }
    else if(drv.driverName==='mysql5') {
        drv.exec("CREATE TABLE IF NOT EXISTS "+App.tableName+"("+
             "id INTEGER PRIMARY KEY DEFAULT NULL AUTO_INCREMENT, "+
             "a INTEGER DEFAULT NULL,"+
             "b DOUBLE DEFAULT NULL,"+
             "c VARCHAR(127) DEFAULT NULL"+
             ")");
    }
    else {
        asserteq(0,1,'Unknown driver name! How can that be?');
    }
}

function testSelect(mode)
{
    var drv = App.drv;
    var st;
    var sql = "select id as id, a as a,b as b,c as c from "+App.tableName;
    try {
        st = drv.prepare(sql);
    }
    catch(e) {
        print("Error preparing sql. Db says: Code #"+drv.errorCode+": "+drv.errorText);
        return;
    }
    print('Testing SELECT. statement='+JSON.stringify(st));
    var sep = '\t';
    if( !st ) throw new Error("WTF? st is null?");
    var colCount = st.columnCount;
    print("Column count="+colCount);
    try {
        var rowCount = 0, i;
        if('object'===mode) {
            var row;
            while( (row = st.stepObject()) ) {
                //asserteq( colCount, row.length, 'Column count matches.' );
                print(JSON.stringify(row));
                ++rowCount;
            }
        }
        else if('array'===mode){
            print( st.columnNames.join(sep) );
            var row;
            while( (row = st.stepArray()) ) {
                //asserteq( colCount, row.length, 'Column count matches.' );
                print(row.join(sep));
                ++rowCount;
            }
        }
        else {
            print( st.columnNames.join(sep) );
            var cols = [], v;
            while( st.step() ) {
                ++rowCount;
                cols.length = 0;
                for(i=0; i < colCount;++i ) {
                    v = st.get(i);
                    cols.push('[type='+st.columnType(i)+']'+
                              ( (v===null) ? 'NULL' : v )
                              );
                }
                print(cols.join(sep));
            }
        }
        print(rowCount+" row(s)");
    }
    finally {

        st.finalize();
    }

}

function testCleanup()
{
    App.drv.exec("DELETE FROM "+App.tableName);
}

function testInsert()
{
    var st;
    try {
        var sql = "INSERT INTO "+App.tableName+"(a,b,c) VALUES(?,?,?)";
        var ds = (new Date()).toString();
        st = App.drv.prepare(sql);
        st.bind(1,24.42);
        st.bind(2);
        st.bind(3, ds);
        //assertThrows( function() { st.bind(4); } );
        st.step();
        print('Inserted new record. ID='+App.drv.lastInsertId("ignored"));
        st.reset();
        st.bind([42.24, null, ds]);
        st.step();
        print('Inserted new record. ID='+App.drv.lastInsertId());
        print('SQL = '+st.sql);
    }
    finally {
        if( st ) {
            st.finalize();
        }
    }
}

function testInsertNamedParams() {
    var st;
    try {
        var sql = "INSERT INTO "+App.tableName+"(a,b,c) VALUES(:pA,:pB,:pC)";
        var ds = (new Date()).toString();
        st = App.drv.prepare(sql);
        asserteq(3,st.paramIndex(':pC'));
        asserteq(0,st.paramIndex(':pX'));
        st.bind(':pB', 32.23);
        st.bind({pA:7, ':pC':ds});
        print('Parameter names: '+JSON.stringify(st.paramNames));
        //assertThrows( function() { st.bind(':pD'); } );
        st.step();
        print('Inserted new record using named params. ID='+App.drv.lastInsertId());
    }
    finally {
        if( st ) {
            st.finalize();
        }
    }

}

function testExt_forEach() {
    var st, sql = "SELECT * FROM "+App.tableName+" WHERE a > ? LIMIT 3";
    var st;
    sql = App.drv.prepare(sql);
    var opt = {
        sql:sql,
        //bind:[20],
        bind:function(st){st.bind(1,20);},
        mode:'object',
        //mode:'array',
        foreach:function(row,data){
            ++data.rows;
            print(JSON.stringify(row));
        },
        foreachData:{rows:0}
    };
    print("Trying db.execForeach(): "+JSON.stringify(opt));
    try {
        //App.drv.execForeach(opt);
        App.drv.exec(opt);
    }
    finally {
        if( sql instanceof JSPDO.Statement ) sql.finalize();
    }
    print(opt.foreachData.rows+" row(s)");
}

function testExt_fetchAll() {
    var sql;
    sql = "SELECT * FROM "+App.tableName+" WHERE a > :pA LIMIT 3";
    if(1) {
        sql = App.drv.prepare(sql);
        print('fetchAll() parameter names: '+JSON.stringify(sql.paramNames));
        print('parameter name 1: '+sql.paramName(1));
        assertThrows( function() { sql.paramName(5) } );
    }
    var opt = {
        sql:sql,
        bind:{pA:20},
        mode:'array'
        //mode:'object'
    };
    print("Trying db.fetchAll( "+JSON.stringify(opt)+" )");
    var all = App.drv.fetchAll(opt);
    print(JSON.stringify(all));
    print(all.rows.length+" row(s)");
}

function test_QueryClass()
{
    var src = 'query.js';
    if( ! load(src) ) {
        print("Could not load ["+src+"].");
        return;
    }
    print("Poking around the 3rd-party Query class...");
    var db = App.drv;
    db.qualify = function(x) { return '`'+x+'`';}
    db.escape = function(x) { return ('string' === typeof x) ? x.replace(/\'/g,"''") : x;}
    db.query = db.exec;
    print("escaped:",db.escape("He's not from'n 'round here."));
    Query.setDB( db );
    var q = new Query(Query.SELECT)
        .field('c')
        .table(App.tableName)
        .where("%f like '%%01:%%'",'c')
        .limit(7);
    print("Query:",q);
    //print( q.execute() );

    var t = new Table(App.tableName);
    q = t.select()
        .field('c')
        .where("%f like '%%01:%%'",'c')
        .limit(7);
    print("Query:"+q);
    t = new Table(App.tableName);
    q = t.insert({a:56.65, b:78.87, c:"Hi, world's'!"});
    print("Query:"+q);
    //testSelect();
    //print( q.execute() );
}

try {
    testConnect();
    testCleanup();
    assert( App.drv, "Driver is alive." );
    testSelect();
    testInsert();
    testSelect('object');
    testInsertNamedParams();
    testSelect('array');
    testExt_forEach();
    testExt_fetchAll();
    //test_QueryClass();
}
catch(e) {
    print("EXCEPTION: "+e);
    //stacktrace is reset in catch! print("Stacktrace:\n"+JSON.stringify(getStacktrace(),0,4));
}
finally {
    if( App.drv ) {
        //print("Closing driver connection "+JSON.stringify(App.drv));
        App.drv.close();
        delete App.drv;
    }
}

print("Tests finished.");
