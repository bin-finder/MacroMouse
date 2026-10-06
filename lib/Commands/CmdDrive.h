#pragma once
#include "HwTankBase.h"
#include "Icommand.h"

class CmdDrive: public Icommand{
    private:
        float powerLeft, powerRight, time;
        HwTankBase& base;

        int startTime;

    public:
        CmdDrive(float powerLeft, float powerRight, float time, HwTankBase& base): 
            powerLeft(powerLeft), 
            powerRight(powerRight), 
            time(time),
            base(base)
        {}

        void startup() override{
            startTime = millis();
            base.onPercent(powerLeft, powerRight);
        }

        void update() override{
            if(millis()-startTime >= time*1000) stop();
        }

        void postStop() override{
            base.stop();
        }
};