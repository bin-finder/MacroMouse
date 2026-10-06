#pragma once 
#include <Arduino.h>

struct LED{
    enum state {OFF, ON};
    private:
    state currentState = OFF;
    public:
    int pin;

    LED(int pin): pin(pin){
        pinMode(pin,OUTPUT);
    }

    void setState(state newState){
        if(newState != currentState) digitalWrite(pin,newState);
    }
    
    void setState(uint8_t value){
        analogWrite(pin,value);
    }
};