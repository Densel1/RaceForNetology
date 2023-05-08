#pragma once

#include "airtransport.h"

class eagle:public airtransport
{
private:
protected:
  float calcDriveTime() override;

public:
  eagle():eagle("Орел",8,0,6){}
  eagle(std::string name, int speed, int distance, float cof1):airtransport()
  {
    this -> setName(name);
    this -> SetSpeed(speed);
	this -> setDistance(distance);
	this -> setReduceCof(cof1/100);
  }
};