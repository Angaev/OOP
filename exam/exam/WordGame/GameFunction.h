#pragma once
#include "stdafx.h"
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

struct UserScore
{
	size_t firstUserScore = 0;
	size_t secondUserScore = 0;
};


bool CanMakeSubword(const string& word, const string& subWord);

bool IsWordUsedBefore(const map<string, bool> &userWords, const string& word);

void SetUserSkipMove(bool isFirstPlayerMove, bool& isFirstPlayerSkipMove, bool& isSecondPlayerSkipMove);

void AddUsedWord(map<string, bool> &userWords, const string& word, bool isFirstPlayerMove);

void PrintPlayerScore(bool isFirstPlayer, const UserScore& userScore);

void PrintPlayerWordList(bool isFirstPlayer, map<string, bool>& userWords);

void PrintWinnerMessage(const UserScore& userScore);

void AddScoreToPlayer(UserScore& userScore, bool isFirstPlayer, size_t score);

void FlipPlayerSkipMove(bool isFirstPlayer, bool& isPlayerSkipMove);