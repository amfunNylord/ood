#pragma once
#include "CNumericStatsDisplay.h"
#include "SWeatherInfo.h"

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

		CNumericStatsDisplay display(m_output);
		display.Display(m_temperatureStats, "Temperature");
		display.Display(m_humidityStats, "Humidity");
		display.Display(m_pressureStats, "Pressure");
	}

private:
	CNumericStatsData m_temperatureStats = CNumericStatsData();
	CNumericStatsData m_humidityStats = CNumericStatsData();
	CNumericStatsData m_pressureStats = CNumericStatsData();
	std::ostream& m_output;
};
