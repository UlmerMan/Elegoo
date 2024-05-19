#include "Elegoo.h"
#include <Servo.h>

// www.elegoo.com
// 2016.09.12

//    The direction of the car's movement
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//  HIGH  HIGH  LOW   LOW   LOW   LOW   Car is stoped
//  HIGH  HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
//  LOW   LOW   N/A   N/A   N/A   N/A   Car is stoped

//    Left motor truth table
//  ENA         IN1               IN2         Description
//  LOW   Not Applicable    Not Applicable    Motor is off
//  HIGH        LOW               LOW         Motor is stopped (brakes)
//  HIGH        HIGH              LOW         Motor is on and turning forwards
//  HIGH        LOW               HIGH        Motor is on and turning backwards
//  HIGH        HIGH              HIGH        Motor is stopped (brakes)

//    Right motor truth table
//  ENB         IN3             IN4         Description
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes)
//  HIGH        LOW             HIGH        Motor is on and turning forwards
//  HIGH        HIGH            LOW         Motor is on and turning backwards
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)

//    The direction of the car's movement
//  Left motor    Right motor     Description
//  stop(off)     stop(off)       Car is stopped
//  forward       forward         Car is running forwards
//  forward       backward        Car is turning right
//  backward      forward         Car is turning left
//  backward      backward        elegoo is running backwards

// Constructor

elegoo::elegoo(String version)
{
  if (version == "v1")
  {
    vers = 1;
    in1 = 9;
    in2 = 8;
    in3 = 7;
    in4 = 6;
    ENA = 10;
    ENB = 5;
    Setup();
  }
  if (version == "v2")
  {
    vers = 2;
    in1 = 6;
    in2 = 7;
    in3 = 8;
    in4 = 9;
    ENA = 5;
    ENB = 11;
    Setup();
  }
  if (version == "v3")
  {
    vers = 3;
    in1 = 7;
    in2 = 8;
    in3 = 9;
    in4 = 11;
    ENA = 5;
    ENB = 6;
    Setup();
  }
  if (version == "v4")
  {
    PWMA = 5;
    PWMB = 6;
    AIN1 = 8;
    BIN1 = 7;
    Setup();
  }
  if (version == "v4.1")
  {
    PWMA = 5;
    PWMB = 6;
    AIN1 = 7;
    BIN1 = 8;
    Setup();
  }
  if (version == "v4.2")
  {
    PWMA = 5;
    PWMB = 6;
    AIN1 = 7;
    BIN1 = 8;
    Setup();
  }
}

void elegoo::Setup()
{
  if (vers <= 3)
  {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(LineTeacking_Pin_Right, INPUT);
    pinMode(LineTeacking_Pin_Middle, INPUT);
    pinMode(LineTeacking_Pin_Left, INPUT);
    Servo libServo;
    libServo.attach(3);
    IRbegin();
    // reset servo to front
    libServo.write(90);
  }
  if (vers >= 4)
  {
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(PIN_Voltage, INPUT);
    pinMode(PIN_LTL, INPUT);
    pinMode(PIN_LTM, INPUT);
    pinMode(PIN_LTR, INPUT);
  }
}
