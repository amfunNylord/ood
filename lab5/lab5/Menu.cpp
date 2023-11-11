#include "stdafx.h"
#include "Menu.h"

using namespace std;

void CMenu::AddItem(const string & shortcut, const string & description, const Command & command)
{
	m_items.emplace_back(shortcut, description, command);
}

void CMenu::Run()
{
	ShowInstructions();

	string command;
	while ((cout << ">")
		&& getline(cin, command)
		&& ExecuteCommand(command))
	{
	}
}

void CMenu::ShowInstructions() const
{
	cout << "Commands list:\n";
	for (auto & item : m_items)
	{
		cout << "  " << item.shortcut << ": " << item.description << "\n";
	}
}

void CMenu::Exit()
{
	m_exit = true;
}

bool CMenu::ExecuteCommand(const string& command)
{
	istringstream iss(command);
	string name;
	iss >> name;

	m_exit = false;
	auto it = m_items.begin();
	while (it != m_items.end())
	{
		if ((*it).shortcut == name)
		{
			break;
		}
		it++;
	}
	if (it != m_items.end())
	{
		it->command(iss);
	}
	else
	{
		cout << "Unknown command" << std::endl;
	}
	return !m_exit;
}
