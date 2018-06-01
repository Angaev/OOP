#pragma once

class CTime
{
public:
	//�������������� ����� �������� ����������� �����, �����, ������
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	
	// �������������� ����� ����������� ������ ����� ��������
	CTime(unsigned timeStamp = 0);

	// ���������� ���������� �����
	unsigned GetHours()const;

	// ���������� ���������� �����
	unsigned GetMinutes()const;

	// ���������� ���������� ������
	unsigned GetSeconds()const;

	//���������� timestamp
	unsigned GetTimeStamp() const;

	//���������� ���������
	CTime & operator++();

	//����������� ���������
	CTime const operator++(int);

	//���������� ���������
	CTime & operator--();

	//����������� ���������
	CTime const operator--(int);

	//�������� �������� �������
	CTime operator + (CTime const & time2)const;

	//�������� ��������� �������
	CTime operator - (CTime const & time2)const;

	//���������� �������� 
	CTime & operator += (CTime const & sumTime);

	//���������� ���������
	CTime & operator -= (CTime const & subTime);

	//��������� ����� �� number
	CTime const operator*(unsigned number)const;

	//������� ������� �� �����
	CTime const operator / (unsigned number)const;

	//������� ������� �� �����
	unsigned operator / (CTime const& time) const;

	//���������� ��������� 
	CTime & operator *= (unsigned number);

	//���������� �������
	CTime & operator /= (unsigned number);

	//����� �� ��� ������
	bool operator == (CTime const& time) const;

	//�� ����� �� ��� ������
	bool operator != (CTime const& time) const;

	//������ ��� ������ �����
	bool operator > (CTime const& time) const;

	//������ ��� ������ �����
	bool operator < (CTime const& time) const;

	//������ ��� ����� ��� ������ �����
	bool operator >= (CTime const& time) const;

	//������ ��� ����� ��� ������ �����
	bool operator <= (CTime const& time) const;

private:
	unsigned m_timestamp = 0;
};

//��������� number �� �����
CTime const operator*(unsigned number, CTime const& time);