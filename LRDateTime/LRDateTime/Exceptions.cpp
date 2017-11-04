#include "stdafx.h"
#include "Exceptions.h"

namespace Ex
{
	BaseException::BaseException(std::string Messsage)
	{
		this->Message = Messsage;
	}

	WrongDate::WrongDate(std::string Message) : BaseException(Message) {}

	CanNotOpenFile::CanNotOpenFile(std::string Message) : BaseException(Message) {}
}