#pragma once
#include "IState.h"
#include "IMultiGumballMachine.h"

class CHasQuarterState : public IState
{
public:
	CHasQuarterState(IMultiGumballMachine& gumballMachine);

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
	std::string ToString() const override;

private:
	IMultiGumballMachine& m_gumballMachine;
};
