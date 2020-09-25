#ifndef ARM_H
#define ARM_H

#include "Arduino.h"
#include "Servo.h"

namespace Car
{
    class ServoCtrl
    {
    public:
        ServoCtrl();
        ~ServoCtrl();

        void enable(int PIN);
        void setPos(int pos);
        void moveTo(int startPos, int endPos);
    private:
        Servo m_sServo;
        int m_pos;
    };
}

#endif