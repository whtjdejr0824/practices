// 우측
int IN1 =8;
int IN2 =7;
int EN1 =9;  // PWM 제어

// 우측
int IN3 =5;
int IN4 =4;
int EN2 =3;// PWM 제어

void setup()
{
    // 우측
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(EN1, OUTPUT);
    // 좌측
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(EN2, OUTPUT);

}

void loop()
{
    // 전진
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(EN1, 200);
    delay(1000);

    // 정지
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    delay(2000);

    // 전진
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(EN2, 200);
    delay(1000);

    // 정지
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(2000);


}

