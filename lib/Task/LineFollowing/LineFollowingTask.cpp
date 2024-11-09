#include <LineFollowing/LineFollowingTask.h>

// extern int threshold = 720;

IRTask::IRTask(IR &ir) 
    : _ir(ir) {
    _taskHandle = NULL;
}

void IRTask::startTask() {
    xTaskCreate(IRTask::runTask, "IRTask", _taskStackSize, this, _taskPriority, &_taskHandle);
    Serial.println("IR task started.");
}

void IRTask::stopTask() {
    vTaskDelete(_taskHandle);
}


void IRTask::runTask(void *pvParameters) {
    IRTask *self = static_cast<IRTask *>(pvParameters);

    for (;;) {
        Serial.println("IR Reading");
        self->_ir.getir1value();
        self->_ir.getir2value();
        self->_ir.getir3value();
        self->_ir.getir4value();
        self->_ir.getir5value();
        self->_ir.printirvalue();
    }
}