#pragma once
#include "AbstractFileSystem.h"
#include <map>
#include <set>
// declaration of SimpleFileSystem class goes here

class SimpleFileSystem : public AbstractFileSystem {
public:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
	virtual int addFile(std::string fileName, AbstractFile* absFile) override;
	virtual int deleteFile(std::string fileName) override;
	virtual AbstractFile* openFile(std::string fileName) override;
	virtual int closeFile(AbstractFile* absFile) override;
};

