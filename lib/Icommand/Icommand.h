#pragma once
#include <Arduino.h>
#include "LazyArray.h"

#define maxSubProcesses 10

class Icommand{

    private:
    
        Icommand* subprocesses[maxSubProcesses];

        LazyArray<Icommand*> mySubprocesses = LazyArray<Icommand*>(subprocesses, maxSubProcesses);

    public:

        Icommand()
        {}

        void preUpdate(){
            update();
            for(int i = 0; i < mySubprocesses.getLastIndex(); i++){
                mySubprocesses[i]->preUpdate();
            }
        }

        virtual void update() = 0;

        virtual void postStop() = 0;

        virtual void startup() = 0;

        void stop(){
            for(int i = 0; i < mySubprocesses.getLastIndex(); i++){
                mySubprocesses[i]->stop();
            }
            postStop();
        }

        void spinup(Icommand* newCommand){
            mySubprocesses.push_back(newCommand);
            newCommand->startup();
        }
};