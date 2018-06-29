#include "stdafx.h"
#include "GameFunction.h"


bool CanMakeSubword(const string& word, const string& subWord)
{
	map<char, size_t> letterStatistic; // разобранное слово

	//todo круто было бы не использовать for
	for (size_t i = 0; i != word.size(); ++i)
	{
		++letterStatistic[word[i]];
	}

	for (size_t i = 0; i != subWord.size(); ++i)
	{
		auto it = letterStatistic.find(subWord[i]);
		//если нашел 
		if (it != letterStatistic.end())
		{
			//проверить, что еще есть буквы
			if ((it->second) > 0)
			{
				//и вычесть
				--letterStatistic[subWord[i]];
			}
			else
			{
				return false;
			}
		}
		else
		{
			//не нашел
			return false;
		}
	}
	return true;
}

bool IsWordUsedBefore(const map<string, bool> &userWords, const string& word)
{

	auto search = userWords.find(word);
	if (search != userWords.end())
	{
		return true;
	}
	return false;
}

void SetUserSkipMove(bool isFirstPlayerMove, bool & isFirstPlayerSkipMove, bool isSecondPlayerSkipMove)
{
	if (isFirstPlayerMove)
	{
		isFirstPlayerSkipMove = true;
	}
	else
	{
		isSecondPlayerSkipMove = true;
	}
}

void AddUsedWord(map<string, bool>& userWords, const string & word, bool isFirstPlayerMove)
{
	pair<string, bool> data = { word, isFirstPlayerMove };
	userWords.insert(data);
}

