#include "InsertDocumentItemCommand.h"

CInsertDocumentItemCommand::CInsertDocumentItemCommand(std::vector<CDocumentItem>& documentItems, std::shared_ptr<CDocumentItem>&& documentItem, 
													   const std::optional<size_t>& index)
	: m_documentItem(documentItem)
	, m_documentItems(documentItems)
	, m_index(index)
{
}

void CInsertDocumentItemCommand::DoExecute()
{
	if (m_index.has_value())
	{
		m_documentItems.emplace(m_documentItems.begin() + m_index.value(), *m_documentItem);
		return;
	}

	m_documentItems.push_back(*m_documentItem);
}

void CInsertDocumentItemCommand::DoUnexecute()
{
	if (m_index.has_value())
	{
		m_documentItems.erase(m_documentItems.begin() + m_index.value());
		return;
	}

	m_documentItems.pop_back();
}
