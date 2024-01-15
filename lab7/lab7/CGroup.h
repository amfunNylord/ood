#pragma once
#include "IGroup.h"
#include <vector>
#include "CGroupBorderStyle.h"
#include "CGroupFillStyle.h"

class CGroup : public IGroup, std::enable_shared_from_this<IGroup>
{
public:
	CGroup();
	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

	std::shared_ptr<IBorderStyle> GetLineStyle() override;
	std::shared_ptr<const IBorderStyle> GetLineStyle() const override;
	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<const IStyle> GetFillStyle() const override;
	void Draw(ICanvas& canvas) const override;

	std::shared_ptr<IGroup> GetGroup() override;
	std::shared_ptr<const IGroup> GetGroup() const override;

	size_t GetShapesCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	void InsertShape(const std::shared_ptr<IShape>& shape, const size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<IBorderStyle> m_borderStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
