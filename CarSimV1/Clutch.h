#ifndef CLUTCH_H
#define CLUTCH_H

#include <Arduino.h>

class Clutch{
  private:
    int pin;
    int val;

  public:
    Clutch(int pin_no){
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