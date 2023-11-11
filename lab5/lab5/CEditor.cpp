#include "CEditor.h"

const std::string POS_END = "end";
const int MIN_IMAGE_SIZE = 1;
const int MAX_IMAGE_SIZE = 10000;

CEditor::CEditor(CHistory& history)
	: m_document(make_unique<CDocument>(history))
{
	m_menu.AddItem("help", "Help", [this](istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("exit", "Exit", [this](istream&) { m_menu.Exit(); });
	m_menu.AddItem("list", "Show document", bind(&CEditor::List, this, _1));
	AddMenuItem("setTitle", "Changes title. Args: <new title>", &CEditor::SetTitle);
	AddMenuItem("undo", "Undo command", &CEditor::Undo);
	AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
	AddMenuItem("insertParagraph", "Inserts paragraph with given text in given position. Args: <position>|end <text>", &CEditor::InsertParagraph);
	AddMenuItem("replaceText", "Replacing text in paragraph in given position. Args: <position> <text>", &CEditor::ReplaceText);
	AddMenuItem("deleteItem", "Deletes document item in given position. Args: <position>", &CEditor::DeleteItem);
	AddMenuItem("insertImage", "Inserts image with given width, height and path in given position. Args: <position>|end <width> <height> <path>", &CEditor::InsertImage);
	AddMenuItem("resizeImage", "Change width and height of the image in given position. Args: <position> <width> <height>", &CEditor::ResizeImage);
}

void CEditor::Start()
{
	m_menu.Run();
}

void CEditor::AddMenuItem(const string& shortcut, const string& description, MenuHandler handler)
{
	m_menu.AddItem(shortcut, description, bind(handler, this, _1));
}

void CEditor::SetTitle(istream& in)
{
	string head;
	string tail;

	if (in >> head)
	{
		getline(in, tail);
	}
	string title = head + tail;

	m_document->SetTitle(title);
}

void CEditor::List(istream&)
{
	cout << "Title: " << m_document->GetTitle() << std::endl;
	for (size_t i = 0; i < m_document->GetItemsCount(); i++)
	{
		std::cout << i + 1 << ". ";
		auto item = m_document->GetItem(i);

		if (auto image = item.GetImage())
		{
			std::cout << "Image: " << image->GetWidth() << ' ' << image->GetHeight() << ' ' << image->GetPath() << std::endl;
		}
		else if (auto paragraph = item.GetParagraph())
		{
			std::cout << "Paragraph: " << paragraph->GetText() << std::endl;
		}
	}
}

void CEditor::Undo(istream&)
{
	if (m_document->CanUndo())
	{
		m_document->Undo();
	}
	else
	{
		cout << "Can't undo" << endl;
	}
}

void CEditor::Redo(istream&)
{

	if (m_document->CanRedo())
	{
		m_document->Redo();
	}
	else
	{
		cout << "Can't redo" << endl;
	}
}

void CEditor::InsertParagraph(istream& in)
{
	string strPos, text;
	in >> strPos;
	getline(in, text);

	std::optional<size_t> pos;
	if (strPos == POS_END)
	{
		pos = nullopt;
	}
	else
	{
		pos = std::stoi(strPos) - 1;
		if (pos > m_document->GetItemsCount() || pos < 0)
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}
	}
	
	m_document->InsertParagraph(text, pos);
}

void CEditor::ReplaceText(istream& in)
{
	string text;
	size_t pos;
	in >> pos >> text;
	
	if (auto paragraph = m_document->GetItem(pos - 1).GetParagraph())
	{
		paragraph->SetText(text);
	}
	else
	{
		std::cout << "Item in this position isn't paragraph" << std::endl;
	}

}

void CEditor::DeleteItem(istream& in)
{
	size_t pos;
	in >> pos;

	if (pos > m_document->GetItemsCount() || pos < 0)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}

	m_document->DeleteItem(pos - 1);
}

void CEditor::InsertImage(istream& in)
{
	string strPos;
	in >> strPos;

	std::optional<size_t> pos;
	if (strPos == POS_END)
	{
		pos = nullopt;
	}
	else
	{
		pos = std::stoi(strPos) - 1;
		if (pos > m_document->GetItemsCount() || pos < 0)
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}
	}

	int width, height;
	in >> width >> height;
	if (width > MAX_IMAGE_SIZE || width < MIN_IMAGE_SIZE || height > MAX_IMAGE_SIZE || height < MIN_IMAGE_SIZE)
	{
		std::cout << "Invalid size parameters" << std::endl;
		return;
	}
	string path;
	in >> path;
	m_document->InsertImage(path, width, height, pos);
}

void CEditor::ResizeImage(istream& in)
{
	size_t pos;
	in >> pos;

	if (auto image = m_document->GetItem(pos - 1).GetImage())
	{
		int width, height;
		in >> width >> height;
		image->Resize(width, height);
	}
	else
	{
		std::cout << "Item in this position isn't image" << std::endl;
	}
}
