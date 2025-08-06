#ifndef EBRAKE_H
#define EBRAKE_H

#include <Arduino.h>

class EBrake{
  private:
    int pin;
    int val;

  public:
    EBrake(int pin_no){
        pin = pin_no;
        pinMode(pin, INPUT_PULLUP);
    }

    bool isActive(){
      val = digitalRead(pin);
      if (val == LOW){
        return true;
        }
      else{
        return false;
      }
    }
};
#endif