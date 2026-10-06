#pragma once
#include "Icommand.h"

class LoopCommand: public Icommand{
    
    Icommand* command;
    
    public:
        LoopCommand(Icommand* command) : command(command){}
        
        void startup() override{
            spinup(command);
        }

        void update() override{
            if(command->getState() == STOPED) spinup(command);
        }
};