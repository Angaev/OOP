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

	// ���������� ���������� � ������������ �������.
	// ��������, ����� ������ ������������ CTime time(99, 32, 83);
	//	����� time.IsValid() ������ ���������� false
	bool IsValid()const;

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

private:
	unsigned m_timestamp = 0;
};

