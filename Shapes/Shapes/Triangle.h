#pragma once
#include "ShapeType.h"
#include "SPoint.h"

namespace shape
{
	class Triangle final : public ShapeType
	{
	public:
		Triangle(std::string type, std::string color, double x1, double y1, double x2, double y2, double x3, double y3);

		void Draw(gfx::ICanvas* canvas) override;
		void MoveShape(double dx, double dy) override;
		std::unique_ptr<ShapeType> Clone() const override;

	private:
		void AppendProperties(std::ostream& strm) const override;

		SPoint m_point1;
		SPoint m_point2;
		SPoint m_point3;
	};
}