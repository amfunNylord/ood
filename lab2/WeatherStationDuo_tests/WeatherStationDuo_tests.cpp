#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../WeatherStationDuo/CWeatherData.h"
#include "../WeatherStationDuo/CStatsDisplay.h"

TEST_CASE("Observer two observable")
{
	std::ostringstream oss;

	CWeatherData weatherDataIn;
	CWeatherData weatherDataOut;

	CStatsDisplay display(weatherDataIn, weatherDataOut, oss);

	weatherDataIn.RegisterObserver(display, 0);
	weatherDataOut.RegisterObserver(display, 0);

	weatherDataIn.SetMeasurements(3, 0.7, 760);
	weatherDataOut.SetMeasurements(5, 0.24, 780);
	std::stringstream expectedString;

	expectedString << "Max Temperature 3\nMin Temperature 3\nAverage Temperature 3\n----------------\nMax Humidity 0.7\nMin Humidity 0.7\n"
					  "Average Humidity 0.7\n----------------\nMax Pressure 760\nMin Pressure 760\nAverage Pressure 760\n----------------\n"
		              "Max Temperature 5\nMin Temperature 5\nAverage Temperature 5\n----------------\nMax Humidity 0.24\nMin Humidity 0.24\n"
		              "Average Humidity 0.24\n----------------\nMax Pressure 780\nMin Pressure 780\nAverage Pressure 780\n----------------\n";

	REQUIRE(oss.str() == expectedString.str());

	expectedString.clear();
	oss.clear();

	weatherDataIn.SetMeasurements(10, 0.24, 751);
	weatherDataOut.SetMeasurements(2, 0.9, 720);

	expectedString << "Max Temperature 10\nMin Temperature 3\nAverage Temperature 6.5\n----------------\nMax Humidity 0.7\nMin Humidity 0.24\n"
					  "Average Humidity 0.47\n----------------\nMax Pressure 760\nMin Pressure 751\nAverage Pressure 755.5\n----------------\n"
		              "Max Temperature 5\nMin Temperature 2\nAverage Temperature 3.5\n----------------\nMax Humidity 0.9\nMin Humidity 0.24\n"
					  "Average Humidity 0.57\n----------------\nMax Pressure 780\nMin Pressure 720\nAverage Pressure 750\n----------------\n";

	REQUIRE(oss.str() == expectedString.str());
}