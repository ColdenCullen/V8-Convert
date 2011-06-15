print("Starting tests...");

load('../test-common.js');

JSPDO.enableDebug = true;
var App = {
drv:null,
user:"",
password:"",
tableName:'mytbl',
CREATE:{
    mysql5:"CREATE TABLE IF NOT EXISTS mytbl("+
             "id INTEGER PRIMARY KEY DEFAULT NULL AUTO_INCREMENT, "+
             "a INTEGER DEFAULT NULL,"+
             "b DOUBLE DEFAULT NULL,"+
             "c VARCHAR(127) DEFAULT NULL"+
             ")",
    sqlite3:"CREATE TABLE IF NOT EXISTS mytbl("+
             "id INTEGER PRIMARY KEY DEFAULT NULL,"+
             "a INTEGER DEFAULT NULL,"+
             "b DOUBLE DEFAULT NULL,"+
             "c VARCHAR(127) DEFAULT NULL"+
             ")"
}
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
    assertThrows(function() { drv.driverName = "should throw"; });
    asserteq( true, !!App.CREATE[drv.driverName] );
    drv.exec(App.CREATE[drv.driverName]);
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
        assertThrows(function(){st.columnNames="should throw";});
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
        print("Inserting: "+st);
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
        print("Inserting: "+st);
        print('Parameter names: '+JSON.stringify(st.paramNames));
        assertThrows(function(){st.paramNames="should throw";});
        assertThrows( function() { st.bind(':pD'); } );
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
        bind:function(st){st.bind(1,20)},
        mode:'object',
        //mode:'array',
        each:function(row,data){
            ++data.rows;
            print(JSON.stringify(row));
        },
        callbackData:{rows:0}
    };
    print("Trying db.exec("+JSON.stringify(opt)+")");
    try {
        App.drv.exec(opt);
        asserteq( 2, opt.callbackData.rows, 'expecting 2 rows' );
    }
    finally {
        if( sql instanceof JSPDO.Statement ) sql.finalize();
    }
    print(opt.callbackData.rows+" row(s)");
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
    asserteq( 2, all.rows.length, 'expecting 2 rows' );
}

function testCopyDb() {
    var db1 = App.drv;
    var db2, st1, st2;
    try {
        db2 = new JSPDO('sqlite3::memory:');
        print("Copying "+App.tableName+".* from "+db1+" to "+db2+"...");
        db2.exec(App.CREATE[db1.driverName]);
        db2.exec("DELETE FROM "+App.tableName);
        st1 = db1.prepare("SELECT * FROM "+App.tableName);
        var i, f = new Array(st1.columnCount);
        for( i = 0; i < f.length; ++i ) f[i] = '?';
        st2 = db2.prepare("INSERT INTO "+App.tableName+" ("+
                        st1.columnNames.join(',')+
                        ') VALUES('+f.join(',')+')');
        f = null;
        i = 0;
        db2.begin();
        while( st1.step() ) {
            st2.bind(st1);
            st2.step();
            st2.reset();
            ++i;
        }
        st1.finalize(); st1 = null;
        st2.finalize(); st2 = null;
        db2.commit();
        print("Copied "+i+" record(s) to second db instance. Results:");
        db2.exec({
            sql:"SELECT * FROM "+App.tableName,
            each:function(row) {print(JSON.stringify(row));},
            mode:'array'
        });
    }
    finally {
        if( st1 ) st1.finalize();
        if( st2 ) st2.finalize();
        if( db2 ) db2.close();
    }
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
    testCopyDb();
}
catch(e) {
    print("GOT AN EXCEPTION: "+e);
    //stacktrace is reset in catch! print("Stacktrace:\n"+JSON.stringify(getStacktrace(),0,4));
}
finally {
    if( App.drv ) {
        print("Closing driver connection "+JSON.stringify(App.drv));
        App.drv.close();
        delete App.drv;
    }
}

print("Tests finished.");
