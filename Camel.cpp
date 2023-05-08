
#include "Camel.h"


float camel::calcDriveTime()
{
  float clock = 0;
  unsigned int way = 0;
  float i = 0;
  for (clock; way < GetDistance(); clock += GetTimeToGoBeforeRest(), ++i)
  {
		// ���� = ����0 + ��������*�����
		way += GetSpeed() * GetTimeToGoBeforeRest();

		clock+=i==1? GetFirstRestTime() :
			   i>1? GetSecondRestTime() : 0;
  }
	// ������� ���������� �������
  if (GetSpeed() == 0)  throw IsZeroException();
  clock -= (static_cast<float>(way) - GetDistance())/ GetSpeed();
  return clock;
}