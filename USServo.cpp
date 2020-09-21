#include "USServo.h"

using namespace Car;

USServo::USServo()
    :
    m_pos(90)
{}

USServo::~USServo()
{}

void USServo::setup()
{
    m_sServo.attach(PIN);
}

void USServo::setPos(int pos)
{
    m_sServo.write(pos);
}

void USServo::moveTo(int startPos, int endPos)
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