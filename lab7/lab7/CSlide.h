#pragma once
#include <memory>
#include <vector>
#include "IShape.h"

class CSlide
{
public:
	CSlide(double width, double height);
	double GetWidth() const;
	double GetHeight() const;

	size_t GetShapesCount() const;
	std::shared_ptr<IShape> GetShapeAtIndex(const size_t index);
	void InsertShape(const std::shared_ptr<IShape>& shape, const size_t position);
	void RemoveShapeAtIndex(const size_t index);
	RGBAColor GetBackgroundColor() const;
	void SetBackgroundColor(const RGBAColor color);

	void Draw(ICanvas& canvas) const;

private:
	double m_width;
	double m_height;
	std::vector<std::shared_ptr<IShape>> m_shapes;
	RGBAColor m_backgroundColor;
};
