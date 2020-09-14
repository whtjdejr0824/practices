#include "Led.h"
#include "Button.h"

Led led(4);
Button btn(11);

void setup() {
    Serial.begin(9600);
}

void work() {
     led.toggle();
}

void loop() {
    led.set(btn.read()); //풀업 버튼인 경우 반전
    // if(state_current) { // 누른경우
    //    if(state_previous == true) {
    //        state_previous = false;
    //        // 버튼을 누른 시점에서 해야할 작업
    //        work();
    //    }
    //    delay(10);
    // } else {
    //     state_previous = true;
    // }
}

// 문제...
// 버튼을 한번 누르면 13번 LED를 켜고
// 버튼을 다시 누르면 13번 LED를 끄세요