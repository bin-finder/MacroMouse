#pragma once
#include "WEMOS_Motor.h"

class TankBase{
    private:
        Motor& leftMotor;
        Motor& rightMotor;
        uint8_t leftMotorDir;
        uint8_t rightMotorDir;

        void rectifyMotorPow(Motor& motor, float speed, uint8_t motorDir){
            if(speed < 0.0){
                if(motorDir == _CW) motor.setmotor(_CCW, speed*-1);
                else motor.setmotor(_CW, speed*-1);
            }
            else motor.setmotor(motorDir, speed);
        }

    public:
        TankBase(Motor& leftMotor, uint8_t leftMotorDir, Motor& rightMotor, uint8_t rightMotorDir): 
            leftMotor(leftMotor), 
            rightMotor(rightMotor), 
            leftMotorDir(leftMotorDir), 
            rightMotorDir(rightMotorDir)
        {}

        /**
         * @brief Set raw motor powers
         * @param leftSpeed The speed for the left motor
         * @param rightSpeed The right motor speed
         */

        void onPercent(float leftSpeed, float rightSpeed){
            rectifyMotorPow(leftMotor, leftSpeed, leftMotorDir);
            rectifyMotorPow(rightMotor, rightSpeed, rightMotorDir);
        }

        /**
         * @brief Stop all motors
         */

        void stop(){
            leftMotor.setmotor(_STOP);
            rightMotor.setmotor(_STOP); }

        void onForTime(double leftSpeed, double rightSpeed, double time){
            onPercent(leftSpeed,rightSpeed);
            delay(time*1000);
            stop();
        }
};