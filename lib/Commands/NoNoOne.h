#pragma once
#include "Icommand.h"

class NoNoOne: public Icommand{
    public:
    int num;
    NoNoOne(int num): num(num){}

    void startup() override{
        Serial.println("UUUUUAHH 1\n Im wakeing up");
    }

    void update() override{
        Serial.print(num);
        Serial.println(" im just so radioactive");
    }

    void postStop() override{
        Serial.print(num);
        Serial.println(" died of radiation poisioning.");
    }

};