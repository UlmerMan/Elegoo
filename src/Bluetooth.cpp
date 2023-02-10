#include "Bluetooth.h"

unsigned long elegoo::getBT(){
  if(Serial.available()){
    unsigned long val = Serial.read();
    return val;
  }
}

char elegoo::getBTdec(){
  int dec;
  switch(getBT()){
    case FORWARD: dec = 'f'; return dec;   break;
    case BACK:    dec = 'b'; return dec;   break;
    case LEFT:    dec = 'l'; return dec;   break;
    case RIGHT:   dec = 'r'; return dec;   break;
    case STOP:    dec = 's'; return dec;   break;
    case KEY0:    dec = '0'; return dec;   break;
    case KEY1:    dec = '1'; return dec;   break;
    case KEY2:    dec = '2'; return dec;   break;
    case KEY3:    dec = '3'; return dec;   break;
    case KEY4:    dec = '4'; return dec;   break;
    case KEY5:    dec = '5'; return dec;   break;
    case KEY6:    dec = '6'; return dec;   break;
    case KEY7:    dec = '7'; return dec;   break;
    case KEY8:    dec = '8'; return dec;   break;
    case KEY9:    dec = '9'; return dec;   break;
    default:                    break;
  }
}

void elegoo::BTremote(){
  int dec;
  switch(getBT()){
    case FORWARD: dec = 'f'; forward();    break;
    case BACK:    dec = 'b'; back();       break;
    case LEFT:    dec = 'l'; left();       break;
    case RIGHT:   dec = 'r'; right();      break;
    case STOP:    dec = 's'; stop();       break;
    default:                    break;
  }
}