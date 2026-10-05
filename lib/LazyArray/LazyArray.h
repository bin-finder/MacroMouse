#pragma once

template <typename T>

/**
 * @brief Just a c style array wrapper.
 */

class LazyArray{

    private:
    
        T* arr;
        unsigned int size;
        unsigned int endIndex = 0;
        unsigned int currPos = 0;
        unsigned int startIndex = 0;


    public:

        LazyArray(T arr[], unsigned int size): arr(arr), size(size){}

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

        T& next(){
            currPos++;
            return arr[currPos];
        }

        T& current(){
            return arr[currPos];
        }

        unsigned int currentPos(){
            return currPos;
        }

        unsigned int getSize(){
            return size;
        }
};