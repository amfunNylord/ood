#include "DocumentSaver.h"
#include <fstream>
#include <filesystem>

void CDocumentSaver::Save(const std::string& path, const IDocument* document)
{
	std::string filePath = path + "\\" + document->GetTitle() + ".html";
	std::ofstream output(filePath);


	std::string imagesPath = path + "\\images\\";
	
	if (!std::filesystem::exists(imagesPath))
	{
		std::filesystem::create_directory(imagesPath);
	}

	output << "<!DOCTYPE html>" << std::endl
		   << "<html>" << std::endl
		   << "  <head>" << std::endl
		   << "    <title>" << GetEncodedHtmlStr(document->GetTitle()) << "</title>" << std::endl
		   << "  </head>" << std::endl
		   << "  <body>" << std::endl;
	
	for (size_t i = 0; i < document->GetItemsCount(); i++)
	{
		output << "    ";

		int imageCount = 0;
		auto item = document->GetItem(i);
		if (auto paragraph = item.GetParagraph())
		{
			output << "<p>" << GetEncodedHtmlStr(paragraph->GetText()) << "</p>" << std::endl;
		}
		else if (auto image = item.GetImage())
		{
			std::filesystem::path p = image->GetPath();
			imageCount++;
			output << "<img src=\"images\\" + p.filename().string() + "\" width=\"" + std::to_string(image->GetWidth())
				   << "\" height=\"" << std::to_string(image->GetHeight()) << "\" alt=\"image" << imageCount << "\">" << std::endl; 
			std::filesystem::copy_file(image->GetPath(), imagesPath + p.filename().string(), std::filesystem::copy_options::overwrite_existing);
		}
	}

	output << "  </body>" << std::endl
		   << "</html>";
}

std::string CDocumentSaver::GetEncodedHtmlStr(const std::string& str) const
{
	std::string encodedStr;

	for (const auto& ch : str)
	{
		auto it = HTML_ENCODED_ENTITIES.find(ch);
		if (it != HTML_ENCODED_ENTITIES.end())
		{
			encodedStr.append(it->second);
		}
		else
		{
			encodedStr.push_back(ch);
		}
	}

	return encodedStr;
}
