int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
    randomSeed(analogRead(A0));
    analogWrite(redPin, 255);
    delay(1000);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    delay(1000);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    delay(1000);
}

void loop() {
    analogWrite(redPin, 256);
    analogWrite(greenPin, 256);
    analogWrite(bluePin, 256);
    delay(1000);
}