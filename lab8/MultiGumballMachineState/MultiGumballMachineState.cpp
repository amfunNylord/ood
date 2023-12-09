#include "CMultiGumballMachine.h"

using namespace std;

template <typename GumballMachineType>
void TestMultiGumballMachine(GumballMachineType& m)
{
	cout << m.ToString() << endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();

	m.EjectQuarter();

	cout << m.ToString() << endl;

	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.TurnCrank();
	m.TurnCrank();
	m.TurnCrank();
	m.TurnCrank();
	m.EjectQuarter();

	cout << m.ToString() << endl;
}

void TestNaiveMultiGumballMachine()
{
	CMultiGumballMachine m(5);
	TestMultiGumballMachine(m);
}
// подумать уменьшить ли количество состояний
int main()
{
	TestNaiveMultiGumballMachine();
	return 0;
}
