#include "Ultrasonic/UltrasonicTask.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10); // TX, RX
extern char Incoming_value = 0;

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
    mySerial.begin(9600);
    for (;;) {

        String data = String(self->_ultrasonic1.getDistance()) + "-" + String(self->_ultrasonic2.getDistance()) + "-" + String(self->_ultrasonic3.getDistance()) + "-";
        mySerial.println(data);

        vTaskDelay(pdMS_TO_TICKS(50));


        //komunikasi dari bluetooth ke arduino belakang
        if(mySerial.available() > 0) { //
            Incoming_value = mySerial.read();      
            Serial.println(Incoming_value); 
        }   

    }

}
