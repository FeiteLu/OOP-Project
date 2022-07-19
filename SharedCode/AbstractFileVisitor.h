#pragma once
// declaration of the file visitor interface here
#include "ImageFile.h"
#include "TextFile.h"


class AbstractFileVisitor {
public:
	virtual void visit(ImageFile*) = 0;
	virtual void visit(TextFile*)= 0;

};