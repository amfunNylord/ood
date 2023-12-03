#pragma once
#include <iostream>

class IState
{
public:
	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;
	virtual void AddBalls(unsigned count) = 0;
	virtual std::string ToString() const = 0;
	virtual ~IState() = default;
};