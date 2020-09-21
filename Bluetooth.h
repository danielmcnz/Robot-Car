#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "Arduino.h"

namespace Car
{
    class Bluetooth
    {
    public:
        Bluetooth();
        ~Bluetooth();

        void BluetoothRun();
    private:
        int direction = 0;
    };
}

#endif