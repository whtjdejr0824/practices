#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SimpleTimer.h>
#include <WifiUtil.h>
#include <MiniCom.h>
#include <DHT.h>

SoftwareSerial softSerial(2, 3); //RX, TX
const char ssid[] = "Jsd.2.4"; // 네트워크 SSID
const char password[] = "whtjdejr0824"; // 비밀번호
const char mqtt_server[] = "192.168.1.145"; // 라즈베리파이서버 주소

unsigned long lowpulseoccupancy = 0;
float ratio = 0;

const int DUST_PIN = 8;
unsigned long sampletime_ms = 2000;

// MQTT용 WiFi 클라이언트 객체 초기화
WifiUtil wifi(2,3);
WiFiEspClient espClient;
PubSubClient client(espClient);
MiniCom com;
DHT dht(4, DHT11);

void mqtt_init() {
    client.setServer(mqtt_server, 1883);
    // subscriber인경우 메시지 수신시 호출할 콜백 함수 등록
}

// MQTT 서버에 접속될 때까지 재접속 시도
void reconnect() {
    while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    if (client.connect("ESP8266Client")) {
    Serial.println("connected");
    // subscriber로 등록
    client.subscribe("home/livingroom/led");
    } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(" try again in 5 seconds");
    delay(5000);
    }
  }
}

void publish() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    char message[10];

    dtostrf(h, 5, 2, message);
    client.publish("iot/home/humi", message);
    dtostrf(t, 5, 2, message);
    client.publish("iot/home/temp", message);

    com.print(0, "humi", h);
    com.print(0, "temp", t);
    Serial.print(h);
    Serial.print(",");
    Serial.print(t);
}

void setup() {
    com.init();
    wifi.init(ssid, password);
    mqtt_init();
    dht.begin();
    pinMode(DUST_PIN, INPUT);
    com.setInterval(2000, publish);
}

void loop() {
    unsigned long start = millis();
    if (!client.connected()) {
        reconnect();
    }
    client.loop();

    com.run();
    unsigned long end = millis();
    Serial.println(end - start);
}



void dust_check() {
    // Integer percentage 0=>100
    ratio = lowpulseoccupancy / (sampletime_ms * 10.0);
    double concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) +
                    520 * ratio + 0.62; // using spec sheet curve
    int dustDensity = concentration * 100 / 13000;
    lowpulseoccupancy = 0;
    int dust_level = 0;

    if(dustDensity > 150) dust_level = 3;
    else if(dustDensity > 80) dust_level = 2;
    else if(dustDensity > 30) dust_level = 1;
    else dust_level = 0;

    Serial.print(dustDensity);
    Serial.print(",");
    Serial.println(dust_level);
    com.print(0, "D", dustDensity, "L", dust_level);
}