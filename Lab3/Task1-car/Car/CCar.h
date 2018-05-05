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

	//возвращает состояние двигателя
	bool IsEngineOn() const;

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
	
	//возвращает последнюю ошибку
	std::string GetLastError();

private:
	bool m_engineStatus = false; //true - двигатель заведен, false - все остальное
	int m_gear = 0; // передача
	int m_speed = 0; // скорость
	std::string m_lastError; // последняя ошибка
};

