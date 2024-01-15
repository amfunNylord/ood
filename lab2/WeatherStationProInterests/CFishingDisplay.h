#pragma once
#include "IObserver.h"
#include "SWeatherInfo.h"
#include <iostream>

class CFishingDisplay : public IObserver<SWeatherInfo>
{
private:
	
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};