#include "RoboCar.h"

using namespace Car;

RoboCar::RoboCar()
    :
    collision(false),
    pickedUpObject(false)
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
    motor->setSpeed(255);
    lt->enable();
    u_sonic->enable();
    stepper_motor->enable();
    pully->enable(PULLY_PIN);
    pully->setPos(PULLY_UP);
}

void RoboCar::setIRRem()
{
    motor->setSpeed(200);
    ircon->enable();
    u_sonic->enable();
}

void RoboCar::enable()
{
    ircon = new IRControl();
    motor = new Motors();
    lt = new LineTracker();
    u_sonic = new UltraSonic();
    stepper_motor = new StepperMotor();
    pully = new ServoCtrl();
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
    if(!u_sonic->scan(20) && collision == false)
    {
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
    }
    else
    {
        motor->Stop();
        collision = true;
        
        if(pickedUpObject == false)
        {
            pickedUpObject = PickupObject();
        }

        if(pickedUpObject == true)
        {
            TurnAround();
            
            collision = false;
        }
    }
}

bool RoboCar::PickupObject()
{
    // TODO: pickup object

    stepper_motor->step(1000);
    //pully->moveTo(PULLY_UP, PULLY_DOWN);
    return true;
}

void RoboCar::TurnAround()
{
    unsigned long time = millis();

    do
    {
        motor->MoveRight();
    } while (time < 500);
    collision = false;
}