#include <Elegoo.h>
#include <Servo.h>

elegoo car("v3");

void setup() {
  Serial.begin(9600);  // Begin a serial connection
}

void loop() {
  // go forward for 1 second
  car.forward();
  delay(1000);

  // go back for 1 second
  car.back();
  delay(1000);
}
