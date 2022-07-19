// studio 18 - simple file factory definitions
#include "AbstractFileSystem.h"
#include "SimpleFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"

AbstractFile* SimpleFileFactory::createFile(string fileName) {
	string textFile = "txt";
	string imageFile = "img";

	if (fileName.rfind(".txt") != std::string::npos) {
		TextFile* newFile = new TextFile(fileName);
		return newFile;
	}
	else if (fileName.rfind(".img") != std::string::npos) {
		ImageFile* newFile = new ImageFile(fileName);
		return newFile;
	}
	else {
		return nullptr;
	}
}