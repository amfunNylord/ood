#include "stdafx.h"
#include "Document.h"
#include "ChangeStringCommand.h"
#include "InsertDocumentItemCommand.h"
#include "DeleteItemCommand.h"
#include "Paragraph.h"
#include "Image.h"

using namespace std;

CDocument::CDocument(CHistory& history, const std::shared_ptr<IDocumentSaver>& documentSaver)
	: m_history(history)
	, m_documentSaver(documentSaver)
{
}

void CDocument::SetTitle(const std::string& title)
{
	m_history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_title, title));
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

bool CDocument::CanUndo() const
{
	return m_history.CanUndo();
}

void CDocument::Undo()
{
	m_history.Undo();
}

bool CDocument::CanRedo() const
{
	return m_history.CanRedo();
}

void CDocument::Redo()
{
	m_history.Redo();
}

size_t CDocument::GetItemsCount() const
{
	return m_documentItems.size();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return m_documentItems[index];
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return m_documentItems[index];
}

void CDocument::DeleteItem(size_t index)
{
	m_history.AddAndExecuteCommand(make_unique<CDeleteItemCommand>(m_documentItems, index));
}

void CDocument::DeleteItemImp(size_t index)
{
	m_documentItems.erase(m_documentItems.begin() + index);
}

void CDocument::AddDocumentItem(const CDocumentItem& documentItem, size_t index)
{
	m_documentItems.insert(m_documentItems.begin() + index, documentItem);
}

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string& text, const std::optional<size_t>& position)
{
	shared_ptr<IParagraph> paragraph = make_shared<CParagraph>(m_history, text);
	shared_ptr<CDocumentItem> item = std::make_shared<CDocumentItem>(std::move(paragraph));
	m_history.AddAndExecuteCommand(make_unique<CInsertDocumentItemCommand>(m_documentItems, std::move(item), position));
	return paragraph;
}

std::shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, const std::optional<size_t>& position)
{
	shared_ptr<IImage> image = make_shared<CImage>(m_history, width, height, path);
	shared_ptr<CDocumentItem> item = std::make_shared<CDocumentItem>(std::move(image));
	m_history.AddAndExecuteCommand(make_unique<CInsertDocumentItemCommand>(m_documentItems, std::move(item), position));
	return image;
}

void CDocument::Save(const std::string& path) const
{
	m_documentSaver->Save(path, this);
}
