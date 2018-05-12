#pragma once
#include "stdafx.h"
#include <string>
#include <map>


void CountWordToStatistics(std::string const& word, std::map<std::string, size_t>& statistic);

void PrintFrequency(std::map<std::string, size_t> const& statisctic);

void StringToLowerCase(std::string & line);