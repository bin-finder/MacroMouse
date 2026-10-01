#include <Arduino.h>
#include <WEMOS_Motor.h>
#include "TankBase.h"
#include "StateHandeler.h"

//My motors:
Motor Lmotor(0x30, _MOTOR_A, 1000);
Motor Rmotor(0x30, _MOTOR_B, 1000);

TankBase myBase(Lmotor,_CW,Rmotor,_CCW);

const char* states[] = {"STOP", "GO", "BLINK"};

StateHandeler myHandeler(states, 3);

uint8_t prevState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {  
  //Drive Streight:
  // myBase.onForTime(100,100,2);
  // delay(1000);
  // //Turn:
  // myBase.onForTime(50, -50, 2);
  // delay(1000);

  myHandeler.updateSerial();
  if(myHandeler.curState != prevState){
    Serial.println(myHandeler.curState);
    prevState = myHandeler.curState;
  }
}

