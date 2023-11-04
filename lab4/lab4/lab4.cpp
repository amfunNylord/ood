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
	std::cout << "Using: <shapeType> <color> <parametrs>" << std::endl
			  << "<shapeType> : rectangle | triangle | ellipse | polygon" << std::endl
			  << "<color> : green | red | blue | yellow | pink | black" << std::endl
			  << "<parametrs> : " << std::endl
			  << "rectangle - <xLeftTop> <yLeftTop> <xRightBottom> <yRightBottom>" << std::endl
			  << "triangle  - <xVertex1> <yVertex1> <xVertex2> <yVertex2> <xVertex3> <yVertex3>" << std::endl
			  << "ellipse   - <xCenter> <yCenter> <horizontalRadius> <verticalRadius>" << std::endl
			  << "polygon   - <vertexCount> <xCenter> <yCenter> <radius>" << std::endl
			  << "\"Ctrl\" + \"Z\" - end of entering figures" << std::endl;

	painter.DrawPicture(designer.CreateDraft(std::cin), canvas.get());
	window.display();
	system("pause");
	return 0;
}