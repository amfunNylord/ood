#include "CGroupFillStyle.h"

CGroupFillStyle::CGroupFillStyle(FillGroupEnumerator& enumerator)
	: m_enumerator(enumerator)
{
}

bool CGroupFillStyle::IsEnabled() const
{
	bool isEnabled = false;
	bool isRepeatedly = false;

	StyleCallback styleCallback = [&isEnabled, &isRepeatedly](IStyle& style) {
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
	m_enumerator(styleCallback);
	return isEnabled;
}

void CGroupFillStyle::Enable()
{
	StyleCallback styleCallback = [](IStyle& style) {
		style.Enable();
	};
	m_enumerator(styleCallback);
}

void CGroupFillStyle::Disable()
{
	StyleCallback styleCallback = [](IStyle& style) {
		style.Disable();
	};
	m_enumerator(styleCallback);
}

std::optional<RGBAColor> CGroupFillStyle::GetColor() const
{
	std::optional<RGBAColor> color = std::nullopt;
	bool isRepeatedly = false;
	StyleCallback styleCallback = [&color, &isRepeatedly](IStyle& style) {
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
	m_enumerator(styleCallback);
	return color;
}

void CGroupFillStyle::SetColor(RGBAColor color)
{
	StyleCallback styleCallback = [color](IStyle& style) {
		style.SetColor(color);
	};
	m_enumerator(styleCallback);
}
