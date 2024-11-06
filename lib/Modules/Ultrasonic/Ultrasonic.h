#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>



class Ultrasonic {
    private:
        // unsigned long _previousMillis;
        // const long _interval = 1000; // interval to measure distance
        const int _echoPin;
        const int _trigPin;
    public:
        Ultrasonic(int echoPin, int trigPin);
        void begin();
        long getDistance();
        // void printDistance();

};

#endif // ULTRASONIC_H