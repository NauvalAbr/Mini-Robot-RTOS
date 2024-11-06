#include "Ultrasonic/UltrasonicTask.h"

UltrasonicTask::UltrasonicTask(Ultrasonic &ultrasonic1, Ultrasonic &ultrasonic2, Ultrasonic &ultrasonic3) 
    : _ultrasonic1(ultrasonic1), _ultrasonic2(ultrasonic2), _ultrasonic3(ultrasonic3) {
    _taskHandle = NULL;
}

void UltrasonicTask::startTask() {
    xTaskCreate(UltrasonicTask::runTask, "UltrasonicTask", _taskStackSize, this, _taskPriority, &_taskHandle);
    Serial.println("Ultrasonic task started.");
}

void UltrasonicTask::stopTask() {
    vTaskDelete(_taskHandle);
}

void UltrasonicTask::runTask(void *pvParameters) {
    UltrasonicTask *self = static_cast<UltrasonicTask *>(pvParameters);

    for (;;) {
        Serial.print("Sensor 1: ");
        Serial.print(self->_ultrasonic1.getDistance());
        Serial.println(" cm");

        Serial.print("Sensor 2: ");
        Serial.print(self->_ultrasonic2.getDistance());
        Serial.println(" cm");

        Serial.print("Sensor 3: ");
        Serial.print(self->_ultrasonic3.getDistance());
        Serial.println(" cm");
        Serial.println("-----------------");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
