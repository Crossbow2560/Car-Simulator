#ifndef PADDLESHIFTER_H
#define PADDLESHIFTER_H

#include <Arduino.h>

class PaddleShifter{
    private:
        int upShiftPin;
        int downShiftPin;
        int upShiftVal;
        int downShiftVal;
        int returnVal;

    public:
        PaddleShifter(int upshiftPin, int downshiftPin){
            upShiftPin = upshiftPin;
            downShiftPin = downshiftPin;
            pinMode(upShiftPin, INPUT_PULLUP);
            pinMode(downShiftPin, INPUT_PULLUP);
        }

        int isShifted(){
            upShiftVal = digitalRead(upShiftPin);
            downShiftVal = digitalRead(downShiftPin);
            if (upShiftVal == LOW){
                returnVal = 1;
            }
            if(downShiftVal == LOW){
                returnVal = -1;
            }
            if(downShiftVal == HIGH && upShiftVal == HIGH){
                returnVal = 0;
            }
            return returnVal;
        }
};

#endif