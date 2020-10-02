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

void RoboCar::enable()
{
    ircon = new IRControl();
    motor = new Motors();
    lt = new LineTracker();
    u_sonic = new UltraSonic();
    stepper_motor = new StepperMotor();
    pully = new ServoCtrl();

    motor->setSpeed(230);
    lt->enable();
    u_sonic->enable();
    stepper_motor->enable();
    pully->enable(PULLY_PIN);
    pully->setPos(PULLY_UP);
    ircon->enable();
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
    }

    if ((millis() - last_update) >= 100)
    {
        last_update = millis();
        motor->Stop();
    }
}

void RoboCar::LineTracking()
{
    if(!u_sonic->scan_distance(20) && collision == false)
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

    stepper_motor->step(200);
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

void RoboCar::CollisionDetection()
{
    while(true)
    {
        unsigned long distance = u_sonic->scan();
        if(distance < 20)
        {
            motor->Stop();
            action posToMoveTo;
            posToMoveTo = u_sonic->specialscan();

            unsigned long starttime = millis();
            unsigned long endtime = starttime;
            int moveDuration = 300;
            switch(posToMoveTo)
            {
            case action::down:
                while ((endtime - starttime) <= 
                    (moveDuration * 2 + moveDuration / 2))
                {
                    motor->MoveLeft();
                    endtime = millis();
                }
                break;
            case action::up:
                while ((endtime - starttime) <= moveDuration)
                {
                    motor->MoveForward();
                    endtime = millis();
                }
                break;
            case action::left:
                while ((endtime - starttime) <= moveDuration)
                {
                    motor->MoveLeft();
                    endtime = millis();
                }
                break;
            case action::kindaleft:
                while ((endtime - starttime) <= moveDuration)
                {
                    motor->MoveLeft();
                    endtime = millis();
                }
            case action::right:
                while ((endtime - starttime) <= moveDuration)
                {
                    motor->MoveRight();
                    endtime = millis();
                }
                break;
            case action::kindaright:
                while ((endtime - starttime) <= moveDuration)
                {
                    motor->MoveRight();
                    endtime = millis();
                }
            }
        }
        else
        {
            motor->MoveForward();
        }
              
    }
}