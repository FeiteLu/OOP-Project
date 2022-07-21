#pragma once
#include "AbstractFileFactory.h" 
// Studio 18 - simplefilefactory class declaration goes here

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string fileName); // sees if the file is a txt or img if so will create a new file with the name given and return it if not will return nullptr

protected:
	enum fileStuff { //possible return types of the simplefilefactory class functions
		success = 0,
		fileNotRecognized = 1,

	};
};