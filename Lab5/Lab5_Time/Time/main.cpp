// Time.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Time.h"

using namespace std;

int main()
{

	try
	{
		CTime time(29, 30, 20);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << "\n";
	}

	CTime time(11113);
	cout << time.GetHours() << " " << time.GetMinutes() << " " << time.GetSeconds() << "\n";

	try
	{
		CTime time(86399 + 10);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << "\n";
	}


    return 0;
}

