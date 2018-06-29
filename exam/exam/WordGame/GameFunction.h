#pragma once
#include "stdafx.h"
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

bool CanMakeSubword(const string& word, const string& subWord);

bool IsWordUsedBefore(const map<string, bool> &userWords, const string& word);

void SetUserSkipMove(bool isFirstPlayerMove, bool& isFirstPlayerSkipMove, bool isSecondPlayerSkipMove);

void AddUsedWord(map<string, bool> &userWords, const string& word, bool isFirstPlayerMove);