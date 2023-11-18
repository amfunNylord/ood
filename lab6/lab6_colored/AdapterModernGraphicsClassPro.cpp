#include "AdapterModernGraphicsClassPro.h"

const modern_graphics_lib_pro::CPoint DEFAULT_START_POINT = { 0, 0 };
const modern_graphics_lib_pro::CRGBAColor DEFAULT_COLOR = { 0.0, 0.0, 0.0, 1.0 };

CAdapterModernGraphicsClassPro::CAdapterModernGraphicsClassPro(std::ostream& output)
	: modern_graphics_lib_pro::CModernGraphicsRenderer(output)
	, m_currPoint(DEFAULT_START_POINT)
	, m_color(DEFAULT_COLOR)
{
	BeginDraw();
}

CAdapterModernGraphicsClassPro::~CAdapterModernGraphicsClassPro()
{
	EndDraw();
}

void CAdapterModernGraphicsClassPro::MoveTo(int x, int y)
{
	m_currPoint = { x, y };
}

void CAdapterModernGraphicsClassPro::LineTo(int x, int y)
{
	DrawLine(m_currPoint, { x, y }, m_color);
	this->MoveTo(x, y);
}

void CAdapterModernGraphicsClassPro::SetColor(uint32_t rgbColor)
{
	m_color.r = ((rgbColor >> 16) & 0xFF) / 255.0f;
	m_color.g = ((rgbColor >> 8) & 0xFF) / 255.0f;
	m_color.b = (rgbColor & 0xFF) / 255.0f;
}
