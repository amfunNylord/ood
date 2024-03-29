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

CommandController::CommandController(std::istream& input, std::ostream& output, shape::Picture& picture, sf::RenderWindow& window, CCanvas& canvas)
	: m_input(input)
	, m_output(output)
	, m_picture(picture)
	, m_window(window)
	, m_canvas(canvas)
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

bool CommandController::AddShape(std::istream& args)
{
	std::string shapeId, shapeColor, shapeType;
	args >> shapeId >> shapeColor >> shapeType;
	std::unique_ptr<shape::ShapeType> shape;

	if (shapeType == CIRCLE_TYPE)
	{
		double x, y, r;
		args >> x >> y >> r;
		shape = std::make_unique<shape::Circle>(CIRCLE_TYPE, shapeColor, x, y, r);
	}
	else if (shapeType == RECTANGLE_TYPE)
	{
		double left, top, width, height;
		args >> left >> top >> width >> height;
		shape = std::make_unique<shape::Rectangle>(RECTANGLE_TYPE, shapeColor, left, top, width, height);
	}
	else if (shapeType == TRIANGLE_TYPE)
	{
		double x1, y1, x2, y2, x3, y3;
		args >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		shape = std::make_unique<shape::Triangle>(TRIANGLE_TYPE, shapeColor, x1, y1, x2, y2, x3, y3);
	}
	else if (shapeType == LINE_TYPE)
	{
		double x1, y1, x2, y2;
		args >> x1 >> y1 >> x2 >> y2;
		shape = std::make_unique<shape::Line>(LINE_TYPE, shapeColor, x1, y1, x2, y2);
	}
	else if (shapeType == TEXT_TYPE)
	{
		double left, top, size;
		args >> left >> top >> size;
		std::string textContents;
		getline(args, textContents);
		textContents.erase(textContents.begin());
		shape = std::make_unique<shape::Text>(TEXT_TYPE, shapeColor, left, top, size, textContents);
	}
	else
	{
		m_output << "Incorrect type" << std::endl;
		return true;
	}
	m_picture.AddShape(std::make_unique<shape::Shape>(shapeId, std::move(shape)));
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
	auto changeableShape = m_picture.GetShape(shapeId, m_output);
	if (changeableShape == nullptr)
	{
		return true;
	}
	changeableShape->GetShapeType()->SetColor(shapeColor);
	return true;
}

bool CommandController::ChangeShape(std::istream& args)
{
	std::string shapeId, shapeType;
	args >> shapeId >> shapeType;

	auto changeableShape = m_picture.GetShape(shapeId, m_output);
	if (changeableShape == nullptr)
	{
		return true;
	}

	if (std::find(AVAILABLE_TYPES.begin(), AVAILABLE_TYPES.end(), shapeType) == AVAILABLE_TYPES.end())
	{
		m_output << "Incorrect type" << std::endl;
		return true;
	}

	std::unique_ptr<shape::ShapeType> shape;
	std::string shapeColor = changeableShape->GetShapeType()->GetColor();

	if (shapeType == CIRCLE_TYPE)
	{
		double x, y, r;
		args >> x >> y >> r;
		shape = std::make_unique<shape::Circle>(CIRCLE_TYPE, shapeColor, x, y, r);
	}
	else if (shapeType == RECTANGLE_TYPE)
	{
		double left, top, width, height;
		args >> left >> top >> width >> height;
		shape = std::make_unique<shape::Rectangle>(RECTANGLE_TYPE, shapeColor, left, top, width, height);
	}
	else if (shapeType == TRIANGLE_TYPE)
	{
		double x1, y1, x2, y2, x3, y3;
		args >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		shape = std::make_unique<shape::Triangle>(TRIANGLE_TYPE, shapeColor, x1, y1, x2, y2, x3, y3);
	}
	else if (shapeType == LINE_TYPE)
	{
		double x1, y1, x2, y2;
		args >> x1 >> y1 >> x2 >> y2;
		shape = std::make_unique<shape::Line>(LINE_TYPE, shapeColor, x1, y1, x2, y2);
	}
	else if (shapeType == TEXT_TYPE)
	{
		double left, top, size;
		args >> left >> top >> size;
		std::string textContents;
		getline(args, textContents);
		textContents.erase(textContents.begin());
		shape = std::make_unique<shape::Text>(TEXT_TYPE, shapeColor, left, top, size, textContents);
	}

	changeableShape->ChangeShape(shapeId, shapeType, std::move(shape));

	return true;
}

bool CommandController::DrawShape(std::istream& args)
{
	std::string shapeId;
	args >> shapeId;
	
	auto drawableShape = m_picture.GetShape(shapeId, m_output);
	if (drawableShape == nullptr)
	{
		return true;
	}

	drawableShape->GetShapeType()->Draw(&m_canvas);

	m_window.display();

	return true;
}

bool CommandController::DrawPicture()
{
	const auto& allShapes = m_picture.GetAllShapes();

	for (const auto& shape : allShapes)
	{
		shape->GetShapeType()->Draw(&m_canvas);
	}

	m_window.display();

	return true;
}

bool CommandController::MoveShape(std::istream& args)
{
	std::string shapeId;
	args >> shapeId;

	auto drawableShape = m_picture.GetShape(shapeId, m_output);
	if (drawableShape == nullptr)
	{
		return true;
	}
	double dx, dy;
	args >> dx >> dy;
	drawableShape->GetShapeType()->MoveShape(dx, dy);

	return true;
}

bool CommandController::MovePicture(std::istream& args)
{
	double dx, dy;
	args >> dx >> dy;

	const auto& allShapes = m_picture.GetAllShapes();

	for (const auto& shape : allShapes)
	{
		shape->GetShapeType()->MoveShape(dx, dy);
	}
	return true;
}
