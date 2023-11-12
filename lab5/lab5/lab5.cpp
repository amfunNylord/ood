// ISpringWord.cpp : Defines the entry point for the console application.
//
#include "CEditor.h"
#include "DocumentSaver.h"

int main()
{
	CHistory history;
	std::shared_ptr<CDocumentSaver> documentSaver = std::make_shared<CDocumentSaver>();
	CEditor editor(history, documentSaver);
	editor.Start();
	return 0;
}