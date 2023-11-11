#pragma once
#include "AbstractCommand.h"
#include "DocumentItem.h"
#include "Document.h"

class CDeleteItemCommand : public CAbstractCommand
{
public:
	CDeleteItemCommand(std::vector<CDocumentItem>& m_documentItems, const size_t& index);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::unique_ptr<CDocumentItem> m_deletedItem;
	size_t m_index;
	std::vector<CDocumentItem>& m_documentItems;
};
