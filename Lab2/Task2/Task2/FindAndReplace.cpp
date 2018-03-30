#include "stdafx.h"
#include "../Task2/FindAndReplace.h"
#include <string>

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace)
{
	/*
		subject - искомая строка
		replace - на что заменить
		search - подстрока поиска
	*/
	std::string afterReplace = subject;
	
	size_t found = subject.find(search);
	if (found != std::string::npos)
	{
		afterReplace.replace(found, found + search.size(), replace);
	}

	return afterReplace;
}