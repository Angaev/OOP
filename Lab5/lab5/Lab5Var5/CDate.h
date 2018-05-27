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

	//�������������� ���� �������� ����, �����, ��� (>=1970, <= 9999)
	CDate(unsigned day, Month month, unsigned year);
	
	//�������������� ���� ����������� ���� � 1 ��� 2017
	CDate(unsigned timestamp = 0);

	//���������� ���� ������ (�� 0 �� 31)
	unsigned GetDay() const;

	//���������� �����
	Month GetMonth() const;

	//��������� ���
	unsigned GetYear() const;

	//���������� ���� ������
	WeekDay GetWeekDay() const;
	
	//���������� ���������� � ������������ �������� ����
	bool IsValid() const;

	//��������� ���������� ���� � ������ �����
	unsigned GetTimeStamp() const;
private:
	unsigned m_timestamp = 0;
};

