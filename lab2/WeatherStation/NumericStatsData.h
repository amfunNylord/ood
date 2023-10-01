#pragma once
#include <iostream>

// вынести в класс, обновлениие должно быть в этом классе - done
// struct NumericStatsData
//{
//	double minimum = std::numeric_limits<double>::infinity();
//	double maximum = -std::numeric_limits<double>::infinity();
//	double accumulatedValue = 0;
//};

class NumericStatsData
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

		m_accumulatedValue += current;
	}
	void Display(const char* text, unsigned count)
	{
		std::cout << "Max " << text << " " << m_maximum << std::endl;
		std::cout << "Min " << text << " " << m_minimum << std::endl;
		std::cout << "Average " << text << " " << (m_accumulatedValue / count) << std::endl;
		std::cout << "----------------" << std::endl;
	}

private:
	double m_minimum = std::numeric_limits<double>::infinity();
	double m_maximum = -std::numeric_limits<double>::infinity();
	double m_accumulatedValue = 0;
};