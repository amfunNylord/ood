#pragma once
#include "IObserver.h"
#include "SWeatherInfo.h"
#include "CWeatherData.h"
#include "CWeatherDataPro.h"
#include "CStats.h"
#include "CStatsPro.h"


class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(const CWeatherData& observableIn, const CWeatherDataPro& observableOut, std::ostream& output)
		: m_observableIn(observableIn)
		, m_observableOut(observableOut)
		, m_output(output)
		, m_statsIn(output)
		, m_statsOut(output)
	{}
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(const SWeatherInfo& data, const IObservable<SWeatherInfo>& observable) override
	{
		if (&observable == &m_observableIn)
		{
			m_statsIn.Update(data);
		}
		if (&observable == &m_observableOut)
		{
			m_statsOut.Update(data);
		}
	}

	const CWeatherData& m_observableIn;
	const CWeatherDataPro& m_observableOut;

	CStats m_statsIn;
	CStatsPro m_statsOut;

	std::ostream& m_output;
	
};