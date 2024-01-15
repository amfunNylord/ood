#pragma once
#include "IObserver.h"
#include "CObservable.h"
#include "SWeatherInfo.h"
#include "WeatherEvents.h"

class CWeatherDataProInterests : public CObservable<SWeatherInfo, WeatherEvents>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature() const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity() const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure() const
	{
		return m_pressure;
	}

	SWindInfo GetWind() const
	{
		return m_wind;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure, double direction, double speed)
	{
		SetCurrentEvents(temp, humidity, pressure, direction, speed);
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;
		m_wind = { direction, speed };

		MeasurementsChanged();
	}

protected:
	SWeatherInfo GetChangedData() const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		info.wind = GetWind();
		return info;
	}
	
	std::set<WeatherEvents> GetCurrentEvents() const override
	{
		return m_currentEvents;
	}

private:
	void SetCurrentEvents(double temp, double humidity, double pressure, double direction, double speed)
	{
		m_currentEvents.clear();

		if (temp != m_temperature)
		{
			m_currentEvents.emplace(WeatherEvents::Temperature);
		}
		if (humidity != m_humidity)
		{
			m_currentEvents.emplace(WeatherEvents::Humidity);
		}
		if (pressure != m_pressure)
		{
			m_currentEvents.emplace(WeatherEvents::Pressure);
		}
		if (speed != m_wind.speed)
		{
			m_currentEvents.emplace(WeatherEvents::WindSpeed);
		}
		if (direction != m_wind.direction)
		{
			m_currentEvents.emplace(WeatherEvents::WindDirection);
		}

		if (!m_currentEvents.empty())
		{
			m_currentEvents.emplace(WeatherEvents::All);
		}
	}

	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
	SWindInfo m_wind;
	std::set<WeatherEvents> m_currentEvents;
};
