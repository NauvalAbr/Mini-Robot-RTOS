#include <Motor/MotorTask.h>

extern int motorSpeed = 100;
extern int motorDirection = 50;

MotorTask::MotorTask(MotorDriver &rightMotor, MotorDriver &leftMotor) 
    :   _rightMotor(rightMotor), 
        _leftMotor(leftMotor), 
        _motorControl(rightMotor, leftMotor) {
        _currentSpeed = 0;
}

MotorTask::~MotorTask() {
    //vTaskDelete(_taskHandle);
}

void MotorTask::startTask() {
    xTaskCreate(MotorTask::runTask, "MotorTask", _taskStackSize, this, _taskPriority, NULL);
}


void MotorTask::runTask(void *pvParameters)
{
    MotorTask *self = static_cast<MotorTask *>(pvParameters);
    
    while (true)
    {
        self->_motorControl.forward();
        Serial.println("Maju");
        vTaskDelay(pdMS_TO_TICKS(3000));
        self->_motorControl.backward();
        Serial.println("Mundur");
        vTaskDelay(pdMS_TO_TICKS(3000));
        self->_motorControl.turnLeft(100);
        Serial.println("Belok Kiri");
        vTaskDelay(pdMS_TO_TICKS(3000));
        self->_motorControl.turnRight(100);
        Serial.println("Belok Kanan");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}

