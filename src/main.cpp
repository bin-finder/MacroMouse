#include <Arduino.h>
// #include <WEMOS_Motor.h>
// #include "TankBase.h"
// #include "StateHandeler.h"
#include "BaseCommand.h"
#include "NoNoOne.h"
#include "arrayCommand.h"
#include "LazyArray.h"
#include "synchronous.h"

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
NoNoOne command3 = NoNoOne(3);

Icommand* commandArr1[] = {&command,&command2};
LazyArray<Icommand*> arrayCommand2(commandArr1,2);
arrayCommand arr(arrayCommand2);

synchronous sync(arr,command3);

void setup() {

  Serial.begin(9600);
  base.spinup(&arr);
}

void loop() {  
  base.update();
  delay(1000);
}

