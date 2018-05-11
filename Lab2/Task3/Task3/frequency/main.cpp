#include "stdafx.h"
#include "frequency.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string word;
	map <string, size_t> statisctic;
	while (cin >> word)
	{
		StringToLowerCase(word);
		CountWordToStatistics(word, statisctic);
	}

	PrintFrequency(statisctic);
    return 0;
}

