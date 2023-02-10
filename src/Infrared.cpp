#include "Infrared.h"
#include <IRremote.hpp>


unsigned long elegoo::getIR(){
  if (IrReceiver.decode()) {
    unsigned long int val = IrReceiver.decodedIRData.decodedRawData;
    IrReceiver.resume();
    return val;
  }
  else {
    return 0;
  }
}

void elegoo::IRbegin(){
  IrReceiver.begin(RECV_PIN, LED);
}

char elegoo::getIRdec(){
  switch(getIR()){
    case FORWARD: return 1;   break;
    case BACK:    return 2;   break;
    case LEFT:    return 3;   break;
    case RIGHT:   return 4;   break;
    case STOP:    return 5;   break;
    case KEY1:    return 6;   break;
    case KEY2:    return 7;   break;
    default:                  break;
  }
}

void elegoo::IRremote(){
  int preMillis;
  switch(getIRdec()){
    case 1: 
      forward();
      preMillis = millis();  
      break;
    case 2:    
      back();
      preMillis = millis();     
      break;
    case 3:    
      left();
      preMillis = millis();     
      break;
    case 4:   
      right(); 
      preMillis = millis();   
      break;
    case 5:    
      stop();
      preMillis = millis();     
      break;
    default:                  
      break;
  }
  if(millis() - preMillis > 500){
    stop();
    preMillis = millis();
  }
}

void elegoo::IRremoteT(int time){
  for(int i = time; i > 0; i--){
    remote();
    delay(1);
  }
}