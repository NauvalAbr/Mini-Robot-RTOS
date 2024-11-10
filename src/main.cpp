#include <Arduino.h>

//FreeRTOS
#include <Arduino_FreeRTOS.h>
// #include <queue.h>
// #include <task.h>
// #include <semphr.h>

#define Arduino_Depan 1 // 1 for Arduino Depan (line), 0 for Arduino Belakang(ultrasonic)


//------------------------------------------------------------------------------------------------------------------------------
#if Arduino_Depan == 1

//Motor
#include <Motor/MotorControl.h>
#include <Motor/MotorDriver.h>
#include <Motor/MotorTask.h>

//IR
#include "IR/IR.h"
#include "LineFollowing/LineFollowingTask.h"

//deklarasi pin motor
#define PINA_IN1  8     //Motor B Kiri
#define PINA_IN2  7
#define PINA_PWM  5
#define PINB_IN1  4     //Motor B Kanan
#define PINB_IN2  2
#define PINB_PWM  3


//definisakan motor
MotorDriver motorA(PINA_IN1, PINA_IN2, PINA_PWM);
MotorDriver motorB(PINB_IN1, PINB_IN2, PINB_PWM);
MotorControl motorControl(motorA, motorB);

MotorTask motorTask(motorA, motorB);

//definisakn pin IR
IR ir;
IRTask irTask(ir);



void setup (){
    Serial.begin(9600);
    Serial.println("Cek Motor: ");
    // ir.begin();
    // irTask.startTask();

    // motorControl.forward();

    motorTask.startTask();
    // ir.printirvalue();
}


void loop() {
    // Kosong, FreeRTOS akan menjalankan task
}






//------------------------------------------------------------------------------------------------------------------------------
#else //Arduino Belakang

//Ultrasonic
#include "Ultrasonic/Ultrasonic.h"
#include "Ultrasonic/UltrasonicTask.h"

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
UltrasonicTask ultrasonicTask(ultrasonic1, ultrasonic2, ultrasonic3);

void setup(){
    Serial.begin(9600);
    Serial.println("Cek Ultrasonic: ");

    ultrasonic1.begin();
    ultrasonic2.begin();
    ultrasonic3.begin();
    ultrasonicTask.startTask();
}


void loop() {
    // Kosong, FreeRTOS akan menjalankan task
}


#endif