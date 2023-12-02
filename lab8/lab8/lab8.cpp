#include "CGumballMachine.h"

template <typename GumballMachineType>
void TestGumballMachine(GumballMachineType& m)
{
	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();

	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.EjectQuarter();
	m.TurnCrank();

	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.EjectQuarter();

	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();

	std::cout << m.ToString() << std::endl;
}

void TestGumballMachineWithState()
{
	CGumballMachine m(5);
	TestGumballMachine(m);
}

int main()
{
	TestGumballMachineWithState();

	return 0;
}