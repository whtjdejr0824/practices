#include <LiquidCrystal_I2C.h>

//I2C  주소, 칸 수(X), 줄 수(Y)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(3,0);

    //문자열 출력
    lcd.print("HELLO WORLD");
}

void loop() {
    lcd.backlight();
    delay(1000);
    lcd.noBacklight();
    delay(1000);


}
