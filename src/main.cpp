#include <Arduino.h>
// #include <WEMOS_Motor.h>
// #include "TankBase.h"
// #include "StateHandeler.h"
#include "BaseCommand.h"
#include "NoNoOne.h"

//My motors:
// Motor Lmotor(0x30, _MOTOR_A, 1000);
// Motor Rmotor(0x30, _MOTOR_B, 1000);

// TankBase myBase(Lmotor,_CW,Rmotor,_CCW);

// const char* states[] = {"STOP", "GO", "BLINK"};

// StateHandeler myHandeler(states, 3);

// uint8_t prevState = 0;

BaseCommand base = BaseCommand();

NoNoOne command = NoNoOne(1);
NoNoOne command2 = NoNoOne(2);

void setup() {

  Serial.begin(9600);
  base.spinup(&command);
  base.spinup(&command2);
  delay(1000);
  base.update();
  delay(1000);
  base.preUpdate();
  delay(1000);
  base.stop();
}

void loop() {  

}

