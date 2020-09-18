#include <math.h>
double Thermister(int RawADC) {
    double Temp;
    Temp = log(((10240000 / RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) *Temp);
    Temp = Temp - 273.15; // Convert Kelvin to Celcius
    return Temp;
}

void setup() {
    Serial.begin(9600);
}

void loop(){
    Serial.print(Thermister(analogRead(A0))); // display Fahrenheit
    Serial.println("c");
    delay(500);
}

// const int ledPin = 2;
// const int thermistorPin = A0;
// int thermistorValue;
// int brightness;

// void setup() {
//     Serial.begin(9600);
// }

// void loop() {
//     thermistorValue=analogRead(thermistorPin);
//     Serial.print("thermistor Value : ");
//     Serial.println(thermistorValue);
//     brightness = map(thermistorValue, 500,625,0,255);
//     Serial.print("brigntness : ");
//     Serial.println(brightness);
//     analogWrite(ledPin, brightness);
//     delay(100);
// }