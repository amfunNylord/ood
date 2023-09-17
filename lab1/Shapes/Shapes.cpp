#include <iostream>
#include "CommandController.h"

int main()
{
	shape::Picture picture;
	CommandController commandController(std::cin, std::cout, picture);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!commandController.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}

	return 0;
}
