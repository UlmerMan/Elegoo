#include <elegoo.h>

#define version 3

elegoo car(version);

void setup(){
  Serial.begin(9600); //Begin a serial connection
}



void loop(){
  car.forward();  //go forward
  delay(1000);    //delay 1000 ms
  car.backward(); //go back
  delay(1000);    //delay 1000 ms
  car.left();     //turning left
  delay(1000);    //delay 1000 ms
  car.right();    //turning right
  delay(1000);    //delay 1000 ms
}
