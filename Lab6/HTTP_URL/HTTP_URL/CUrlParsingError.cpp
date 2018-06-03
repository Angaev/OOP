#include "stdafx.h"
#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string errorMessage)
{
	throw std::invalid_argument(errorMessage);
}
