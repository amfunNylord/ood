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
		
		m_temperatureStats.IncreaseCount();
		m_humidityStats.IncreaseCount();
		m_pressureStats.IncreaseCount();
		m_windSpeed.IncreaseCount();

		CNumericStatsDisplay display;
		display.Display(m_temperatureStats);
		display.Display(m_humidityStats);
		display.Display(m_pressureStats);
		display.Display(m_windSpeed);
		CWindStatsDisplay displayWind;
		displayWind.Display(m_windDirection);
	}

	CNumericStatsData m_temperatureStats = CNumericStatsData("Temperature");
	CNumericStatsData m_humidityStats = CNumericStatsData("Humidity");
	CNumericStatsData m_pressureStats = CNumericStatsData("Pressure");
	CNumericStatsData m_windSpeed = CNumericStatsData("Wind speed");
	CWindDirectionData m_windDirection;
	
};