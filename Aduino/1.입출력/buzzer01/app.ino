// int buzzerPin = 5;
int speakerPin = 5;

void setup() {
    // pinMode(buzzerPin, OUTPUT);
}
void loop() {
    // digitalWrite(buzzerPin, HIGH);
    // delay(50);
    // digitalWrite(buzzerPin, LOW);
    // delay(50);
    tone(speakerPin, 5000, 1000);
    delay(2000);
}