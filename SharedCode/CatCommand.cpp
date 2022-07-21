/*File Name : CatCommand.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "CatCommand.h"
#include <iostream>
#include <sstream>
#include "DisplayCommand.h"


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
	
		if (file_name.substr(file_name.size()-2,2) == "-a") { //checks if flag -a is typed within the command call if so it will print out the file and append to end of it if wq is called
			istringstream iss(file_name);
			iss >> file_name;
			AbstractFile* file;
			file = system->openFile(file_name);
			if (file == nullptr) {
				system->closeFile(file);
				return static_cast<int>(cat_state::file_not_exist);
			}
			vector<char> contents = file->read();
			string output;
			for (char c: contents) {
				output += c;
			}
			cout << output << endl;
			cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
			
			while (cin>>input) { // contiuniously getting input from user until :wq or :q is typed
				if (input == ":wq") {
					vector<char> input_vec;
					for (char c : save_input) { // pushing all the input to vector and and check if it can write to the file if so it will write and close file if not it will return write error and close file if so will close file and return success
						input_vec.push_back(c);
					}
					if (file->append(input_vec) != 0) {
						return file->append(input_vec);
					}
					system->closeFile(file);
					return static_cast<int>(cat_state::success);
				}
			   
				if (input == ":q") {
					system->closeFile(file);
					return static_cast<int>(cat_state::success);
				}

				if (save_input.empty()) {
					save_input = input;
				}
				else { //newline for everytime the user types on a new line
					save_input += "\n" + input;
				}
			}
			system->closeFile(file);
			
		
		}
	
	AbstractFile* file;
	file = system->openFile(file_name);
	if (file == nullptr) { //checks if it can open file and if not will close the file and return file does not exist error
		system->closeFile(file);
		return static_cast<int>(cat_state::file_not_exist);
	}



	cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
	while (cin>>input) { // contiuniously getting input from user until :wq or :q is typed
		if (input == ":wq") {
			vector<char> input_vec;
			for (char c : save_input) { // pushing all the input to vector and and check if it can write to the file if so it will write and close file if not it will return write error and close file if so will close file and return success
				input_vec.push_back(c);
			}
			try {
				file->write(input_vec);
			}
			catch (...) {
				system->closeFile(file);
				return static_cast<int>(cat_state::write_file_error);
			}
			system->closeFile(file);
			return static_cast<int>(cat_state::success);
		}

		if (input == ":q") { // checks if :q is typed if so will close file and return success
			system->closeFile(file);
			return static_cast<int>(cat_state::success);
		}

		if (save_input.empty()) { 
			save_input = input;
		}
		else { //inputs new line for each time there is a new line by the user
			save_input += "\n" + input;
		}
	}
	system->closeFile(file); //closes file if it was not returned by previous returns and returns error
	return static_cast<int>(cat_state::error_occurs);
}

void CatCommand::displayInfo() { //prints out how to use cat
	string output1 = "cat is for concatenating files and writing files, cat can be invoked with the command: cat <filename> [-a] ";
	string output2 = "the -a is optional, you can either enter cat <filename> or cat <filename> -a";
	string output3 = "After adding data to the file, you can enter :wq to save and quit, enter :q to quit without saving and without -a, the input will not be appended but will overwrite the old contents";
	cout << output1 << endl;
	cout << output2 << endl;
	cout << output3 << endl;
}