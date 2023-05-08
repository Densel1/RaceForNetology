#pragma once

#include <string>
#include "MyExceptions.h"

enum transport_type { unknown = 0, ground, air, ground_and_air };

class transport
{
private:
    std::string transportName;
    transport_type transportType;
    unsigned int speed;
    float driveTime;
    unsigned int distanceToGo;
public:
    transport() :transport("Transport", unknown) {}
    transport(std::string name, transport_type tr)
    {
        this->transportName = name;
        this->transportType = tr;
    }

    float GetDriveTime(); // возвращает время за которое проезжается дистанция
    void setDistance(int distance);
	transport_type GetTransportType()
	{
	  return transportType;
	}
    std::string GetName();

protected:

    virtual float calcDriveTime();
    unsigned int GetSpeed();
    void SetSpeed(int speed);
    unsigned int GetDistance();
	void setName(std::string);
};
