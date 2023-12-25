#pragma once
#include <numbers>
#include <cmath>

class CWindDirectionData
{
public:
	void Update(double data)
	{
		m_sinSum += std::sin(ToRadians(data));
		m_cosSum += std::cos(ToRadians(data));

		double x = ToDegrees(std::atan2(m_sinSum, m_cosSum)) + 360;
		m_average = std::fmod(x, 360);
	}
	double GetAverage()
	{
		return m_average;
	}

private:
	double ToRadians(double degrees) const
	{
		return std::numbers::pi * degrees / 180;
	}

	double ToDegrees(double radians) const
	{
		return 180 * radians / std::numbers::pi;
	}

	double m_sinSum = 0;
	double m_cosSum = 0;
	double m_average = 0;
};