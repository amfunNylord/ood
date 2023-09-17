#pragma once
#include "Shape.h"

namespace shape
{
	class Circle final : public Shape
	{
	public:
		Circle(std::string id, std::string color, std::string type, double x, double y, double r);
		~Circle();
	private:
		void AppendProperties(std::ostream& strm) const override;
		double m_x;
		double m_y;
		double m_r;
	};
}