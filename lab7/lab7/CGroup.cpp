#include "CGroup.h"
#include <stdexcept>
#include <assert.h>

size_t CGroup::GetShapesCount() const
{
	return m_shapes.size();
}

std::shared_ptr<IShape> CGroup::GetShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount())
	{
		throw std::out_of_range("Out of range");
	}

	return m_shapes[index];
}

void CGroup::InsertShape(const std::shared_ptr<IShape>& shape, size_t index)
{
	if (shape == nullptr)
	{
		throw std::invalid_argument("Empty shape");
	}
	if (index > GetShapesCount())
	{
		throw std::out_of_range("Out of range");
	}
	m_shapes.insert(m_shapes.begin() + index, shape);
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount())
	{
		throw std::out_of_range("Out of range");
	}
	m_shapes.erase(m_shapes.begin() + index);
}

CGroup::CGroup()
{
	BorderGroupEnumerator borderGroupEnumerator = [this](BorderStyleEnumerator styleEnumerator) {
		for (const auto& shape : m_shapes)
		{
			styleEnumerator(*shape->GetLineStyle());
		}
	};

	m_borderStyle = std::make_shared<CGroupBorderStyle>(borderGroupEnumerator);

	FillGroupEnumerator fillGroupEnumerator = [this](StyleCallback StyleCallback) {
		for (const auto& shape : m_shapes)
		{
			StyleCallback(*shape->GetFillStyle());
		}
	};

	m_fillStyle = std::make_shared<CGroupFillStyle>(fillGroupEnumerator);
}
// написать test
std::optional<RectD> CGroup::GetFrame()
{
	if (m_shapes.empty())
	{
		return std::nullopt;
	}
	double maxX = std::numeric_limits<double>::min();
	double minX = std::numeric_limits<double>::max();
	double maxY = std::numeric_limits<double>::min();
	double minY = std::numeric_limits<double>::max();
	// если в группу добавить пустую группу то посчитать фрейм и кроме пустой группы ничего
	for (const auto& shape : m_shapes)
	{
		RectD frame;
		if (shape->GetFrame().has_value())
		{
			frame = shape->GetFrame().value();
		}
		else
		{
			continue;
		}

		maxX = std::max(maxX, frame.left + frame.width);
		minX = std::min(minX, frame.left);
		maxY = std::max(maxY, frame.top + frame.height);
		minY = std::min(minY, frame.top);
	}
	// пустаая группа возвращает nullopt а группа пустых групп возвращает 0000
	if (maxX == std::numeric_limits<double>::min())
	{
		return RectD(0, 0, 0, 0);
	}
	else
	{
		return RectD{ minX, minY, maxX - minX, maxY - minY };
	}
}

void CGroup::SetFrame(const RectD& rect)
{
	RectD currentFrame;
	if (GetFrame().has_value())
	{
		currentFrame = GetFrame().value();
	}
	else
	{
		currentFrame = RectD(0, 0, 0, 0);
	}

	if (currentFrame.left == 0 && currentFrame.top == 0 && currentFrame.height == 0 && currentFrame.width == 0)
	{
		return;
	}

	auto coefX = rect.width / currentFrame.width;
	auto coefY = rect.height / currentFrame.height;

	for (const auto& shape : m_shapes)
	{
		RectD shapeFrame;
		if (shape->GetFrame().has_value())
		{
			shapeFrame = shape->GetFrame().value();
		}
		else
		{
			continue;
		}

		auto leftPointX = rect.left + (shapeFrame.left - currentFrame.left) * coefX;
		auto leftPointY = rect.top + (shapeFrame.top - currentFrame.top) * coefY;
		auto width = shapeFrame.width * coefX;
		auto height = shapeFrame.height * coefY;

		RectD newFrame{ leftPointX, leftPointY , width, height };
		shape->SetFrame(newFrame);
	}
}
// сделать для стилей const доступ к стилям
std::shared_ptr<IBorderStyle> CGroup::GetLineStyle()
{
	assert(m_borderStyle);
	return m_borderStyle;
}

std::shared_ptr<const IBorderStyle> CGroup::GetLineStyle() const
{
	assert(m_borderStyle);
	return m_borderStyle;
}

std::shared_ptr<IStyle> CGroup::GetFillStyle()
{
	assert(m_fillStyle);
	return m_fillStyle;
}

std::shared_ptr<const IStyle> CGroup::GetFillStyle() const
{
	assert(m_fillStyle);
	return m_fillStyle;
}

void CGroup::Draw(ICanvas& canvas) const
{
	for (const auto& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}

// реализовать const метод
std::shared_ptr<IGroup> CGroup::GetGroup()
{
	return shared_from_this();
}

std::shared_ptr<const IGroup> CGroup::GetGroup() const
{
	return shared_from_this();
}
