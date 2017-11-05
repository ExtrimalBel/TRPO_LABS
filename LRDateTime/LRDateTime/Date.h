#pragma  once
#include "Exceptions.h"
#include <string>

class Date
{
	void InitialDate(std::string Datestr);
	int Day, Year, Mounth;
public:
	void PrintDate();
	Date(int d, int m, int y);
	Date(std::string DateStr);
	void CheckDate();
	bool operator==(const Date &a);


};