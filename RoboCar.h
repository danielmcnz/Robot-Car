#ifndef ROBOCAR_H
#define ROBOCAR_H

#include "Arduino.h"
#include "SoftwareSerial.h"
//#include "IRremote.h"    do i need this???

#include "Motors.h"
#include "Bluetooth.h"
#include "IRControl.h"
#include "LineTracking.h"
#include "RoboCar.h"
#include "UltraSonic.h"

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
        void Automate();
    private:
        Motors *motor;
        IRControl *ircon;
        LineTracker *lt;
        UltraSonic *u_sonic;
        unsigned long last_update;
        bool foundObject;
        bool pickedUpObject;
    };
}

#endif