#include <Arduino.h>
#include "BaseCommand.h"
#include "NoNoOne.h"
#include "ArrayCommand.h"
#include "LazyArray.h"
#include "Synchronous.h"
#include "DriveCommand.h"
#include "TankBase.h"
#include "WaitCommand.h"
#include "LoopCommand.h"


//My motors:
Motor Lmotor(0x30, _MOTOR_A, 1000);
Motor Rmotor(0x30, _MOTOR_B, 1000);

TankBase myBase(Lmotor,_CW,Rmotor,_CCW);

// const char* states[] = {"STOP", "GO", "BLINK"};
// StateHandeler myHandeler(states, 3);
// uint8_t prevState = 0;

BaseCommand base = BaseCommand();

DriveCommand streight(100.0,100.0,1,myBase);

DriveCommand turn(-100,100,1,myBase);

WaitCommand wait(1);

Icommand* drivePath[] = {&streight, &wait, &turn, &wait};
ArrayCommand drivePathcmd(drivePath,4);

LoopCommand driveLoop(&drivePathcmd);

// NoNoOne cmd1(4);
// NoNoOne cmd2(3);
// NoNoOne cmd3(2);
// Icommand* commandArr1[] = {&cmd1, &cmd2, &cmd3};
// ArrayCommand arr(commandArr1,3);

void setup() {
  Serial.begin(9600); 
  base.spinup(&driveLoop);
}

void loop() {  
  base.preUpdate();
}