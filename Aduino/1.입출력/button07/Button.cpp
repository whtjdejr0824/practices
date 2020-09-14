#include "Button.h"

Button::Button(int pin) : pin(pin){
    pinMode(pin, INPUT_PULLUP);
    state_previous = true;
}

int Button::read() {
    return !digitalRead(pin); // 풀업이 반전
}