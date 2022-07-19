#pragma once
// declaration of MetadataDisplayVisitor here
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	MetadataDisplayVisitor();
	virtual void visit(ImageFile*);
	virtual void visit(TextFile*);

private:
	string type;
	string name;
	int size;
};