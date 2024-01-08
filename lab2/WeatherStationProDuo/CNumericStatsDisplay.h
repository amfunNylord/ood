#pragma once
#include "CNumericStatsData.h"

class CNumericStatsDisplay
{
public:
	CNumericStatsDisplay(std::ostream& output)
		: m_output(output)
	{
	}
	void Display(CNumericStatsData stats, const std::string& sensorName)
	{
		m_output << "Max " << sensorName << " " << stats.GetMax() << std::endl;
		m_output << "Min " << sensorName << " " << stats.GetMin() << std::endl;
		m_output << "Average " << sensorName << " " << stats.GetAverageValue() << std::endl;
		m_output << "----------------" << std::endl;
	}

private:
	std::ostream& m_output;
};