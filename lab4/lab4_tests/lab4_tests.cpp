#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab4/ICanvas.h"
#include "../lab4/CDesigner.h"
#include "../lab4/CPainter.h"
#include "../lab4/CShapeFactory.h"
#include "../lab4/CRectangle.h"
#include "../lab4/CTriangle.h"
#include "../lab4/CEllipse.h"
#include "../lab4/CRegularPolygon.h"

class TextCanvas : public ICanvas
{
public:
	TextCanvas(std::ostream& output)
		: m_output(output)
	{}

	void SetColor(Color c) override
	{
		std::string strColor;
		switch (c)
		{
		case Color::Green:
			strColor = "green";
			break;
		case Color::Red:
			strColor = "red";
			break;
		case Color::Black:
			strColor = "black";
			break;
		case Color::Blue:
			strColor = "blue";
			break;
		case Color::Yellow:
			strColor = "yellow";
			break;
		case Color::Pink:
			strColor = "pink";
			break;
		}
		m_output << "set color " << strColor << std::endl;
	}

	void DrawLine(Point from, Point to) override
	{
		m_output << "draw line from " << from.x << ' ' << from.y << " to " << to.x << ' ' << to.y << std::endl;
	}

	void DrawEllipse(Point center, double horizontalRadius, double verticalRadius) override
	{
		m_output << "draw ellipse, center is " << center.x << ' ' << center.y << ", horizontal radius is " << horizontalRadius 
				 << ", vertical radius is " << verticalRadius << std::endl;
	}

private:
	std::ostream& m_output;
	Color m_color = Color::Black;
};

SCENARIO("Test CPictureDraft")
{
	std::ostringstream output;
	WHEN("We only created draft")
	{
		CPictureDraft draft;
		THEN("It is empty")
		{
			REQUIRE(draft.IsEmpty() == true);
		}
	}
	CPictureDraft draft;
	WHEN("We add some shape")
	{
		std::unique_ptr<CShape> rectangle = std::make_unique<CRectangle>(Color::Green, Point(100, 100), Point(500, 500), 0);
		draft.AddShape(std::move(rectangle));
		THEN("It isn't empty")
		{
			REQUIRE(draft.IsEmpty() == false);
		}
	}
	WHEN("We add 3 shapes")
	{
		std::unique_ptr<CShape> rectangle = std::make_unique<CRectangle>(Color::Green, Point(100, 100), Point(500, 500), 0);
		std::unique_ptr<CShape> triangle = std::make_unique<CTriangle>(Color::Black, Point(100, 100), Point(200, 200), Point(300, 300), 1);
		std::unique_ptr<CShape> ellipse = std::make_unique<CEllipse>(Color::Pink, Point(250, 250), 100, 200, 2);
		draft.AddShape(std::move(rectangle));
		draft.AddShape(std::move(triangle));
		draft.AddShape(std::move(ellipse));
		THEN("GetShapeCount() return 3")
		{
			REQUIRE(draft.GetShapeCount() == 3);
		}
	}
}

SCENARIO("Test CShapeFactory and all shapes")
{
	CShapeFactory factory;
	CPainter painter;
	CPictureDraft draft;
	std::ostringstream output;
	auto canvas = std::make_unique<TextCanvas>(output);
	WHEN("Adds rectangle with valid values")
	{
		draft.AddShape(factory.CreateShape("rectangle yellow 100 100 200 200"));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation")
		{
			REQUIRE(output.str() == "set color yellow\ndraw line from 100 100 to 200 100\ndraw line from 200 100 to 200 200\n"
									"draw line from 200 200 to 100 200\ndraw line from 100 200 to 100 100\n");
		}
	}
	WHEN("Adds triangle with valid values")
	{
		draft.AddShape(factory.CreateShape("triangle black 100 100 200 200 300 300"));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation")
		{
			REQUIRE(output.str() == "set color black\ndraw line from 100 100 to 200 200\ndraw line from 200 200 to 300 300\n"
									"draw line from 300 300 to 100 100\n");
		}
	}
	WHEN("Adds ellipse with valid values")
	{
		draft.AddShape(factory.CreateShape("ellipse pink 250 250 100 200"));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation")
		{
			REQUIRE(output.str() == "set color pink\ndraw ellipse, center is 250 250, horizontal radius is 100, vertical radius is 200\n");
		}
	}
	WHEN("Adds polygon with valid values")
	{
		draft.AddShape(factory.CreateShape("polygon green 8 100 150 50"));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation")
		{
			REQUIRE(output.str() == "set color green\ndraw line from 150 150 to 135.355 185.355\ndraw line from 135.355 185.355 to 100 200\n"
									"draw line from 100 200 to 64.6447 185.355\ndraw line from 64.6447 185.355 to 50 150\n"
									"draw line from 50 150 to 64.6447 114.645\ndraw line from 64.6447 114.645 to 100 100\n"
									"draw line from 100 100 to 135.355 114.645\ndraw line from 135.355 114.645 to 150 150\n");
		}
	}
}

