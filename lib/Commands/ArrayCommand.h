#pragma once
#include "Icommand.h"
#include "LazyArray.h"

/**
 * @brief This command takes in a LazyArray of command pointers, and runs every one each in turn, and waits for it to end
 */

class ArrayCommand : public Icommand{
    private:
        Icommand** commands;
        unsigned int numCommands;
        unsigned int currentCommand = 0;
    public:

        /**
         * @param commands A LazyArray of commands to be run in sequence.
         */

        ArrayCommand(Icommand** commands, unsigned int numCommands): commands(commands), numCommands(numCommands){}

        void startup() override{
            commands[currentCommand]->preStartup();
        }

        void update() override{
            if(commands[currentCommand]->getState() == STOPED){
                if(currentCommand < numCommands - 1) {
                    currentCommand++;
                    commands[currentCommand]->preStartup();
                }
                else stop();
            }
            commands[currentCommand]->preUpdate();
        }

        void postStop()override{
            //only stop the command if it is running. dont run a stop script twice
            if(commands[currentCommand]->getState() == RUNNING) commands[currentCommand]->stop();
        }
};