#pragma once
#include <iostream>

class CNumericStatsData
{
public:
	void Update(double current)
	{
		if (m_minimum > current)
		{
			m_minimum = current;
		}

		if (m_maximum < current)
		{
			m_maximum = current;
		}
		IncreaseCount();
		m_accumulatedValue += current;
		m_averageValue = m_accumulatedValue / m_count;
	}
	double GetMin()
	{
		return m_minimum;
	}
	double GetMax()
	{
		return m_maximum;
	}
	double GetAverageValue()
	{
		return m_averageValue;
	}
	double GetCount()
	{
		return m_count;
	}

private:
	void IncreaseCount()
	{
		m_count++;
	}
	double m_minimum = std::numeric_limits<double>::infinity();
	double m_maximum = -std::numeric_limits<double>::infinity();
	double m_accumulatedValue = 0;
	unsigned m_count = 0;
	double m_averageValue = 0;
};