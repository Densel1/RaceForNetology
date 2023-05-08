
#pragma once

#include "groundtransport.h"

class fastCamel:public groundtransport
{
  unsigned char other_rest_time;
  
  
protected:
  float calcDriveTime() override;
  
  void SetOtherRestTime(unsigned int t)
  {
    this->other_rest_time = t;
  }
  
  unsigned int GetOtherRestTime()
  {
    return this->other_rest_time;
  }
  
public:
	fastCamel() :fastCamel("ֱûסענûי גונבכ‏ה",40,0,10,5,6.5,8) {};

  fastCamel(std::string name, unsigned int speed, unsigned int dist,
             unsigned char TTGBR, unsigned char SFRT, float SSRT,
			 unsigned int SORT)
  {
     	this->setName(name);
		this->SetSpeed(speed);
		this->setDistance(dist);
		this->SetTimeToGoBeforeRest(TTGBR);
		this->SetFirstRestTime(SFRT);
		this->SetSecondRestTime(SSRT);
		this->SetOtherRestTime(SORT);
  }
};

