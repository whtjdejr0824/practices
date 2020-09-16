int pin_LED1 = 3;
int pin_LED2 = 5;

boolean LED_state1 = false;
unsigned long time_previous1, time_current1;
boolean LED_state2 = false;
unsigned long time_previous2, time_current2;

void setup() {
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);

    digitalWrite(pin_LED1, LOW);
    digitalWrite(pin_LED2, LOW);
}

void loop() {
    blink_1000();
    blink_500();
}

void blink_1000() {
    time_currnet1 = millis()
;
    if(time_current1 - time_previous1 >= 1000) {
        time_previous1 = time_current1;  //핵심
        LED_state1 = ! LED_state1;
        digitalWrite(pin_LED1, LED_state1);
    }
}

void blink_500() {
    time_current2 = millis();

    if(time_current2 - time_previous2 >= 500) {
        time_previous2 = time_current2;
        LED_state2 = ! LED_state2;
        digitalWrite(pin_LED2, LED_state2);
    }
}