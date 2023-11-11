#include "DeleteItemCommand.h"

CDeleteItemCommand::CDeleteItemCommand(std::vector<CDocumentItem>& documentItems, const size_t& index)
	: m_documentItems(documentItems)
	, m_index(index)
{
	m_deletedItem = std::make_unique<CDocumentItem>(documentItems.at(index));
}

void CDeleteItemCommand::DoExecute()
{
	m_documentItems.erase(m_documentItems.begin() + m_index);
}

void CDeleteItemCommand::DoUnexecute()
{
	m_documentItems.emplace(m_documentItems.begin() + m_index, *m_deletedItem);
}
