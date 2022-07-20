#include "CatCommand.h"
#include <iostream>
#include <sstream>


using namespace std;

CatCommand::CatCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int CatCommand::execute(string file_name) {
	string save_input;
	string input;
	if (file_name == " ") {
		return static_cast<int>(cat_state::no_file_name_argument);
	}
	for (char c : file_name) {
		if (c == '-'&& ++c == 'a') {
			istringstream iss(file_name);
			iss >> file_name;
			AbstractFile* file = system->openFile(file_name);
			file->read();
			cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
			
			while (getline(cin, input)) {
				if (input == ":wq") {
					vector<char> input_vec;
					for (char c : save_input) {
						input_vec.push_back(c);
					}
					file->append(input_vec);
					return static_cast<int>(cat_state::success);
				}
			   
				if (input == ":q") {
					return static_cast<int>(cat_state::success);
				}

				if (save_input.empty()) {
					save_input = input;
				}
				else {
					save_input += "\n" + input;
				}
			}
			system->closeFile(file);
			
		
		}
	}
	AbstractFile* file = system->openFile(file_name);
	cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
	while (getline(cin, input)) {
		if (input == ":wq") {
			vector<char> input_vec;
			for (char c : save_input) {
				input_vec.push_back(c);
			}
			file->write(input_vec);
			return static_cast<int>(cat_state::success);
		}

		if (input == ":q") {
			return static_cast<int>(cat_state::success);
		}

		if (save_input.empty()) {
			save_input = input;
		}
		else {
			save_input += "\n" + input;
		}
	}
	system->closeFile(file);
	return static_cast<int>(cat_state::error_occurs);
}

void CatCommand::displayInfo() {
	string output1 = "cat is for concatenating files and writing files, cat can be invoked with the command: cat <filename> [-a] ";
	string output2 = "the -a is optional, you can either enter cat <filename> or cat <filename> -a";
	string output3 = "After adding data to the file, you can enter :wq to save and quit, enter :q to quit without saving and without -a, the input will not be appended but will overwrite the old contents";
	cout << output1 << endl;
	cout << output2 << endl;
	cout << output3 << endl;
}