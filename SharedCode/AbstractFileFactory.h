#pragma once
#include <string>
#include "AbstractFile.h"

// studio 18 - file factory interface declared here
class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string fileName) = 0;
};
