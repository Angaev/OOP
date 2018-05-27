#pragma once
class CTime
{
public:
	//инициализирует время заданным количеством часов, минут, секунд
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	
	// инициализирует время количеством секунд после полуночи
	CTime(unsigned timeStamp = 0);

	// возвращает количество часов
	unsigned GetHours()const;

	// возвращает количество минут
	unsigned GetMinutes()const;

	// возвращает количество секунд
	unsigned GetSeconds()const;

	// возвращает информацию о корректности времени.
	// Например, после вызова конструктора CTime time(99, 32, 83);
	//	метод time.IsValid() должен возвращать false
	bool IsValid()const;

	//возвращает timestamp
	unsigned GetTimeStamp() const;


	//префиксный инкремент
	CTime & operator++();

	//постфиксный инкремент
	CTime const operator++(int);

	//префиксный декремент
	CTime & operator--();

	//постфиксный декремент
	CTime const operator--(int);

	//бинарное сложение времени
	CTime operator + (CTime const & time2)const;

	//бинарное вычитание времени
	CTime operator - (CTime const & time2)const;

private:
	unsigned m_timestamp = 0;
};

