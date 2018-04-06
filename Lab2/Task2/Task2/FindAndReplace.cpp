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
	std::string afterReplace;
	size_t position = 0;

	while (position < subject.length())
	{
		size_t found = subject.find(search, position);
		afterReplace.append(subject, position, found - position);
		position = found;
		if (position != std::string::npos)
		{ 
			afterReplace.append(replace);
			position += search.length();
		}

	}

	return afterReplace;
}