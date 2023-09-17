#include "Picture.h"
#include "Shape.h"
#include <memory>
#include <iostream>

void shape::Picture::AddShape(std::shared_ptr<Shape> shape)
{
	m_shapesVector.emplace_back(shape);
}

void shape::Picture::DeleteShape(std::string shapeId, std::ostream& output)
{
	size_t shapesCount = m_shapesVector.size();
	for (size_t i = 0; i < shapesCount; i++)
	{
		if (m_shapesVector[i].get()->GetId() == shapeId)
		{
			m_shapesVector.erase(m_shapesVector.begin() + i);
			return;
		}
	}
	output << "Shape with such id isn't exist" << std::endl;
}

void shape::Picture::DrawPicture()
{
}

void shape::Picture::List(std::ostream& output)
{
	size_t shapesCount = m_shapesVector.size();
	for (size_t i = 0; i < shapesCount; i++)
	{
		output << i + 1 << ' ' << m_shapesVector[i]->ToString();
	}
}

std::shared_ptr<shape::Shape> shape::Picture::GetShape(std::string shapeId, std::ostream& output)
{
	size_t shapesCount = m_shapesVector.size();
	for (size_t i = 0; i < shapesCount; i++)
	{
		if (m_shapesVector[i].get()->GetId() == shapeId)
		{
			return m_shapesVector[i];
		}
	}
	output << "Shape with such id isn't exist" << std::endl;
	return nullptr;
}
