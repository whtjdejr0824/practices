#include "BtMiniCom.h"

BtMiniCom::BtMiniCom(int rx, int tx, btminicom_callback_t callback)
    : MiniCom(), btSerial(rx, tx), callback(callback) {
    }

void BtMiniCom::init() {
    MiniCom::init();
    btSerial.begin(9600);
}
String BtMiniCom::readLine(){
    String message="";
    while (btSerial.available()){
        char data = (char)btSerial.read();
        if(data == '\r') continue;
        if(data == '\n') break;

        message+=data;
        delay(5);
    }
    Serial.print(message);
    return message;
}

void BtMiniCom::send(const char *msg){
    btSerial.println(msg);
}

void BtMiniCom::run(){
    String msg = readLine();
    if(msg != "" && callback != NULL) {
        Serial.print(msg);
        callback(msg);
    }
    MiniCom.run();
}