#pragma once
#include <iostream>
#include "CWindDirectionData.h"

class CWindStatsDisplay
{
public:
	CWindStatsDisplay(std::ostream& output)
		: m_output(output)
	{}
	void Display(CWindDirectionData stats)
	{
		m_output << "Average direction " << stats.GetAverage() << std::endl;
	}

private:
	std::ostream& m_output;
};