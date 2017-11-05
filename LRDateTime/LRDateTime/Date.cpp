#include "stdafx.h"
#include "Date.h"
#include <iostream>
Date::Date(int d, int m, int y)
{
	Year = y;
	Mounth = m;
	Day = d;
	CheckDate();
}

Date::Date(std::string DateStr)
{
	InitialDate(DateStr);
	CheckDate();
}

void Date::PrintDate()
{
	std::cout << Day << "." << Mounth << "." << Year;
}
void Date::InitialDate(std::string Datestr)
{
	Day = atoi(Datestr.substr(0, 2).c_str());
	Mounth = atoi(Datestr.substr(3, 2).c_str());
	if (Datestr.size() == 10) Year = atoi(Datestr.substr(6,4).c_str());
	if (Datestr.size() == 8) Year = 1900 + atoi(Datestr.substr(6, 2).c_str()); // For short year write
	if (Datestr.size() != 8 && Datestr.size() != 10) throw Ex::WrongDate("Неправильный формат даты");
}
void Date::CheckDate()
{
	if (Day < 1) throw Ex::WrongDate("Неправильная дата");
	if (Mounth < 1 && Mounth >> 12) throw Ex::WrongDate("Неправильная дата");
	switch (Mounth)
	{
	case 1: case 3: case 5: case 8: case 10: case 12:

		if (Day > 31) throw Ex::WrongDate("Неправильная дата");
		break;
	case 2:
		if (!(Year % 400) || (!(Year % 4) && Year % 100)) // Сдесь проверяю год 
		{
			if (Day > 29) throw Ex::WrongDate("Неправильная дата");
		}
		else if (Day > 28) throw Ex::WrongDate("Неправильная дата");
		break;
	default:
		if (Day > 30) throw Ex::WrongDate("Неправильная дата");
	}
}

bool Date::operator==(const Date &a)
{
	if (a.Day == this->Day && a.Mounth == this->Mounth && a.Year == this->Year) return true;
	else return false;
}