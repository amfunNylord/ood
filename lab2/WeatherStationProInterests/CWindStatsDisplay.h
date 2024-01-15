#pragma once
#include <iostream>
#include "CWindDirectionData.h"

class CWindStatsDisplay
{
public:
	void Display(CWindDirectionData stats)
	{
		std::cout << "Average direction " << stats.GetAverage() << std::endl;
	}
};