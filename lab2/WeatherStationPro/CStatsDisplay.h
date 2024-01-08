#pragma once
#include "IObserver.h"
#include "SWeatherInfo.h"
#include "CNumericStatsData.h"
#include "CNumericStatsDisplay.h"
#include "CWindStatsDisplay.h"

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		m_temperatureStats.Update(data.temperature);
		m_humidityStats.Update(data.humidity);
		m_pressureStats.Update(data.pressure);
		m_windSpeed.Update(data.wind.speed);
		m_windDirection.Update(data.wind.direction);

		CNumericStatsDisplay display;
		display.Display(m_temperatureStats, "Temperature");
		display.Display(m_humidityStats, "Humidity");
		display.Display(m_pressureStats, "Pressure");
		display.Display(m_windSpeed, "Wind speed");
		CWindStatsDisplay displayWind;
		displayWind.Display(m_windDirection);
	}

	CNumericStatsData m_temperatureStats = CNumericStatsData();
	CNumericStatsData m_humidityStats = CNumericStatsData();
	CNumericStatsData m_pressureStats = CNumericStatsData();
	CNumericStatsData m_windSpeed = CNumericStatsData();
	CWindDirectionData m_windDirection;
	
};