// LRDateTime.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Exceptions.h"
#include "Date.h"
#include "FileAnalyser.h"
// TODO корректно прописать проверку даты и поддржкусокращеных дат по типу d.m.yy
void FindDate(std::string Filename, Date CurrentDate);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите дату (10 символов)";
	std::string DateStr;
	std::getline(std::cin, DateStr);
	Date *b = NULL;
	try
	{
		b = new Date(DateStr);
	}
	catch (Ex::WrongDate &Ex)
	{
		std::cout << Ex.Message << std::endl;
		return -1;
	}
	std::cout << "введите имя файла в котором будем искать сообщения" << std::endl;
	std::string FileName;
	std::getline(std::cin, FileName);
	FindDate(FileName, *b);
	return 0;
}

void FindDate(std::string Filename, Date CurrentDate)
{
	try
	{
		FileAnalyser F(Filename);
		F.PrintStringWithThisData(CurrentDate);
	}
	catch (Ex::CanNotOpenFile &Ex)
	{
		std::cout << Ex.Message << std::endl;
	}
}

