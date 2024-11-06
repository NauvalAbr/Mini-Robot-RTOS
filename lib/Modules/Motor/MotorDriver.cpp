#include "Motor/MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pinA, uint8_t pinB, uint8_t pinPWM) {
    _pinA = pinA;
    _pinB = pinB;
    _pinPWM = pinPWM;
    _maxPwm = 255;
    
    pinMode(_pinA, OUTPUT);
    pinMode(_pinB, OUTPUT);
    pinMode(_pinPWM, OUTPUT);
    pinMode(_pwm_standby_pin, OUTPUT);
    digitalWrite(_pwm_standby_pin, HIGH);
}

void MotorDriver::forward(uint8_t pwm) {
    _pwm = constrain(pwm, 0, _maxPwm);
    digitalWrite(_pinA, HIGH);
    digitalWrite(_pinB, LOW);
    analogWrite(_pinPWM, _pwm);

    // reverse
    //digitalWrite(_pinA, LOW);
    //digitalWrite(_pinB, HIGH);
    //analogWrite(_pinPWM, _pwm);  

}

void MotorDriver::backward(uint8_t pwm) {
    _pwm = constrain(pwm, 0, _maxPwm);
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, HIGH);
    analogWrite(_pinPWM, _pwm);  

    // reverse
    //digitalWrite(_pinA, _pwm);
    //digitalWrite(_pinB, 0);
    //analogWrite(_pinPWM, _pwm);
}

void MotorDriver::stop() {
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
    analogWrite(_pinPWM, _pwm);
}

