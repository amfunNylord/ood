#pragma once

struct IMultiGumballMachine
{
	virtual void ReleaseBall() = 0;
	virtual unsigned GetBallCount() const = 0;
	virtual unsigned GetQuarterCount() const = 0;
	virtual void SetQuarterCount(unsigned count) = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;
	virtual void SetHasMaxQuartersState() = 0;

	virtual ~IMultiGumballMachine() = default;
};