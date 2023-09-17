#pragma once
#include "Shape.h"

namespace shape
{
	class Text final : public Shape
	{
	public:
		Text(std::string id, std::string color, std::string type, double left, double top, double size, std::string text);
		~Text();
	private:
		void AppendProperties(std::ostream& strm) const override;
		double m_left;
		double m_top;
		double m_size;
		std::string m_text;

	};
}
