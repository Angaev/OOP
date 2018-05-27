#pragma once

enum Month
{
	JANUARY = 1, FEBRALY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

enum  WeekDay
{
	SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY,  FRIDAY, SATURDAY
};

class CDate
{
public:

	//инициализирует дату заданием день, месяц, год (>=1970, <= 9999)
	CDate(unsigned day, Month month, unsigned year);
	
	//инициализирует дату количеством дней с 1 янв 2017
	CDate(unsigned timestamp = 0);

	//возвращает день месяца (от 0 до 31)
	unsigned GetDay() const;

	//возвращает месяц
	Month GetMonth() const;

	//возращает год
	unsigned GetYear() const;

	//возвращает день недели
	WeekDay GetWeekDay() const;
	
	//возвращает информацию о корректности хранимой даты
	bool IsValid() const;

	//возвращет количество дней с начала эпохи
	unsigned GetTimeStamp() const;
private:
	unsigned m_timestamp = 0;
};

