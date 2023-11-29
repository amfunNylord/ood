#include "CGroupBorderStyle.h"

CGroupBorderStyle::CGroupBorderStyle(BorderGroupEnumerator& enumerator)
	: m_enumerator(enumerator)
{
}

void CGroupBorderStyle::SetThickness(double thickness)
{
	BorderStyleEnumerator styleEnumerator = [thickness](IBorderStyle& style) {
		style.SetThickness(thickness);
	};
	m_enumerator(styleEnumerator);
}

std::optional<double> CGroupBorderStyle::GetThickness() const
{
	std::optional<double> thickness = std::nullopt;
	bool isRepeatedly = false;

	BorderStyleEnumerator styleEnumerator = [&thickness, &isRepeatedly](IBorderStyle& style) {
		if (!isRepeatedly)
		{
			thickness = style.GetThickness();
			isRepeatedly = true;
		}
		if (thickness != style.GetThickness())
		{
			thickness = std::nullopt;
		}
	};
	m_enumerator(styleEnumerator);
	return thickness;
}

bool CGroupBorderStyle::IsEnabled() const
{
	bool isEnabled = false;
	bool isRepeatedly = false;

	BorderStyleEnumerator styleEnumerator = [&isEnabled, &isRepeatedly](IBorderStyle& style) {
		if (!isRepeatedly)
		{
			isEnabled = style.IsEnabled();
			isRepeatedly = true;
		}
		if (isEnabled != style.IsEnabled())
		{
			isEnabled = false;
		}
	};
	m_enumerator(styleEnumerator);
	return isEnabled;
}

void CGroupBorderStyle::Enable()
{
	BorderStyleEnumerator styleEnumerator = [](IBorderStyle& style) {
		style.Enable();
	};
	m_enumerator(styleEnumerator);
}

void CGroupBorderStyle::Disable()
{
	BorderStyleEnumerator styleEnumerator = [](IBorderStyle& style) {
		style.Disable();
	};
	m_enumerator(styleEnumerator);
}

std::optional<RGBAColor> CGroupBorderStyle::GetColor() const
{
	std::optional<RGBAColor> color = std::nullopt;
	bool isRepeatedly = false;

	BorderStyleEnumerator styleEnumerator = [&color, &isRepeatedly](IBorderStyle& style) {
		if (!isRepeatedly)
		{
			color = style.GetColor();
			isRepeatedly = true;
		}
		if (color != style.GetColor())
		{
			color = std::nullopt;
		}
	};
	m_enumerator(styleEnumerator);
	return color;
}

void CGroupBorderStyle::SetColor(RGBAColor color)
{
	BorderStyleEnumerator styleEnumerator = [color](IBorderStyle& style) {
		style.SetColor(color);
	};
	m_enumerator(styleEnumerator);
}
