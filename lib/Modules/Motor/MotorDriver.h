#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <Arduino.h>

#define STBY 9   // Standby pin

class MotorDriver {
    private:
        const uint8_t _pwm_standby_pin = STBY;
        uint8_t _pinA;
        uint8_t _pinB;
        uint8_t _pinPWM;
        uint8_t _pwm;
        uint8_t _maxPwm;

    public:
        MotorDriver(uint8_t pinA, uint8_t pinB, uint8_t pinPWM);
        
        void forward(uint8_t pwm);
        void backward(uint8_t pwm);
        void stop();

};

#endif // MOTOR_DRIVER_H
