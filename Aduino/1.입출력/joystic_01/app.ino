#include <LiquidCrystal_I2C.h>
#include <Button.h>
#include <AnalogSensor.h>

AnalogSensor jx(A0, 0,1023);
AnalogSensor jy(A1, 0,1023);
Button btn(2);

LiquidCrystal_I2C lcd(0x27, 6, 2);
SimpleTimer timer;

void readJoystick() {
    char buf[17];

    int x = jx.read();
    int y = jy.read();
    int z = jz.read();
    sprintf(buf, "x: %4d, y: %4d", x, y);
    lcd.setCursor(0, 0);
    lcd.print(buf);

    spritf(buf, "z: %d", z);
    lcd.setCursor(0, 1);
    lcd.print(buf);
}

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();

    timer.setInterval(50, readJoystick);
    Serial.begin(9600);
}

void loop() {
    timer.run();
}