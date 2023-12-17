#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class CMenuFP
{
public:
	typedef std::function<void()> Command;
	void AddItem(
		const std::string& shortcut,
		const std::string& description,
		const Command& command)
	{
		m_items.emplace_back(shortcut, description, command);
	}

	void Run()
	{
		ShowInstructions();

		std::string command;
		while ((std::cout << ">")
			&& getline(std::cin, command)
			&& ExecuteCommand(command))
		{
		}
	}

	void ShowInstructions() const
	{
		std::cout << "Commands list:\n";
		for (auto& item : m_items)
		{
			std::cout << "  " << item.shortcut << ": " << item.description << "\n";
		}
	}

	void Exit()
	{
		m_exit = true;
	}

	void BeginMacro()
	{
		if (!m_macroEditing)
		{
			std::cout << "Enter macro shortcut: ";
			std::getline(std::cin, m_macroInfo.shortcut);

			std::cout << "Enter macro description: ";
			std::getline(std::cin, m_macroInfo.description);

			std::cout << "Enter commands which makes up macro... To finish add commands execute 'end_macro' command\n";

			m_macroEditing = true;

			std::string command;
			while ((std::cout << ">")
				&& getline(std::cin, command)
				&& AddCommandToMacro(m_macroInfo.commands, command))
			{
			}
		}
		else
		{
			std::cout << "Can't execute begin_macro inside another macro" << std::endl;
		}
	}

	void EndMacro()
	{
		if (m_macroEditing)
		{
			AddItem(m_macroInfo.shortcut, m_macroInfo.description, [*this]() {
				for (auto& command : m_macroInfo.commands)
				{
					command();
				}
			});

			m_macroInfo.commands.clear();

			m_macroEditing = false;

			std::cout << "Macro successfully created." << std::endl;
		}
		else
		{
			std::cout << "Command 'end_macro' cannot be executed before 'begin_macro'" << std::endl;
		}
	}

private:
	bool ExecuteCommand(const std::string& command)
	{
		m_exit = false;
		auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item& item) {
			return item.shortcut == command;
		});
		if (it != m_items.end())
		{
			it->command();
		}
		else
		{
			std::cout << "Unknown command\n";
		}
		return !m_exit;
	}

	bool AddCommandToMacro(std::vector<Command>& commands, const std::string& command)
	{
		auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item& item) {
			return item.shortcut == command;
		});
		if (it != m_items.end())
		{
			if (command == "begin_macro" || command == "end_macro")
			{
				it->command();
			}
			else
			{
				commands.push_back(it->command);
			}
		}
		else
		{
			std::cout << "Unknown command\n";
		}

		return m_macroEditing;
	}

	struct Item
	{
		Item(const std::string& shortcut, const std::string& description, const Command& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{
		}

		std::string shortcut;
		std::string description;
		Command command;
	};
	std::vector<Item> m_items;

	struct MacroInfo
	{
		std::string shortcut;
		std::string description;
		std::vector<Command> commands;
	};

	MacroInfo m_macroInfo;

	bool m_exit = false;
	bool m_macroEditing = false;
};