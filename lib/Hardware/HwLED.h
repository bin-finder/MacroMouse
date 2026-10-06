#pragma once 
#include <Arduino.h>

struct HwLED{
    public:
        enum state {OFF, ON};
    private:
        state currentState = OFF;
    public:
        int pin;

        HwLED(int pin): pin(pin){
            pinMode(pin,OUTPUT);
        }

        void setState(state newState){
            if(newState != currentState) digitalWrite(pin,newState);
        }
        
        void setState(uint8_t value){
            analogWrite(pin,value);
        }   
};