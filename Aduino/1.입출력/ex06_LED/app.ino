int pin_LED1 = 3;
int pin_LED2 = 5;
int pin_LED3 = 7;

void setup() {
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  pinMode(pin_LED3, OUTPUT);
}

void loop() {
  digitalWrite(pin_LED1, HIGH);
  delay(200);

  digitalWrite(pin_LED1, LOW);
  digitalWrite(pin_LED2, HIGH);
  delay(100);

  digitalWrite(pin_LED2, LOW);
  digitalWrite(pin_LED3, HIGH);
  delay(200);

  digitalWrite(pin_LED3, LOW);
}