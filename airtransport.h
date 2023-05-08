#pragma once
#include "transport.h"

class airtransport:public transport
{
private:
  unsigned int dist1;
  float reduce_cof1;
protected:
  float getReduceCof()
  {
    return this->reduce_cof1;
  }
  
  void setReduceCof(float cof)
  {
    this->reduce_cof1 = cof;
  }
  
  unsigned int getDist()
  {
    return this -> dist1;
  }
  
  void setDist(unsigned int dist)
  {
    this -> dist1 = dist;
  }


public:
  airtransport():airtransport(air){}
  airtransport(transport_type tr):transport("AirTransport", air){}
};