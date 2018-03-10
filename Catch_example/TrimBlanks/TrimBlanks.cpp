#include "stdafx.h"
#include "trimblanks.h"

std::string TrimBlanks(const std::string & str)
{
	size_t printableCharacterPosition = str.find_first_not_of(" ");
	if (printableCharacterPosition == std::string::npos)
	{
		return {};
	}
	size_t lastPrintableCharacterPosition = str.find_last_not_of(" ");
	return str.substr(printableCharacterPosition, lastPrintableCharacterPosition - printableCharacterPosition + 1);

}