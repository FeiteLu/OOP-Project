/*File Name : AbstractFileSystem.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include <string>
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include <set>
// declaration of the interface all file systems provide goes here

class AbstractFileSystem {
public:
	virtual int addFile(std::string fileName, AbstractFile* absFile) = 0; //adds file with the given string and the type with the pointer
	virtual int deleteFile(std::string fileName) = 0; //deletes the file with the corresponding name of the string passed
	virtual AbstractFile* openFile(std::string fileName) = 0; //opens the file with the corresponding name of the string passed
	virtual int closeFile(AbstractFile* absFile) = 0; // closes the file that is passed with the parameter given
	virtual set<string> getFileNames() = 0; //returns the file names

	enum fileStuff { //possible return types of the abstract file system class
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

