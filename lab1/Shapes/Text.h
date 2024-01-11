#pragma once
#include "ShapeType.h"

namespace shape
{
	class Text final : public ShapeType
	{
	public:
		Text(std::string type, std::string color, double left, double top, double size, std::string text);

		void Draw(gfx::ICanvas* canvas) override;
		void AppendProperties(std::ostream& strm) const override;
		void MoveShape(double dx, double dy) override;

	private:
		double m_left;
		double m_top;
		double m_size;
		std::string m_text;
	};
}
