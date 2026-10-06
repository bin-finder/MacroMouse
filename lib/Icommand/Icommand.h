#pragma once
#include <Arduino.h>
#include "LazyArray.h"

#define maxSubProcesses 10

class Icommand{
    public:
        enum commandStates {STOPED, RUNNING, NOT_STARTED};
    private:
    
        Icommand* subprocesses[maxSubProcesses];

        LazyArray<Icommand*> mySubprocesses = LazyArray<Icommand*>(subprocesses, maxSubProcesses);
 
        commandStates state = NOT_STARTED;

    public:

        Icommand()
        {}

        void preUpdate(){
            update();
            for(int i = 0; i < mySubprocesses.getLastIndex(); i++){
                if(mySubprocesses[i]->getState() == RUNNING) mySubprocesses[i]->preUpdate();
            }
        }

        void preStartup(){
            state = RUNNING;
            startup();
        }

        virtual void update(){}

        virtual void postStop(){}

        virtual void startup(){}

        void stop(){
            for(int i = 0; i < mySubprocesses.getLastIndex(); i++){
                mySubprocesses[i]->stop();
            } 
            if(state == RUNNING) postStop();
            state = STOPED;
        }

        void spinup(Icommand* newCommand){
            mySubprocesses.push_back(newCommand);
            newCommand->preStartup();
        }

        commandStates getState(){
            return state;
        }        
};