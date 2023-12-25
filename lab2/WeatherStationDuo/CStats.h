#pragma once
#include "SWeatherInfo.h"
#include "CNumericStatsDisplay.h"

class CStats
{
public:
	CStats(std::ostream& output)
		: m_output(output)
	{}
	void Update(SWeatherInfo const& data) 
	{
		m_temperatureStats.Update(data.temperature);
		m_humidityStats.Update(data.humidity);
		m_pressureStats.Update(data.pressure);

		m_temperatureStats.IncreaseCount();
		m_humidityStats.IncreaseCount();
		m_pressureStats.IncreaseCount();

		CNumericStatsDisplay display(m_output);
		display.Display(m_temperatureStats);
		display.Display(m_humidityStats);
		display.Display(m_pressureStats);
	}

private:
	CNumericStatsData m_temperatureStats = CNumericStatsData("Temperature");
	CNumericStatsData m_humidityStats = CNumericStatsData("Humidity");
	CNumericStatsData m_pressureStats = CNumericStatsData("Pressure");
	std::ostream& m_output;
};
