// WordGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GameFunction.h"

constexpr bool firstPlayer = false;
constexpr bool secondPlayer = true;

using namespace std;

struct UserScore
{
	size_t firstUserScore = 0;
	size_t secondUserScore = 0;
};

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
	cin >> baseWord;

	bool isFirstPlayerSkipMove = false;
	bool isSecondPlayerSkipMove = false;
	bool isFirstPlayerMove = true;
	
	UserScore userScore;
	
	set<string>usedWords;
	cin.ignore();

	do
	{
		cout << "Player " << ((isFirstPlayerMove) ? 1 : 2) << ">";
		string playerWord;
		getline(cin, playerWord);
		if (!playerWord.empty())
		{
			//можно ли его использовать
			if (CanMakeSubword(baseWord, playerWord))
			{
				//проверить не было ли уже этого
				if (!IsWordUsedBefore(usedWords, playerWord))
				{
					//засчитать это слово (добавить в его набор слов, добавить баллы, переключит флаг хода пользователя)
					usedWords.insert(playerWord);
					if (isFirstPlayerMove)
					{
						userScore.firstUserScore += playerWord.size();
						isFirstPlayerSkipMove = false;
					}
					else
					{
						userScore.secondUserScore += playerWord.size();
						isSecondPlayerSkipMove = false;
					}
					isFirstPlayerMove = !isFirstPlayerMove;
				}
				else
				{
					//попробовать снова
					cout << "This word has already been entered. Enter another\n";
					continue;
				}
			}
			else
			{
				//повторить слово
				cout << "You can't make this word from " << baseWord<<". Enter another\n";
				continue;
			}
		}
		else
		{
			SetUserSkipMove(isFirstPlayerMove, isFirstPlayerSkipMove, isSecondPlayerSkipMove);
			isFirstPlayerMove = !isFirstPlayerMove;
		}

	} while (true);//(!(isFirstPlayerSkipMove && isSecondPlayerSkipMove)); //пока true

	cout << "Game Over";
	return 0;
}
