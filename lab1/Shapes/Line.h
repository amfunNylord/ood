#pragma once
#include "Shape.h"
namespace shape
{
	class Line final : public Shape
	{
	public:
		Line(std::string id, std::string color, std::string type, double x1, double y1, double x2, double y2);
		~Line();

	private:
		void AppendProperties(std::ostream& strm) const override;
		double m_x1;
		double m_y1;
		double m_x2;
		double m_y2;
	};

}