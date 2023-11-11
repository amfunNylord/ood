#pragma once
#include "IParagraph.h"
#include "History.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(CHistory& history, std::string text);
	std::string GetText() const override;
	void SetText(const std::string& text) override;

private:
	std::string m_text;
	CHistory& m_history;
};