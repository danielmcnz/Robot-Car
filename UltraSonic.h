#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define echoPin A4
#define trigPin A5

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
        long distance;
        long duration;
        USServo *us_servo;
    };
}

#endif