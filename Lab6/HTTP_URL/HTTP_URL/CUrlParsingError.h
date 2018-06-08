#pragma once
#include <string>

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(std::string const& errorMessage)
		: invalid_argument(errorMessage) {};
};
