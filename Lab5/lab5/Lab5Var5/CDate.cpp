#include "stdafx.h"
#include "CDate.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

/*const map<Month, unsigned> dayInMonth = { 
	{JANUARY, 31}, {FEBRALY, 28}, {MARCH, 31}, 
	{APRIL, 30}, {MAY, 31}, {JUNE, 30}, {JULY, 31},
	{AUGUST, 31},  {SEPTEMBER, 30}, {OCTOBER, 31}, 
	{NOVEMBER, 30}, {DECEMBER, 31} };*/

const vector<unsigned> dayInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const vector<Month> monthList = { JANUARY, FEBRALY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
const vector<WeekDay> weekDayList = { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY,  FRIDAY, SATURDAY };
constexpr unsigned START_YEAR = 1970;
constexpr Month START_MONTH = JANUARY;
constexpr unsigned START_DAY = 1;
constexpr unsigned DAY_IN_YEAR = 365;
constexpr unsigned DAY_IN_WEEK = 7;
constexpr unsigned MAX_YEAR = 9999;


//возвращает true если год високосный
bool IsLeapYear(unsigned year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

//возврщает количество високосных годов [1970, year)
unsigned GetQuantityLeapYear(unsigned year)
{
	unsigned count = 0;
	for (unsigned i = START_YEAR; i < year; ++i)
	{
		if (IsLeapYear(i))
		{
			count++;
		}
	}
	return count;
}

//возвращет enum месяц от входного числа
Month MonthByNumber(unsigned numb)
{
	return monthList[numb - 1];
}

//возвращает enum день недели от числа недели
WeekDay WeekDayByNumber(unsigned numb)
{
	return weekDayList[numb];
}

void TimestampToDate(unsigned timestamp, unsigned& finalDay, Month& finalMonth, unsigned& finalYear)
{
	finalDay = START_DAY;
	finalMonth = START_MONTH;
	finalYear = START_YEAR;

	unsigned tempTimestamp = timestamp;
	unsigned year = tempTimestamp / DAY_IN_YEAR;
	finalYear += year;
	//вычесть года из timestamp
	tempTimestamp -= year * DAY_IN_YEAR;
	//и учесть високосные года
	tempTimestamp -= GetQuantityLeapYear(finalYear);

	//вычесть месяца года
	unsigned i = 1;
	while (tempTimestamp > dayInMonth[i - 1])
	{
		tempTimestamp -= dayInMonth[i - 1];
		i++;
	}
	finalMonth = MonthByNumber(i);

	//назначить день
	finalDay = tempTimestamp + 1;
	
	if (IsLeapYear(finalYear) && (finalMonth > FEBRALY))
	{
		finalDay--;
	}
}

CDate::CDate(unsigned day, Month month, unsigned year)
{
	unsigned timestamp = (year - START_YEAR) * DAY_IN_YEAR;
	timestamp += GetQuantityLeapYear(year);

	if (IsLeapYear(year))
	{
		//высокосный день уже прошел? 
		if (month > FEBRALY)
			timestamp++;
	}

	unsigned dayCount = 0;
	for (size_t i = 1; i < month; ++i)
	{
		dayCount += dayInMonth[i-1];
	}
	timestamp += dayCount;
	timestamp += (day - 1);

	m_timestamp = timestamp;
}

CDate::CDate(unsigned timestamp) : 
	m_timestamp(timestamp)
{
}

unsigned CDate::GetDay() const
{
	unsigned day;
	Month month;
	unsigned year;
	TimestampToDate(m_timestamp, day, month, year);
	return day;
}

Month CDate::GetMonth() const
{
	unsigned day;
	Month month;
	unsigned year;
	TimestampToDate(m_timestamp, day, month, year);
	return month;
}

unsigned CDate::GetYear() const
{
	unsigned day;
	Month month;
	unsigned year;
	TimestampToDate(m_timestamp, day, month, year);
	return year;
}

WeekDay CDate::GetWeekDay() const
{
	unsigned dayOffset = m_timestamp % DAY_IN_WEEK;
	unsigned weekDayNumber = ((THURSDAY + dayOffset) % DAY_IN_WEEK);
	auto result =  WeekDayByNumber(weekDayNumber);

	return result;
}


bool CDate::IsValid() const
{
	//из timestamp в формат даты перевести
	unsigned day;
	Month month;
	unsigned year;
	TimestampToDate(m_timestamp, day, month, year);
	//проверить год [1970, 9999]
	if ((year < START_YEAR) || (year > MAX_YEAR))
	{
		return false;
	}

	//проверить, что месяца существуют
	if ((month < JANUARY) || (month > DECEMBER))
	{
		return false;
	}

	//проверить, что день существует в месяце, учитывая, что год мб високосный
	if (day <= 0)
	{
		return false;
	}

	if (day >= dayInMonth[month])
	{
		return false;
	}
	return true;
}

unsigned CDate::GetTimeStamp() const
{
	return m_timestamp;
}
