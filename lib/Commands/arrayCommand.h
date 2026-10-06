#pragma once
#include "Icommand.h"
#include "LazyArray.h"

/**
 * @brief This command takes in a LazyArray of command pointers, and runs every one each in turn, and waits for it to end
 */

class arrayCommand : public Icommand{
    private:
        LazyArray<Icommand*>& commands;
    public:

        /**
         * @param commands A LazyArray of commands to be run in sequence.
         */

        arrayCommand(LazyArray<Icommand*>& commands): commands(commands){}

        void startup(){
            commands.current()->preStartup();
        }

        void update(){
            if(commands.current()->getState() == STOPED){
                if(commands.currentPos() < commands.getSize()-1) commands.next();
                else stop();
            }
            commands.current()->update();
        }

        void postStop(){
            //only stop the command if it is running. dont run a stop script twice
            if(commands.current()->getState() == RUNNING) commands.current()->stop();
        }
};