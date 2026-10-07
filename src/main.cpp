#include <Arduino.h>
#include "CmdArray.h"
#include "CmdAsync.h"
#include "CmdBase.h"
#include "CmdBlinkLED.h"
#include "CmdDebug.h"
#include "CmdDrive.h"
#include "CmdLoop.h"
#include "CmdWait.h"
#include "HwLED.h"
#include "HwTankBase.h"

//My motors
Motor Lmotor(0x30, _MOTOR_A, 1000);
Motor Rmotor(0x30, _MOTOR_B, 1000);
HwTankBase myBase(Lmotor,_CW,Rmotor,_CCW);

//My LEDs
HwLED myLED(LED_BUILTIN);
CmdBinkLED blinky(myLED,1);

//driveing commands
CmdDrive streight(100.0,100.0,1,myBase);
CmdDrive turn(-100,100,0.25,myBase);
CmdWait driveWait(1);
CmdWait turnWait(1);
CmdWait initialWait(7);

//Set up drive loop
Icommand* drivePath[] = {&streight, &driveWait, &turn, &turnWait};
CmdArray drivePathcmd(drivePath,4);
CmdLoop driveLoop(&drivePathcmd);

//Add initial delay
Icommand* mainLoop[] = {&initialWait,&driveLoop};
CmdArray mainLoopCmd(mainLoop,2);

//Make the LED blink all the time
Icommand* blinkLoop[] = {&blinky,&mainLoopCmd};
CmdAsync masterLoop(blinkLoop,2);

CmdBase base = CmdBase(&masterLoop);

void setup() {
  Serial.begin(9600);
  base.startup(); 
}

void loop() {  
  base.update();
}