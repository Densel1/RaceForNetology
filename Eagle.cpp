
#include "Eagle.h"



float eagle::calcDriveTime()
{
  float way = GetDistance()*(1-getReduceCof());
  if (GetSpeed() == 0)  throw IsZeroException();
  return way / GetSpeed();
}
