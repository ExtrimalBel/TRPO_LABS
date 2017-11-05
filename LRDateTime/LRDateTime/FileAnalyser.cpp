#include "stdafx.h"
#include "FileAnalyser.h"

FileAnalyser::FileAnalyser(std::string filename)
{
	infile.open(filename);
	if (!infile.is_open()) throw Ex::CanNotOpenFile("Невозможно открыть файл");
}

void FileAnalyser::PrintStringWithThisData(Date d)
{
	std::string tmpstring;
	do
	{
		std::getline(infile, tmpstring);
		std::regex Expression("\\d{2}.\\d{2}.\\d{4}.*");
		std::regex SExpression("\\d{2}.\\d{2}.\\d{2}.*");
		if (std::regex_search(tmpstring, SExpression))
		{
			try
			{
				std::string DateStr;
				if (std::regex_search(tmpstring, Expression)) DateStr = tmpstring.substr(0, 10);
				else DateStr = tmpstring.substr(0, 8);
				Date b(DateStr);
			
				if (d == b) std::cout << tmpstring << std::endl;

			}
			catch (Ex::WrongDate &Ex)
			{
				continue;
			}
			
		}
	} while (!infile.eof());
}