#include "RoboCar.h"

using namespace Car;

RoboCar::RoboCar()
{}

RoboCar::~RoboCar()
{
    delete ircon;
    delete motor;
    delete lt;
    delete u_sonic;

    ircon = nullptr;
    motor = nullptr;
    lt = nullptr;
    u_sonic = nullptr;
}

void RoboCar::setLT()
{
    motor->setSpeed(125);
    lt->enable();
}

void RoboCar::setIRRem()
{
    motor->setSpeed(255);
    ircon->enable();
}

void RoboCar::enable()
{
    ircon = new IRControl();
    motor = new Motors();
    lt = new LineTracker();
    u_sonic = new UltraSonic();

    u_sonic->enable();
}

void RoboCar::IRRemoteControl()
{
    switch(ircon->decodeIR())
    {
        case action::up:
            motor->MoveForward();
            last_update = millis();
            break;
        case action::down:
            motor->MoveBackward();
            last_update = millis();
            break;
        case action::left:
            motor->MoveLeft();
            last_update = millis();
            break;
        case action::right:
            motor->MoveRight();
            last_update = millis();
            break;
        case action::one:
            break;
        case action::two:
            break;
        case action::three:
            break;
        case action::none:
            break;
        case action::err:
            break;
        default:
            break;
    }

    if ((millis() - last_update) >= 100)
    {
        last_update = millis();
        motor->Stop();
    }
}

void RoboCar::LineTracking()
{
    // if(!u_sonic->scan(200))
    // {
        switch(lt->run())
        {
            case action::up:
                motor->MoveForward();
                break;
            case action::left:
                motor->MoveLeft();
                break;
            case action::right:
                motor->MoveRight();
                break;
            default:
                break;
        }
        Serial.println("nope");
    // }
    // else
    // {
    //     Serial.println("collision");
    //     motor->Stop();
    // }
    
}

void RoboCar::Automate()
{
    /*
        Car logic here
        Example below
    */

    unsigned long time = millis() / 1000;
    if(time < 1)
    {
        motor->MoveForward();
    }
    else if(time > 1 && time < 2)
    {
        motor->MoveLeft();
    }
    else if(time > 2 && time < 3)
    {
        motor->MoveForward();
    }
    else
    {
        motor->Stop();
    }
}