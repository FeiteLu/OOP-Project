#pragma once
#include <vector>
#include <string>


using namespace std;
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual ~AbstractFile() = default;
	virtual AbstractFile* clone() = 0;
};

enum class returnType {
	success = 0,
	sizeMismatch = 1,
	wrongCharType = 2,
	appendNotSupported = 3,
	emptyInput = 4
};

