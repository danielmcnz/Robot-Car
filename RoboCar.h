#ifndef ROBOCAR_H
#define ROBOCAR_H

#include "Arduino.h"
#include "SoftwareSerial.h"

#include "Motors.h"
#include "Bluetooth.h"
#include "IRControl.h"
#include "LineTracking.h"
#include "RoboCar.h"
#include "UltraSonic.h"
#include "StepperMotor.h"
#include "ServoCtrl.h"

#define PULLY_PIN 12
#define PULLY_UP 0 // position to start at
#define PULLY_DOWN 180 // position to end at

namespace Car
{
    class RoboCar
    {
    public:
        RoboCar();
        ~RoboCar();

        void setLT();
        void setIRRem();

        void enable();
        void IRRemoteControl();
        void LineTracking();

private:
        bool PickupObject();
        void TurnAround();
    private:
        Motors *motor;
        IRControl *ircon;
        LineTracker *lt;
        UltraSonic *u_sonic;
        StepperMotor *stepper_motor;
        ServoCtrl* pully;
        unsigned long last_update;
        bool collision;
        bool pickedUpObject;
    };
}

#endif