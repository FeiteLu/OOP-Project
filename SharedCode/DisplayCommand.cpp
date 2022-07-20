#include "DisplayCommand.h"
#include <iostream>
#include <sstream>
#include "BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int DisplayCommand::execute(string file_name) {
	if (file_name == " ") {
		return static_cast<int>(display_state::no_file_name_argument);
	}
	
		if (file_name.substr(file_name.size() - 2, 2) == "-d") {
			istringstream iss(file_name);
			iss >> file_name;
			AbstractFile* file;
			file = system->openFile(file_name);
			if (file == nullptr) {
				return static_cast<int>(display_state::file_not_found);
			}
			vector<char> contents = file->read();
			for (char c : contents) {
				cout << c;
			}
			cout << endl;
			system->closeFile(file);
			return static_cast<int>(display_state::success);
		}
	
		AbstractFile* file;
		file = system->openFile(file_name);
		if (file == nullptr) {
			return static_cast<int>(display_state::file_not_found);
		}
	AbstractFileVisitor* visitor = new BasicDisplayVisitor();
	try {
		file->accept(visitor);
		system->closeFile(file);
		return static_cast<int>(display_state::success);
	}
	catch (...) {
		system->closeFile(file);
		return static_cast<int>(display_state::error_occurs);
	}
}



void DisplayCommand::displayInfo() {
	string output = "ds is for display contents in a file, display formatted contents can be invoked with ds <filename> and display unformatted contents can be invoked with ds <filename> -d";
	cout << output << endl;
}