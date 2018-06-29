#pragma once
#include "stdafx.h"
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool CanMakeSubword(const string& word, const string& subWord);

bool IsWordUsedBefore(const set<string> &userWords, const string& word);

void SetUserSkipMove(bool isFirstPlayerMove, bool& isFirstPlayerSkipMove, bool isSecondPlayerSkipMove);
