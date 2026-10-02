#pragma once
#include "Icommand.h"

class NoNoOne: public Icommand{
    public:
    int num;
    NoNoOne(int num): num(num){}

    void startup(){
        Serial.println("UUUUUAHH 1");
    }

    void update(){
        Serial.print("Log ");
        Serial.println(num);
    }

    void postStop(){
        Serial.print(num);
        Serial.println(" Died!");
    }

};