#pragma once
#include "CMultiGumballMachine.h"
#include "CMenu.h"

class CMultiGumballMachineController
{
public:
	CMultiGumballMachineController();
	void Start();

private:
	void InsertQuarter();
	void EjectQuarter();
	void AddBalls(std::istream& in);
	void TurnCrank();
	void GetMachineState();

	CMultiGumballMachine m_gumballMachine;
	CMenu m_menu;
};
