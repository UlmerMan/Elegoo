#ifndef elegoo_H
#define elegoo_H
#include <Arduino.h>
#include <Servo.h>


//--------Ultrasonic Sensor---------//
#define echo A4
#define trig A5

#define defaultVersion 3
#define defaultSpeed 255

//-------Line Tracking Pins--------//
#define LineTeacking_Pin_Right  10
#define LineTeacking_Pin_Middle 4
#define LineTeacking_Pin_Left   2

//---------- IR REMOTE -------------//
#define RECV_PIN  12        //Infrared signal receiving pin
#define LED       13        //define LED pin
#define L         16738455
#define UNKNOWN_L 1386468383

//------- IR REMOTE CODES ---------//
#define FORWARD   16736925
#define BACK      16754775
#define LEFT      16720605
#define RIGHT     16761405
#define STOP      16712445
#define KEY1      16738455 //Line Teacking mode
#define KEY2      16750695 //Obstacles Avoidance mode
#define KEY3      16756815
#define KEY4      16724175
#define KEY5      16718055
#define KEY6      16743045
#define KEY7      16716015
#define KEY8      16726215
#define KEY9      16734885
#define KEY0      16730805
#define KEY_STAR  16728765
#define KEY_HASH  16732845


class elegoo
{
  public:
    elegoo(int version);  //Constructor
    /**
    This is the functiom to Initialze the Library.
    Write the Version Number of your Robot into the brackets.
    */
    void  forward(int speed);
    void  back(int speed);
    void  left(int speed);
    void  right(int speed);
    void  forward();
    void  back();
    void  left();
    void  right();
    void  stop();
    long  getDistance();
    long  getDistance(int angle);
    long  getDistanceReturn(int angle);
    void  forwardT(int speed, float time);
    void  backT(int speed, float time);
    void  leftT(int speed, float time);
    void  rightT(int speed, float time);
    unsigned long getIR();
    char  getIRdec();
    void  remoteIR();
    void  remoteIRT(int time);
    int   getLightR();
    int   getLightM();
    int   getLightL();
    void  line();
    unsigned long getBT();
    char getBTdec();
    void delay(unsigned long time);
    void remote();
    float regler(float ist, float soll, int p_faktor, float d_faktor, float i_faktor);
    void IRbegin();
    void keepDistance();
    void enableKeepDistance();
    void disableKeepDistance();
    void setKeepDistance(int val);
  private:
    Servo *libServo;
    int in1 = 0;
    int in2 = 0;
    int in3 = 0;
    int in4 = 0;
    int ENA = 0;
    int ENB = 0;
};

//#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_CAR)
//extern elegoo car;
//#endif

#endif
