#include <Arduino.h>

//FreeRTOS
#include <Arduino_FreeRTOS.h>
// #include <queue.h>
// #include <task.h>
// #include <semphr.h>

//Motor
// #include <Motor/MotorControl.h>
// #include <Motor/MotorDriver.h>
// #include <Motor/MotorTask.h>


// //Ultrasonic
#include "Ultrasonic/Ultrasonic.h"
#include "Ultrasonic/UltrasonicTask.h"

//IR
// #include "IR/IR.h"
// #include "LineFollowing/LineFollowingTask.h"

//deklarasi pin motor
// #define PINA_IN1  8
// #define PINA_IN2  7
// #define PINA_PWM  5
// #define PINB_IN1  4
// #define PINB_IN2  2
// #define PINB_PWM  3


//deklarasi pin ultrasonic
#define ECHOR 6
#define TRIGR 7
#define ECHOL 2
#define TRIGL 3
#define ECHOF 4
#define TRIGF 5

//definisakan motor
// MotorDriver motorA(PINA_IN1, PINA_IN2, PINA_PWM);
// MotorDriver motorB(PINB_IN1, PINB_IN2, PINB_PWM);
// MotorControl motorControl(motorA, motorB);

// MotorTask motorTask(motorA, motorB);

//
//definisikan ultrasonic
Ultrasonic ultrasonic1(ECHOR, TRIGR);	// An ultrasonic sensor HC-04
Ultrasonic ultrasonic2(ECHOL, TRIGL);		// An ultrasonic sensor PING)))
Ultrasonic ultrasonic3(ECHOF, TRIGF);		// An Seeed Studio ultrasonic sensor
//jalankan task untuk ultrasonic
UltrasonicTask ultrasonicTask(ultrasonic1, ultrasonic2, ultrasonic3);

// IR ir;
// IRTask irTask(ir);

// IRTask irTask(ir, motorA, motorB);


void setup (){
    Serial.begin(9600);
    Serial.println("Cek Ultrasonic: ");

    ultrasonic1.begin();
    ultrasonic2.begin();
    ultrasonic3.begin();
    ultrasonicTask.startTask();

    // ir.begin();
    // irTask.startTask();

    // motorControl.forward();

    // motorTask.startTask();
    // ir.printirvalue();


}


void loop() {
    // motorControl.forward();
    // Serial.println("Maju");
    // delay(3000);
    // motorControl.backward();
    // Serial.println("Mundur");
    // delay(5000);
    // motorControl.stop();
    // Serial.println("Stop");
    // delay(3000);
    // Kosong, FreeRTOS akan menjalankan task
}
