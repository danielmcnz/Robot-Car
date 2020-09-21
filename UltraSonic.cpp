#include "UltraSonic.h"

using namespace Car;

UltraSonic::UltraSonic()
{
    us_servo = new USServo();
}

UltraSonic::~UltraSonic()
{
    delete us_servo;

    us_servo = nullptr;
}

void UltraSonic::enable()
{
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);

    us_servo->setup();
    us_servo->setPos(200);
}

bool UltraSonic::scan(int maxDistance)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    Serial.println(duration);
    distance = (duration * 0.034) / 2;
    Serial.println(distance);
    delay(15);
    if(distance > maxDistance && maxDistance < 3000)
    {
        return true;
    }
    return false;
}