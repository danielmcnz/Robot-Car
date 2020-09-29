#include "RoboCar.h"

Car::RoboCar car;

void setup()
{
  Serial.begin(9600);
  car.enable();
  car.setLT();
}

void loop()
{
  car.LineTracking();
}
