
#pragma once

#include "camel.h"

class GoEverywhereBoots: public camel
{
public:
  GoEverywhereBoots():GoEverywhereBoots("Ботинки-вездеходы",6,1,60,10,5){}
  GoEverywhereBoots(std::string name, unsigned int speed, unsigned int dist,
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
