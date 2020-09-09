#include "Car.hpp" // 검색순서: cwd(& include 검색) -> 사용자 lib -> 컴파일러 lib
#include <iostream> // 검색순서: 사용자 lib -> 컴파일러 lib

// 클래스 정의 파일
void setSpeed(int s) { // :: scope 연산자
    speed : s;
}

int Car::getSpeed() {
    return speed;
}