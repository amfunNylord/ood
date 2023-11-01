#include <iostream>

#include "CShapeFactory.h"
#include "CDesigner.h"
#include "CPainter.h"
#include "CCanvas.h"

int main()
{
	CDesigner designer(std::make_unique<CShapeFactory>());
	CPainter painter;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Lab4", sf::Style::Close);
	window.setFramerateLimit(60);
	auto canvas = std::make_unique<CCanvas>(sf::Color(), window);
	painter.DrawPicture(designer.CreateDraft(std::cin), canvas.get());
	window.display();
	system("pause");
	return 0;
}