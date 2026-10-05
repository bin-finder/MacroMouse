#pragma once
#include "Icommand.h"

class NoNoOne: public Icommand{
    public:
    int num;
    NoNoOne(int num): num(num){}

    void startup() override{
        Serial.println("UUUUUAHH 1");
    }

    void update() override{
        Serial.print("Log ");
        Serial.println(num);
    }

    void postStop() override{
        Serial.print(num);
        Serial.println(" Died!");
    }

};