#pragma once
#include <string>

	namespace Ex
	{
		class BaseException
		{
		public:
			std::string Message;
			BaseException(std::string Messsage);
		};

		class WrongDate : public BaseException
		{
		public:
			WrongDate(std::string Message);
		};

		class CanNotOpenFile : public BaseException
		{
		public:
			CanNotOpenFile(std::string Message);
		};
}