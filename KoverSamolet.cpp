
#include "KoverSamolet.h"



float koverSamolet::calcDriveTime()
{
  float way = 0;
  if (GetSpeed() == 0)  throw IsZeroException();
//	|---
  if(GetDistance() < getDist())  return getDist()/GetSpeed();
//	|-----|_____|_____|_____
  else way = getDist();

 
//	|-----|---
  if(GetDistance() < getDist2())
  {
    way += (GetDistance() - getDist()) * (1-getReduceCof());
    return way / GetSpeed();
  }//	|-----|-----|_____|_____
  else way += (getDist2() - getDist())*(1- getReduceCof());


  if(GetDistance() < getDist3())
  {
//	|-----|-----|---
    way += (GetDistance() - getDist2()) * (1-getReduceCof2());
    return way / GetSpeed();
  }
  else{
//	|-----|-----|-----|---
    way += (getDist3() - getDist2())*(1- getReduceCof2());
	way += (GetDistance() - getDist3()) * (1-getReduceCof3());
  }
  return way / GetSpeed();
}
