#include "race.h"



using std::cout;
using std::cin;
using std::string;
using std::endl;


bool race::air_transport(const unsigned char selection)
{
	if ((selection == '2') || (selection == '5') || (selection == '7'))
	{
		return true;
	}
	return false;
}

bool race::ground_transport(const unsigned char selection)
{
	if ((selection == '1') || (selection == '3') || (selection == '4') || (selection == '6'))
	{
		return true;
	}
	return false;
}


std::string race::save_result(transport& tr, const unsigned char TS_count)
{
    this -> pos[TS_count] = TS_count;
    this -> name[TS_count] = tr.GetName();
    this -> time[TS_count] = tr.GetDriveTime();
    
	return "";
}


std::string race::initBoots(string& reg_transport, unsigned char& TS_count)
{
	GoEverywhereBoots goEverywhereBoots("Ботинки-вездеходы", 6, distance, 60, 10, 5);
	reg_transport += goEverywhereBoots.GetName();
	return save_result(goEverywhereBoots, TS_count);
}


std::string race::initCamel(string& reg_transport, unsigned char& TS_count)
{
	camel Verblud("Верблюд", 10, distance, 30, 5, 8);
	reg_transport += Verblud.GetName();
	return save_result(Verblud, TS_count);
}

std::string race::initFastCamel(string& reg_transport, unsigned char& TS_count)
{
	fastCamel FastVerblud("Быстрый верблюд", 40, distance, 10, 5, 6.5, 8);
	reg_transport += FastVerblud.GetName();
    return save_result(FastVerblud, TS_count);
}

std::string race::initKentavr(string& reg_transport, unsigned char& TS_count)
{
	kentavr Kentavr("Кентавр", 15, distance, 8, 2);
	reg_transport += Kentavr.GetName();
	return save_result(Kentavr, TS_count);
}

std::string race::initEagle(string& reg_transport, unsigned char& TS_count)
{
	eagle Eagle("Орел", 8, distance, 6);
	reg_transport += Eagle.GetName();
	return save_result(Eagle, TS_count);
}

std::string race::initKoverSamolet(string& reg_transport, unsigned char& TS_count)
{
	koverSamolet KoverSamolet("Ковер-самолет", 10, distance, 1000, 5000, 10000, 3, 10, 5);
	reg_transport += KoverSamolet.GetName();
	return save_result(KoverSamolet, TS_count);
}


std::string race::initMetla(string& reg_transport, unsigned char& TS_count)
{
	metla Metla("Метла", 20, distance, 1);
	reg_transport += Metla.GetName();
	return save_result(Metla, TS_count);
}


void race::addTransportToString(string &sType, const int trType)
{
	switch (trType)
	{
	case ground:
		sType = "наземного ";
		break;

	case air:
		sType = "воздушного ";
		break;

	case ground_and_air:
		sType = "наземного и воздушного ";
		break;
	}
}

string race::operator[](unsigned char TS_count)
{
	if((1>TS_count)&&(TS_count>8)) throw IsResultException();
	std::string TS_count_string = std::to_string(TS_count);
	std::string DriveTime = std::to_string(time[TS_count]);
	std::string str = TS_count_string + "." + name[TS_count] +
		". Время: " + DriveTime + "\n";
	return str;
}


void race::sort(int sz)
{
    sz = sz>size?size:sz;
	bool change = false;
	do {
		change = false;
		float t;
        string s;
		for (int i = 1; i <= sz; ++i)
		{
			if (time[i - 1] > time[i])
			{
				t = time[i - 1];
                s = name[i - 1];
				time[i - 1] = time[i];
				name[i - 1] = name[i];
				time[i] = t;
				name[i] = s;
				change = true;
			}
		}
	} while (change);
}
