#include <Arduino.h>

//FreeRTOS
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <task.h>
#include <semphr.h>

//Motor
#include <Motor/MotorControl.h>
#include <Motor/MotorDriver.h>
#include <Motor/MotorTask.h>


//Ultrasonic
#include "Ultrasonic/Ultrasonic.h"
#include "Ultrasonic/UltrasonicTask.h"

//IR
#include "IR/IR.h"

//deklarasi pin ultrasonic
#define ECHOR 6
#define TRIGR 7
#define ECHOL 2
#define TRIGL 3
#define ECHOF 4
#define TRIGF 5

//definisikan ultrasonic
Ultrasonic ultrasonic1(ECHOR, TRIGR);	// An ultrasonic sensor HC-04
Ultrasonic ultrasonic2(ECHOL, TRIGL);		// An ultrasonic sensor PING)))
Ultrasonic ultrasonic3(ECHOF, TRIGF);		// An Seeed Studio ultrasonic sensor
//jalankan task untuk ultrasonic
UltrasonicTask ultrasonicTask(ultrasonic1, ultrasonic2, ultrasonic3 );

IR ir;

void setup (){
    Serial.begin(9600);
    Serial.println("Cek Ultrasonic");
    ultrasonic1.begin();
    ultrasonic2.begin();
    ultrasonic3.begin();
    ultrasonicTask.startTask();
    ir.begin();
    ir.printirvalue();


    
}


void loop() {
    // Kosong, FreeRTOS akan menjalankan task
}
