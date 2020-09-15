#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <AnalogSensor.h>
#include <SimpleTimer.h>

AnalogSensor poten(A0, 0, 179);
LiquidCrystal_I2C lcd(0x27, 6, 2);
Servo servoMoter;
SimpleTimer timer;

const int servoPin = 9;

void motorControl() {
    char buf[17];

    int angle = poten.read();
    servoMoter.write(angle);

    sprintf(buf, "amngle : 3d%", angle);
    lcd.setCursor(0, 0);
    lcd.print(buf);
}

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();

    servoMoter.attach(servoPin);
    servoMoter.write(poten.read());
    timer.setInterval(50, motorControl);
    Serial.begin(9600);
}

void loop() {
    char buf[17];

    int angle = poten.read();
    servoMoter.write(angle);

    sprintf(buf, "angle : 3d%", angle);
    lcd.setCursor(0, 0);
    lcd.print(buf);
}