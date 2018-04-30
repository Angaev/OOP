#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <cctype>

void CountWordToStatistics(std::string const& word, std::map<std::string, size_t>& statisctic);

void PrintFrequency(std::map<std::string, size_t> const& statisctic);

void StringToLowerCase(std::string & line);