#include "Ultrasonic/Ultrasonic.h"

Ultrasonic::Ultrasonic(int echoPin, int trigPin) 
    : _echoPin(echoPin),_trigPin(trigPin) {
    

}

void Ultrasonic::begin() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}


long Ultrasonic::getDistance() {

    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    long duration, distance;
    duration = pulseIn(_echoPin, HIGH, 30000);
    
    if (duration == 0) {
        return -1;
    }

    distance = duration * 0.034 / 2;
    return distance;
}

// void Ultrasonic::printDistance() {
//     unsigned long previousMillis = 0;
//     const long interval = 1000; // interval at which to print (milliseconds)

//     for (;;) {
//         unsigned long currentMillis = millis();
//         if (currentMillis - previousMillis >= interval) {
//             previousMillis = currentMillis;
            
//             Serial.print("Distance: ");
//             Serial.print(getDistance());
//             Serial.println(" cm");
//         }
//     }
// }


