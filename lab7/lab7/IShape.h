#pragma once
#include <memory>
#include "IStyle.h"
#include "ICanvas.h"
#include "IBorderStyle.h"

class IGroup;

class IShape
{
public:
	virtual std::optional<RectD> GetFrame() = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual std::shared_ptr<IBorderStyle> GetLineStyle() = 0;
	virtual std::shared_ptr<const IBorderStyle> GetLineStyle() const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual std::shared_ptr<const IStyle> GetFillStyle() const = 0;

	virtual void Draw(ICanvas& canvas) const = 0;
	virtual std::shared_ptr<IGroup> GetGroup() = 0;
	virtual std::shared_ptr<const IGroup> GetGroup() const = 0;

	~IShape() = default;
};