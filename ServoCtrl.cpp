#include "ServoCtrl.h"

using namespace Car;

ServoCtrl::ServoCtrl()
    :
    m_pos(90)
{}

ServoCtrl::~ServoCtrl()
{}

void ServoCtrl::enable(int PIN)
{
    m_sServo.attach(PIN);
}

void ServoCtrl::setPos(int pos)
{
    m_sServo.write(pos);
}

void ServoCtrl::moveTo(int startPos, int endPos)
{
    // Check if startPos and endPos and which one
    // is greater determines if the for loop is
    // greater than or less than

    for (m_pos = startPos;m_pos >= endPos;--m_pos) 
    {
        m_sServo.write(m_pos);
        delay(15);
    }
}