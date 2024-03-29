#include <Servo.h>
#include <Joystick.h>
#include <MiniCom.h>

const int SERVO_PIN = 9;
Servo servo;
JoyStick joy(A0, A1, 3);
bool mode = true; // true : 주행모드, false : 카메라 방향 모드
MiniCom com;


// joystick 값 읽고 출력하기.
void readJoystick() {
    joystick_value_t value = joy.read();
    
    if(mode) { // 주행 모드
        com.print(0,"X:/Y:", value.x, value.y);
    } else {  // 카메라 방향 모드
        servo.write(value.x); //카메라 방향 조정
        com.print(1, "Angle:", value.x, value.y);
        
    }
}

// joystick 운영 모드 변경.
void changeMode() {
    mode = !mode;
    if(mode) { // 주행 모드
        joy.setRangeX(-255, 255);
    } else { //서보모터 방향모드
        joy.setRangeY(0, 179);
    }
}

void setup() {
    com.init();
    servo.attach(SERVO_PIN);
    //DC 모터 : 속도 조절은 PWM: 0~255, 전진, 후진:
    joy.setRangeX(-255, 255); 
    joy.setRangeY(-255, 255); 
    joy.setCallback(changeMode);
    
    com.setInterval(50, readJoystick);
}

void loop() {
    com.run();
    joy.check();
}