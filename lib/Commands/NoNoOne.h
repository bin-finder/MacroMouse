#pragma once
#include "Icommand.h"

class NoNoOne: public Icommand{
    public:
    int num;
    int itterator = 1;
    NoNoOne(int num): num(num){}

    void startup(){
        Serial.print("UUUUUAHH ");
        Serial.print(num);
        Serial.println(" Im wakeing up");
    }

    void update(){
        Serial.print(num);
        Serial.println(" im just so radioactive");
        if(itterator >= num) stop();
        itterator++;
    }

    void postStop(){
        Serial.print(num);
        Serial.println(" died of radiation poisioning.");
    }

};