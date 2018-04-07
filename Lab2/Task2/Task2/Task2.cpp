// Task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Wrong count arguments. Example " ;
		return 1;
	}
	string subject;
	getline(cin, subject);
	cout << FindAndReplace(subject, argv[1], argv[2]);
	return 0;
}

