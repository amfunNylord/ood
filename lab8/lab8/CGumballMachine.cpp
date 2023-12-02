#include "CGumballMachine.h"

CGumballMachine::CGumballMachine(unsigned numBalls)
	: m_soldState(*this)
	, m_soldOutState(*this)
	, m_noQuarterState(*this)
	, m_hasQuarterState(*this)
	, m_state(&m_soldOutState)
	, m_count(numBalls)
{
	if (m_count > 0)
	{
		m_state = &m_noQuarterState;
	}
	if (m_count == -1)
	{
		m_state = &m_soldState;
		m_count = 1;
	}
}

void CGumballMachine::EjectQuarter()
{
	m_state->EjectQuarter();
}

void CGumballMachine::InsertQuarter()
{
	m_state->InsertQuarter();
}

void CGumballMachine::TurnCrank()
{
	m_state->TurnCrank();
	m_state->Dispense();
}

std::string CGumballMachine::ToString() const
{
	std::string str = "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\nInventory: " + 
					  std::to_string(m_count) + " gumball" + (m_count != 1 ? "s" : "") + "\nMachine is " + m_state->ToString();
	return str;
}

unsigned CGumballMachine::GetBallCount() const
{
	return m_count;
}

void CGumballMachine::ReleaseBall()
{
	if (m_count != 0)
	{
		std::cout << "A gumball comes rolling out the slot...\n";
		--m_count;
	}
}

void CGumballMachine::SetSoldOutState()
{
	m_state = &m_soldOutState;
}

void CGumballMachine::SetNoQuarterState()
{
	m_state = &m_noQuarterState;
}

void CGumballMachine::SetSoldState()
{
	m_state = &m_soldState;
}

void CGumballMachine::SetHasQuarterState()
{
	m_state = &m_hasQuarterState;
}
