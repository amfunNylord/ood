#include "CGroup.h"
#include <stdexcept>
#include <assert.h>

size_t CGroup::GetShapesCount() const
{
	return m_shapes.size();
}

std::shared_ptr<IShape> CGroup::GetShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount() || index < 0)
	{
		// out_of_range ex
		//throw std::logic_error("Out of range");
		throw std::out_of_range("Out of range");
	}

	return m_shapes[index];
}

void CGroup::InsertShape(const std::shared_ptr<IShape>& shape, size_t index)
{
	if (shape == nullptr)
	{
		// invalid_argument
		//throw std::logic_error("Empty shape");
		throw std::invalid_argument("Empty shape");
	}
	if (index < 0 || index > GetShapesCount())
	{
		//throw std::logic_error("Out of range");
		throw std::out_of_range("Out of range");
	}
	m_shapes.insert(m_shapes.begin() + index, shape);
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount() || index < 0)
	{
		//throw std::logic_error("Out of range");
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
		// проверить has-value
		RectD frame;
		if (shape->GetFrame().has_value())
		{
			frame = shape->GetFrame().value();
		}
		else
		{
			throw std::invalid_argument("No frame");
		}
		frame = shape->GetFrame().value();

		maxX = std::max(maxX, frame.left + frame.width);
		minX = std::min(minX, frame.left);
		maxY = std::max(maxY, frame.top + frame.height);
		minY = std::min(minY, frame.top);
	}

	return RectD{ minX, minY, maxX - minX, maxY - minY };
}

void CGroup::SetFrame(const RectD& rect)
{
	// has_value
	RectD currentFrame;
	if (GetFrame().has_value())
	{
		currentFrame = GetFrame().value();
	}
	else
	{
		throw std::invalid_argument("No frame");
	}

	if (currentFrame.left == 0 && currentFrame.top == 0 && currentFrame.height == 0 && currentFrame.width == 0)
	{
		return;
	}

	auto coefX = rect.width / currentFrame.width;
	auto coefY = rect.height / currentFrame.height;

	for (const auto& shape : m_shapes)
	{
		// has_value
		RectD shapeFrame;
		if (shape->GetFrame().has_value())
		{
			shapeFrame = shape->GetFrame().value();
		}
		else
		{
			throw std::invalid_argument("No frame");
		}

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
	// assert можно использовать
	/*if (!m_borderStyle)
	{
		throw std::logic_error("No border style");
	}*/
	assert(m_borderStyle);
	return m_borderStyle;
}

std::shared_ptr<IStyle> CGroup::GetFillStyle() const
{
	/*if (!m_fillStyle)
	{
		throw std::logic_error("No line style");
	}*/
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
// не работает . std:: enable_shared_from_this
std::shared_ptr<IGroup> CGroup::GetGroup()
{
	return shared_from_this();
}
