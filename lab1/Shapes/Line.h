#pragma once
#include "ShapeType.h"

namespace shape
{
	class Line final : public ShapeType
	{
	public:
		Line(std::string type, std::string color, double x1, double y1, double x2, double y2);
		~Line();
		void Draw(Canvas& canvas) override;
		void AppendProperties(std::ostream& strm) const override;
		void MoveShape(double dx, double dy) override;

	private:
		double m_x1;
		double m_y1;
		double m_x2;
		double m_y2;
	};

}