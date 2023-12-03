#include "CHasMaxQuartersState.h"

CHasMaxQuartersState::CHasMaxQuartersState(IMultiGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CHasMaxQuartersState::InsertQuarter()
{
	std::cout << "You can't insert more quarters" << std::endl;
}

void CHasMaxQuartersState::EjectQuarter()
{
	std::cout << "Quarter" << (m_gumballMachine.GetQuarterCount() > 1 ? "s" : "") << " returned" << std::endl;
	m_gumballMachine.SetQuarterCount(0);
	m_gumballMachine.SetNoQuarterState();
}

void CHasMaxQuartersState::TurnCrank()
{
	std::cout << "You turned..." << std::endl;
	m_gumballMachine.SetQuarterCount(m_gumballMachine.GetQuarterCount() - 1);
	m_gumballMachine.SetSoldState();
}

void CHasMaxQuartersState::AddBalls(unsigned count)
{
	std::cout << "You added balls" << std::endl;
	m_gumballMachine.RefillBalls(count);
}

void CHasMaxQuartersState::Dispense()
{
	std::cout << "You need to pay first" << std::endl;
}

std::string CHasMaxQuartersState::ToString() const
{
	return "full of quarters";
}
