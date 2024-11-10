#include <Motor/MotorTask.h>

extern int motorSpeed = 100;
extern int motorDirection = 50;
extern char Incoming_value = 0;

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
    Serial.begin(9600);
    for(;;) {
        if(Serial.available() > 0) {
            Incoming_value = Serial.read();      
            Serial.println(Incoming_value); 


            // if(Incoming_value == 'A') { // Kiri Maju
            // self->_motorControl.forward();

            if(Incoming_value == 'B') {      // Maju  
            self->_motorControl.forward();
            
            // } else if(Incoming_value == 'C') {      // Kanan Maju
            // motorB_CCW(255);
            // motorA_CW(255);
            
            } else if(Incoming_value == 'D') {      // Kiri
            self->_motorControl.turnLeft(100);
            
            } else if(Incoming_value == 'F') {      // Kanan 
            self->_motorControl.turnRight(100);

            // } else if(Incoming_value == 'G') {      // Kiri Mundur
            // motorB_CW(255);
            // motorA_CCW(255);
    
            } else if(Incoming_value == 'H') {      // Mundur  
            self->_motorControl.backward();     

            // } else if(Incoming_value == 'I') {      //kanan mundur
            // motorB_CCW(255);
            // motorA_CW(255);

            } else if(Incoming_value == 'S') {      // Stop
            self->_motorControl.stop();
            }
            // self->_motorControl.forward();
            // Serial.println("Maju");
            // vTaskDelay(pdMS_TO_TICKS(3000));
            // self->_motorControl.backward();
            // Serial.println("Mundur");
            // vTaskDelay(pdMS_TO_TICKS(3000));
            // self->_motorControl.turnLeft(100);
            // Serial.println("Belok Kiri");
            // vTaskDelay(pdMS_TO_TICKS(3000));
            // self->_motorControl.turnRight(100);
            // Serial.println("Belok Kanan");
            // vTaskDelay(pdMS_TO_TICKS(3000));
        }
    }
}

