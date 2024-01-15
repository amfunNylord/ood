#include "Picture.h"
#include "Shape.h"
#include <memory>
#include <iostream>

shape::Picture::Picture(const Picture& other)
{
	for (const auto& shape : other.m_shapesVector)
	{
		m_shapesVector.emplace_back(std::make_unique<Shape>(*shape));
	}
}

void shape::Picture::AddShape(std::unique_ptr<Shape> shape)
{
	m_shapesVector.emplace_back(std::move(shape));
}

void shape::Picture::DeleteShape(const std::string& shapeId, std::ostream& output)
{
	auto it = std::remove_if(m_shapesVector.begin(), m_shapesVector.end(),
		[&shapeId](const std::unique_ptr<Shape>& shape) {
			return shape->GetId() == shapeId;
		});
	if (it != m_shapesVector.end()) {
		m_shapesVector.erase(it, m_shapesVector.end());
	}
	else {
		output << "Shape with such id isn't exist" << std::endl;
	}
}

void shape::Picture::List(std::ostream& output)
{
	size_t shapesCount = m_shapesVector.size();
	for (size_t i = 0; i < shapesCount; i++)
	{
		output << i + 1 << ' ' << m_shapesVector[i]->ToString();
	}
}

std::unique_ptr<shape::Shape> shape::Picture::GetShape(const std::string& shapeId, std::ostream& output)
{
	auto it = std::find_if(m_shapesVector.begin(), m_shapesVector.end(),
		[&shapeId](const std::unique_ptr<Shape>& shape) {
			return shape->GetId() == shapeId;
		});

	if (it != m_shapesVector.end()) {
		return std::move(*it);
	}
	else {
		output << "Shape with such id isn't exist" << std::endl;
		return nullptr;
	}
}

const std::vector<std::unique_ptr<shape::Shape>>& shape::Picture::GetAllShapes() const
{
	return m_shapesVector;
}
