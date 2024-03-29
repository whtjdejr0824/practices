#include <DHT.h> // DHT.h 라이브러리를 포함한다
#include "MiniCom.h" 
#define DHTPIN 2 // DHT핀을 2번으로 정의 한다.(DATA핀)
#define DHTTYPE DHT11  //DHT타입을 DHT11로 정의한다

DHT dht11(DHTPIN, DHTTYPE); // DHT설정 - dht (디지털3, dht11)

MiniCom com;

void checkHumiTemp() {
    float h = dht11.readHumidity(); // 변수 h에 습도 값을 저장
    float t = dht11.readTemperature(); // 변수 t에 온도 값을 저장
    
    com.print(0, "Humi", h);
    com.print(1, "Temp", t); 
}

void setup() {
    com.init();
    com.setInterval(2000, checkHumiTemp);
    com.print(0, "MiniCom Start...");
    com.print(1, "Humi/Temp Ex");
    dht11.begin();
}
void loop() {
    com.run();
}