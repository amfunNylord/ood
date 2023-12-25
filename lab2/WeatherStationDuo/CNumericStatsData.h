#pragma once
#include <iostream>

class CNumericStatsData
{
	//display v otdelniy klass - done
public:
	CNumericStatsData(const char* sensorName)
		: m_sensorName(sensorName)
	{}
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

		m_accumulatedValue += current;
	}
	void IncreaseCount()
	{
		m_count++;
	}
	double GetMin()
	{
		return m_minimum;
	}
	double GetMax()
	{
		return m_maximum;
	}
	double GetAccumulatedValue()
	{
		return m_accumulatedValue;
	}
	double GetCount()
	{
		return m_count;
	}
	const char* GetSensorName()
	{
		return m_sensorName;
	}

private:
	double m_minimum = std::numeric_limits<double>::infinity();
	double m_maximum = -std::numeric_limits<double>::infinity();
	double m_accumulatedValue = 0;
	unsigned m_count = 0;
	const char* m_sensorName;
};