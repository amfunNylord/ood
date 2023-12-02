#pragma once
#include <iostream>
#include <string>

const int MAX_QUARTERS_COUNT = 5;

namespace naive
{
class CMultiGumballMachine
{
public:
	enum class State
	{
		SoldOut, // Жвачка закончилась
		NoQuarter, // Нет монетки
		HasQuarter, // Есть монетка
		Sold, // Монетка выдана
		HasMaxQuarters, // Максимальное кол-во монеток
	};

	CMultiGumballMachine(unsigned count)
		: m_count(count)
		, m_state(count > 0 ? State::NoQuarter : State::SoldOut)
	{
	}

	void InsertQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You can't insert a quarter, the machine is sold out\n";
			break;
		case State::NoQuarter:
			cout << "You inserted a quarter\n";
			m_quartersCount++;
			m_state = State::HasQuarter;
			break;
		case State::HasQuarter:
			cout << "You inserted a quarter" << endl;
			m_quartersCount++;
			if (m_quartersCount == MAX_QUARTERS_COUNT)
			{
				cout << "You inserted max quarters" << endl;
				m_state = State::HasMaxQuarters;
			}
			break;
		case State::Sold:
			cout << "Please wait, we're already giving you a gumball\n";
			break;
		case State::HasMaxQuarters:
			cout << "You can't insert more quarters" << endl;
			break;
		}
	}

	void EjectQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::HasQuarter:
		case State::HasMaxQuarters:
			cout << "Quarter" << (m_quartersCount > 1 ? "s" : "") << " returned" << endl;
			m_quartersCount = 0;
			m_state = State::NoQuarter;
			break;
		case State::NoQuarter:
			cout << "You haven't inserted a quarter\n";
			break;
		case State::Sold:
			cout << "Sorry you already turned the crank\n";
			break;
		case State::SoldOut:
			if (m_quartersCount != 0)
			{
				cout << "Quarter" << (m_quartersCount > 1 ? "s" : "") << " returned" << endl;
				m_quartersCount = 0;
			}
			else
			{
				cout << "You can't eject, you haven't inserted a quarter yet" << endl;
			}
			break;
		}
	}

	void TurnCrank()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You turned but there's no gumballs\n";
			break;
		case State::NoQuarter:
			cout << "You turned but there's no quarter\n";
			break;
		case State::HasQuarter:
		case State::HasMaxQuarters:
			cout << "You turned...\n";
			m_quartersCount--;
			m_state = State::Sold;
			Dispense();
			break;
		case State::Sold:
			cout << "Turning twice doesn't get you another gumball\n";
			break;
		}
	}

	void Refill(unsigned numBalls)
	{
		m_count = numBalls;
		m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
	}

	std::string ToString() const
	{
		std::string state = (m_state == State::SoldOut) ? "sold out" : 
							(m_state == State::NoQuarter) ? "waiting for quarter" : 
							(m_state == State::HasQuarter) ? "waiting for turn of crank" : "delivering a gumball";
		auto fmt = "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\nInventory: " + 
				   std::to_string(m_count) + " gumball" + (m_count != 1 ? "s" : "") + "\nMachine is " + state;
		return fmt;
	}

private:
	void Dispense()
	{
		using namespace std;
		switch (m_state)
		{
		case State::Sold:
			cout << "A gumball comes rolling out the slot\n";
			--m_count;
			if (m_count == 0)
			{
				cout << "Oops, out of gumballs\n";
				m_state = State::SoldOut;
			}
			else if (m_quartersCount)
			{
				m_state = State::HasQuarter;
			}
			else
			{
				m_state = State::NoQuarter;
			}
			break;
		case State::NoQuarter:
			cout << "You need to pay first\n";
			break;
		case State::SoldOut:
		case State::HasQuarter:
			cout << "No gumball dispensed\n";
			break;
		}
	}

	unsigned m_count; // Количество шариков
	State m_state = State::SoldOut;
	unsigned m_quartersCount = 0;
};
} // namespace naive