var echo = {
host:'127.0.0.1',
//port:9090,
port:8080,
crnl:'\r\n'
};
echo.socketType =
    //echo.Socket.SOCK_DGRAM
    Socket.SOCK_STREAM
    ;
echo.socketFamily = Socket.AF_INET;
