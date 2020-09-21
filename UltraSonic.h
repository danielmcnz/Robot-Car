#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define echoPin 4
#define trigPin 5

#include "USServo.h"

namespace Car
{
    class UltraSonic
    {
    public: 
        UltraSonic();
        ~UltraSonic();

        void enable();
        bool scan(int maxDistance);
    private:
        float distance;
        float duration;
        USServo *us_servo;
    };
}

#endif