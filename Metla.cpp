
#include "Metla.h"



float metla::calcDriveTime()
{
  int j = 0;
  float i = 0;
  j = GetDistance()/1000; //4
  i = static_cast<float>(j)/100;
  if (GetSpeed() == 0)  throw IsZeroException();
  return  (GetDistance() *(1 - i)) / GetSpeed();
}
