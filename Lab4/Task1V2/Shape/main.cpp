// Shape.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Point.h"
#include "ClineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "IShape.h"

using namespace std;

bool FindShape(string const& shapeName)
{
	if (shapeName == "lineSegment")
	{
		return true;
	}
	if (shapeName == "triagle")
	{
		return true;
	}
	if (shapeName == "rectagle")
	{
		return true;
	}
	if (shapeName == "circle")
	{
		return true;
	}


	return false;
}

vector<IShape> ReadShape(std::istream& input)
{
	string command;
	vector<IShape> shapeList;
	while (getline(input, command))
	{
		//1. взять первое слово
		auto position = command.find_first_of(" ");
		string shapeName = command.substr(0, position);
		if (!FindShape(shapeName))
		{
		}
		//2. если есть такая фигура то вызвать обработчик

	}

	return shapeList;
}

int main()
{
	ReadShape(cin);
    return 0;
}

