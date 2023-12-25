#pragma once
#include "IObserver.h"
#include "SWeatherInfo.h"
#include "CNumericStatsData.h"
#include "CNumericStatsDisplay.h"

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
		// count � NumericStatsDisplay - done
		m_temperatureStats.IncreaseCount();
		m_humidityStats.IncreaseCount();
		m_pressureStats.IncreaseCount();

		CNumericStatsDisplay display;
		display.Display(m_temperatureStats);
		display.Display(m_humidityStats);
		display.Display(m_pressureStats);
	}

	CNumericStatsData m_temperatureStats = CNumericStatsData("Temperature");
	CNumericStatsData m_humidityStats = CNumericStatsData("Humidity");
	CNumericStatsData m_pressureStats= CNumericStatsData("Pressure");
};