#pragma once
#include <string>

enum class Direction
{
	REVERSE = -1,
	STOP = 0,
	FORWARD = 1
};

class CCar
{
public:

	//���������� ��������� ���������
	bool IsEngineOn() const;

	//�������� ���������
	bool TurnOnEngine();

	//������ ���������
	bool TurnOffEngine();

	//�������� ��������
	bool SetGear(int const gear);

	//���������� ���������� ��������
	int GetTurnGear() const;

	//������������� �������� ����������
	bool SetSpeed(int const speed);

	//���������� �������� ����������
	int GetSpeed() const;

	//���������� ����������� ��������
	Direction GetDirection() const;
	
	//���������� ��������� ������
	std::string GetLastError();

private:
	bool m_engineStatus = false; //true - ��������� �������, false - ��� ���������
	int m_gear = 0; // ��������
	int m_speed = 0; // ��������
	std::string m_lastError; // ��������� ������
};

