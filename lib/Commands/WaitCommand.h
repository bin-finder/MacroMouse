#pragma once
#include "Icommand.h"

class WaitCommand: public Icommand{

    double time;
    int startTime;

    public:
        WaitCommand(double time): time(time){}

        void startup() override{
            startTime = millis();
        }

        void update() override{
            if(millis() - startTime > time) stop();
        }
};