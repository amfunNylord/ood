#pragma once
#include "ShapeType.h"
namespace shape
{
	class Triangle final : public ShapeType
	{
	public:
		Triangle(std::string type, std::string color, double x1, double y1, double x2, double y2, double x3, double y3);
		void Draw(Canvas& canvas) override;
		~Triangle();
		void AppendProperties(std::ostream& strm) const override;
		void MoveShape(double dx, double dy) override;

	private:
		double m_x1;
		double m_y1;
		double m_x2;
		double m_y2;
		double m_x3;
		double m_y3;
	};
}