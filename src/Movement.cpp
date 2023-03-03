#include "Movement.h"

// TODO logging of movement

controler libPID(0.3, 0.2, 0.0005);

/*define forward function*/
void elegoo::forward(int speed)
{
  if (version == 1)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  if (version == 2)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  if (version == 3)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}
/*define back function*/
void elegoo::back(int speed)
{
  if (version == 1)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  if (version == 2)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  if (version == 3)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}
/*define left function*/
void elegoo::left(int speed)
{
  if (version == 1)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  if (version == 2)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  if (version == 3)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}
/*define right function*/
void elegoo::right(int speed)
{
  if (version == 1)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  if (version == 2)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  if (version == 3)
  {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}

void elegoo::forward()
{
  forward(defaultSpeed);
}

void elegoo::back()
{
  forward(defaultSpeed);
}

void elegoo::left()
{
  forward(defaultSpeed);
}

void elegoo::right()
{
  forward(defaultSpeed);
}

void elegoo::stop()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void elegoo::forwardT(int speed, float time)
{
  forward(speed);
  delay(time);
  stop();
}

void elegoo::backT(int speed, float time)
{
  back(speed);
  delay(time);
  stop();
}

void elegoo::leftT(int speed, float time)
{
  left(speed);
  delay(time);
  stop();
}

void elegoo::rightT(int speed, float time)
{
  right(speed);
  delay(time);
  stop();
}

// TODO PID

bool elegoo::forwardDistance(int distance, int speed)
{
  int startDistance = elegoo::getDistanceS(90);

  if (startDistance > (distance + keepDistanceValue))
  {
    return 0;
  }

  int should = startDistance - distance;
  forward(speed);

  while (elegoo::getDistanceS(90) > should)
  {
    elegoo::delay(1);
  }
  stop();
}

void elegoo::backDistance(int distance, int speed)
{
  int startDistance = elegoo::getDistanceS(90);
  int should = startDistance + distance;

  back(speed);

  while (elegoo::getDistanceS(90) < should)
    ;
  stop();
}

bool elegoo::forwardDistance(int distance)
{
  bool val = elegoo::forwardDistance(distance, 255);
  return val;
}

void elegoo::backDistance(int distance)
{
  elegoo::backDistance(distance, 255);
}