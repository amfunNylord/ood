#include "CWeatherDataProInterests.h"
#include "WeatherEvents.h"
#include "CDisplay.h"
#include "CFishingDisplay.h"

int main()
{
	CWeatherDataProInterests wdProInterests;

	CDisplay display;
	CFishingDisplay fishermanDisplay;

	wdProInterests.RegisterObserver(display, WeatherEvents::All);
	wdProInterests.RegisterObserver(fishermanDisplay, WeatherEvents::Temperature);
	wdProInterests.RegisterObserver(fishermanDisplay, WeatherEvents::Pressure);

	wdProInterests.SetMeasurements(3, 0.7, 760, 3, 90);
	wdProInterests.SetMeasurements(3, 0.8, 760, 5, 300);

	wdProInterests.RemoveObserver(display, WeatherEvents::All);

	wdProInterests.SetMeasurements(5, 0.8, 760, 5, 300);
	wdProInterests.SetMeasurements(3, 0.8, 760, 5, 300);
	wdProInterests.SetMeasurements(4, 0.8, 758, 5, 300);

	return 0;
}