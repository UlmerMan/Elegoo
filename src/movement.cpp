#include "movement.h"

/*define forward function*/
void elegoo::forward(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
/*define back function*/
void elegoo::back(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
/*define left function*/
void elegoo::left(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
/*define right function*/
void elegoo::right(int speed){
  analogWrite(ENA,HIGH);
  analogWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void elegoo::forward(){
  forward(defaultSpeed);
}

void elegoo::back(){
  forward(defaultSpeed);
}

void elegoo::left(){
  forward(defaultSpeed);
}

void elegoo::right(){
  forward(defaultSpeed);
}

void elegoo::stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
}

void elegoo::forwardT(int speed, float time){
  forward(speed);
  delay(time);
  stop();
}

void elegoo::backT(int speed, float time){
  back(speed);
  delay(time);
  stop();
}

void elegoo::leftT(int speed, float time){
  left(speed);
  delay(time);
  stop();
}

void elegoo::rightT(int speed, float time){
  right(speed);
  delay(time);
  stop();
}


float elegoo::regler(float ist, float soll, int p_faktor){
  float abweichung = soll - ist;
  float ergebnis  = (abweichung * p_faktor);
  return ergebnis;
}