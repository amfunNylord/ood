#pragma once
#include "ShapeType.h"

namespace shape
{
	class Circle final : public ShapeType
	{
	public:
		Circle(std::string type, std::string color, double x, double y, double r);
		~Circle();
		void Draw(CCanvas& canvas) override;
		void AppendProperties(std::ostream& strm) const override;
		void MoveShape(double dx, double dy) override;
	private:
		double m_x;
		double m_y;
		double m_r;
	};
}