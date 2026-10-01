#include <Arduino.h>

#define BUFFER_LENGTH 32

/**
 * This is just a tiny serial parser lib that will parse serial for you. Nothring formal here.
 */

class StateHandeler{
    public:
        int curState = 0; //Default State
    private:
        const char** states;
        int numStates;
        char serialBuffer[BUFFER_LENGTH];
        uint serialBufferWritePos = 0;    
        char charIn;

        void processBuffer(){
            bool validCommand = false;
            for(uint i = 0; i < numStates; i ++){
                if(strcmp(states[i],serialBuffer) == 0){
                    curState = i;
                    validCommand = true;
                    break;
                }
            }

            //The end condition (aka no matching commands were found)
            if(!validCommand) Serial.println("ERROR: " + static_cast<String>(serialBuffer) + " is not a valid command.");
        }

    public:

        StateHandeler(const char** states, int numStates):
            states(states), numStates(numStates)    
        {}

        void updateSerial(){                                    //-1 for a space for the null character.
            while(Serial.available() && serialBufferWritePos < BUFFER_LENGTH-1){
                charIn = Serial.read();
                if(charIn == '\n'){
                    serialBuffer[serialBufferWritePos] = '\0';
                    serialBufferWritePos = 0;
                    processBuffer();
                }
                else serialBuffer[serialBufferWritePos++] = charIn;
            }
        }
};