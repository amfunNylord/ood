#pragma once
#include <stdexcept>

enum class Color
{
	Green,
	Red, 
	Blue,
	Yellow,
	Pink,
	Black
};

inline Color ConvertStrColor(std::string colorStr)
{
	if (colorStr == "green")
	{
		return Color::Green;
	}
	else if (colorStr == "red")
	{
		return Color::Red;
	}
	else if (colorStr == "blue")
	{
		return Color::Blue;
	}
	else if (colorStr == "yellow")
	{
		return Color::Yellow;
	}
	else if (colorStr == "pink")
	{
		return Color::Pink;
	}
	else if (colorStr == "black")
	{
		return Color::Black;
	}
	else
	{
		throw std::invalid_argument("Invalid color string value");
	}
}