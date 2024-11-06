#ifndef ULTRASONICTASK_H_
#define ULTRASONICTASK_H_

#include <Arduino_FreeRTOS.h>
#include "Ultrasonic/Ultrasonic.h"

class UltrasonicTask{
    private:
        Ultrasonic &_ultrasonic1;
        Ultrasonic &_ultrasonic2;
        Ultrasonic &_ultrasonic3;
        static void runTask(void *pvParameters);

        const UBaseType_t _taskPriority = 1;
        const uint32_t _taskStackSize = 64*2; 
        // Stack size in words, karna 1 word = 4 bytes, maka 128 word = 512 bytes,
        // 2kb SRAM berarti 2048 bytes, 512 bytes adalah 25% dari 2048 bytes 
        // dan karna arduino nano memiliki 2KB SRAM, maka 512 bytes adalah ukuran yang cukup

        TaskHandle_t _taskHandle;

    public:
        UltrasonicTask(Ultrasonic &ultrasonic1, Ultrasonic &ultrasonic2, Ultrasonic &ultrasonic3);
        void startTask();
        void stopTask();
};


#endif // ULTRASONICCONTROL_H
