#pragma once
#include <functional>
#include <iostream>

class CMenu
{
public:
	using Command = std::function<void(std::istream &args)>;
	void AddItem(const std::string& shortcut, const std::string& description, const Command& command);
	void Run();
	void ShowInstructions() const;
	void Exit();

private:
	bool ExecuteCommand(const std::string& command);

	struct Item
	{
		Item(const std::string& shortcut, const std::string& description, const Command& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{}

		std::string shortcut;
		std::string description;
		Command command;
	};

	std::vector<Item> m_items;
	bool m_exit = false;
};
