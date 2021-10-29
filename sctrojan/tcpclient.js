var hexVal = "fff";

var net = require("net");
var HOST = "192.168.0.17";
var PORT = 3000;

var client = new net.Socket();
// client.connect(PORT, HOST, function(){
//     console.log('CONNECTED TO: ' + HOST + ":" + PORT);
//     client.write(hexVal);
// });

// client.on('data', function(data){
//     console.log('DATA: ' + data);
//     client.destroy();
// });
// client.on('close', function(){
//     console.log("Connection closed");
// });