#pragma once
#include "SWindInfo.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0; // влажность
	double pressure = 0; // давление
	SWindInfo wind;
};