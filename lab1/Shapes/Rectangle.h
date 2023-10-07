#pragma once
#include "ShapeType.h"

namespace shape
{
	class Rectangle final : public ShapeType
	{
	public:
		Rectangle(std::string type, std::string color, double left, double top, double width, double height);
		void Draw(Canvas& canvas) override;
		~Rectangle();

		void MoveShape(double dx, double dy) override;

	private:
		void AppendProperties(std::ostream& strm) const override;
		double m_left;
		double m_top;
		double m_width;
		double m_height;
	};
}
