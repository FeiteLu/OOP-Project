/*File Name : TextFile.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
#include <string>
#include <iostream>
#include "AbstractFileVisitor.h"

using namespace std;

TextFile::TextFile(string in) : name(in) {}

unsigned int TextFile::getSize() { // returns size
	unsigned int out = static_cast<unsigned int>(contents.size());
	return out;
}

string TextFile::getName() { //returns name
	return name;
}

int TextFile::write(vector<char> in) { //clear content vector and iterates through characters in given vector and pushes back into contents then returns success
	contents.clear();
	for(char k : in){
		contents.push_back(k);
	}
	return static_cast<int>(returnType::success);
}

int TextFile::append(vector<char> in) {
	for (char k : in) { //iterates through vector given and pushes back into contents and then returns success
		contents.push_back(k);
	}
	return static_cast<int>(returnType::success);
}

vector<char> TextFile::read() {
	vector<char> output;
	for (char k : contents) { //iterates through contents vector and pushes back into output and returns output
		output.push_back(k);
	}
	return output;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit(this);
}

AbstractFile* TextFile::clone(string new_file) {
	AbstractFile* copy = new TextFile(new_file);  //makes new object and stores in copy reads contents from object and writes into the copy and returns the copy
	vector<char> contents = this->read();
	copy->write(contents);
	return copy;
}