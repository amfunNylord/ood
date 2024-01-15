#pragma once
#include <numbers>
#include <cmath>

/*
*  исправления:
*   поменял название параметра передаваемое в update, более конкретное
*   вынес из класса функции, которые не взаимодействуют с полями класса
*/

inline double ToRadians(double degrees) 
{
	return std::numbers::pi * degrees / 180;
}

inline double ToDegrees(double radians)
{
	return 180 * radians / std::numbers::pi;
}

class CWindDirectionData
{
public:
	void Update(double angle)
	{
		m_sinSum += std::sin(ToRadians(angle));
		m_cosSum += std::cos(ToRadians(angle));

		double x = ToDegrees(std::atan2(m_sinSum, m_cosSum)) + 360;
		m_average = std::fmod(x, 360);
	}
	double GetAverage()
	{
		return m_average;
	}

private:
	double m_sinSum = 0;
	double m_cosSum = 0;
	double m_average = 0;
};