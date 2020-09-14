#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("Arduino LCD"); 
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Welcome");
    delay(250);
    // LCD 백라이트 두번 점멸
    lcd.noBacklight();
    delay(250);
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
    lcd.backlight();
    delay(3000);
    // Open Serial Monitor Type to display 표시
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Open Serial Mntr");
    lcd.setCursor(0, 1);
    lcd.print("Type to display");
}

// 16x2
//라인별로 한줄 전체를 덮어있는 형태...
//python input()
String readLIne() {
    String line = "";
    //Serial로 부터 한줄 입력 받아.. line 변수에 저장

    while(Serial.available() > 0) {
        char ch = Serial.read();
        if(ch != '\r' && ch != '\n')
        line +=ch;
    }
    return line;
}


void loop() {
    if(Serial.available()) {
       delay(100);
    //    lcd.clear(); // 긴 문장 보내고 --> 짧은 문장 전송.
       lcd.setCursor(0, 0);
       lcd.print("Message from PC");
       lcd.setCursor(0, 1);

       String line = readLIne();
       if(line != "") // 수신데이터 유무
         lcd.setCursor(0, 1);
         char buf[17]; // \0
         sprintf(buf, "%-16s", line.c_str());  //f"{}" x+y=16(-:우측정렬)
         
         lcd.print(buf); // conste char * 타입

    //    while(Serial.available() > 0) {
    //        char ch = Serial.read();
    //        if(ch != '\r' && ch != '\n')
    //         //   lcd.write(ch); // 
    //           lcd.print(line.c_str());
    //     }
    }
}