#include <string>
#include <iostream>
#include <fstream>
#include "Exceptions.h"
#include "Date.h"
#include <regex>
class Date;
class FileAnalyser
{
	std::ifstream infile;
public:
	FileAnalyser(std::string filename);

	void PrintStringWithThisData(Date d);
};