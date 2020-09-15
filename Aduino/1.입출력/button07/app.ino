#include "Led.h"
#include "Button.h"
#include <SimpleTimer.h>

SimpleTimer timer; 

Led led1(6);
Led led2(4);
Led led3(3);

Button btn1(11);
Button btn2(10);
Button btn3(9);

bool blinkPlay = false; //블링크 중인지 여부, 디폴트는 중지
int blinkTimer = -1; //블링크용 타이머 ID

void led2OnOff() {
    led2.toggle();
}

void led3Blink() {
    led3.toggle();
}

void led3BlinkControl() {
    blinkPlay = !blinkPlay; //상태반전
    if(blinkPlay) {         // 이제 블링크 중지면
        led3.off();
    }
    timer.toggle(blinkTimer);   //타이머 활성/ 비활성 토글
}

void setup() {
    Serial.begin(9600);
    btn2.setCallback(led2OnOff);
    btn3.setCallback(led3BlinkControl);
    blinkTimer = timer.setInterval(500, led3Blink);
    timer.disable(blinkTimer); //타이머 중지 상태로 시작
    
}

void loop() {
    timer.run();
    led1.set(btn1.read()); //풀업 버튼인 경우 반전
    btn2.check(); //에지가 발생했는지 체크
    btn3.check(); //에지가 발생했는지 체크

}

// 문제...
// 버튼을 한번 누르면 13번 LED를 켜고
// 버튼을 다시 누르면 13번 LED를 끄세요