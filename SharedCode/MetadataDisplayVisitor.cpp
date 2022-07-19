// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>

MetadataDisplayVisitor::MetadataDisplayVisitor() {
	type = ' ';
	name = ' ';
	size = 0;
}
 
void MetadataDisplayVisitor::visit(ImageFile* file) {
	type = "image";
	name = file->getName();
	size = file->getSize();
	cout << "Type: " << type << endl;
	cout << "Name: " << name << endl;
	cout << "Size: " << size << endl;
}

void MetadataDisplayVisitor::visit(TextFile* file) {
	type = "text";
	name = file->getName();
	size = file->getSize();
	cout << "Type: " << type << endl;
	cout << "Name: " << name << endl;
	cout << "Size: " << size << endl;
}

