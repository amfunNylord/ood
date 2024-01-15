#include "CCanvas.h"
#include "CEllipse.h"
#include "CGroup.h"
#include "CRectangle.h"
#include "CSlide.h"
#include "CTriangle.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void MakePicture(std::shared_ptr<CSlide> slide)
{
	auto field = std::make_shared<CRectangle>(0, 300, 800, 300);
	field->GetFillStyle()->Enable();
	field->GetFillStyle()->SetColor(0x009900CC);

	auto sky = std::make_shared<CRectangle>(0, 0, 800, 300);
	sky->GetFillStyle()->Enable();
	sky->GetFillStyle()->SetColor(0x0000FFFF);

	auto sun = std::make_shared<CEllipse>(PointD(500, 100), 50, 50);
	sun->GetFillStyle()->Enable();
	sun->GetFillStyle()->SetColor(0xECEC53FF);

	auto houseMain = std::make_shared<CRectangle>(100, 250, 200, 150);
	houseMain->GetFillStyle()->Enable();
	houseMain->GetFillStyle()->SetColor(0x6A4100FF);

	auto houseRoof = std::make_shared<CTriangle>(PointD{ 80, 250 }, PointD{ 200, 150 }, PointD{ 320, 250 });
	houseRoof->GetFillStyle()->Enable();
	houseRoof->GetFillStyle()->SetColor(0x787878FF);
	houseRoof->GetLineStyle()->Enable();
	houseRoof->GetLineStyle()->SetColor(0x000000FF);
	houseRoof->GetLineStyle()->SetThickness(4);

	auto group = std::make_shared<CGroup>();
	group->InsertShape(field, 0);
	group->InsertShape(sky, 1);
	group->InsertShape(sun, 2);
	group->InsertShape(houseMain, 3);
	group->InsertShape(houseRoof, 4);
	//group->SetFrame(RectD(400, 300, 400, 300));
	slide->InsertShape(group, 0);
}

int main()
{
	auto slide = std::make_shared<CSlide>(800, 600);
	MakePicture(slide);
	sf::RenderWindow window(sf::VideoMode(800, 600), "lab7", sf::Style::Close);
	CCanvas canvas(window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::White);
		slide->Draw(canvas);
		window.display();
	}
	return 0;
}