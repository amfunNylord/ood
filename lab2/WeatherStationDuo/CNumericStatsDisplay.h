#pragma once
#include "CNumericStatsData.h"

class CNumericStatsDisplay
{
public:
	CNumericStatsDisplay(std::ostream& output)
		: m_output(output)
	{
	}
	void Display(CNumericStatsData stats)
	{
		m_output << "Max " << stats.GetSensorName() << " " << stats.GetMax() << std::endl;
		m_output << "Min " << stats.GetSensorName() << " " << stats.GetMin() << std::endl;
		m_output << "Average " << stats.GetSensorName() << " " 
			      << (stats.GetAccumulatedValue() / stats.GetCount()) << std::endl;
		m_output << "----------------" << std::endl;
	}

private:
	std::ostream& m_output;
};