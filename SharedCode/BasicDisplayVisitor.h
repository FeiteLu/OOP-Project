/*File Name : BasicDisplay.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractFileVisitor.h"
// declaration of BasicDisplayVisitor here

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	BasicDisplayVisitor();
	virtual void visit(ImageFile*); //display imagefile
	virtual void visit(TextFile*); //display textfile

private:
	vector<char> contents;
};

