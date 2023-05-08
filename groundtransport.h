#pragma once
#include "transport.h"

class groundtransport : public transport
{
  unsigned char time_to_go_before_rest;
  unsigned char first_rest_time;
  float second_rest_time;
protected:
  void SetTimeToGoBeforeRest(unsigned char t)
  {
    this->time_to_go_before_rest = t;
  }
  unsigned char GetTimeToGoBeforeRest()
  {
    return this->time_to_go_before_rest;
  }
  void SetFirstRestTime(unsigned char t)
  {
    this->first_rest_time = t;
  }
  unsigned char GetFirstRestTime()
  {
    return this->first_rest_time;
  }
  void SetSecondRestTime(float t)
  {
    this->second_rest_time = t;
  }
  float GetSecondRestTime()
  {
    return this->second_rest_time;
  }
public:
	groundtransport():groundtransport(ground) {}
	groundtransport(transport_type tr):transport("GroundTransport", ground){}
};
