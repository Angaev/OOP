// task5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

int main()
{
	bool wasExit = false;
	while (wasExit)
	{
		string incomingData;
		float speed = 0;
		float angle = 0;
		cout << "Enter v0 (or type ‘exit’)>";
		cin >> incomingData;
		try
		{
			speed = stoi(incomingData);
		}
		catch()
		{

		}

	}

	cout << "Goodbye \n";
    return 0;
}

