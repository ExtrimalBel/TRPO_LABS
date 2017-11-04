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
		if (std::regex_search(tmpstring, Expression))
		{
			try
			{
				Date b(tmpstring.substr(0, 10));
			
				if (d == b) std::cout << tmpstring;

			}
			catch (Ex::WrongDate &Ex)
			{
				continue;
			}
			
		}
	} while (!infile.eof());
}