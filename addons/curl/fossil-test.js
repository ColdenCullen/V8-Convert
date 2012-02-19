
Curl.fossilJson = function(opt){
    var c = new Curl();
    var content;
    var inBody;
    try {
        var contentLength;
        if(opt.envelope){
            if('object' === typeof opt.envelope) {
                content = JSON.stringify(opt.envelope);
            }
            else if('string' === typeof opt.envelope){
                content = opt.envelope;
            }
        }
        if(content) {
            content = new Curl.ByteArray(content);
            contentLength = content.length;
        }

        var copt = {
            url: opt.url,
            //verbose: true,
            httpHeader:['Content-Type: application/json'],
            writeFunction: function(data, ud){
                if(!inBody) inBody = new Curl.ByteArray();
                inBody.append(data);
                var len = data.length;
                data.destroy();
                return len;
            }
        };
        if( content ){
            copt.post = true;
            copt.httpHeader.push('Content-Length: '+contentLength);
            copt.readFunction = function(len,ud)
            {
                //throw new Error("Testing error handling.");
                if( ud.pos >= contentLength ) return null;
                var clen = contentLength - ud.pos;
                var xlen = (len > clen) ? clen : len;
                var s = content.slice( ud.pos, xlen );
                //print("readFunction(",len,") sending",s.length,'bytes');
                ud.pos += xlen;
                return s;
            };
            copt.readData = {
                pos:0
            };
        }
        c.setOpt(copt);
        var rc = c.easyPerform();
        if(rc){
            throw new Error("Curl returned error code #"+rc+".");
        }
        if('function' === typeof opt.onResponse){
            var body = inBody ? inBody.stringValue() : "";
            //print("CONTENT: "+body);
            opt.onResponse(JSON.parse(body));
        }
    }
    finally{
        if(inBody) inBody.destroy();
        if(content) content.destroy();
        c.destroy();
    }
};

function test1(){
    var opt = {
        onResponse:function(obj){
            print("onResponse: "+JSON.stringify(obj));
        },
        url: 'http://fossil.wanderinghorse.net/repos/whio/index.cgi/json',
        envelope: {
            "command": "wiki/list",
            "requestId": "yoohooÄöüß"
        }
    };
    Curl.fossilJson(opt);

}

test1();

