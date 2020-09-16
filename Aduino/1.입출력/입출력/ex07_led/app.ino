#include <TrafficLight.h>

Trafficlight lights(3,5,7);

void setup() {
   
}

// 2초간 직진 신호
// 1초간 직진, 좌회전 동시 긴호
// 2초간 정지 신호
void loop() {
 lights.run();
}