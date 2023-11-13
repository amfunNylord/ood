#include <iostream>
#include <memory>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab5/Document.h"
#include "../lab5/History.h"
#include "../lab5/DocumentSaver.h"
#include "../lab5/Paragraph.h"
#include "../lab5/Image.h"
#include "../lab5/ChangeStringCommand.h"
#include "../lab5/DeleteItemCommand.h"
#include "../lab5/InsertDocumentItemCommand.h"
#include "../lab5/ResizeImageCommand.h"

SCENARIO("Test CDocument")
{
	CHistory history;
	std::shared_ptr<CDocumentSaver> documentSaver = std::make_shared<CDocumentSaver>();
	WHEN("We create document")
	{
		CDocument document(history, documentSaver);
		THEN("Document is untitled and doesn't have items")
		{
			REQUIRE(document.GetTitle() == "Untitled");
			REQUIRE(document.GetItemsCount() == 0);
		}
	}
	CDocument document(history, documentSaver);
	WHEN("We insert paragraph in empty document")
	{
		document.InsertParagraph("Hello", std::nullopt);
		THEN("Document has only 1 element and it's paragraph")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetImage() == nullptr);
			REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "Hello");
		}
	}
	WHEN("We insert paragraphs in empty document")
	{
		document.InsertParagraph("Hello2", 0);
		document.InsertParagraph("Hello1", 1);
		THEN("Items are in correct order")
		{
			REQUIRE(document.GetItemsCount() == 2);
			REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "Hello2");
			REQUIRE(document.GetItem(1).GetParagraph()->GetText() == "Hello1");
		}
	}
	WHEN("We insert image in empty document")
	{
		document.InsertImage("C:\\image.png", 500, 400, std::nullopt);
		THEN("Document has only 1 element and it's image")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetParagraph() == nullptr);
			REQUIRE(document.GetItem(0).GetImage()->GetPath() == "C:\\image.png");
			REQUIRE(document.GetItem(0).GetImage()->GetHeight() == 400);
			REQUIRE(document.GetItem(0).GetImage()->GetWidth() == 500);
		}
	}
	WHEN("We insert images in empty document")
	{
		document.InsertImage("C:\\image.png", 500, 400, 0);
		document.InsertImage("C:\\image234.png", 400, 300, 1);
		THEN("Items are in correct order")
		{
			REQUIRE(document.GetItemsCount() == 2);
			REQUIRE(document.GetItem(0).GetParagraph() == nullptr);
			REQUIRE(document.GetItem(0).GetImage()->GetPath() == "C:\\image.png");
			REQUIRE(document.GetItem(0).GetImage()->GetHeight() == 400);
			REQUIRE(document.GetItem(0).GetImage()->GetWidth() == 500);
			REQUIRE(document.GetItem(1).GetParagraph() == nullptr);
			REQUIRE(document.GetItem(1).GetImage()->GetPath() == "C:\\image234.png");
			REQUIRE(document.GetItem(1).GetImage()->GetHeight() == 300);
			REQUIRE(document.GetItem(1).GetImage()->GetWidth() == 400);
		}
	}
	WHEN("We change document title")
	{
		document.SetTitle("New title");
		THEN("Title is changed")
		{
			REQUIRE(document.GetTitle() == "New title");
		}
	}
	WHEN("We add paragraph, then do undo, then do redo")
	{
		document.InsertParagraph("Hello", std::nullopt);
		THEN("After undo, document has 0 items")
		{
			document.Undo();
			REQUIRE(document.GetItemsCount() == 0);
			THEN("After redo, document has 1 item and it's our paragraph")
			{
				document.Redo();
				REQUIRE(document.GetItemsCount() == 1);
				REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "Hello");
			}
		}
		
	}
}

SCENARIO("Test CParagraph")
{
	CHistory history;
	WHEN("We create paragraph with given text")
	{
		auto paragraph = CParagraph(history, "Given text");
		THEN("We can get text which this paragraph has")
		{
			REQUIRE(paragraph.GetText() == "Given text");
		}
		THEN("We can replace text")
		{
			paragraph.SetText("New text");
			REQUIRE(paragraph.GetText() == "New text");
		}
	}
}


SCENARIO("Test CImage")
{
	CHistory history;
	WHEN("We create image with given path, width, height")
	{
		auto image = CImage(history, 300, 500, "C:\\example.png");
		THEN("We can get parameters of this picture")
		{
			REQUIRE(image.GetHeight() == 500);
			REQUIRE(image.GetWidth() == 300);
			REQUIRE(image.GetPath() == "C:\\example.png");
		}
		THEN("We can resize image")
		{
			image.Resize(700, 1000);
			REQUIRE(image.GetHeight() == 1000);
			REQUIRE(image.GetWidth() == 700);
		}
	}
}

