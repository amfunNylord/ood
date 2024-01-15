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
		// ���� �������, ���� ������� ���� ����� � ������ ��� ��������
		CNumericStatsDisplay display;
		display.Display(m_temperatureStats, "Temperature");
		display.Display(m_humidityStats, "Humidity");
		display.Display(m_pressureStats, "Pressure");
	}
	CNumericStatsData m_temperatureStats = CNumericStatsData();
	CNumericStatsData m_humidityStats = CNumericStatsData();
	CNumericStatsData m_pressureStats = CNumericStatsData();
};