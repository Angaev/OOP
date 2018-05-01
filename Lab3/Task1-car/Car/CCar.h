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

	//возвращает состояние двигателя
	bool GetEngineStatus() const;

	//стартует двигатель
	bool TurnOnEngine();

	//глушит двигатель
	bool TurnOffEngine();

	//включает передачу
	bool SetGear(int const gear);

	//возвращает включенную передачу
	int GetTurnGear() const;

	//устанавливает скорость автомобиля
	bool SetSpeed(int const speed);

	//возвращает скорость автомобиля
	int GetSpeed() const;

	//возвращает направление движения
	Direction GetDirection() const;

private:
	bool m_engineStatus = false; //true - двигатель заведен, false - все остальное
	int m_gear = 0; // передача
	int m_speed = 0; // скорость
};

