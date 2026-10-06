#pragma once
#include "Icommand.h"

/**
 * @brief This command runs two commands side by side untill one of them ends, then it ends the other.
 */

class CmdAsync: public Icommand{

    Icommand** commands;
    unsigned int numCommands;

    public:

        /**
         * @param commands An array of pointers to commands.
         * @param numCommands The number of commands in the array.
         */

        CmdAsync(Icommand** commands, unsigned int numCommands) : commands(commands), numCommands(numCommands){}

        void startup() override{
            for(unsigned int i = 0; i < numCommands; i++){
                commands[i]->preStartup();
            }
        }

        void update() override{
            for(unsigned int i = 0; i < numCommands; i++){
                commands[i]->preUpdate();
                if(commands[i]->getState() == STOPED) stop();
            }
        }

        void postStop() override{
            for(unsigned int i =0; i < numCommands; i++){
                commands[i]->stop();
            }
        }
};
