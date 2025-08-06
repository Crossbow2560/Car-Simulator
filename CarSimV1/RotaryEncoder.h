#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H

#include <Arduino.h>
#include <TimerOne.h>

class RotaryEncoder {
  private:
    int pinA;
    int pinB;
    volatile long position;
    volatile int lastStateA;
    volatile int lastStateB;
    
  public:
    RotaryEncoder(int pinA_val, int pinB_val) {
      pinA = pinA_val;
      pinB = pinB_val;
      position = 0;
      
      pinMode(pinA, INPUT_PULLUP);
      pinMode(pinB, INPUT_PULLUP);
      
      lastStateA = digitalRead(pinA);
      lastStateB = digitalRead(pinB);
    }
    
    void readEncoder() {
      int currentStateA = digitalRead(pinA);
      int currentStateB = digitalRead(pinB);
      
      if (currentStateA != lastStateA) {
        if (currentStateB != currentStateA) {
          position++;
        } else {
          position--;
        }
      }
      
      lastStateA = currentStateA;
      lastStateB = currentStateB;
    }
    
    long getPosition() {
      return position;
    }
    
    void resetPosition() {
      position = 0;
    }
};

#endif