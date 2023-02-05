#include <car.h>

void setup(){
  Serial.begin(9600); //Begin a serial connection
  car.init();         //Initialze car. Please put the Version of your robot into the brackets
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
