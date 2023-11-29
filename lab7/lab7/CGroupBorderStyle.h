#pragma once
#include <functional>
#include "IBorderStyle.h"

using BorderStyleEnumerator = std::function<void(IBorderStyle& style)>;
using BorderGroupEnumerator = std::function<void(BorderStyleEnumerator)>;

class CGroupBorderStyle : public IBorderStyle
{
public:
	CGroupBorderStyle(BorderGroupEnumerator& enumerator);
	void SetThickness(double thickness) override;
	std::optional<double> GetThickness() const override;

	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;
	std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	BorderGroupEnumerator m_enumerator;
};
