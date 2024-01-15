#include <iostream>
#include "CommandController.h"
#include <SFML/Window.hpp>
#include "CCanvas.h"

int main()
{
	shape::Picture picture;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes", sf::Style::Close);
	window.setFramerateLimit(60);
	CCanvas canvas(sf::Color(), 0.0, 0.0, window);
	CommandController commandController(std::cin, std::cout, picture, window, canvas);
	while (window.isOpen())
	{
		while (!std::cin.eof() && !std::cin.fail())
		{
			std::cout << "> ";
			if (!commandController.HandleCommand())
			{
				std::cout << "Unknown command!" << std::endl;
			}
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}