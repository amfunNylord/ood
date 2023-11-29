#pragma once
#include "CommonTypes.h"
#include <optional>
#include <vector>

class ICanvas
{
public:
	virtual void DrawLine(PointD start, PointD end, RGBAColor color, std::optional<double> thickness) = 0;
	virtual void DrawEllipse(const PointD center, double horizontalRadius, double verticalRadius, 
							 std::optional<RGBAColor> borderColor, std::optional<RGBAColor> fillColor, 
							 std::optional<double> thickness) = 0;
	virtual void FillPolygon(const std::vector<PointD> vertexes, RGBAColor fillColor) = 0;
	/*virtual void SetFillColor() = 0;
	virtual void SetLineColor() = 0;
	virtual void SetLineThickness() = 0;*/

	~ICanvas() = default;
};