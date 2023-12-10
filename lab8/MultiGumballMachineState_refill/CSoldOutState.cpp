#include "CSoldOutState.h"

CSoldOutState::CSoldOutState(IMultiGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldOutState::InsertQuarter()
{
	std::cout << "You can't insert a quarter, the machine is sold out\n";
}

void CSoldOutState::EjectQuarter()
{
	if (m_gumballMachine.GetQuarterCount() != 0)
	{
		std::cout << "Quarter" << (m_gumballMachine.GetQuarterCount() > 1 ? "s" : "") << " returned" << std::endl;
		m_gumballMachine.SetQuarterCount(0);
	}
	else
	{
		std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
	}
}

void CSoldOutState::TurnCrank()
{
	std::cout << "You turned but there's no gumballs\n";
}

void CSoldOutState::AddBalls(unsigned count)
{
	std::cout << "You added balls" << std::endl;
	m_gumballMachine.RefillBalls(count);
	m_gumballMachine.SetNoQuarterState();
}

void CSoldOutState::Dispense()
{
	std::cout << "No gumball dispensed\n";
}

std::string CSoldOutState::ToString() const
{
	return "sold out";
}