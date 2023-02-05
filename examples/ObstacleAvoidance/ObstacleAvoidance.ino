//www.elegoo.com

#include <car.h>
#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

int Echo = A4;
int Trig = A5;


int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void setup() {
  myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);
  car.stop();
}

void loop() {
    myservo.write(90);  //setservo position according to scaled value
    delay(500);
    middleDistance = car.getDistance();

    if(middleDistance <= 20) {
      car.stop();
      delay(500);
      myservo.write(10);
      delay(1000);
      rightDistance = car.getDistance();

      delay(500);
      myservo.write(90);
      delay(1000);
      myservo.write(180);
      delay(1000);
      leftDistance = car.getDistance();

      delay(500);
      myservo.write(90);
      delay(1000);
      if(rightDistance > leftDistance) {
        car.right();
        delay(360);
      }
      else if(rightDistance < leftDistance) {
        car.left();
        delay(360);
      }
      else if((rightDistance <= 20) || (leftDistance <= 20)) {
        car.back();
        delay(180);
      }
      else {
        car.forward();
      }
    }
    else {
        car.forward();
    }
}