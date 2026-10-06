#include <Arduino.h>
#include "CmdBase.h"
#include "CmdDebug.h"
#include "CmdArray.h"
#include "LazyArray.h"
#include "CmdAsync.h"
#include "CmdDrive.h"
#include "TankBase.h"
#include "CmdWait.h"
#include "CmdLoop.h"
#include "LED.h"
#include "CmdBlinkLED.h"


//My motors:
Motor Lmotor(0x30, _MOTOR_A, 1000);
Motor Rmotor(0x30, _MOTOR_B, 1000);

TankBase myBase(Lmotor,_CW,Rmotor,_CCW);

//My LED:
LED myLED(LED_BUILTIN);

CmdBinkLED blinky(myLED,1);

// const char* states[] = {"STOP", "GO", "BLINK"};
// StateHandeler myHandeler(states, 3);
// uint8_t prevState = 0;

CmdBase base = CmdBase();

CmdDrive streight(100.0,100.0,1,myBase);

CmdDrive turn(-100,100,1,myBase);

CmdWait wait(1);

CmdWait initialWait(7);

Icommand* drivePath[] = {&streight, &wait, &turn, &wait};
CmdArray drivePathcmd(drivePath,4);
CmdLoop driveLoop(&drivePathcmd);

Icommand* mainLoop[] = {&initialWait,&driveLoop};
CmdArray mainLoopCmd(mainLoop,2);

Icommand* blinkLoop[] = {&blinky,&mainLoopCmd};
CmdAsync masterLoop(blinkLoop,2);

// NoNoOne cmd1(4);
// LoopCommand myLoop(&cmd1);
// NoNoOne cmd2(3);
// NoNoOne cmd3(2);
// Icommand* commandArr1[] = {&cmd1, &cmd2, &cmd3};
// ArrayCommand SyncArr(commandArr1,3);
// LoopCommand myLoop(&SyncArr);

void setup() {
  Serial.begin(9600); 
  base.spinup(&masterLoop);
}

void loop() {  
  base.preUpdate();
}