/*File Name : SimpleFileSystem.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
// define methods of SimpleFileSystem class here
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include <utility>
#include "ImageFile.h"
#include "TextFile.h"


using namespace std;

int SimpleFileSystem::addFile(std::string fileName, AbstractFile* absFile) {
	
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);
	if (it != files.end()) { //iterates through files checks if it it already exists and if so returns fileexists 
		return AbstractFileSystem::fileExists;
	}
	if (absFile == nullptr) { //checks if the parameter passed is a nullptr if so will return a nullptr
		return AbstractFileSystem::nullPtr;
	}
	files.insert(std::pair<string, AbstractFile*>(fileName, absFile)); //if it passes the previous if statements will add file and return success
	return AbstractFileSystem::success;
}


int SimpleFileSystem::deleteFile(std::string fileName) {
	
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);

	if (it != files.end()) {
		if (openFiles.find((*it).second) != openFiles.end()) { //iterates through files and checks if it exists if so will delete the file and return success if not will return file does not exist
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
		
		if (openFiles.find(it->second) != openFiles.end()) { //iterates through files and sees if it exists if not will return nullptr  if so it will open the file and return it second
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


		if (openFiles.find(absFile) != openFiles.end()) { //checks if file exists and will call erase on it and return success
			openFiles.erase(absFile);
			return AbstractFileSystem::success;
		}
		else { //if not return file not open error
			return AbstractFileSystem::fileNotOpen;
		}
	
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> fileNames;
	string fileName;
	for (auto file = files.begin(); file != files.end(); ++file) { //iterates through files and inserts it into filenames and then returns file names
		fileName = file->first;
		fileNames.insert(fileName);
	}
	return fileNames;
	
}