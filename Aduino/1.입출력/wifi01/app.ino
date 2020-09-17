#include <WifiUtil.h>

char ssid[] = "Jsd.2.4"; // your network SSID (name)
char pass[] = "whtjdejr0824"; // your network password

WifiUtil wifi(2, 3);

void setup() {
    Serial.begin(9600);
    wifi.init(ssid, pass);
}

void loop() {
    if(wifi.check()) { // WIFI 연결 확인
      ;
    }
}