#include "CSlide.h"
#include <stdexcept>

CSlide::CSlide(double width, double height)
	: m_width(width)
	, m_height(height)
	, m_backgroundColor(0xffffff)
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

size_t CSlide::GetShapesCount() const
{
	return m_shapes.size();
}

std::shared_ptr<IShape> CSlide::GetShapeAtIndex(const size_t index)
{
	if (index >= GetShapesCount() || index < 0)
	{
		throw std::logic_error("Out of range");
	}
	return m_shapes[index];
}

void CSlide::InsertShape(const std::shared_ptr<IShape>& shape, const size_t position)
{
	if (shape == nullptr)
	{
		throw std::logic_error("Empty shape");
	}
	if (position < 0 || position > GetShapesCount())
	{
		throw std::logic_error("Out of range");
	}
	m_shapes.insert(m_shapes.begin() + position, shape);
}

void CSlide::RemoveShapeAtIndex(const size_t index)
{
	if (index >= GetShapesCount() || index < 0)
	{
		throw std::logic_error("Out of range");
	}
	m_shapes.erase(m_shapes.begin() + index);
}

RGBAColor CSlide::GetBackgroundColor() const
{
	return m_backgroundColor;
}

void CSlide::SetBackgroundColor(const RGBAColor color)
{
	m_backgroundColor = color;
}

void CSlide::Draw(ICanvas& canvas) const
{
	for (const auto& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}
