#pragma once

#include "IShape.h"

class IGroup : public IShape
{
public:
	virtual size_t GetShapesCount() const = 0;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) = 0;
	virtual void InsertShape(const std::shared_ptr<IShape>& shape, const size_t index) = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;
};