#include "CSoldOutState.h"

CSoldOutState::CSoldOutState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldOutState::InsertQuarter()
{
	std::cout << "You can't insert a quarter, the machine is sold out\n";
}

void CSoldOutState::EjectQuarter()
{
	std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}

void CSoldOutState::TurnCrank()
{
	std::cout << "You turned but there's no gumballs\n";
}

void CSoldOutState::Dispense()
{
	std::cout << "No gumball dispensed\n";
}

std::string CSoldOutState::ToString() const
{
	return "sold out";
}