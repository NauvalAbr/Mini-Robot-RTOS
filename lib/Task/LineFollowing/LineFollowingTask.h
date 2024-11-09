#ifndef LINEFOLLOWINGTASK_H
#define LINEFOLLOWINGTASK_H

#include <IR/IR.h>
#include <Arduino_FreeRTOS.h>
#include <Motor/MotorDriver.h>

class IRTask {
    private:

        IR &_ir;
        static void runTask(void *pvParameters);
        const UBaseType_t _taskPriority = 1;
        const uint32_t _taskStackSize = 64*2; // Reduced stack size for Arduino Nano
        TaskHandle_t _taskHandle;

    public:
        IRTask(IR &ir);
        
        void startTask();
        void stopTask();

};
#endif // IRRUN_H