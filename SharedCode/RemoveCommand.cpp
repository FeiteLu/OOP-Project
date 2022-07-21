/*File Name : RemoveCommand.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "RemoveCommand.h"
#include <iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int RemoveCommand::execute(string fileName) {
	if (fileName != " ") { //checks if input given is white space if not will return deletefile on the given filename if so it will return no file name
		return system->deleteFile(fileName);
	}
	else {
		return static_cast<int>(Remove_state::no_file_name_argument);
	}
}

void RemoveCommand::displayInfo() { //displays information on how to run the command and the use
	string output = "remove can remove the file from the file system, remove can be invoked with the command: remove <filename> ";
	cout << output << endl;
}