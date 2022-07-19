// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <cmath>

using namespace std;

BasicDisplayVisitor::BasicDisplayVisitor() {
	contents.push_back(' ');
}

void BasicDisplayVisitor::visit(ImageFile* file) {
	contents = (*file).read();
	int size = (*file).getSize();
	int dimensions = static_cast<int>(sqrt(size)); //check size?
	for (int i = (dimensions - 1); i >= 0; --i) {
		for (int j = 0; j < dimensions; ++j) {
			int index = j * dimensions + i;
			/*if (contents[index] == ' ') {
				cout << 'Y';
			}
			else {
				cout << contents[index];
			}*/							// for debugging
			cout << contents[index];
			//cout << output[(*file).createIndex(i, j)];
		}
		cout << endl;
	}
}

void BasicDisplayVisitor::visit(TextFile* file){
	contents = (*file).read();
	for (char k : contents) {
		cout << k;
	}
}


