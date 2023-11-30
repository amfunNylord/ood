#pragma once
#include "IGroup.h"
#include <vector>
#include "CGroupBorderStyle.h"
#include "CGroupFillStyle.h"

class CGroup : public IGroup
{
public:
	CGroup();
	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

	std::shared_ptr<IBorderStyle> GetLineStyle() const override;
	std::shared_ptr<IStyle> GetFillStyle() const override;
	void Draw(ICanvas& canvas) const override;

	std::shared_ptr<IGroup> GetGroup() override;

	size_t GetShapesCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	void InsertShape(const std::shared_ptr<IShape>& shape, const size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<IBorderStyle> m_borderStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
