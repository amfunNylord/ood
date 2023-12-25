#pragma once
#include "IObserver.h"
#include "CStats.h"
#include "SWeatherInfo.h"

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(const CWeatherData& observableIn, const CWeatherData& observableOut, std::ostream& output)
		: m_observableIn(observableIn)
		, m_observableOut(observableOut)
		, m_output(output)
		, m_statsIn(output)
		, m_statsOut(output)

	{}

private:
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
	const CWeatherData& m_observableOut;

	CStats m_statsIn;
	CStats m_statsOut;

	std::ostream& m_output;

};