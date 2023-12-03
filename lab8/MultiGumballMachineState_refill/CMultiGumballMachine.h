#pragma once
#include "IMultiGumballMachine.h"
#include "IState.h"
#include "CHasQuarterState.h"
#include "CNoQuarterState.h"
#include "CSoldOutState.h"
#include "CSoldState.h"
#include "CHasMaxQuartersState.h"
#include <string>

class CMultiGumballMachine : private IMultiGumballMachine
{
public:
	CMultiGumballMachine(unsigned numBalls);

	void EjectQuarter();
	void InsertQuarter();
	void TurnCrank();
	std::string ToString() const;
	void AddBalls(unsigned count);

private:
	unsigned GetBallCount() const override;
	unsigned GetQuarterCount() const override;
	void SetQuarterCount(unsigned count) override;
	void ReleaseBall() override;
	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;
	void SetHasMaxQuartersState() override;
	void RefillBalls(unsigned ballCount) override;

private:
	unsigned m_count = 0;
	unsigned m_quartersCount = 0;
	CSoldState m_soldState;
	CSoldOutState m_soldOutState;
	CNoQuarterState m_noQuarterState;
	CHasQuarterState m_hasQuarterState;
	CHasMaxQuartersState m_hasMaxQuartersState;
	IState* m_state;
};
