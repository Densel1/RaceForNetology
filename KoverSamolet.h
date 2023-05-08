#pragma once

#include "airtransport.h"

class koverSamolet:public airtransport
{
private:
  unsigned int dist2;
  unsigned int dist3;
  float reduce_cof2;
  float reduce_cof3;
protected:
  float calcDriveTime() override;
  
  float getReduceCof2()
  {
    return this->reduce_cof2;
  }
  void setReduceCof2(float cof)
  {
    this->reduce_cof2 = cof;
  }
  float getReduceCof3()
  {
    return this->reduce_cof3;
  }
  void setReduceCof3(float cof)
  {
    this->reduce_cof3 = cof;
  }
  
  unsigned int getDist2()
  {
    return this -> dist2;
  }
  
  void setDist2(unsigned int dist)
  {
    this -> dist2 = dist;
  }

  unsigned int getDist3()
  {
    return this -> dist3;
  }
  
  void setDist3(unsigned int dist)
  {
    this -> dist3 = dist;
  }

public:
  koverSamolet():koverSamolet("Ковер самолет",10,0,1000,5000,10000,3,10,5){}
  koverSamolet(std::string name, int speed, int distance, int dist1, int dist2, int dist3, float cof1, float cof2, float cof3):airtransport()
  {
    this -> setName(name);
    this -> SetSpeed(speed);
	this -> setDistance(distance);
	this -> setDist(dist1);
	this -> setDist2(dist2);
	this -> setDist3(dist3);
	this ->  setReduceCof(cof1/100);
	this -> setReduceCof2(cof2/100);
	this -> setReduceCof3(cof3/100);
  }
};