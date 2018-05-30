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

	//присвоение сложения 
	CTime & operator += (CTime const & sumTime);

	//присвоение вычитания
	CTime & operator -= (CTime const & subTime);

	//умножение время на время
	CTime const operator * (CTime const& multpTime)const;

	//умножение время на int
	CTime const friend operator * (int numb, CTime const& multpTime);

	//деление времени на число
	CTime const operator / (unsigned number)const;

	//деление времени на время
	unsigned operator / (CTime const& time) const;

	//присвоение умножения 
	CTime & operator *= (CTime const & time);

	//присвоение деления
	CTime & operator /= (unsigned number);

	//равны ли два времен
	bool const operator == (CTime const& time) const;

	//не равны ли два времен
	bool const operator != (CTime const& time) const;

	//больше чем другое время
	bool const operator > (CTime const& time) const;

	//меньше чем другое время
	bool const operator < (CTime const& time) const;

	//больше или равно чем другое время
	bool const operator >= (CTime const& time) const;

	//меньше или равно чем другое время
	bool const operator <= (CTime const& time) const;

private:
	unsigned m_timestamp = 0;
};

