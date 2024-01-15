#include "CShape.h"
#include "CSimpleBorderStyle.h"
#include "CSimpleFillStyle.h"

CShape::CShape()
	: m_borderStyle(std::make_shared<CSimpleBorderStyle>())
	, m_fillStyle(std::make_shared<CSimpleFillStyle>())
{
}

std::shared_ptr<IBorderStyle> CShape::GetLineStyle() 
{
	return m_borderStyle;
}

std::shared_ptr<IStyle> CShape::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<IGroup> CShape::GetGroup()
{
	return nullptr;
}

std::shared_ptr<const IBorderStyle> CShape::GetLineStyle() const
{
	return m_borderStyle;
}

std::shared_ptr<const IStyle> CShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<const IGroup> CShape::GetGroup() const
{
	return nullptr;
}
