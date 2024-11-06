#ifndef IR_H_
#define IR_H_

#include <Arduino.h>

#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A6

//thresshold value for IR sensor to detect white or other colors line, expect black line
//using moving avarege method for each IR sensor
//using PID method for line following
//-> (2) using calibrate the value for each IR sensor -> button to calibrate
//-> (2) using button to start and stop the robot
//using button to change the mode -> line following, obstacle avoidance, line following + obstacle avoidance
//-> (1) change mode by GUI, (auto) = line following + obstacle avoidance
//-> (1) ketika mode auto calibarate sensor IR by GUI, start and stop robot by GUI, change PID by GUI, change speed by GUI



class IR {
    private:
        const int _ir1 = IR1;
        const int _ir2 = IR2;
        const int _ir3 = IR3;
        const int _ir4 = IR4;
        const int _ir5 = IR5;
        int _ir1value;
        int _ir2value;
        int _ir3value;
        int _ir4value;
        int _ir5value;

    public:
        IR();
        void begin();
        int getir1value();
        int getir2value();
        int getir3value();
        int getir4value();
        int getir5value();
        void printirvalue();
};

#endif // IR_H_