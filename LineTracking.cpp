#include "LineTracking.h"

using namespace Car;

LineTracker::LineTracker()
{}

LineTracker::~LineTracker()
{}

void LineTracker::enable()
{
    pinMode(LT_R, INPUT);
    pinMode(LT_M, INPUT);
    pinMode(LT_L, INPUT);
}

action LineTracker::run()
{
    if (!digitalRead(LT_M))
    {
        return action::up;
    } 
    else if (!digitalRead(LT_R))
    {
        return action::right;
    } 
    else if (!digitalRead(LT_L))
    {
        return action::left;
    }
    return action::none;
}