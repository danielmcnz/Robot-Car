#include "Bluetooth.h"

using namespace Car;

Bluetooth::Bluetooth()
{}

Bluetooth::~Bluetooth()
{}

void Bluetooth::BluetoothRun()
{
    if(Serial.available() > 0)
    {
        char data;
        data = Serial.read();
        Serial.write(Serial.read());

        switch(data)
        {
        case 1:
            direction = 1;
        case 2:
            direction = 0;
        case 3:
            direction = -1;
        default:
            Serial.println(data);
        }
    }
}