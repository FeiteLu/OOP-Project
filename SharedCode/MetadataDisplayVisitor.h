/*File Name : MetadataDisplayVisitor.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
// declaration of MetadataDisplayVisitor here
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	MetadataDisplayVisitor(); //constructor
	virtual void visit(ImageFile*); //sets member variables equal to their respective getters and prints out the member variables
	virtual void visit(TextFile*); //sets member variables equal to their respective getters and prints out the member variables

private:
	string type;
	string name;
	int size;
};