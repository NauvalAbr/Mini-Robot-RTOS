#ifndef MOTOR_TASK_H
#define MOTOR_TASK_H

#include "Motor/MotorDriver.h"
#include "Motor/MotorControl.h"
#include <Arduino_FreeRTOS.h>

class MotorTask {

    private:
        static void runTask(void *pvParameters);

        const UBaseType_t _taskPriority = 1;
        const uint32_t _taskStackSize = 32*4; // Reduced stack size for Arduino Nano
        MotorDriver &_rightMotor;
        MotorDriver &_leftMotor;
        MotorControl _motorControl;

        uint8_t _currentSpeed;

    public:
        MotorTask(MotorDriver &rightMotor, MotorDriver &leftMotor);
        ~MotorTask();
        
        void startTask();

};



#endif // MOTOR_TASK_H