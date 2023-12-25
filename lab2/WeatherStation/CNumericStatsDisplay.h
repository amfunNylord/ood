#pragma once
#include "CNumericStatsData.h"

class CNumericStatsDisplay
{
public:
	void Display(CNumericStatsData stats)
	{
		std::cout << "Max " << stats.GetSensorName() << " " << stats.GetMax() << std::endl;
		std::cout << "Min " << stats.GetSensorName() << " " << stats.GetMin() << std::endl;
		std::cout << "Average " << stats.GetSensorName() << " " 
			      << (stats.GetAccumulatedValue() / stats.GetCount()) << std::endl;
		std::cout << "----------------" << std::endl;
	}
};