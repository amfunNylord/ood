#pragma once
#include "CNumericStatsData.h"

class CNumericStatsDisplay
{
public:
	void Display(CNumericStatsData stats, const std::string& sensorName)
	{
		std::cout << "Max " << sensorName << " " << stats.GetMax() << std::endl;
		std::cout << "Min " << sensorName << " " << stats.GetMin() << std::endl;
		std::cout << "Average " << sensorName << " " << stats.GetAverageValue() << std::endl;
		std::cout << "----------------" << std::endl;
	}
};