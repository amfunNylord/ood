#include "CWeatherData.h"
#include "CStatsDisplay.h"
#include <iostream>

int main()
{
	CWeatherData wd;

	CStatsDisplay display;

	wd.RegisterObserver(display, 0);

	wd.SetMeasurements(3, 0.7, 760, 180, 2);

	return 0;
}