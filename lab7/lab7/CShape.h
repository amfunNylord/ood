#pragma once
#include "IShape.h"
#include "CSimpleBorderStyle.h"
#include "CSimpleFillStyle.h"

class CShape : public IShape
{
public:
	CShape();
	std::shared_ptr<IBorderStyle> GetLineStyle() override;

	std::shared_ptr<IStyle> GetFillStyle() override;

	std::shared_ptr<IGroup> GetGroup() override;

	std::shared_ptr<const IBorderStyle> GetLineStyle() const override;

	std::shared_ptr<const IStyle> GetFillStyle() const override;

	std::shared_ptr<const IGroup> GetGroup() const override;

private:
	std::shared_ptr<IBorderStyle> m_borderStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
