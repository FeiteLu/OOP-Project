/*File Name : BasicDisplay.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
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
	for (int i = (dimensions - 1); i >= 0; --i) { //iterates through given file and prints out each index
		for (int j = 0; j < dimensions; ++j) {
			int index = i * dimensions + j;
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
	for (char k : contents) { //iterates through contents of given file and prints out each index
		cout << k;
	}
}


