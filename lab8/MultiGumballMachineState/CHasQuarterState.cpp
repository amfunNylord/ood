#include "CHasQuarterState.h"

const int MAX_QUARTERS_COUNT = 5;

CHasQuarterState::CHasQuarterState(IMultiGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CHasQuarterState::InsertQuarter()
{
	std::cout << "You inserted a quarter" << std::endl;
	m_gumballMachine.SetQuarterCount(m_gumballMachine.GetQuarterCount() + 1);
	if (m_gumballMachine.GetQuarterCount() == MAX_QUARTERS_COUNT)
	{
		std::cout << "You inserted max quarters" << std::endl;
		m_gumballMachine.SetHasMaxQuartersState();
	}
}

void CHasQuarterState::EjectQuarter()
{
	std::cout << "Quarter" << (m_gumballMachine.GetQuarterCount() > 1 ? "s" : "") << " returned" << std::endl;
	m_gumballMachine.SetQuarterCount(0);
	m_gumballMachine.SetNoQuarterState();
}

void CHasQuarterState::TurnCrank()
{
	std::cout << "You turned...\n";
	m_gumballMachine.SetQuarterCount(m_gumballMachine.GetQuarterCount() - 1);
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
