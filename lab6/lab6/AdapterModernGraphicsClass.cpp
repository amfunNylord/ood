#include "AdapterModernGraphicsClass.h"

const modern_graphics_lib::CPoint DEFAULT_START_POINT = { 0, 0 };

CAdapterModernGraphicsClass::CAdapterModernGraphicsClass(std::ostream& output)
	: modern_graphics_lib::CModernGraphicsRenderer(output)
	, m_currPoint(DEFAULT_START_POINT)
{
	BeginDraw();
}

CAdapterModernGraphicsClass::~CAdapterModernGraphicsClass()
{
	EndDraw();
}

void CAdapterModernGraphicsClass::MoveTo(int x, int y)
{
	m_currPoint = { x, y };
}

void CAdapterModernGraphicsClass::LineTo(int x, int y)
{
	DrawLine(m_currPoint, { x, y });
	this->MoveTo(x, y);
}

