// task5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

int main()
{
	bool wasExit = false;
	while (!wasExit)
	{
		string incomingData;
		int speed = 0;
		int angle = 0;
		cout << "Enter v0 (or type ‘exit’)>";
		cin >> incomingData;
		try
		{
			speed = stoi(incomingData);
		}
		catch(const exception&)
		{
			//если сюда попали, значит это точно не число, равнить с exit и return 0;
			
		}

	}

	cout << "Goodbye \n";
    return 0;
}

