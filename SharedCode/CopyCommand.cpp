#include "CopyCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}


int CopyCommand::execute(string file_names) {
	if (file_names == " ") {
		return static_cast<int>(copy_state::no_file_name_arguments);
	}
	istringstream iss(file_names);
	string old_file, new_file;
	iss >> old_file;
	if (iss >> new_file) {
		new_file += old_file.substr(old_file.size() - 4, 4);
		if (new_file == old_file) {
			return static_cast<int>(copy_state::same_name_for_two_files);
		}
		AbstractFile* copy = system->openFile(new_file);
		if (copy != nullptr) {
			system->closeFile(copy);
			return static_cast<int>(copy_state::file_already_exist);
		}
		AbstractFile* original_file = system->openFile(old_file);
		if (original_file == nullptr) {
			return static_cast<int>(copy_state::file_not_exist);
		}
		AbstractFile* file_copy = original_file->clone(new_file);
		system->closeFile(original_file);
		try {
			system->addFile(new_file, file_copy);
			return static_cast<int>(copy_state::success);
		}
		catch (...) {
			return static_cast<int>(copy_state::fail_to_add_file);
		}
		
	}
	else {
		return static_cast<int>(copy_state::no_new_file_name_argument);
	}
}


void CopyCommand::displayInfo() {
	string output = "cp copies a file to a new file with the user chosen name, cp command can be invoked with cp <file_to_copy> <new_name_with_no_extension>";
	cout << output << endl;
}