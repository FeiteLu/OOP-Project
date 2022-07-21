/*File Name : CopyCommand.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "CopyCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* in_sys) { //constructor that sets system to the parameter passed
	system = in_sys;
}


int CopyCommand::execute(string file_names) {
	if (file_names == " ") { //if the string passed is empty it will return no file name arguments
		return static_cast<int>(copy_state::no_file_name_arguments);
	}
	istringstream iss(file_names);
	string old_file, new_file;
	iss >> old_file;
	if (iss >> new_file) { //checks if it new file
		new_file += old_file.substr(old_file.size() - 4, 4); //concatenates the extension of the old file into the new file
		if (new_file == old_file) { //checks if the file names are the same if so it wil return same name for two files
			return static_cast<int>(copy_state::same_name_for_two_files);
		}
		AbstractFile* copy = system->openFile(new_file); //check if the new file is in the file system 
		if (copy != nullptr) { //if copy exists it will close the file and return the file already exist
			system->closeFile(copy); 
			return static_cast<int>(copy_state::file_already_exist);
		}
		AbstractFile* original_file = system->openFile(old_file); //checks if old file is in the file system
		if (original_file == nullptr) { //if original file equals null pointer it will return file not exist
			return static_cast<int>(copy_state::file_not_exist);
		}
		AbstractFile* file_copy = original_file->clone(new_file); //makes copy of the orginal with the newfile 
		system->closeFile(original_file); 
		try { //tries to add the file to the system and will catch fail to add file if that is not caught it will return success
			system->addFile(new_file, file_copy);
			return static_cast<int>(copy_state::success);
		}
		catch (...) {
			return static_cast<int>(copy_state::fail_to_add_file);
		}
		
	}
	else { //if it can't extract new file it will return no new file name arguement
		return static_cast<int>(copy_state::no_new_file_name_argument);
	}
}


void CopyCommand::displayInfo() {
	string output = "cp copies a file to a new file with the user chosen name, cp command can be invoked with cp <file_to_copy> <new_name_with_no_extension>";
	cout << output << endl;
}