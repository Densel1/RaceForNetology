
#pragma once
#include <exception>
#include "groundtransport.h"

class kentavr: public groundtransport
{
protected:
  float calcDriveTime() override;
public:
  kentavr() :kentavr("Кентавр", 15, 100, 8, 2){}
  kentavr(std::string name, unsigned int speed, unsigned int dist,
          unsigned char TTGBR, unsigned char SORT)
  {
     	this->setName(name);
		this->SetSpeed(speed);
		this->setDistance(dist);
		this->SetTimeToGoBeforeRest(TTGBR);
		this->SetFirstRestTime(SORT);
  }
};