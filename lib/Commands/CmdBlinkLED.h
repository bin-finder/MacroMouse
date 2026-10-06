#pragma once
#include "Icommand.h"
#include "LED.h"
#include "math.h"

class CmdBinkLED: public Icommand{

    double value;
    int xMul;
    LED& myLED;
    double flashFreq;
    unsigned long cycleStartTime;

    public:
        CmdBinkLED(LED& myLED, int flashFreq): myLED(myLED), flashFreq(flashFreq){}

        void startup() override{
            value = 0;
            xMul = 1;
            cycleStartTime = millis();
        }

        void update() override{
            value = xMul*510.0*(millis() - cycleStartTime)/1000.0*flashFreq-xMul*255.0/2.0+255.0/2.0;
            if(value > 255){
                xMul = -1;
                value = 255;
                cycleStartTime = millis();
            }
            else if(value < 0){
                xMul = 1;
                value = 0;
                cycleStartTime = millis();
            }
            myLED.setState(value);
        }

        void postStop() override{
            myLED.setState(0);
        }
};