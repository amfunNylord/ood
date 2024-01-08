#pragma once
#include "SWeatherInfo.h"
#include "CNumericStatsDisplay.h"
#include "CWindStatsDisplay.h"

class CStatsPro
{
public:
	CStatsPro(std::ostream& output)
		: m_output(output)
	{}
	void Update(SWeatherInfo const& data)
	{
		m_temperatureStats.Update(data.temperature);
		m_humidityStats.Update(data.humidity);
		m_pressureStats.Update(data.pressure);
		m_windSpeed.Update(data.wind.speed);
		m_windDirection.Update(data.wind.direction);

		CNumericStatsDisplay display(m_output);
		display.Display(m_temperatureStats, "Temperature");
		display.Display(m_humidityStats, "Humidity");
		display.Display(m_pressureStats, "Pressure");
		display.Display(m_windSpeed, "Wind speed");
		CWindStatsDisplay displayWind(m_output);
		displayWind.Display(m_windDirection);
	}

private:
	CNumericStatsData m_temperatureStats = CNumericStatsData();
	CNumericStatsData m_humidityStats = CNumericStatsData();
	CNumericStatsData m_pressureStats = CNumericStatsData();
	CNumericStatsData m_windSpeed = CNumericStatsData();
	CWindDirectionData m_windDirection;
	std::ostream& m_output;
};