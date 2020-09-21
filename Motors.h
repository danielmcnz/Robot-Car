#ifndef MOTORS_H
#define MOTORS_H

#include "Arduino.h"

#define N1 11
#define N2 9
#define N3 8
#define N4 7

#define ENA 6
#define ENB 5

namespace Car
{
    class Motors
    {
    public:
        Motors();
        ~Motors();

        void setSpeed(int speed);

        void MoveLeft();
        void MoveRight();
        void MoveForward();
        void MoveBackward();
        void Stop();
    private:
        void WheelsSetup();
    private:
        int speed;
    };
}

#endif