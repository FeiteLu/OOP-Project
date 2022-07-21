#include "DisplayCommand.h"
#include <iostream>
#include <sstream>
#include "BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int DisplayCommand::execute(string file_name) {
	if (file_name == " ") { //checks if a valid file name was passed and if not it returns an error
		return static_cast<int>(display_state::no_file_name_argument);
	}
	
		if (file_name.substr(file_name.size() - 2, 2) == "-d") { //checks if -d was passed in the command call
			istringstream iss(file_name);
			iss >> file_name;
			AbstractFile* file;
			file = system->openFile(file_name);
			if (file == nullptr) { //checks if the file exists if not will return error
				return static_cast<int>(display_state::file_not_found);
			}
			vector<char> contents = file->read();
			for (char c : contents) { //itereates through the characters of the given file and prints it out and then closes the file and returns success
				cout << c;
			}
			cout << endl;
			system->closeFile(file);
			return static_cast<int>(display_state::success);
		}
	
		AbstractFile* file;
		file = system->openFile(file_name);
		if (file == nullptr) { //checks if file exists and if not returns an error
			return static_cast<int>(display_state::file_not_found);
		}
	AbstractFileVisitor* visitor = new BasicDisplayVisitor();
	try { //tries to open file and then closes file and returns success will catch if an error is returned by the file if so will return an error
		file->accept(visitor);
		system->closeFile(file);
		return static_cast<int>(display_state::success);
	}
	catch (...) {
		system->closeFile(file);
		return static_cast<int>(display_state::error_occurs);
	}
}



void DisplayCommand::displayInfo() { //prints out how to use the command and the use
	string output = "ds is for display contents in a file, display formatted contents can be invoked with ds <filename> and display unformatted contents can be invoked with ds <filename> -d";
	cout << output << endl;
}