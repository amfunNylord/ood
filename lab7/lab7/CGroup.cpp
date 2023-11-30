#include "CGroup.h"
#include <stdexcept>

size_t CGroup::GetShapesCount() const
{
	return m_shapes.size();
}

std::shared_ptr<IShape> CGroup::GetShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount() || index < 0)
	{
		throw std::logic_error("Out of range");
	}

	return m_shapes[index];
}

void CGroup::InsertShape(const std::shared_ptr<IShape>& shape, size_t index)
{
	if (shape == nullptr)
	{
		throw std::logic_error("Empty shape");
	}
	if (index < 0 || index > GetShapesCount())
	{
		throw std::logic_error("Out of range");
	}
	m_shapes.insert(m_shapes.begin() + index, shape);
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount() || index < 0)
	{
		throw std::logic_error("Out of range");
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

	for (const auto& shape : m_shapes)
	{
		auto frame = shape->GetFrame().value();

		maxX = std::max(maxX, frame.left + frame.width);
		minX = std::min(minX, frame.left);
		maxY = std::max(maxY, frame.top + frame.height);
		minY = std::min(minY, frame.top);
	}

	return RectD{ minX, minY, maxX - minX, maxY - minY };
}

void CGroup::SetFrame(const RectD& rect)
{
	auto currentFrame = GetFrame().value();

	if (currentFrame.left == 0 && currentFrame.top == 0 && currentFrame.height == 0 && currentFrame.width == 0)
	{
		return;
	}

	auto coefX = rect.width / currentFrame.width;
	auto coefY = rect.height / currentFrame.height;

	for (const auto& shape : m_shapes)
	{
		auto shapeFrame = shape->GetFrame().value();

		auto leftPointX = rect.left + (shapeFrame.left - currentFrame.left) * coefX;
		auto leftPointY = rect.top + (shapeFrame.top - currentFrame.top) * coefY;
		auto width = shapeFrame.width * coefX;
		auto height = shapeFrame.height * coefY;

		RectD newFrame{ leftPointX, leftPointY , width, height };
		shape->SetFrame(newFrame);
	}
}

std::shared_ptr<IBorderStyle> CGroup::GetLineStyle() const
{
	if (!m_borderStyle)
	{
		throw std::logic_error("No border style");
	}
	return m_borderStyle;
}

std::shared_ptr<IStyle> CGroup::GetFillStyle() const
{
	if (!m_fillStyle)
	{
		throw std::logic_error("No line style");
	}
	return m_fillStyle;
}

void CGroup::Draw(ICanvas& canvas) const
{
	for (const auto& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}

std::shared_ptr<IGroup> CGroup::GetGroup()
{
	return std::shared_ptr<IGroup>(this);
}
