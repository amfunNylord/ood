#pragma once
#include <string>
namespace shape
{
	class ShapeType
	{
	public:
		ShapeType(std::string shapeType);
		std::string GetType() const;
		std::string ToString() const;
		virtual void AppendProperties(std::ostream& strm) const = 0;

	private:
		std::string m_shapeType;
	};
} // namespace shape