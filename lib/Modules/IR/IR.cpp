#include "IR/IR.h"

IR::IR() {

}

void IR::begin() {
    pinMode(_ir1, INPUT);
    pinMode(_ir2, INPUT);
    pinMode(_ir3, INPUT);
    pinMode(_ir4, INPUT);
    pinMode(_ir5, INPUT);
}

int IR::getir1value() {
    _ir1value = analogRead(_ir1);
    return _ir1value;
}

int IR::getir2value() {
    _ir2value = analogRead(_ir2);
    return _ir2value;
}

int IR::getir3value() {
    _ir3value = analogRead(_ir3);
    return _ir3value;
}

int IR::getir4value() {
    _ir4value = analogRead(_ir4);
    return _ir4value;
}

int IR::getir5value() {
    _ir5value = analogRead(_ir5);
    return _ir5value;
}

void IR::printirvalue() {
    Serial.print(">");
    Serial.print("IR1:");
    Serial.print(_ir1value); 
    Serial.print(",IR2:");
    Serial.print(_ir2value);
    Serial.print(",IR3:");
    Serial.print(_ir3value);
    Serial.print(",IR4:");
    Serial.print(_ir4value);
    Serial.print(",IR5:");
    Serial.println(_ir5value);
}