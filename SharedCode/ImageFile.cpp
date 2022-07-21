// definition of ImageFile class here

#include "ImageFile.h"
#include "AbstractFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "AbstractFileVisitor.h"

using namespace std;

ImageFile::ImageFile(string s) { //sets name to string given and size to 0
	name = s;
	size = 0;
}

unsigned int ImageFile::getSize() { //getter for size and returns size
	return (unsigned int)contents.size();
}

string ImageFile::getName() { //getter for name returns name
	return name;
}

int ImageFile::write(std::vector<char> v) {
	if (v.size() <= 0) { //checks if size is less than or equal to zero if so will return emptyinput
		return static_cast<int>(returnType::emptyInput);
	}
	size = v[v.size() - 1] - '0';
	
		v.pop_back();
		for (unsigned int i = 0; i < v.size(); ++i) { 
			contents.push_back(v[i]);
			if (contents[i] != 'X' && contents[i] != ' ') {
				contents.clear();
				size = 0;
				return static_cast<int>(returnType::wrongCharType);
			}
		}

		if (size * size != static_cast<char>(v.size())) {
			contents.clear();
			size = 0;
			return static_cast<int>(returnType::sizeMismatch);
		}

		return static_cast<int>(returnType::success);

	

}

int ImageFile::append(std::vector<char>) {
	return static_cast<int>(returnType::appendNotSupported);
}

int ImageFile::createIndex(int x_coord, int y_coord) {
	return y_coord * size + x_coord;
}

vector<char> ImageFile::read() {
	
	return contents;

	/*for (int i = size - 1; i >= 0; --i) {
		for (int j = 0; j < size; ++j) {
			cout << contents[createIndex(i, j)];
		}
		cout << endl;
	}*/

}


void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit(this);
}

AbstractFile* ImageFile::clone(string new_file) {
	AbstractFile* copy = new ImageFile(new_file);
	vector<char> contents = this->read();
	contents.push_back(static_cast<char>(sqrt(contents.size())));
	copy->write(contents);
	return copy;
}