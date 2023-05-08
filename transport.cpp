
#include "transport.h"

float transport::GetDriveTime()
{
	driveTime = calcDriveTime();
	return driveTime;
}

void transport::setDistance(int distance)
{

	if (distance < 0) throw IsNegativeException();
	this->distanceToGo = distance;
}


float transport::calcDriveTime()
{
	return driveTime;
}

unsigned int transport::GetSpeed()
{
	return speed;
}

void transport::SetSpeed(int speed)
{
	if (speed < 0) throw IsNegativeException();
	this->speed = speed;
}

unsigned int transport::GetDistance()
{
	return distanceToGo;
}

std::string transport::GetName()
{
  return this-> transportName;
}

void transport::setName(std::string Name)
{
  this-> transportName = Name;
}