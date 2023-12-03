#include "CMenu.h"
#include <string>
#include <sstream>

void CMenu::AddItem(const std::string& shortcut, const std::string& description, const Command& command)
{
	m_items.emplace_back(shortcut, description, command);
}

void CMenu::Run()
{
	ShowInstructions();

	std::string command;
	while ((std::cout << "> ") && getline(std::cin, command) && ExecuteCommand(command))
	{
	}
}

void CMenu::ShowInstructions() const
{
	std::cout << "Commands list:" << std::endl;
	for (auto& item : m_items)
	{
		std::cout << "  " << item.shortcut << ": " << item.description << std::endl;
	}
}

void CMenu::Exit()
{
	m_exit = true;
}

bool CMenu::ExecuteCommand(const std::string& command)
{
	std::istringstream iss(command);
	std::string name;
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
		std::cout << "Unknown command" << std::endl;
	}
	return !m_exit;
}
