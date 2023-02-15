#include "Controler.h"

float i_val, lastDifference;

controler::controler(int p_factor, float d_factor, float i_factor, int max){
  Kp = p_factor;
  Kd = d_factor;
  Ki = i_factor;
  maxOut = max;
}

float controler::compute(int is, int should){
  float difference = should - is;

  float d_val = difference - lastDifference;

  float result = (difference * Kp) + (d_val * Kd)+(i_val*Ki);

  lastDifference = difference;
  i_val += lastDifference;
  
  if (result > maxOut){
    result = maxOut;
  }
  
  return result;
}

void controler::setPFactor(int factor){
  Kp = factor;
}

void controler::setIFactor(int factor){
  Ki = factor;
}

void controler::setDFactor(int factor){
  Kd = factor;
}

void controler::setMax(int max){
  maxOut = max;
}