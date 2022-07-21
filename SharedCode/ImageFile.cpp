/*File Name : ImageFile.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
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
		for (unsigned int i = 0; i < v.size(); ++i) {  //iterates through vector and pushes back the contents of v into contents
			contents.push_back(v[i]);
			if (contents[i] != 'X' && contents[i] != ' ') { //if input has characters other X or whitespace it will clear contents and set size to zero and return wrong char type
				contents.clear();
				size = 0;
				return static_cast<int>(returnType::wrongCharType);
			}
		}

		if (size * size != static_cast<char>(v.size())) { // if size squared does not equal the size of v it will clear contents set size to zero and return size mismatch
			contents.clear();
			size = 0;
			return static_cast<int>(returnType::sizeMismatch);
		}

		return static_cast<int>(returnType::success); //if the program does not return previous to this statement it indicates success hence the return statement of success

	

}

int ImageFile::append(std::vector<char>) {
	return static_cast<int>(returnType::appendNotSupported) //returns append not supported
}

int ImageFile::createIndex(int x_coord, int y_coord) { //returns y coord times size plus x coord
	return y_coord * size + x_coord;
}

vector<char> ImageFile::read() { //returns contents
	
	return contents;

	/*for (int i = size - 1; i >= 0; --i) {
		for (int j = 0; j < size; ++j) {
			cout << contents[createIndex(i, j)];
		}
		cout << endl;
	}*/

}


void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit(this); //asks visitor to display the object
}

AbstractFile* ImageFile::clone(string new_file) {
	AbstractFile* copy = new ImageFile(new_file); //creates object of the type imagefile with the name of the string passed by the parameter
	vector<char> contents = this->read(); //stores the contents of the object this function was called on
	contents.push_back(static_cast<char>(sqrt(contents.size()))); //pushes back the contents of the object this function was called on into the new object that was created
	copy->write(contents); //writes input vector into the new file
	return copy; //returns the new object
}