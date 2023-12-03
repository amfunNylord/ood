#pragma once
#include "IMultiGumballMachine.h"
#include "IState.h"

class CSoldOutState : public IState
{
public:
	CSoldOutState(IMultiGumballMachine& gumballMachine);

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void AddBalls(unsigned count) override;
	void Dispense() override;
	std::string ToString() const override;

private:
	IMultiGumballMachine& m_gumballMachine;
};