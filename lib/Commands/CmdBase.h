#pragma once
#include "Icommand.h"

class CmdBase : public Icommand{
    private:
        Icommand* command;
    public:
        CmdBase(Icommand* command): command(command){}

        void update() override{
            command->update();
        }

        void postStop() override{
            command->stop();
        }

        void startup() override{
            command->preStartup();
        }
};