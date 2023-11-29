#pragma once
#include <functional>
#include "IStyle.h"

using StyleCallback = std::function<void(IStyle&)>;
using FillGroupEnumerator = std::function<void(StyleCallback)>;

class CGroupFillStyle : public IStyle
{
public:
	CGroupFillStyle(FillGroupEnumerator& enumerator);
	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;
	std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	FillGroupEnumerator m_enumerator;
};
