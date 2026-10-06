#pragma once
#include "Icommand.h"

/**
 * @brief This command runs two commands side by side untill one of them ends, then it ends the other.
 */

class synchronous: public Icommand{

    Icommand com1, com2;

    public:

        /**
         * @param com1 The first command.
         * @param com2 The sedond command.
         */

        synchronous(Icommand& com1, Icommand& com2) : com1(com1), com2(com2){}

        void startup() override{
            com1.preStartup();
            com2.preStartup();
        }

        void update() override{
            com1.update();
            com2.update();
            if(com1.getState() == STOPED) com2.stop();
            else if(com2.getState() == STOPED) com1.stop();
        }

        void postStop() override{
            com1.stop();
            com2.stop();
        }
};