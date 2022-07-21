/*File Name : AbstractFileFactor.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include <string>
#include "AbstractFile.h"

// studio 18 - file factory interface declared here
class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string fileName) = 0; //creates a file with the given string
};
