#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../WeatherStation/WeatherData.h"

class TestDisplay : public IObserver<SWeatherInfo>
{
public:
	TestDisplay(CObservable<SWeatherInfo>& observableRef)
		: m_observableRef(observableRef)
	{
	}

private:
	void Update(const SWeatherInfo& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;

		m_observableRef.RemoveObserver(*this);
	}

	CObservable<SWeatherInfo>& m_observableRef;
};

SCENARIO("Removing observer while updating it")
{
	WHEN("We're trying to remove observer while updating it")
	{
		CWeatherData wd;
		TestDisplay testDisplay(wd);
		wd.RegisterObserver(testDisplay);
		THEN("Throws exception")
		{
			REQUIRE_THROWS_AS(wd.SetMeasurements(3, 0.7, 760), std::logic_error);
		}
	}
}