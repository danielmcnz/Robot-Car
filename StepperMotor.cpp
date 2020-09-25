#include "StepperMotor.h"

using namespace Car;

StepperMotor::StepperMotor()
    :
    stepper(STEPS_PER_REVOLUTION, IN1, IN2, IN3, IN4),
    speed(200)
{}

StepperMotor::~StepperMotor()
{}

void StepperMotor::SetSpeed(int speed)
{
    this->speed = speed;
    stepper.setSpeed(speed);
}

void StepperMotor::enable()
{
    stepper.setSpeed(speed);
}

void StepperMotor::step(int step)
{
    stepper.step(step);
}