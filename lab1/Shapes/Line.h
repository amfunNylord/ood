#pragma once
#include "ShapeType.h"
#include "SPoint.h"

namespace shape
{
	class Line final : public ShapeType
	{
	public:
		Line(std::string type, std::string color, double x1, double y1, double x2, double y2);
		void Draw(gfx::ICanvas* canvas) override;
		void AppendProperties(std::ostream& strm) const override;
		void MoveShape(double dx, double dy) override;

	private:
		SPoint m_point1;
		SPoint m_point2;
	};

}