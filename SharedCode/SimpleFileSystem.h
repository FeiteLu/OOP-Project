/*File Name : SimpleFileSystem.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractFileSystem.h"
#include <map>
#include <set>
// declaration of SimpleFileSystem class goes here

class SimpleFileSystem : public AbstractFileSystem {
public:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
	virtual int addFile(std::string fileName, AbstractFile* absFile) override; //adds file with the given pointer and string name
	virtual int deleteFile(std::string fileName) override; //delets file with the given string
	virtual AbstractFile* openFile(std::string fileName) override; //opens file with the given string
	virtual int closeFile(AbstractFile* absFile) override; //closes file with the given string
	virtual set<string> getFileNames() override; //gets all the file names
};

