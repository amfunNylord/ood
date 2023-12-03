#include "CMultiGumballMachineController.h"

CMultiGumballMachineController::CMultiGumballMachineController()
	: m_gumballMachine(CMultiGumballMachine(0))
{
	m_menu.AddItem("InsertQuarter", "Insert quarter into machine", [this](std::istream&) { InsertQuarter(); });
	m_menu.AddItem("EjectQuarter", "Eject all quarters from machine", [this](std::istream&) { EjectQuarter(); });
	m_menu.AddItem("AddGumballs", "Refill machine with new gumballs", [this](std::istream& in) { AddBalls(in); });
	m_menu.AddItem("TurnCrank", "Turn machine's crank", [this](std::istream&) { TurnCrank(); });
	m_menu.AddItem("GetMachineState", "Get know about machine state", [this](std::istream&) { GetMachineState(); });
	m_menu.AddItem("Help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("Exit", "Exit", [this](std::istream&) { m_menu.Exit(); });
}

void CMultiGumballMachineController::Start()
{
	m_menu.Run();
}

void CMultiGumballMachineController::InsertQuarter()
{
	m_gumballMachine.InsertQuarter();
}

void CMultiGumballMachineController::EjectQuarter()
{
	m_gumballMachine.EjectQuarter();
}

void CMultiGumballMachineController::AddBalls(std::istream& in)
{
	unsigned count;
	in >> count;
	m_gumballMachine.AddBalls(count);
}

void CMultiGumballMachineController::TurnCrank()
{
	m_gumballMachine.TurnCrank();
}

void CMultiGumballMachineController::GetMachineState()
{
	std::cout << m_gumballMachine.ToString() << std::endl;
}
