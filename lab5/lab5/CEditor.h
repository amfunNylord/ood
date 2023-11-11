#pragma once

#include "stdafx.h"
#include "Document.h"
#include "Menu.h"

using namespace std;
using namespace std::placeholders;

class CEditor
{
public:
	CEditor(CHistory& history);

	void Start();

private:
	// ”казатель на метод класса CEditor, принимающий istream& и возвращающий void
	typedef void (CEditor::*MenuHandler)(istream& in);

	void AddMenuItem(const string& shortcut, const string& description, MenuHandler handler);

	// TODO: скипнуть первый пробел элегантнее
	void SetTitle(istream& in);

	void List(istream&);

	void Undo(istream&);

	void Redo(istream&);

	void InsertParagraph(istream& in);
	
	void ReplaceText(istream& in);

	void DeleteItem(istream& in);

	void InsertImage(istream& in);

	void ResizeImage(istream& in);

	CMenu m_menu;
	unique_ptr<IDocument> m_document;
};
