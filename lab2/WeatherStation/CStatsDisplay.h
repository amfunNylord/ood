#pragma once
#include "IObserver.h"
#include "WeatherInfo.h"
#include "NumericStatsData.h"
class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* ����� Update ������ ���������, ����� ���������� ����������� ��� ������ ��������
	������ CObservable �� ����� �������� ��� �����, �.�. � ���������� IObserver ��
	�������� ���������
	*/
	void Update(SWeatherInfo const& data) override
	{
		m_temperatureStats.Update(data.temperature);
		m_humidityStats.Update(data.humidity);
		m_pressureStats.Update(data.pressure);

		++m_count;

		m_temperatureStats.Display("Temperature", m_count);
		m_humidityStats.Display("Humidity", m_count);
		m_pressureStats.Display("Pressure", m_count);
	}

	NumericStatsData m_temperatureStats;
	NumericStatsData m_humidityStats;
	NumericStatsData m_pressureStats;

	unsigned m_count = 0;
};