/*File Name : AbstractFileVisitor.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
// declaration of the file visitor interface here
#include "ImageFile.h"
#include "TextFile.h"


class AbstractFileVisitor {
public:
	virtual void visit(ImageFile*) = 0; //displays the contents of the imagefile
	virtual void visit(TextFile*)= 0; //displays the contents of the text file

};