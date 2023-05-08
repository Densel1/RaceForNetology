#pragma once

#include "airtransport.h"

class metla:public airtransport
{

protected:
  float calcDriveTime() override;

public:
  metla():metla("Метла",20,0,1){}
  metla(std::string name, int speed, int dist1, float cof1):airtransport()
  {
    this -> setName(name);
    this -> SetSpeed(speed);
	this -> setDistance(dist1);
	this -> setReduceCof(cof1/100);
  }
};