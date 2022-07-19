#include "TouchCommand.h"
#include "AbstractFileSystem.h"
#include <iostream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* in_sys, AbstractFileFactory* in_fact) {
	factory = in_fact;
	system = in_sys;
}

int TouchCommand::execute(std::string file_name) {
	AbstractFile* file = factory->createFile(file_name);
	if (file == nullptr) {
		cout << "Error creating file" << endl;
		return static_cast<int>(execute_result::file_creation_error);
	}
	else {
		if (system->addFile(file_name, file) == 1) {//fileExists
			cout << "Error adding file to file system" << endl;
			delete file;
			return static_cast<int>(execute_result::file_adding_error);
		} 
	}
	return static_cast<int>(execute_result::success);
}

void TouchCommand::displayInfo() {
	string output = "touch creates a file, touch can be invoked with the command : touch <filename> "; 
	cout << output << endl;
}