SCENARIO("Test CHistory")
{
	WHEN("We create history")
	{
		CHistory history;
		THEN("We can't do \"Undo\" and \"Redo\"")
		{
			REQUIRE(history.CanUndo() == false);
			REQUIRE(history.CanRedo() == false);
		}
	}
	CHistory history;
	WHEN("We add command in history")
	{
		std::string target = "test";
		std::string newValue = "newValue";
		history.AddAndExecuteCommand(std::make_unique<CChangeStringCommand>(target, newValue));
		THEN("We can do \"Undo\"")
		{
			REQUIRE(history.CanUndo() == true);
			history.Undo();
			THEN("We can do \"Redo\"")
			{
				REQUIRE(history.CanRedo() == true);
			}
		}
	}
}

SCENARIO("Test CChangeStringCommmand")
{
	std::string target1 = "target1";
	std::string target2 = "target2";
	
	ICommandPtr command = std::make_unique<CChangeStringCommand>(target1, target2);
	WHEN("We execute command")
	{
		command->Execute();
		THEN("Target1 gets target2 value")
		{
			REQUIRE(target1 == "target2");
			WHEN("We unexecute command")
			{
				command->Unexecute();
				THEN("Target1 returned to it start values")
				{
					REQUIRE(target1 == "target1");
				}
			}
		}
	}
}

SCENARIO("Test InsertDocumentItemCommand")
{
	std::vector<CDocumentItem> documentItems;
	std::optional<size_t> index = 0;
	CHistory history;
	std::shared_ptr<IParagraph> paragraph = std::make_shared<CParagraph>(history, "Given text");
	std::shared_ptr<CDocumentItem> documentItem = std::make_shared<CDocumentItem>(paragraph);
	ICommandPtr command = std::make_unique<CInsertDocumentItemCommand>(documentItems, move(documentItem), index);
	WHEN("We execute command")
	{
		command->Execute();
		THEN("Vector size is 1")
		{
			REQUIRE(documentItems.size() == 1);
			WHEN("We unexecute command")
			{
				command->Unexecute();
				THEN("Vector size is 0")
				{
					REQUIRE(documentItems.size() == 0);
				}
			}
		}
	}
}

SCENARIO("Test DeleteDocumentItemCommand")
{
	size_t index = 0;
	CHistory history;
	std::shared_ptr<IParagraph> paragraph = std::make_shared<CParagraph>(history, "Given text");
	std::shared_ptr<CDocumentItem> documentItem = std::make_shared<CDocumentItem>(paragraph);
	std::vector<CDocumentItem> documentItems = {*documentItem};
	ICommandPtr command = std::make_unique<CDeleteItemCommand>(documentItems, index);
	WHEN("We execute command")
	{
		command->Execute();
		THEN("Vector size is 0")
		{
			REQUIRE(documentItems.size() == 0);
			WHEN("We unexecute command")
			{
				command->Unexecute();
				THEN("Vector size is 1")
				{
					REQUIRE(documentItems.size() == 1);
				}
			}
		}
	}
}

SCENARIO("Test ResizeImageCommand")
{
	int width1 = 100;
	int height1 = 50;
	int width2 = 200;
	int height2 = 100;
	ICommandPtr command = std::make_unique<CResizeImageCommand>(width1, height1, width2, height2);
	WHEN("We execute command")
	{
		command->Execute();
		THEN("Width1 gets width2 value and height1 gets height2 value")
		{
			REQUIRE(width1 == width2);
			REQUIRE(height1 == height2);
			WHEN("We unexecute command")
			{
				command->Unexecute();
				THEN("Width1 and height1 get start values")
				{
					REQUIRE(width1 == 100);
					REQUIRE(height1 == 50);
				}
			}
		}
	}
}

SCENARIO("Test CDocumentSaver")
{
	CHistory history;
	std::shared_ptr<CDocumentSaver> documentSaver = std::make_shared<CDocumentSaver>();
	CDocument document = CDocument(history, documentSaver);
	document.InsertImage("C:\\projects\\ood\\lab5\\lab5\\forTests\\sauron.jpg", 400, 400, 0);
	document.InsertParagraph("It is a paragraph.", 1);
	document.SetTitle("title");
	WHEN("We save document in given folder")
	{
		document.Save("C:\\projects\\ood\\lab5\\lab5\\forTests");
		THEN("We get html file")
		{
			std::ifstream outputFile("C:\\projects\\ood\\lab5\\lab5\\forTests\\title.html");
			std::ostringstream fileContain;
			fileContain << outputFile.rdbuf();
			outputFile.close();
			std::string gotResult = fileContain.str();
			std::string wantedResult = "<!DOCTYPE html>\n<html>\n  <head>\n    <title>title</title>\n  </head>\n  <body>\n    <img src=\"images\\sauron.jpg\" width=\"400\" height=\"400\" alt=\"image1\">\n    <p>It is a paragraph.</p>\n  </body>\n</html>";
			REQUIRE(gotResult == wantedResult);
		}
	}
}