#include "stdafx.h"
#include "Time.h"
#include <stdexcept>

constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned SECONDS_IN_DAY = 86400;
constexpr unsigned ONE_SECOND = 1;

constexpr unsigned HOURS_IN_DAY = 24;
constexpr unsigned MINUTES_IN_HOUR = 60;

unsigned PreventOverFlowSecond(unsigned timeStamp)
{
	return timeStamp % SECONDS_IN_DAY;
}

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (hours >= HOURS_IN_DAY || minutes >= MINUTES_IN_HOUR || seconds >= SECONDS_IN_MINUTE)
	{
		throw std::invalid_argument("Invalid hour, minute or (and) second value");
	}

	m_timestamp = hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
}

CTime::CTime(unsigned timeStamp) 
{
	if (timeStamp >= SECONDS_IN_DAY)
	{
		throw std::invalid_argument("Invalid hour, minute or (and) second value");
	}
	m_timestamp = timeStamp;
}

unsigned CTime::GetHours() const
{
	return m_timestamp / SECONDS_IN_HOUR;
}

unsigned CTime::GetMinutes() const
{
	return m_timestamp / SECONDS_IN_MINUTE - (m_timestamp / SECONDS_IN_HOUR) * SECONDS_IN_MINUTE;
}

unsigned CTime::GetSeconds() const
{
	return m_timestamp % SECONDS_IN_MINUTE;
}

unsigned CTime::GetTimeStamp() const
{
	return m_timestamp;
}

//префиксный инкремент
CTime & CTime::operator++()
{
	++m_timestamp;
	if (m_timestamp >= SECONDS_IN_DAY)
	{
		m_timestamp = m_timestamp - SECONDS_IN_DAY;
	}
	return *this;
}

//постфиксный инкремент
CTime const CTime::operator++(int)
{
	CTime tempTime = m_timestamp;
	m_timestamp++;
	if (m_timestamp >= SECONDS_IN_DAY)
	{
		m_timestamp = m_timestamp - SECONDS_IN_DAY;
	}
	return tempTime;
}

//префиксный декремент
CTime & CTime::operator--()
{
	if (m_timestamp == 0)
	{
		m_timestamp = SECONDS_IN_DAY - ONE_SECOND;
	}
	else
	{
		--m_timestamp;
	}
	return *this;
}

//постфиксный декремент
CTime const CTime::operator--(int)
{
	CTime tempTime = m_timestamp;
	if (m_timestamp == 0)
	{
		m_timestamp = SECONDS_IN_DAY - ONE_SECOND;
	}
	else
	{
		--m_timestamp;
	}
	return tempTime;
}

//бинарное сложение времени
CTime CTime::operator+(CTime const & time2) const
{
	unsigned sum = m_timestamp + time2.GetTimeStamp();
	return CTime (PreventOverFlowSecond(sum));
}

CTime CTime::operator-(CTime const & time2) const
{
	unsigned difference = 0;
	if (m_timestamp < time2.m_timestamp)
	{
		difference = SECONDS_IN_DAY - (time2.m_timestamp - m_timestamp);
	}
	else
	{
		difference = m_timestamp - time2.GetTimeStamp();
	}
	return CTime(difference);
}

CTime & CTime::operator+=(CTime const & sumTime)
{
	auto before = m_timestamp;

	m_timestamp = PreventOverFlowSecond(before + sumTime.m_timestamp);

	return *this;
}

CTime & CTime::operator-=(CTime const & subTime)
{
	auto before = m_timestamp;

	if (subTime.m_timestamp > before)
	{
		m_timestamp = SECONDS_IN_DAY - (subTime.m_timestamp - m_timestamp);
		return *this;
	}

	m_timestamp = before - subTime.m_timestamp;
	return *this;

}

CTime const CTime::operator*(unsigned number) const
{
	unsigned resultmultiply = m_timestamp * number;
	return CTime(PreventOverFlowSecond(resultmultiply));
}


CTime const CTime::operator / (unsigned number) const
{
	if (number == 0)
	{
		throw std::invalid_argument("Invalid operation. Division by zero");
	}

	return CTime(m_timestamp / number);
}

unsigned CTime::operator/(CTime const & time) const
{
	if (time.m_timestamp == 0)
	{
		throw std::invalid_argument("Invalid operation. Division by zero");
	}

	return (m_timestamp / time.m_timestamp);
}

CTime & CTime::operator*=(unsigned number)
{
	m_timestamp = PreventOverFlowSecond(m_timestamp * number);
	return *this;
}

CTime & CTime::operator/=(unsigned number)
{
	if (number == 0)
	{
		throw std::invalid_argument("Invalid operation. Division by zero");
	}

	m_timestamp = m_timestamp / number;
	return *this;
}

bool CTime::operator==(CTime const & time) const
{
	return (m_timestamp == time.m_timestamp);
}

bool CTime::operator!=(CTime const & time) const
{
	return (m_timestamp != time.m_timestamp);
}

bool CTime::operator>(CTime const & time) const
{
	return (m_timestamp > time.m_timestamp);
}

bool CTime::operator<(CTime const & time) const
{
	return (m_timestamp < time.m_timestamp);
}

bool CTime::operator>=(CTime const & time) const
{
	return (m_timestamp >= time.m_timestamp);;
}

bool CTime::operator<=(CTime const & time) const
{
	return (m_timestamp <= time.m_timestamp);
}

CTime const operator*(unsigned number, CTime const & time)
{
	unsigned resultMultiply = number * time.GetTimeStamp();
	return CTime(PreventOverFlowSecond(resultMultiply));
}
