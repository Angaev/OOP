#pragma once
#include <vector>
#include <iostream>
#include <cmath>

enum class Direction
{
	REVERSE = -1,
	STOP = 0,
	FORWARD = 1
};

class CCar
{
public:
	CCar();
	~CCar();

	//���������� ��������� ���������
	bool GetEngineStatus() const;

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

private:
	bool m_engineStatus = false; //true - ��������� �������, false - ��� ���������
	int m_gear = 0; // ��������
	int m_speed = 0; // ��������
};

