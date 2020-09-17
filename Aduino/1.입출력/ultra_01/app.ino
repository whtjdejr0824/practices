#include <MiniCom.h>
#include <Ultra.h>
#include <Servo.h>
#include <LED.h>
#include <Pulse.h>

MiniCom com;
Ultra ultra(2, 3);
Led led(8);
Servo servo;
Pulse pulse(100, 500);

int delayTimes[] ={
    50, 100, 200, 300, 500, 1000
};

void pulseCallback(int value) {
    //LED제어
    led.set(value);
}
void checkDistance() {
   int distance = ultra.read();
   com.print(0, "distance", distance);
   if(distance <10) {
    // led.on();
    // Pulse의 offDelay를 distance를 고려하여 조성
       int offDelay = map(distance, 0, 9, 0, 4);
       pulse.setDelay(10, delayTimes[offDelay]);
       servo.write(90);
       if(!pulse.getState()) { //처음 10초, 이하로 됐을 때
           pulse.play();
       }
   } else {
       if(pulse.getState()) {
           pulse.stop();
       }
       // led.off();
       servo.write(0);
   }
}

void setup() {
    com.init();
    servo.attach(9);
    servo.write(0);
    com.setInterval(1000, checkDistance);
    pulse.setCallback(pulseCallback);
    }

void loop() {
    com.run();
}

// Event driven 방식