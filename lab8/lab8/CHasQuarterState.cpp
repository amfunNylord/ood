#include "CHasQuarterState.h"

CHasQuarterState::CHasQuarterState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CHasQuarterState::InsertQuarter()
{
	std::cout << "You can't insert another quarter\n";
}

void CHasQuarterState::EjectQuarter()
{
	std::cout << "Quarter returned\n";
	m_gumballMachine.SetNoQuarterState();
}

void CHasQuarterState::TurnCrank()
{
	std::cout << "You turned...\n";
	m_gumballMachine.SetSoldState();
}

void CHasQuarterState::Dispense()
{
	std::cout << "No gumball dispensed\n";
}

std::string CHasQuarterState::ToString() const
{
	return "waiting for turn of crank";
}
