#include <WEMOS_Motor.h>
#include "TankBase.h"

//My motors:
Motor Lmotor(0x30, _MOTOR_B, 1000);
Motor Rmotor(0x30, _MOTOR_A, 1000);

TankBase myBase(Lmotor,_CCW,Rmotor,_CW);

void setup() {
  // put your setup code here, to run once:
}

void loop() {  
  //Drive Streight:
  myBase.onForTime(100,100,2);
  delay(1000);
  //Turn:
  myBase.onForTime(50, -50, 2);
  delay(1000);
}