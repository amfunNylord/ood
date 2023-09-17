#pragma once
#include <string>

namespace shape
{
	class Shape
	{
	public:
		Shape(std::string id, std::string color, std::string type);
		virtual ~Shape();

		void MoveShape();
		void SetColor(std::string newColor);
		void ChangeShape(std::string shapeId, std::string shapeType, std::istream& args);
		void DrawShape();

		std::string GetColor() const;
		std::string GetType() const;
		std::string GetId() const;
		std::string ToString() const;

	private:
		virtual void AppendProperties(std::ostream& strm) const = 0;
		std::string m_id;
		std::string m_color;
		std::string m_type;
		//IDrawingStrategy m_drawingStrategy;
	};

} // namespace shape