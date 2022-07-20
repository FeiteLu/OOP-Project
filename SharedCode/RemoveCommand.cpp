#include "RemoveCommand.h"
#include <iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int RemoveCommand::execute(string fileName) {
	if (fileName != " ") {
		return system->deleteFile(fileName);
	}
	else {
		return static_cast<int>(Remove_state::no_file_name_argument);
	}
}

void RemoveCommand::displayInfo() {
	string output = "remove can remove the file from the file system, remove can be invoked with the command: remove <filename> ";
	cout << output << endl;
}