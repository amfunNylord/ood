#pragma once
#include "ShapeType.h"

namespace shape
{
	class Rectangle final : public ShapeType
	{
	public:
		Rectangle(std::string type, double left, double top, double width, double height);
		~Rectangle();

	private:
		void AppendProperties(std::ostream& strm) const override;
		double m_left;
		double m_top;
		double m_width;
		double m_height;
	};
}
