#pragma once
#include "IShape.h"
#include "CSimpleBorderStyle.h"
#include "CSimpleFillStyle.h"

class CShape : public IShape
{
public:
	CShape();
	std::shared_ptr<IBorderStyle> GetLineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() const override;

	std::shared_ptr<IGroup> GetGroup() override;

private:
	std::shared_ptr<IBorderStyle> m_borderStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
