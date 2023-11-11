#include "stdafx.h"
#include "Paragraph.h"
#include "ChangeStringCommand.h"
#include <memory>

CParagraph::CParagraph(CHistory& history, std::string text)
	: m_history(history)
	, m_text(text)
{
}

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(const std::string& text)
{
	m_history.AddAndExecuteCommand(std::make_unique<CChangeStringCommand>(m_text, text));
}
