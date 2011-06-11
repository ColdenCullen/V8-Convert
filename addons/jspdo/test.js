print("Starting tests...");

load('../test-common.js');

var App = {
drv:null,
user:"",
password:"",
tableName:'mytbl'
};
if(1) {
    App.dsn = 'sqlite3:db.sqlite3';
}
else {
    App.dsn = 'mysql5:host=localhost;dbname=cpdo';
    App.user = App.password = 'cpdo';
}

function testConnect() {
    var drv = App.drv = new JSPDO(App.dsn,App.user,App.password);
    print("Driver: "+drv);
    var li, k;
    li = ['ERROR',
          'NULL',
          'INT8',
          'INT16',
          'INT32',
          'INT64',
          'FLOAT',
          'DOUBLE',
          'STRING',
          'BLOB',
          'CUSTOM'
          ];
    print('JSPDO.columnTypes:');
    for( k in li ) {
        k = li[k];
        print('\t'+k+'='+JSPDO.columnTypes[k]);
    }

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
        asserteq(0,1,'Unknown driver name! How can that be? i wrote the damned thing!');
    }
}

function testSelect()
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
    print('statement='+st);
    if( !st ) throw new Error("WTF? st is null?");
    var colCount = st.columnCount;
    print("Column count="+colCount);
    try {
        var cols = [], i, v;
        var names = [];
        for(i=0; i < colCount; ++i ) {
            names.push(st.columnName(i));
        }
        print( names.join('\t') );
        while( st.step() ) {
            cols.length = 0;
            for(i=0; i < colCount;++i ) {
                v = st.getColumn(i);
                cols.push('[type='+st.columnType(i)+']'+
                          ( (v===null) ? 'NULL' : v )
                          );
            }
            print(cols.join('\t'));
        }
    }
    finally {
        print("Closing statement handle "+st);
        st.finalize();
    }

}

function testInsert()
{
    var st;
    try {
        var sql = "INSERT INTO "+App.tableName+"(a,b,c) VALUES(?,?,?)";
        st = App.drv.prepare(sql);
        st.bind(1,24.42);
        st.bind(2);
        st.bind(3, (new Date()).toString() );
        st.step();
        print('Inserted new record. ID='+App.drv.lastInsertId())
    }
    finally {
        if( st ) {
            print("Closing statement handle "+st);
            st.finalize();
        }
    }
}

try {
    testConnect();
    assert( App.drv, "Driver is alive." );
    testSelect();
    testInsert();
    testSelect();
}
catch(e) {
    print("Exception: "+e);
}
finally {
    if( App.drv ) {
        print("Closing driver connection "+App.drv);
        App.drv.close();
        delete App.drv;
    }
}
print("Tests finished.");
