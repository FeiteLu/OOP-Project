// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>

MetadataDisplayVisitor::MetadataDisplayVisitor() {
	type = ' ';
	name = ' ';
	size = 0;
}
 
void MetadataDisplayVisitor::visit(ImageFile* file) {
	type = "image";
	name = file->getName();
	size = file->getSize();
	cout << setw(name.size() + 1) << name;
	cout << setw(name.size() + 1) << type;
	cout << setw(name.size() + 1) << size << endl;
}

void MetadataDisplayVisitor::visit(TextFile* file) {
	type = "text";
	name = file->getName();
	size = file->getSize();
	cout << setw(name.size() + 1) << name;
	cout << setw(name.size() + 1) << type;
	cout << setw(name.size() + 1) << size << endl;
}