SCENARIO("Test CPainter")
{
	CPainter painter;
	CPictureDraft draft;
	std::ostringstream output;
	auto canvas = std::make_unique<TextCanvas>(output);
	WHEN("Trying to draw rectangle")
	{
		std::unique_ptr<CShape> rectangle = std::make_unique<CRectangle>(Color::Green, Point(100, 100), Point(500, 500), 0);
		draft.AddShape(std::move(rectangle));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation rectangle")
		{
			REQUIRE(output.str() == "set color green\ndraw line from 100 100 to 500 100\ndraw line from 500 100 to 500 500\n"
									"draw line from 500 500 to 100 500\ndraw line from 100 500 to 100 100\n");
		}
	}
	WHEN("Trying to draw triangle")
	{
		std::unique_ptr<CShape> triangle = std::make_unique<CTriangle>(Color::Black, Point(100, 100), Point(200, 200), Point(300, 300), 0);
		draft.AddShape(std::move(triangle));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation triangle")
		{
			REQUIRE(output.str() == "set color black\ndraw line from 100 100 to 200 200\ndraw line from 200 200 to 300 300\n"
									"draw line from 300 300 to 100 100\n");
		}
	}
	WHEN("Trying to draw ellipse")
	{
		std::unique_ptr<CShape> ellipse = std::make_unique<CEllipse>(Color::Pink, Point(250, 250), 100, 200, 0);
		draft.AddShape(std::move(ellipse));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation ellipse")
		{
			REQUIRE(output.str() == "set color pink\ndraw ellipse, center is 250 250, horizontal radius is 100, vertical radius is 200\n");
		}
	}
	WHEN("Trying to draw polygon")
	{
		std::unique_ptr<CShape> polygon = std::make_unique<CRegularPolygon>(Color::Green, 8, Point(100, 150), 50, 0);
		draft.AddShape(std::move(polygon));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the message of creation polygon")
		{
			REQUIRE(output.str() == "set color green\ndraw line from 150 150 to 135.355 185.355\ndraw line from 135.355 185.355 to 100 200\n"
									"draw line from 100 200 to 64.6447 185.355\ndraw line from 64.6447 185.355 to 50 150\n"
									"draw line from 50 150 to 64.6447 114.645\ndraw line from 64.6447 114.645 to 100 100\n"
									"draw line from 100 100 to 135.355 114.645\ndraw line from 135.355 114.645 to 150 150\n");
		}
	}
	WHEN("Trying to draw all shapes together")
	{
		std::unique_ptr<CShape> rectangle = std::make_unique<CRectangle>(Color::Green, Point(100, 100), Point(500, 500), 0);
		std::unique_ptr<CShape> triangle = std::make_unique<CTriangle>(Color::Black, Point(100, 100), Point(200, 200), Point(300, 300), 1);
		std::unique_ptr<CShape> ellipse = std::make_unique<CEllipse>(Color::Pink, Point(250, 250), 100, 200, 2);
		std::unique_ptr<CShape> polygon = std::make_unique<CRegularPolygon>(Color::Green, 8, Point(100, 150), 50, 3);
		draft.AddShape(std::move(rectangle));
		draft.AddShape(std::move(triangle));
		draft.AddShape(std::move(ellipse));
		draft.AddShape(std::move(polygon));
		painter.DrawPicture(draft, canvas.get());
		THEN("We get the messages of creation all shapes")
		{
			REQUIRE(output.str() == "set color green\ndraw line from 100 100 to 500 100\ndraw line from 500 100 to 500 500\n"
									"draw line from 500 500 to 100 500\ndraw line from 100 500 to 100 100\n"
									"set color black\ndraw line from 100 100 to 200 200\ndraw line from 200 200 to 300 300\n"
									"draw line from 300 300 to 100 100\n"
									"set color pink\ndraw ellipse, center is 250 250, horizontal radius is 100, vertical radius is 200\n"
									"set color green\ndraw line from 150 150 to 135.355 185.355\ndraw line from 135.355 185.355 to 100 200\n"
									"draw line from 100 200 to 64.6447 185.355\ndraw line from 64.6447 185.355 to 50 150\n"
									"draw line from 50 150 to 64.6447 114.645\ndraw line from 64.6447 114.645 to 100 100\n"
									"draw line from 100 100 to 135.355 114.645\ndraw line from 135.355 114.645 to 150 150\n");
		}
	}
}

SCENARIO("Test CDesigner class")
{
	CDesigner designer(std::make_unique<CShapeFactory>());
	CPainter painter;
	std::ostringstream output;
	auto canvas = std::make_unique<TextCanvas>(output);
	WHEN("We're trying to create figures with valid values and draw them")
	{
		std::istringstream input("rectangle red 100 100 500 500\ntriangle yellow 100 100 200 200 300 300\n"
				                 "ellipse pink 250 250 100 200\npolygon green 8 100 150 50\n");
		painter.DrawPicture(designer.CreateDraft(input), canvas.get());
		THEN("Gets messages of drawing elements")
		{
			REQUIRE(output.str() == "set color red\ndraw line from 100 100 to 500 100\ndraw line from 500 100 to 500 500\n"
									"draw line from 500 500 to 100 500\ndraw line from 100 500 to 100 100\nset color yellow\n"
									"draw line from 100 100 to 200 200\ndraw line from 200 200 to 300 300\ndraw line from 300 300 to 100 100\n"
									"set color pink\ndraw ellipse, center is 250 250, horizontal radius is 100, vertical radius is 200\n"
									"set color green\ndraw line from 150 150 to 135.355 185.355\ndraw line from 135.355 185.355 to 100 200\n"
									"draw line from 100 200 to 64.6447 185.355\ndraw line from 64.6447 185.355 to 50 150\n"
									"draw line from 50 150 to 64.6447 114.645\ndraw line from 64.6447 114.645 to 100 100\n"
									"draw line from 100 100 to 135.355 114.645\ndraw line from 135.355 114.645 to 150 150\n");
		}
	}
}