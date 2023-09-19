#pragma once
#include "ShapeType.h"

namespace shape
{
	class Circle final : public ShapeType
	{
	public:
		Circle(std::string type, double x, double y, double r);
		~Circle();
		void AppendProperties(std::ostream& strm) const override;
	private:
		double m_x;
		double m_y;
		double m_r;
	};
}