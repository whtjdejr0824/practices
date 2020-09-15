#include <Led.h>
#include <Button.h>
#include <SimpleTimer.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SimpleTimer timer;

Led led1(4);  //정지상태에서 on, 기동중 off
Led led2(3);  // 기동중 블링크

Button btn1(11);  // start, stop
Button btn2(10);  // lap time
Button btn3(9);   // reset

int timerId = -1; // stopwatch용 타이머
int blinkTimerId = -1; // 블링크용 타이머

bool state = false; // 0:준비상태, : 가동상태
unsigned long startTime = 0; // 시작 버튼읅 누른 시점의 시간 ****

void printTime(unsigned long t, int row) {
    char buf[17];
    
    // millisecond -> 시:분:초로 변환해서 출력
    int misec = t % 1000 /100; // 100 ms 단위
    t = t/1000; // 밀리초 -> 초
    int h = t /3600;             // 초 -> 시간
    int m = (t - (h*3600)) / 60; // 초 -> 분
    int s = t - (h*3600+m*60);   // 초

    sprintf(buf, "%02d:%02d:%02d,%d", h, m, s, misec);
    lcd.setCursor(0, row);
    lcd.print(buf); 

}

void printTime() {
    unsigned long t = millis();
    unsigned long diff = t - startTime;
    printTime(diff, 0);
}
/// ????
void startStop() {
    if(state == false) { //리셋 이후 처음 버튼을 누른 경우
      // 최초 기동 시작
      startTime = millis();  //기준 시간 설정
      timer.enable(blinkTimerId);
      led1.off();
      state = true; // 기동중임을 설정
    }
      // 잠시 멈춤
      timer.disable(blinkTimerId);
    
}

void laptime() {
    if(state) { //가동중일 때만 출력
      unsigned long t = millis();
      unsigned long diff = t - startTime;
      printTime(diff, 1);
    }
}

void reset() {
    state = false;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("00:00:00.0");
    led1.on();
    led2.off();
    timer.disable(timerId);
    timer.disable(blinkTimerId);
}

void blink() {
    led2.toggle();
}
void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    // 타이머 ID, 0부터 배정
    timerId = timer.setInterval(100, printTime); // 스톱워치용
    blinkTimerId = timer.setInterval(250, blink); // 블링크용 0.25초 간격으로 호출
    reset();

    btn1.setCallback(startStop);
    btn2.setCallback(laptime);
    btn3.setCallback(reset);
}

void loop() {
    timer.run();
    btn1.check();
    btn2.check();
    btn3.check();
}