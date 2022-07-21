/*File Name : MetadataDisplayVisitor.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>

MetadataDisplayVisitor::MetadataDisplayVisitor() { //constructor
	type = ' ';
	name = ' ';
	size = 0;
}
 
void MetadataDisplayVisitor::visit(ImageFile* file) {
	type = "image";
	name = file->getName(); //sets member variables equal to their respective getters and prints out the member variables
	size = file->getSize();
	cout << setw(name.size() + 1) << name;
	cout << setw(name.size() + 1) << type;
	cout << setw(name.size() + 1) << size << endl;
}

void MetadataDisplayVisitor::visit(TextFile* file) {
	type = "text";
	name = file->getName(); //sets member variables equal to their respective getters and prints out the member variables
	size = file->getSize();
	cout << setw(name.size() + 1) << name;
	cout << setw(name.size() + 1) << type;
	cout << setw(name.size() + 1) << size << endl;
}

