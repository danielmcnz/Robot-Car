#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define echoPin A4
#define trigPin A5

#include "IRControl.h"
#include "Servo.h"

#define ULTRA_SONIC_SERVO_PIN 3

namespace Car
{
    class UltraSonic
    {
    public: 
        UltraSonic();
        ~UltraSonic();

        void enable();
        unsigned long scan();
        bool scan_distance(int maxDist);
        action specialscan();
    private:
        unsigned long distance;
        unsigned long duration;
        Servo servo;
    };
}

#endif