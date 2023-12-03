#pragma once
#include "IState.h"
#include "IMultiGumballMachine.h"

class CSoldState : public IState
{
public:
	CSoldState(IMultiGumballMachine& gumballMachine);
	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void AddBalls(unsigned count) override;
	void Dispense() override;
	std::string ToString() const override;

private:
	IMultiGumballMachine& m_gumballMachine;
};
