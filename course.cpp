

#include <iostream>
#include <string>
#include <Windows.h>
#include "camel.h"
#include "fastCamel.h"
#include "GoEverywhereBoots.h"
#include "kentavr.h"
#include "KoverSamolet.h"
#include "Eagle.h"
#include "Metla.h"
#include "race.h"
#include "MyExceptions.h"

#pragma execution_character_set( "utf-8" )

using std::cout;
using std::cin;
using std::string;
using std::endl;


string save_result(transport& tr, const unsigned char TS_count)
{

	string TS_count_string = std::to_string(TS_count);

	string DriveTime = std::to_string(tr.GetDriveTime());

	string str = TS_count_string + "." + tr.GetName() +
		". Время: " + DriveTime + "\n";
	return str;
}

void initGroundTransport(race& r, unsigned char& TS_count, const unsigned char selection, string& reg_transport)
{
	switch (selection)
	{
	case '1':
	{
		r.initBoots(reg_transport, TS_count);
		break;
	}

	case '3':
	{
		r.initCamel(reg_transport, TS_count);
		break;
	}

	case '4':
	{
		r.initKentavr(reg_transport, TS_count);
		break;
	}
	case '6':
	{
		r.initFastCamel(reg_transport, TS_count);

		break;
	}
	}

}

void initAirTransport(race& r, unsigned char& TS_count, const unsigned char selection, string& reg_transport)
{
	switch (selection)
	{
	case '2':
	{
		r.initMetla(reg_transport, TS_count);
		break;
	}
	case '5':
	{
		r.initEagle(reg_transport, TS_count);
		break;
	}

	case '7':
	{
		r.initKoverSamolet(reg_transport, TS_count);
		break;
	}
	}
}


void regGroungTransport(race& r, int trType, unsigned char& TS_count, int& distance)
{
	unsigned char selection = 0;
	string reg_transport = "";
	string sType;

	r.addTransportToString(sType, trType); 	// Подготовка строки с видом гонки для вывода на консоль
	do {
		switch (trType)
		{
		case ground:
		{
			if (r.air_transport(selection))
				cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n" << endl;
			else if (r.ground_transport(selection))
			{
				if (TS_count == 0)
				{
					reg_transport = "Зарегистрированные транспортные средства: ";
				}
				TS_count++;
				if(TS_count>=8) throw  IsResultException();
				if (TS_count > 1) reg_transport += ", ";
				initGroundTransport(r, TS_count, selection, reg_transport);
			}
			break;
		}
		case air:
		{
			if (r.ground_transport(selection))
				cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
			else if (r.air_transport(selection))
			{
				if (TS_count == 0)
				{
					reg_transport = "Зарегистрированные транспортные средства: ";
				}
				TS_count++;
				if (TS_count >= 8) throw IsResultException();
				if (TS_count > 1) reg_transport += ", ";
				initAirTransport(r, TS_count, selection, reg_transport);
			}
			break;
		}
		case ground_and_air:
		{
			if (r.ground_transport(selection) || r.air_transport(selection))
			{
				if (TS_count == 0)
				{
					reg_transport = "Зарегистрированные транспортные средства: ";
				}
				TS_count++;
				if (TS_count >= 8) throw  IsResultException();
				if (TS_count > 1) reg_transport += ", ";
				initGroundTransport(r, TS_count, selection, reg_transport);
				initAirTransport(r, TS_count, selection, reg_transport);
			}
			break;
		}
		}
		cout << "Гонка для " << sType << "транспорта. Расстояние: " << distance << endl << reg_transport << endl;
		cout << "1.Ботинки-вездеходы" << endl;
		cout << "2.Метла" << endl;
		cout << "3.Верблюд" << endl;
		cout << "4.Кентавр" << endl;
		cout << "5.Орел" << endl;
		cout << "6.Верблюд-быстроход" << endl;
		cout << "7.Ковер-самолет" << endl;
		cout << "0.Закончить регистрацию" << endl;
		cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		cin >> selection;
		cout << endl;
	} while ((selection != '0'));
}

int main()
{
	SetConsoleOutputCP(65001);
	int distance = 4500;
	int trType;
	unsigned char trCnt;
	unsigned char TS_count = 0;
	try {
		cout << "Добро пожаловать в гоночный симулятор!" << endl;
		do {
			//			string result[8];
			TS_count = 0;
			cout << "1. Гонка для наземного транспорта\n2. Гонка для воздушного транспорта\n3. Гонка для наземного и воздушного транспорта\nВыберите тип гонки: ";
			cin >> trType;


			cout << endl;
			cout << "Укажите длину дистанции (должна быть положительна): ";
			cin >> distance;
			cout << endl;
			if (distance < 0) throw IsNegativeException();
			race r(distance);

			string mes1 = "2.Начать гонку\n";
			do {
				if (TS_count < 2) cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства\n";
				cout << "1.Зарегистрировать транспорт\n";
				if (TS_count > 1) cout << mes1;
				cout << "Выберите действие: ";
				cin >> trCnt;
				cout << endl;
				if (trCnt == '1')
				{
					regGroungTransport(r, trType, TS_count, distance);
				}
			} while ((TS_count < 2) || (trCnt == '1'));
			cout << endl;
			cout << "Результаты гонки: " << endl;
			r.sort(TS_count);
			for (int i = 1; i <= TS_count; ++i)
			{
				cout << r[i];
			}
			cout << endl;

			cout << "1. Провести еще одну гонку" << endl;
			cout << "2. Выйти" << endl;
			cout << "Выберите действие: ";
			cin >> trCnt;

			if (trCnt == '2') return 0;
			else if (trCnt == '1') continue;
		} while (true);
	}
	catch (IsZeroException x) { cout << "Ошибка деления на 0" << endl; }
	catch (IsResultException x) { cout << "Ошибка: Выход за пределы массива" << endl; }
	catch (IsNegativeException x) { cout << "Ошибка: отрицательное число" << endl; }
}

