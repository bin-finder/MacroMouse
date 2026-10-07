#pragma once
#include "Icommand.h"

class CmdWait: public Icommand{

    double time;
    int startTime;

    public:
        CmdWait(double time): time(time){}

        void startup() override{
            startTime = millis();
        }

        void update() override{
            if(millis() - startTime > time*1000) stop();
        }

        void postStop(){}
};