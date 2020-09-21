#include "Motors.h"

using namespace Car;

Motors::Motors()
    :
    speed(255)
{
    WheelsSetup();
}

Motors::~Motors()
{
    Stop();
}

void Motors::WheelsSetup()
{
    pinMode(ENA, OUTPUT);
    pinMode(ENA, OUTPUT);

    pinMode(N1, OUTPUT);
    pinMode(N2, OUTPUT);
    pinMode(N3, OUTPUT);
    pinMode(N4, OUTPUT);
}

void Motors::setSpeed(int speed)
{
    this->speed = speed;
}

void Motors::MoveLeft()
{
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);
}

void Motors::MoveRight()
{
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(N1, LOW);
    digitalWrite(N2, HIGH);
    digitalWrite(N3, LOW);
    digitalWrite(N4, HIGH);
}

void Motors::MoveForward()
{
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, LOW);
    digitalWrite(N4, HIGH);
}

void Motors::MoveBackward()
{
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(N1, LOW);
    digitalWrite(N2, HIGH);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);
}

void Motors::Stop()
{
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(N1, LOW);
    digitalWrite(N2, LOW);
    digitalWrite(N3, LOW);
    digitalWrite(N4, LOW);
}