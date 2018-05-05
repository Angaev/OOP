#include "stdafx.h"
#include "CCar.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const vector < pair<int, int>> speedRange =
	{
		{-20, 0},
		{0, 30},
		{20, 50},
		{30, 60},
		{40, 90},
		{50, 150}
	};

bool IsBetween(int const numb, pair<int, int> range)
{
	if ((numb >= range.first) && (numb <= range.second))
	{
		return true;
	}
	return false;
}

void RangeErrorMessage(string &lastError)
{
	lastError = "Out of speed range\n";
}

bool CCar::IsEngineOn() const
{
	return m_engineStatus;
}

bool CCar::TurnOnEngine()
{
	if (!IsEngineOn())
	{
		m_engineStatus = true; 
		return true;
	}
	else
	{
		m_lastError = "Engine already turn on\n";
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if (IsEngineOn() && (GetTurnGear() == 0) && (GetSpeed() == 0))
	//двигатель включен и передача нейтраль
	{
		m_engineStatus = false;
		return true;
	}
	else
	{
		if (GetTurnGear() != 0)
		{
			m_lastError = "Set 0 gear before turn off engine\n";
			return false;
		}
		if (GetSpeed() != 0)
		{
			m_lastError = "Speed must be 0 before turn off engine\n";
			return false;
		}
		m_lastError = "Engine already turn off\n";
		return false;
	}
}

bool CCar::SetGear(int const gear)
{
	if (gear < -1 || gear > 5)
	{
		m_lastError = "wrong gear number \n";
		return false;
	}

	if (!IsEngineOn() && (gear != 0))
	{
		m_lastError = "Turn on engine before set gear \n";
		return false;
	}
	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}

	if (gear == -1 && IsBetween(m_speed, speedRange[0]))
	{
		if (GetTurnGear() != 0)
		{
			m_lastError = "Set 0 gear before \n";
			return false;
		}
		m_gear = gear;
		return true;
	}
	if (gear == 1 && IsBetween(m_speed, speedRange[1]))
	{
		m_gear = gear;
		return true;
	}
	if (gear == 2 && IsBetween(m_speed, speedRange[2]))
	{
		m_gear = gear;
		return true;
	}
	if (gear == 3 && IsBetween(m_speed, speedRange[3]))
	{
		m_gear = gear;
		return true;
	}
	if (gear == 4 && IsBetween(m_speed, speedRange[4]))
	{
		m_gear = gear;
		return true;
	}
	if (gear == 5 && IsBetween(m_speed, speedRange[5]))
	{
		m_gear = gear;
		return true;
	}
	m_lastError = "Can't set gear\n";
	return false;
}

int CCar::GetTurnGear() const
{
	return m_gear;
}

bool CCar::SetSpeed(int const speed)
{
	if (speed < 0)
	{
		m_lastError = "Incorrect speed\n";
		return false;
	}

	if (!IsEngineOn())
	{
		m_lastError = "Turn on engine before set speed\n";
		return false;
	}
	if (GetTurnGear() == -1)
	{
		if (IsBetween((speed * -1), speedRange[0]))
		{
			m_speed = speed * -1;
			return true;
		}
		RangeErrorMessage(m_lastError);
		return false;
	}
	
	if (GetTurnGear() == 1)
	{
		if (IsBetween(speed, speedRange[1]))
		{
			m_speed = speed;
			return true;
		}
		RangeErrorMessage(m_lastError);
		return false;
	}

	if (GetTurnGear() == 2)
	{
		if (IsBetween(speed, speedRange[2]))
		{
			m_speed = speed;
			return true;
		}
		RangeErrorMessage(m_lastError);
		return false;
	}

	if (GetTurnGear() == 3)
	{
		if (IsBetween(speed, speedRange[3]))
		{
			m_speed = speed;
			return true;
		}
		RangeErrorMessage(m_lastError);
		return false;
	}

	if (GetTurnGear() == 4)
	{
		if (IsBetween(speed, speedRange[4]))
		{
			m_speed = speed;
			return true;
		}
		RangeErrorMessage(m_lastError);
		return false;
	}

	if (GetTurnGear() == 5)
	{
		if (IsBetween(speed, speedRange[5]))
		{
			m_speed = speed;
			return true;
		}
		RangeErrorMessage(m_lastError);
		return false;
	}

	if (GetTurnGear() == 0)
	{
		if (speed <= abs(m_speed))
		{
			if (GetDirection() == Direction::REVERSE)
			{
				m_speed = speed * -1;
				return true;
			}
			m_speed = speed;
			return true;
		}
		m_lastError = "Speed can only be reduced\n";
		return false;
	}
	return false;
}

int CCar::GetSpeed() const
{
	return abs(m_speed);
}

Direction CCar::GetDirection() const
{
	Direction direction;
	if (m_speed < 0)
	{
		direction = Direction::REVERSE;
	}
	if (m_speed == 0)
	{
		direction = Direction::STOP;
	}
	if (m_speed > 0)
	{
		direction = Direction::FORWARD;
	}
	return direction;
}

std::string CCar::GetLastError()
{
	return m_lastError;
}
