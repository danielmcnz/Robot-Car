#include "IRControl.h"

using namespace Car;

IRControl::IRControl()
    :
    recv(IR_PIN),
    prevKey(0xFFFFFFFF)
{}

IRControl::~IRControl()
{}

void IRControl::enable()
{
    recv.enableIRIn();
    recv.blink13(false);
}

action IRControl::decodeIR()
{
    if(recv.decode(&results))
    {
        unsigned long val = results.value;
        recv.resume();

        if(val == 0xFFFFFFFF)
        {
            val = prevKey;
        }
        else
        {
            prevKey = val;
        }
        
        switch(val)
        {
        case ZERO:
            break;
        case ONE:
            return action::one;
            break;
        case TWO:
            return action::two;
            break;
        case THREE:
            return action::three;
            break;
        case FOUR:
            return action::four;
            break;
        case FIVE:
            break;
        case SIX:
            break;
        case SEVEN:
            break;
        case EIGHT:
            break;
        case NINE:
            break;
        case UP:
            return action::up;
            break;
        case DOWN:
            return action::down;
            break;
        case LEFT:
            return action::left;
            break;
        case RIGHT:
            return action::right;
            break;
        default:
            Serial.println(results.value);
            break;
        }
        return action::none;
    }
    return action::err;
}