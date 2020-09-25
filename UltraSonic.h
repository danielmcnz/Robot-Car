#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define echoPin A4
#define trigPin A5

#include "ServoCtrl.h"

#define ULTRA_SONIC_SERVO_PIN 3

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
        ServoCtrl *us_servo;
    };
}

#endif