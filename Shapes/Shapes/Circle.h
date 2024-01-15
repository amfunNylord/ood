#pragma once
#include "ShapeType.h"

namespace shape
{
	class Circle final : public ShapeType
	{
	public:
		Circle(std::string type, std::string color, double x, double y, double r);

		void Draw(gfx::ICanvas* canvas) override;
		void MoveShape(double dx, double dy) override;
		std::unique_ptr<ShapeType> Clone() const override;

	private:
		void AppendProperties(std::ostream& strm) const override;

		double m_x;
		double m_y;
		double m_r;
	};
}