// CMyArray.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMyArray.h"
#include <string>

using namespace std;

int main()
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);

	string sum{};
	for_each(arr0.begin(), arr0.end(), [sum](auto & item) {sum += item});
	if (sum == "hello World"s)
	{
		cout << "ok \n";
	}
	else
	{
		cout << "not ok\n";
	}
    return 0;
}

