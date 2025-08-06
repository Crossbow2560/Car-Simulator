#ifndef BRAKE_H
#define BRAKE_H

#include <Arduino.h>

class Brake{
  private:
    int pin;
    int minVal;
    float val;
    int maxVal;
    float range;

  public:
    Brake(int pinVal, int min_Val = 0, int max_Val = 1023){
      pin = pinVal;
      minVal = min_Val;
      maxVal = max_Val;
      range = (float)(maxVal - minVal);

      pinMode(pin, INPUT);
    }

    int getVal(){
      val = analogRead(pin);
      if (val >= maxVal){
        val = maxVal;
      }
      else if (val <= minVal){
          val = minVal;
      }

      val = (val - minVal)/range;
      val = val * 255;
      val = 255-val;
      return (int)val;
    }
};

#endif