//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
#include <string>
#include <iostream>
#include "AbstractFileVisitor.h"

using namespace std;

TextFile::TextFile(string in) : name(in) {}

unsigned int TextFile::getSize() {
	unsigned int out = static_cast<unsigned int>(contents.size());
	return out;
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> in) {
	contents.clear();
	for(char k : in){
		contents.push_back(k);
	}
	return 0;
}

int TextFile::append(vector<char> in) {
	for (char k : in) {
		contents.push_back(k);
	}
	return 0;
}

vector<char> TextFile::read() {
	vector<char> output;
	for (char k : contents) {
		output.push_back(k);
	}
	return output;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit(this);
}

AbstractFile* TextFile::clone() {
	return new TextFile(*this);
}