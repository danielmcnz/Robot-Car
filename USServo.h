#ifndef ARM_H
#define ARM_H

#include "Arduino.h"
#include "Servo.h"

#define PIN 3

namespace Car
{
    class USServo
    {
    public:
        USServo();
        ~USServo();

        void setup();
        void setPos(int pos);
        void moveTo(int startPos, int endPos);
    private:
        Servo m_sServo;
        int m_pos;
    };
}

#endif