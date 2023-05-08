#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include "camel.h"
#include "fastCamel.h"
#include "GoEverywhereBoots.h"
#include "kentavr.h"
#include "KoverSamolet.h"
#include "Eagle.h"
#include "Metla.h"

#define size 8

#pragma execution_character_set( "utf-8" )

class race
{
private:
	unsigned char pos[size];
	std::string name[size];
	float time[size];
public:

	//    const unsigned char size = 8;
	std::string result[size];
	race(unsigned int distance)
	{
		this->distance = distance;
	}


	unsigned int distance;

	//    std::string getName(const unsigned char pos){return name[pos];}
	//    std::string getTime(const unsigned char pos){return time[pos];}

	std::string operator[](unsigned char TS_count);


	bool air_transport(const unsigned char selection);
	bool ground_transport(const unsigned char selection);


	std::string save_result(transport& tr, const unsigned char TS_count);


	std::string initBoots(std::string&, unsigned char& TS_count);
	std::string initCamel(std::string&, unsigned char& TS_count);
	std::string initFastCamel(std::string&, unsigned char& TS_count);
	std::string initKentavr(std::string&, unsigned char& TS_count);
	std::string initEagle(std::string&, unsigned char& TS_count);
	std::string initKoverSamolet(std::string&, unsigned char& TS_count);
	std::string initMetla(std::string&, unsigned char& TS_count);
	void addTransportToString(std::string& sType, const int trType);
	void sort(int);

};