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
	if (DateStr.size() != 10) throw Ex::WrongDate("Неправильный формат даты");
	Year = atoi(DateStr.substr(6, 4).c_str());
	std::cout << DateStr.substr(0, 2);
	Day = atoi(DateStr.substr(0, 2).c_str());
	Mounth = atoi(DateStr.substr(3, 2).c_str());
}

void Date::CheckDate()
{
	int leapYear = Year % 4;

	if (Day < 1 || Day > 31)
	{
		throw Ex::WrongDate("Неправильная дата");
	}

	if (Mounth < 1 || Mounth > 12)
	{
		throw Ex::WrongDate("Неправильная дата");
	}

	if (Mounth == 2 && Day > 29 - leapYear)
	{
		throw Ex::WrongDate("Неправильная дата");
	}

	if (Day > 30 + Mounth % 2)
	{
		throw Ex::WrongDate("Неправильная дата");
	}
}

bool Date::operator==(const Date &a)
{
	if (a.Day == this->Day && a.Mounth == this->Mounth && a.Year == this->Year) return true;
	else return false;
}