#pragma once

#include <memory>
#include <string>

// Интерфейс "напиток"
class IBeverage
{
public:
	virtual std::string GetDescription() const = 0;
	virtual double GetCost() const = 0;
	virtual ~IBeverage() = default;
};

typedef std::unique_ptr<IBeverage> IBeveragePtr;
