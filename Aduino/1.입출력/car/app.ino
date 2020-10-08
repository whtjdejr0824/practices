#include "car.h"
// #include "motor.h"


// Motor right(8, 7, 9);
// Motor left(5, 4, 3);
Car car(8, 7, 9, 5, 4, 3);

void setup() {

}

void loop() {

    // 전진
    car.forward();
    delay(500);

    // 정지
    car.stop();
    delay(2000);

    // 후진
    car.backward();
    delay(500);
    
    // 정지
    car.stop();
    delay(2000);

    // 좌회전
    car.turnleft();
    delay(500);

    // 정지
    car.stop();
    delay(2000);

    // 우회전
    car.turnright();
    delay(500);

    // 정지
    car.stop();
    delay(2000);

}

