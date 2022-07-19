// define methods of SimpleFileSystem class here
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include <utility>
#include "ImageFile.h"
#include "TextFile.h"
#include<iostream>
#include <iomanip>

using namespace std;

int SimpleFileSystem::addFile(std::string fileName, AbstractFile* absFile) {
	
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);
	if (it != files.end()) {
		return AbstractFileSystem::fileExists;
	}
	if (absFile == nullptr) {
		return AbstractFileSystem::nullPtr;
	}
	files.insert(std::pair<string, AbstractFile*>(fileName, absFile));
	return AbstractFileSystem::success;
}


int SimpleFileSystem::deleteFile(std::string fileName) {
	
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);

	if (it != files.end()) {
		if (openFiles.find((*it).second) != openFiles.end()) {
			return AbstractFileSystem::fileOpen;
		}
		
		delete it->second;
		files.erase(it);

		return AbstractFileSystem::success;
	}
	else {
		return AbstractFileSystem::fileNotExist;
	}


}
AbstractFile* SimpleFileSystem::openFile(std::string fileName) {
	
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);
	
	
	if (it != files.end()) {
		
		if (openFiles.find((*it).second) != openFiles.end()) {
			return nullptr;
		}
		else {
			openFiles.insert(it->second);
			return it->second;
		}
	}
	else {
		return nullptr;
	}

	
}
int SimpleFileSystem::closeFile(AbstractFile* absFile) {


		if (openFiles.find(absFile) != openFiles.end()) {
			openFiles.erase(absFile);
			return AbstractFileSystem::success;
		}
		else {
			return AbstractFileSystem::fileNotOpen;
		}
	
}

set<string> SimpleFileSystem::getFileNames() {
	int count = 0;
	set<string> fileNames;
	string fileName;
	for (auto file = files.begin(); file != files.end(); ++file) {
		fileName = file->first;
		if (count == 0) {
			cout << setw(20) << fileName;
			++count;
		}
		else if (count == 1) {
			cout << setw(20) << fileName << endl;
			count = 0;
		}
		fileNames.insert(fileName);
	}
	return fileNames;
	
}