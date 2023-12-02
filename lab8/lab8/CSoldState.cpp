#include "CSoldState.h"

CSoldState::CSoldState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldState::InsertQuarter()
{
	std::cout << "Please wait, we're already giving you a gumball\n";
}

void CSoldState::EjectQuarter()
{
	std::cout << "Sorry you already turned the crank\n";
}

void CSoldState::TurnCrank()
{
	std::cout << "Turning twice doesn't get you another gumball\n";
}

void CSoldState::Dispense()
{
	m_gumballMachine.ReleaseBall();
	if (m_gumballMachine.GetBallCount() == 0)
	{
		std::cout << "Oops, out of gumballs\n";
		m_gumballMachine.SetSoldOutState();
	}
	else
	{
		m_gumballMachine.SetNoQuarterState();
	}
}

std::string CSoldState::ToString() const
{
	return "delivering a gumball";
}
