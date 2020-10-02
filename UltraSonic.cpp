#include "UltraSonic.h"

using namespace Car;

UltraSonic::UltraSonic()
{}

UltraSonic::~UltraSonic()
{}

void UltraSonic::enable()
{
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    
    servo.attach(ULTRA_SONIC_SERVO_PIN);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

bool UltraSonic::scan_distance(int maxDist)
{

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = microsecondsToCentimeters(duration);
    
    delay(15);

    if(distance < maxDist)
    {
        return true;
    }

    return false;
}

unsigned long UltraSonic::scan()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    delay(15);

    distance = microsecondsToCentimeters(duration);

    return distance;
}

action UltraSonic::specialscan()
{
    action pos;

    int maxDist = 0;
    int prevPos = 0;
    int angle = 0;
    for (int i=0;i <= 180;i+=45) 
    {
        servo.write(i);
        delay(300);
        prevPos = i;
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);

        delay(15);

        distance = microsecondsToCentimeters(duration);

        if(distance > maxDist)
        {
            if(distance > 275 || distance < 5)
            {
                servo.write(90);
                return action::down;
            }
            maxDist = distance;
            switch(i)
            {
            case 0:
                pos = action::right;
                break;
            case 45:
                pos = action::kindaright;
                break;
            case 90:
                pos = action::up;
                break;
            case 135:
                pos = action::kindaleft;
                break;
            case 180:
                pos = action::left;
                break;
            }
        }
    }

    servo.write(90);

    return pos;
}