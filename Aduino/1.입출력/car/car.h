#pragma once

#include <Arduino.h>
#include "motor.h"

class Car {
protected:
    Motor right;
    Motor left;

public:
    Car(int in1, int in2, int en1, int in3, int in4, int en2);

    void forward(int speed=200);
    void backward(int speed=200);
    void turnleft(int speed=200);  //r: forward, l: backward
    void turnright(int speed=200); //r: backward, l: forward
    void setSpeed(int rightSpeed, int leftSpeed);
    void stop();
};