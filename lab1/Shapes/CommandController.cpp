#include "CommandController.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Text.h"
#include "Triangle.h"

const std::string CIRCLE_TYPE = "circle",
				  RECTANGLE_TYPE = "rectangle",
				  TRIANGLE_TYPE = "triangle",
				  LINE_TYPE = "line",
				  TEXT_TYPE = "text";

const std::vector<std::string> AVAILABLE_TYPES = {CIRCLE_TYPE, RECTANGLE_TYPE, TRIANGLE_TYPE, LINE_TYPE, TEXT_TYPE};

CommandController::CommandController(std::istream& input, std::ostream& output, shape::Picture& picture)
	: m_input(input)
	, m_output(output)
	, m_picture(picture)
	, m_actionMap({
		  { "AddShape", bind(&CommandController::AddShape, this, std::placeholders::_1) },
		  { "List", std::bind(&CommandController::List, this) },
		  { "DeleteShape", bind(&CommandController::DeleteShape, this, std::placeholders::_1) },
		  { "ChangeColor", bind(&CommandController::ChangeColor, this, std::placeholders::_1) },
		  { "ChangeShape", bind(&CommandController::ChangeShape, this, std::placeholders::_1) },
		  { "DrawShape", bind(&CommandController::DrawShape, this, std::placeholders::_1) },
		  { "DrawPicture", std::bind(&CommandController::DrawPicture, this) },
		  { "MoveShape", bind(&CommandController::MoveShape, this, std::placeholders::_1) },
		  { "MovePicture", bind(&CommandController::MovePicture, this, std::placeholders::_1) }
	  })
{
}

bool CommandController::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

CommandController::~CommandController()
{
}

bool CommandController::AddShape(std::istream& args)
{
	std::string shapeId, shapeColor, shapeType;
	args >> shapeId >> shapeColor >> shapeType;
	std::shared_ptr<shape::ShapeType> shape;

	if (shapeType == CIRCLE_TYPE)
	{
		double x, y, r;
		args >> x >> y >> r;
		shape = std::make_shared<shape::Circle>(CIRCLE_TYPE, shapeColor, x, y, r);
	}
	else if (shapeType == RECTANGLE_TYPE)
	{
		double left, top, width, height;
		args >> left >> top >> width >> height;
		shape = std::make_shared<shape::Rectangle>(RECTANGLE_TYPE, shapeColor, left, top, width, height);
	}
	else if (shapeType == TRIANGLE_TYPE)
	{
		double x1, y1, x2, y2, x3, y3;
		args >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		shape = std::make_shared<shape::Triangle>(TRIANGLE_TYPE, shapeColor, x1, y1, x2, y2, x3, y3);
	}
	else if (shapeType == LINE_TYPE)
	{
		double x1, y1, x2, y2;
		args >> x1 >> y1 >> x2 >> y2;
		shape = std::make_shared<shape::Line>(LINE_TYPE, shapeColor, x1, y1, x2, y2);
	}
	else if (shapeType == TEXT_TYPE)
	{
		double left, top, size;
		args >> left >> top >> size;
		std::string textContents;
		getline(args, textContents);
		textContents.erase(textContents.begin());
		shape = std::make_shared<shape::Text>(TEXT_TYPE, shapeColor, left, top, size, textContents);
	}
	else
	{
		m_output << "Incorrect type" << std::endl;
		return true;
	}
	m_picture.AddShape(std::make_shared<shape::Shape>(shapeId, shape));
	return true;
}

bool CommandController::List()
{
	m_picture.List(m_output);
	return true;
}

bool CommandController::DeleteShape(std::istream& args)
{
	std::string shapeId;
	args >> shapeId;
	m_picture.DeleteShape(shapeId, m_output);
	return true;
}

