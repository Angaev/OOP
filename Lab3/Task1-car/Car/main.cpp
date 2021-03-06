// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
using namespace boost;

void Info(CCar const& car)
{
	cout << "Engine - ";
	if (car.IsEngineOn())
	{
		cout << "On\n";
	}
	else
	{
		cout << "Off\n";
	}

	cout << "Direction - ";
	switch (car.GetDirection())
	{
		case Direction::REVERSE:
			{
			cout << "Reverse\n";
			}
		break;
		case Direction::STOP:
		{
			cout << "Stop\n";
		}
		break;
		case Direction::FORWARD:
		{
			cout << "Forward\n";
		}
		break;
	}

	cout << "Speed - " << car.GetSpeed() << "\n";
	
	cout << "Gear - " << car.GetTurnGear() << "\n";
}

void EngineOn(CCar &car)
{
	if (car.TurnOnEngine())
	{
		cout << "Engine was started\n";
	}
	else
	{
		cout << car.GetLastError();
	}
}

void EngineOff(CCar &car)
{
	if (car.TurnOffEngine())
	{
		cout << "Engine was stopped\n";
	}
	else
	{
		cout << car.GetLastError();
	}
}

void SetGear(int const gear, CCar &car)
{
	if (car.SetGear(gear))
	{
		cout << "Gear was set\n";
	}
	else
	{
		cout << car.GetLastError();
	}
}

void SetSpeed(int const speed, CCar &car)
{
	if (car.SetSpeed(speed))
	{
		cout << "Speed was set\n";
	}
	else
	{
		cout << car.GetLastError();
	}
}

int main()
{
	string command;
	CCar car;
	cout << "Enter command: \n>";
	while (getline(cin, command))
	{
		algorithm::to_lower(command);
		if (command == "info")
		{
			Info(car);
		}
		if (command == "engineon")
		{
			EngineOn(car);
		}
		if (command == "engineoff")
		{
			EngineOff(car);
		}
		if (command.find("setgear", 0) != std::string::npos)
		{
			int gear = 0;
			try
			{
				gear = stoi(command.substr(8));
				SetGear(gear, car);
			}
			catch(std::exception& e)
			{ 
				cout << e.what() << "\n";
			}
		}

		if (command.find("setspeed", 0) != std::string::npos)
		{
			int speed = 0;
			try
			{
				speed = stoi(command.substr(9));
				SetSpeed(speed, car);
			}
			catch (std::exception& e)
			{
				cout << e.what() << "\n";
			}
		}

		cout << ">";
	}
    return 0;
}

