#pragma  once
#include "Exceptions.h"
#include <string>

class Date
{
public:
	int Day, Year, Mounth;
	Date(int d, int m, int y);
	Date(std::string DateStr);
	void CheckDate();
	bool operator==(const Date &a);

};