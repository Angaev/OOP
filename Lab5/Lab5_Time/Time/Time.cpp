#include "stdafx.h"
#include "Time.h"

constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned SECONDS_IN_DAY = 86400;
constexpr unsigned ONE_SECOND = 1;

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	m_timestamp = hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
}

CTime::CTime(unsigned timeStamp) :
	m_timestamp(timeStamp)
{
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

bool CTime::IsValid() const
{
	return false;
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
	return CTime(sum % SECONDS_IN_DAY);
}

CTime CTime::operator-(CTime const & time2) const
{
	unsigned difference = 0;
	if (m_timestamp < time2.GetTimeStamp())
	{
		difference = SECONDS_IN_DAY - (time2.GetTimeStamp() - m_timestamp);
	}
	else
	{
		difference = m_timestamp - time2.GetTimeStamp();
	}
	return CTime(difference);
}
