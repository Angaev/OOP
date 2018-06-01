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

	//присвоение сложения 
	CTime & operator += (CTime const & sumTime);

	//присвоение вычитания
	CTime & operator -= (CTime const & subTime);

	//умножение время на number
	CTime const operator*(unsigned number)const;

	//деление времени на число
	CTime const operator / (unsigned number)const;

	//деление времени на время
	unsigned operator / (CTime const& time) const;

	//присвоение умножения 
	CTime & operator *= (unsigned number);

	//присвоение деления
	CTime & operator /= (unsigned number);

	//равны ли два времен
	bool operator == (CTime const& time) const;

	//не равны ли два времен
	bool operator != (CTime const& time) const;

	//больше чем другое время
	bool operator > (CTime const& time) const;

	//меньше чем другое время
	bool operator < (CTime const& time) const;

	//больше или равно чем другое время
	bool operator >= (CTime const& time) const;

	//меньше или равно чем другое время
	bool operator <= (CTime const& time) const;

private:
	unsigned m_timestamp = 0;
};

//умножение number на время
CTime const operator*(unsigned number, CTime const& time);