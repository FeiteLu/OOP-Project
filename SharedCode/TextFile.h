#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"


using namespace std;
// TextFile declaration goes here

class TextFile : public AbstractFile {
public:
	TextFile(string);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char>);
	virtual int append(std::vector<char>);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone();
private:
	vector<char> contents;
	string name;

};
