#include "Sensors.h"

long elegoo::getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  long cm = (duration/2) / 29.1;
  return cm;
}

int elegoo::getLightR(){
  int r = !digitalRead(10);
  return r;
}

int elegoo::getLightM(){
  int m = !digitalRead(4);
  return m;
}

int elegoo::getLightL(){
  int l = !digitalRead(2);
  return l;
}

void elegoo::line(){
  if(elegoo::getLightM() == 0){
    forward();
  }
  else if(elegoo::getLightR() == 0) {
    right();
    while(elegoo::getLightR() == 0);
  }
  else if(elegoo::getLightL() == 0) {
    left();
    while(elegoo::getLightL() == 0);
  }
}