#pragma once
#include <string>
#include <exception>
#include "groundtransport.h"

class camel :public groundtransport
{
protected:
  float calcDriveTime() override;
public:
	camel():camel("Верблюд",10,1000,30,5,8) {}
    camel(std::string name, unsigned int speed, unsigned int dist,
             unsigned char TTGBR, unsigned char SFRT, unsigned char SSRT)
    {
     	this->setName(name);
		this->SetSpeed(speed);
		this->setDistance(dist);
		this->SetTimeToGoBeforeRest(TTGBR);
		this->SetFirstRestTime(SFRT);
		this->SetSecondRestTime(SSRT);
    }
};
