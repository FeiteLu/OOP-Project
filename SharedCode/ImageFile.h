#pragma once
#include "AbstractFile.h"

// Image file class declaration here

class ImageFile : public AbstractFile {
public:
	ImageFile(std::string s);
	virtual vector<char> read();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual string getName();
	virtual void accept(AbstractFileVisitor*);
private:
	virtual int createIndex(int x_coord, int y_coord);
	std::string name;
	std::vector<char> contents;
	char size;

};


