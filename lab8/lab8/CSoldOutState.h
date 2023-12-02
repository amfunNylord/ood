#pragma once
#include "IState.h"
#include "IGumballMachine.h"

class CSoldOutState : public IState
{
public:
	CSoldOutState(IGumballMachine& gumballMachine);
	
	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
	std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
};