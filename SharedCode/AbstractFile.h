/*File Name : AbstractFile.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include <vector>
#include <string>


using namespace std;
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual vector<char> read() = 0; // reads contents return vector of type char
	virtual int write(std::vector<char>) = 0; //use vector given and writes to contents after clearing contents
	virtual int append(std::vector<char>) = 0; // use vector given and writes to the end of contents
	virtual unsigned int getSize() = 0; //returns size
	virtual string getName() = 0; //return name
	virtual void accept(AbstractFileVisitor*) = 0; //displays the info of the file depending on what file it is
	virtual ~AbstractFile() = default; //destructor
	virtual AbstractFile* clone(string) = 0; //creats a copy of the abstractfile it is called upon and gives it the name of the string passed

};

enum class returnType { //possible return types of the abstractfile class functions
	success = 0,
	sizeMismatch = 1,
	wrongCharType = 2,
	appendNotSupported = 3,
	emptyInput = 4
};

