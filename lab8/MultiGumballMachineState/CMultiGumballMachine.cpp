#include "CMultiGumballMachine.h"

CMultiGumballMachine::CMultiGumballMachine(unsigned numBalls)
	: m_soldState(*this)
	, m_soldOutState(*this)
	, m_noQuarterState(*this)
	, m_hasQuarterState(*this)
	, m_hasMaxQuartersState(*this)
	, m_state(&m_soldOutState)
	, m_count(numBalls)
{
	if (m_count > 0)
	{
		m_state = &m_noQuarterState;
	}
}

void CMultiGumballMachine::EjectQuarter()
{
	m_state->EjectQuarter();
}

void CMultiGumballMachine::InsertQuarter()
{
	m_state->InsertQuarter();
}

void CMultiGumballMachine::TurnCrank()
{
	m_state->TurnCrank();
	m_state->Dispense();
}

std::string CMultiGumballMachine::ToString() const
{
	std::string str = "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\nInventory: " + 
					  std::to_string(m_count) + " gumball" + (m_count != 1 ? "s" : "") + "\nMachine is " + m_state->ToString();
	return str;
}

unsigned CMultiGumballMachine::GetBallCount() const
{
	return m_count;
}

unsigned CMultiGumballMachine::GetQuarterCount() const
{
	return m_quartersCount;
}

void CMultiGumballMachine::SetQuarterCount(unsigned count)
{
	m_quartersCount = count;
}

void CMultiGumballMachine::ReleaseBall()
{
	if (m_count != 0)
	{
		std::cout << "A gumball comes rolling out the slot...\n";
		--m_count;
	}
}

void CMultiGumballMachine::SetSoldOutState()
{
	m_state = &m_soldOutState;
}

void CMultiGumballMachine::SetNoQuarterState()
{
	m_state = &m_noQuarterState;
}

void CMultiGumballMachine::SetSoldState()
{
	m_state = &m_soldState;
}

void CMultiGumballMachine::SetHasQuarterState()
{
	m_state = &m_hasQuarterState;
}

void CMultiGumballMachine::SetHasMaxQuartersState()
{
	m_state = &m_hasMaxQuartersState;
}
