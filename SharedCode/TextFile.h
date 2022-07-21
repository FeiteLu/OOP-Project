/*File Name : TextFile.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"


using namespace std;
// TextFile declaration goes here

class TextFile : public AbstractFile {
	friend AbstractFile* clone();
public:
	TextFile(string);
	virtual unsigned int getSize(); //returns the size
	virtual string getName(); //returns the name
	virtual int write(vector<char>); //clears contents vector and replaces it with the given vector
	virtual int append(std::vector<char>); //adds the given vector to the end of the contents vector
	virtual vector<char> read(); //copys contents to output vector and returns the vector output
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string); //makes copy of the object with a new name given by the string


private:
	vector<char> contents;
	string name;
	

};
