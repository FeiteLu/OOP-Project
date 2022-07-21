// studio 18 - simple file factory definitions
#include "AbstractFileSystem.h"
#include "SimpleFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"

AbstractFile* SimpleFileFactory::createFile(string fileName) { 
	string textFile = "txt";
	string imageFile = "img";

	if (fileName.rfind(".txt") != std::string::npos) { // checks if file name given within the parameter is .txt if so will create a new text file with that name and return it
		TextFile* newFile = new TextFile(fileName);
		return newFile;
	}
	else if (fileName.rfind(".img") != std::string::npos) { // checks if file name given within the parameter is .img if so will create a new image file with that name and return it
		ImageFile* newFile = new ImageFile(fileName);
		return newFile;
	}
	else { //if it does not find img or txt will return nullptr
		return nullptr;
	}
}