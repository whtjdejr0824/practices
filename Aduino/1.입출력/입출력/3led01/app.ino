const int redPin = 11; // Red
const int greenPin = 10;  // GREEN
const int bluePin = 9;  // BLUE

void setup() {
    randomSeed(analogRead(A0));
}

void loop() {
    analogWrite(redPin, random(256));
    analogWrite(greenPin, random(256));
    analogWrite(bluePin, random(256));
    delay(1000);
}