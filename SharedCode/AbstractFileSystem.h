#pragma once
#include <string>
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include <set>
// declaration of the interface all file systems provide goes here

class AbstractFileSystem {
public:
	virtual int addFile(std::string fileName, AbstractFile* absFile) = 0;
	virtual int deleteFile(std::string fileName) = 0;
	virtual AbstractFile* openFile(std::string fileName) = 0;
	virtual int closeFile(AbstractFile* absFile) = 0;
	virtual set<string> getFileNames() = 0;

	enum fileStuff {
		success = 0,
		fileExists = 1,
		nullPtr = 2,
		fileNotOpen = 3,
		fileNotRecognized = 4,
		fileOpen = 5,
		fileNotExist = 6,
		addFileFailed = 7

	};
};

