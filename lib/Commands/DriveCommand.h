#pragma once
#include "TankBase.h"
#include "Icommand.h"

class DriveCommand: public Icommand{
    private:
        float powerLeft, powerRight, time;
        TankBase& base;

        int startTime;

    public:
        DriveCommand(float powerLeft, float powerRight, float time, TankBase& base): 
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