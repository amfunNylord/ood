#pragma once
#include "IDocumentSaver.h"
#include <map>

class CDocumentSaver : public IDocumentSaver
{
public:
	void Save(const std::string& path, const IDocument* document) override;

private:
	std::map<const char, const std::string> HTML_ENCODED_ENTITIES = {
		{ '\"', "&quot;" },
		{ '\'', "&apos;" },
		{ '<', "&lt;" },
		{ '>', "&gt;" },
		{ '&', "&amp;" }
	};
	std::string GetEncodedHtmlStr(const std::string& str) const;
};
