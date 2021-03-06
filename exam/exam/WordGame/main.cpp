// WordGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GameFunction.h"

constexpr bool firstPlayer = true;
constexpr bool secondPlayer = false;

using namespace std;

int main()
{
	/*
	Написать программу, в начале которой запрашивается "слово" из которого надо будет составлять слова
	Почередно игрок 1 и игрок 2 вводят слова, которые они составили из букв этого слова (программа полагается на честность игроков)
	Каждому игроку начисляется столько баллов, сколько букв в его слове
	Если игрок ввел пустую строку, он пропускает ход
	Если оба игрока последовательно ввели пустую строку, игра завершается
	Если игрок ввел слово, которое составить нельзя из букв исходного, он должен ввести другое слово
	Если игрок ввел слово, которое уже было принято, он должен ввести другое слово

	Перед выходом программа выводит слова, введенные каждым игроком и сумму набранных им баллов, и объявляет победителя

	Пример диалога:
	Enter a word: телеграмма
	Player 1> грамм
	Player 2> рама
	Player 1> грамм
	This word has already been entered. Enter another
	Player 1> лама
	Player 2> телега
	Player 1> телефон
	You can't make this word from "телеграмма". Enter another
	Player 1>
	Player 2>
	Game over.
	Player 1 words (9 points):
	грамм 5
	лама 4
	Player 2 words (10 points):
	рама 4
	телега 6
	Player 2 have won!
	*/

	cout << "Enter a word:";
	string baseWord;
	getline(cin, baseWord);


	bool isFirstPlayerSkipMove = false;
	bool isSecondPlayerSkipMove = false;
	bool isFirstPlayerMove = true;
	
	UserScore userScore;
	
	map<string, bool>usedWords;

	do
	{
		cout << "Player " << ((isFirstPlayerMove) ? 1 : 2) << ">";
		string playerWord;
		getline(cin, playerWord);
		if (!playerWord.empty())
		{
			if (CanMakeSubword(baseWord, playerWord))
			{
				if (!IsWordUsedBefore(usedWords, playerWord))
				{
					AddUsedWord(usedWords,playerWord,isFirstPlayerMove);

					AddScoreToPlayer(userScore, isFirstPlayerMove, playerWord.size());

					if (isFirstPlayerMove)
					{
						isFirstPlayerSkipMove = false;
					}
					else
					{
						isSecondPlayerSkipMove = false;
					}
					isFirstPlayerMove = !isFirstPlayerMove;
				}
				else
				{
					cout << "This word has already been entered. Enter another\n";
					continue;
				}
			}
			else
			{
				cout << "You can't make this word from " << baseWord<<". Enter another\n";
				continue;
			}
		}
		else
		{
			SetUserSkipMove(isFirstPlayerMove, isFirstPlayerSkipMove, isSecondPlayerSkipMove);
			isFirstPlayerMove = !isFirstPlayerMove;
		}

	} while (!(isFirstPlayerSkipMove && isSecondPlayerSkipMove)); 

	cout << "Game Over\n";
	PrintPlayerScore(firstPlayer, userScore);
	PrintPlayerWordList(firstPlayer, usedWords);

	PrintPlayerScore(secondPlayer, userScore);
	PrintPlayerWordList(secondPlayer, usedWords);


	PrintWinnerMessage(userScore);
	return 0;
}
