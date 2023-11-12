#pragma once
#include "IDocument.h"
#include "History.h"
#include "IDocumentSaver.h"

#include <vector>

class CDocument : public IDocument
{
public:
	CDocument(CHistory& history, const std::shared_ptr<IDocumentSaver>& documentSaver);
	void SetTitle(const std::string & title) override;
	std::string GetTitle() const override;

	bool CanUndo() const override;	
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text, const std::optional<size_t>& position = std::nullopt) override;
	std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, 
										const std::optional<size_t>& position = std::nullopt) override;

	void Save(const std::string& path) const override;

	size_t GetItemsCount() const override;
	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;
	void DeleteItem(size_t index) override;
	void DeleteItemImp(size_t index);
	void AddDocumentItem(const CDocumentItem& documentItem, size_t index);

private:
	std::vector<CDocumentItem> m_documentItems;
	std::string m_title = "Untilted";
	CHistory& m_history;
	std::shared_ptr<IDocumentSaver> m_documentSaver;
};