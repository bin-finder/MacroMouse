#pragma once
#include "Icommand.h"

class LoopCommand: public Icommand{
    
    Icommand* command;
    
    public:
        LoopCommand(Icommand* command) : command(command){}
        
        void startup() override{
            command->preStartup();
        }

        void update() override{
            if(command->getState() == STOPED) command->preStartup();
            command->preUpdate();
        }

        void postStop() override{
            command->stop();
        }
};