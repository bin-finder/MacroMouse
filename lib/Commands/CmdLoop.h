#pragma once
#include "Icommand.h"

class CmdLoop: public Icommand{
    
    Icommand* command;
    
    public:
        CmdLoop(Icommand* command) : command(command){}
        
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