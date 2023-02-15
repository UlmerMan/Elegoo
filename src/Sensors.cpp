#include "Sensors.h"

bool keepDistanceState = 1;
bool IRremoteState = 0;
bool BTremoteState = 0;
int  max = 180;

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

long elegoo::getDistance(int angle) {
  if(angle > max){
    angle = 180;
  }
  libServo->write(angle);
  return getDistance();
}

long elegoo::getDistanceReturn(int angle){
  int current = libServo->read();
  long val = getDistance(angle);
  libServo->write(current);
  return val;
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

void elegoo::delay(unsigned long time){
  for(unsigned long i = 0; i < time; i++) {
    if(IRremoteState){
      IRremote();
    }
    if(BTremoteState){
      BTremote();
    }
    keepDistance();
    delay(1);
  }
}

void elegoo::keepDistance(){
  if(keepDistanceState){
    int distance = getDistance();
    if(distance < keepDistanceValue){
      stop();
    }
  }
}

void elegoo::enableKeepDistance(){
  keepDistanceState = 1;
}

void elegoo::disableKeepDistance(){
  keepDistanceState = 0;
}

void elegoo::setKeepDistance(int val){
  keepDistanceValue = val;
}

void elegoo::enableIRremote(){
  IRremoteState = 1;
}

void elegoo::disableIRremote(){
  IRremoteState = 0;
}

void elegoo::enableBTremote(){
  BTremoteState = 1;
}

void elegoo::disableBTremote(){
  BTremoteState = 0;
}