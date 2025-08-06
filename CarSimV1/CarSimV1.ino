#include "Accelerator.h"
#include "Brake.h"
#include "Clutch.h"
#include "EBrake.h"
#include "RotaryEncoder.h"
#include "PaddleShifter.h"
#include <TimerOne.h>

Accelerator accel(A0, 400, 1000);
Brake brake(A1, 650, 940);
Clutch clutch(11);
EBrake ebrake(13);
RotaryEncoder encoder(2, 3);
PaddleShifter shifter(9, 10);


char sendString[50];

int accelVal;
int brakeVal;
int shifterVal;
bool clutchVal;
bool ebrakeVal;
long encoderPos;

void timerISR(){
  encoder.readEncoder();
}

void setup() {
  Serial.begin(115200);

  encoder.resetPosition();
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerISR);
}

void loop() {
  accelVal = constrain(accel.getVal(), 0, 255);
  brakeVal = constrain(brake.getVal(), 0, 255);
  clutchVal = constrain(clutch.isActive(), 0, 1);
  shifterVal = constrain(shifter.isShifted(), -1, 1);
  eBrakeVal = contrain(ebrake.isActive(), -1, 1);
  encoderPos = encoder.getPosition();

  sprintf(sendString, "%d,%d,%ld,%d,%d,%d", accelVal, brakeVal, encoderPos, clutchVal, shifterVal, ebrakeVal);
  Serial.println(sendString);

  delay(1);
}
