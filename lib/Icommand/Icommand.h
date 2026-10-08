#pragma once

class Icommand{
    public:
        enum commandStates {STOPED, RUNNING, NOT_STARTED};
    private:
 
        commandStates state = NOT_STARTED;

    public:

        void preStartup(){
            state = RUNNING;
            startup();
        }

        virtual void update() = 0;

        virtual void postStop() = 0;

        virtual void startup() = 0;

        void stop(){
            if(state == RUNNING) postStop();
            state = STOPED;
        }

        commandStates getState(){
            return state;
        }        
};