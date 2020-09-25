#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#define STEPS_PER_REVOLUTION 32
#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3

#include "Arduino.h"
#include "Stepper.h"

namespace Car
{
    class StepperMotor
    {
    public:
        StepperMotor();
        ~StepperMotor();

        void SetSpeed(int speed);

        void enable();
        void step(int step);
    private:
        Stepper stepper;
        int speed;
    };
}

#endif