#include "CStatsDisplay.h"
#include <iostream>

int main()
{
	// �� ������ ����� � ����� weatherdata
	CWeatherData weatherData;
	CWeatherDataPro weatherDataPro;
	CStatsDisplay display(weatherData, weatherDataPro, std::cout);

	weatherData.RegisterObserver(display, 0);
	weatherDataPro.RegisterObserver(display, 0);

	weatherData.SetMeasurements(3, 0.7, 760);
	weatherDataPro.SetMeasurements(3, 0.7, 760, 180, 2);

	weatherData.SetMeasurements(9, 0.24, 780);
	weatherDataPro.SetMeasurements(5, 0.32, 750, 190, 9);
}