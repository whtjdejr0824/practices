#include <SimpleTimer.h>
int pin_LED1 = 3;
int pin_LED2 = 5;
int pin_LED3 = 7;

SimpleTimer timer;

// void blink_1000() {
//     time_current1 = millis():

//     if(time_current1 - time_previous >= 1000) {
//         time_previous1 = time_current1;
//         LED_state1 = !LED_state1
//         digitalWrite(pin_LED1, LED_state1);
//     }
// }
void blink_1000() {
    int state = digitalRead(pin_LED1);
    digitalWrite(pin_LED1, !state); // toggle
}

void blink_500() {
    int state = digitalRead(pin_LED2); // 지정한 핀의 현재 상태 읽기
    digitalWrite(pin_LED2, !state);
}

void blink_200() {
    int state = digitalRead(pin_LED3); // 지정한 핀의 현재 상태 읽기
    digitalWrite(pin_LED3, !state);
}

void setup() {
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);
    timer.setInterval(1000, blink_1000);
    timer.setInterval(500, blink_500);
    timer.setInterval(200, blink_200);
}

void loop() {
    timer.run();
}