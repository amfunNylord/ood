#pragma once

#include "IDocument.h"

class IDocumentSaver
{
public:
	// не передавать сырой указатель
	virtual void Save(const std::string& path, const IDocument* document)= 0;
	
	virtual ~IDocumentSaver() = default;
};