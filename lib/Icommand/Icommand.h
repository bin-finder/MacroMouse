#pragma once
#include <Arduino.h>
#include "LazyArray.h"

//TODO: Figure out how to get rid of this, and move to ArrayCommands instead if having a lengtho of 1
#define maxSubProcesses 1

class Icommand{
    public:
        enum commandStates {STOPED, RUNNING, NOT_STARTED};
    private:
    
        Icommand* subprocesses[maxSubProcesses];

        LazyArray<Icommand*> mySubprocesses = LazyArray<Icommand*>(subprocesses, maxSubProcesses);
 
        commandStates state = NOT_STARTED;

    public:

        //Icommand(){}

        void preUpdate(){
            update();
            for(int i = 0; i < mySubprocesses.getLastIndex(); i++){
                if(mySubprocesses[i]->getState() == RUNNING) mySubprocesses[i]->preUpdate();
                else if(mySubprocesses[i]->getState() == STOPED) mySubprocesses.pop_back();
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

            //IDK if I need this anymore...
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