#pragma once
// #ifndef __car_H__ //if not defined
// #define __car_H__ 


#include <string>
using namespace std;

// 클래스원형
class Car {
// 디폴트 접근 제한자: private    
    int speed;
    int gear;
    string color;

public:
    int getSpeed();  //함수원형
    void setSpeed();
};