#pragma once
#include <Arduino.h>

template <typename T>

class LazyArray{

    private:
    
        T* arr;
        uint16_t size;
        uint16_t currPos = 0;
        uint16_t endIndex = 0;
        uint16_t startIndex = 0;


    public:

        LazyArray(T arr[], uint16_t size): arr(arr), size(size){}

        uint16_t getRWheadPos(){
            return currPos;
        }

        void setRWhead(uint16_t newPos){
            currPos = newPos;
        }

        uint16_t getLastIndex(){
            return endIndex;
        }

        bool push_back(T newElement){
            if(endIndex < size){
                arr[endIndex++] = newElement;
                return true;
            }
            else return false;
        }

        bool pop_back() {
            if (endIndex == 0)
                return false;

            --endIndex;
            return true;
        }

        T& operator[](uint16_t index) {
            return arr[index];
        }
};