bool CommandController::ChangeColor(std::istream& args)
{
	std::string shapeId, shapeColor;
	args >> shapeId >> shapeColor;
	std::shared_ptr<shape::Shape> changeableShape = m_picture.GetShape(shapeId, m_output);
	if (changeableShape == nullptr)
	{
		return true;
	}
	changeableShape.get()->GetShapeType()->SetColor(shapeColor);
	return true;
}

bool CommandController::ChangeShape(std::istream& args)
{
	std::string shapeId, shapeType;
	args >> shapeId >> shapeType;

	std::shared_ptr<shape::Shape> changeableShape = m_picture.GetShape(shapeId, m_output);
	if (changeableShape == nullptr)
	{
		return true;
	}

	if (std::find(AVAILABLE_TYPES.begin(), AVAILABLE_TYPES.end(), shapeType) == AVAILABLE_TYPES.end())
	{
		m_output << "Incorrect type" << std::endl;
		return true;
	}
	std::shared_ptr<shape::ShapeType> shape;
	std::string shapeColor = changeableShape.get()->GetShapeType()->GetColor();
	if (shapeType == CIRCLE_TYPE)
	{
		double x, y, r;
		args >> x >> y >> r;
		shape = std::make_shared<shape::Circle>(CIRCLE_TYPE, shapeColor, x, y, r);
	}
	else if (shapeType == RECTANGLE_TYPE)
	{
		double left, top, width, height;
		args >> left >> top >> width >> height;
		shape = std::make_shared<shape::Rectangle>(RECTANGLE_TYPE, shapeColor, left, top, width, height);
	}
	else if (shapeType == TRIANGLE_TYPE)
	{
		double x1, y1, x2, y2, x3, y3;
		args >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		shape = std::make_shared<shape::Triangle>(TRIANGLE_TYPE, shapeColor, x1, y1, x2, y2, x3, y3);
	}
	else if (shapeType == LINE_TYPE)
	{
		double x1, y1, x2, y2;
		args >> x1 >> y1 >> x2 >> y2;
		shape = std::make_shared<shape::Line>(LINE_TYPE, shapeColor, x1, y1, x2, y2);
	}
	else if (shapeType == TEXT_TYPE)
	{
		double left, top, size;
		args >> left >> top >> size;
		std::string textContents;
		getline(args, textContents);
		textContents.erase(textContents.begin());
		shape = std::make_shared<shape::Text>(TEXT_TYPE, shapeColor, left, top, size, textContents);
	}

	changeableShape.get()->ChangeShape(shapeId, shapeType, shape);

	return true;
}

bool CommandController::DrawShape(std::istream& args)
{
	std::string shapeId;
	args >> shapeId;
	
	std::shared_ptr<shape::Shape> drawableShape = m_picture.GetShape(shapeId, m_output);
	if (drawableShape == nullptr)
	{
		return true;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes", sf::Style::Close);
	CCanvas canvas(sf::Color(), 0.0, 0.0, window);

	window.clear(sf::Color::White);

	drawableShape.get()->GetShapeType()->Draw(canvas);

	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return true;
}

bool CommandController::DrawPicture()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes", sf::Style::Close);
	CCanvas canvas(sf::Color(), 0.0, 0.0, window);

	window.clear(sf::Color::White);

	for (const auto& shape : m_picture.GetAllShapes())
	{
		shape.get()->GetShapeType()->Draw(canvas);
	}

	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	return true;
}

bool CommandController::MoveShape(std::istream& args)
{
	std::string shapeId;
	args >> shapeId;

	std::shared_ptr<shape::Shape> drawableShape = m_picture.GetShape(shapeId, m_output);
	if (drawableShape == nullptr)
	{
		return true;
	}
	double dx, dy;
	args >> dx >> dy;
	drawableShape.get()->GetShapeType()->MoveShape(dx, dy);

	return true;
}

bool CommandController::MovePicture(std::istream& args)
{
	double dx, dy;
	args >> dx >> dy;

	for (const auto& shape : m_picture.GetAllShapes())
	{
		shape.get()->GetShapeType()->MoveShape(dx, dy);
	}
	return true;
}
