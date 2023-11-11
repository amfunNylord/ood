#pragma once
#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <optional>
#include <vector>

class CInsertDocumentItemCommand : public CAbstractCommand
{
public:
	CInsertDocumentItemCommand(std::vector<CDocumentItem>& documentItems, std::shared_ptr<CDocumentItem>&& documentItem, const std::optional<size_t>& index);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_documentItems;
	std::shared_ptr<CDocumentItem> m_documentItem;
	std::optional<size_t> m_index;
};
