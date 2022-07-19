#pragma once
#include "AbstractFileVisitor.h"
// declaration of BasicDisplayVisitor here

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	BasicDisplayVisitor();
	virtual void visit(ImageFile*);
	virtual void visit(TextFile*);

private:
	vector<char> contents;
};

