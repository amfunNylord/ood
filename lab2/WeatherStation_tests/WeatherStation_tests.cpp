#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../WeatherStation/WeatherData.h"

class TestDisplay1 : public IObserver<SWeatherInfo>
{
public:
	TestDisplay1(CObservable<SWeatherInfo>& observableRef, std::ostream& output)
		: m_observableRef(observableRef)
		, m_output(output)
	{
	}

private:
	void Update(const SWeatherInfo& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
		m_output << "I'am here";
		m_observableRef.RemoveObserver(*this);
	}

	std::ostream& m_output;
	CObservable<SWeatherInfo>& m_observableRef;
};

SCENARIO("Removing observer while updating it")
{
	WHEN("We're trying to remove observer while updating it")
	{
		std::ostringstream output;
		CWeatherData wd;
		TestDisplay1 testDisplay(wd, output);
		wd.RegisterObserver(testDisplay);
		THEN("There is no undefined behaviour")
		{
			wd.SetMeasurements(3, 0.7, 760);
			REQUIRE(output.str() == "I'am here");
			wd.SetMeasurements(1, 0.3, 758);
			REQUIRE(output.str() != "I'am hereI'am here");
		}
	}
}

class TestDisplay2 : public IObserver<SWeatherInfo>
{
public:
	TestDisplay2(const int& displayIndex, std::ostream& output)
		: m_displayIndex(displayIndex)
		, m_output(output)
	{
	}

private:
	void Update(const SWeatherInfo& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
		m_output << m_displayIndex;
	}
	int m_displayIndex;
	std::ostream& m_output;

};

SCENARIO("Test priority notifying")
{
	std::ostringstream output;

	WHEN("We're adding observers with their priority")
	{
		TestDisplay2 testDisplay1(1, output);
		TestDisplay2 testDisplay2(2, output);
		TestDisplay2 testDisplay3(3, output);

		THEN("We get their correct order of notification")
		{
			CWeatherData wd;

			wd.RegisterObserver(testDisplay1, 2);
			wd.RegisterObserver(testDisplay2, 3);
			wd.RegisterObserver(testDisplay3, 1);

			wd.MeasurementsChanged();

			REQUIRE(output.str() == "213");
		}
	}

	WHEN("We're trying to add the same observer more the once")
	{
		TestDisplay2 testDisplay1(1, output);
		CWeatherData wd;

		wd.RegisterObserver(testDisplay1, 5);

		THEN("We get error")
		{
			REQUIRE_THROWS_AS(wd.RegisterObserver(testDisplay1, 0), std::logic_error);
		}
	}
}