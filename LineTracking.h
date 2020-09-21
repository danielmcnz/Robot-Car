#ifndef LINETRACKING_H
#define LINETRACKING_H

#include "Arduino.h"

#include "Motors.h"
#include "IRControl.h"

#define LT_R 10
#define LT_M 4
#define LT_L 2

namespace Car
{
    class LineTracker
    {
    public:
        LineTracker();
        ~LineTracker();

        void enable();
        action run();
    };
}

#endif