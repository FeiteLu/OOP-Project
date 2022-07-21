/*File Name : TouchCommand.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "TouchCommand.h"
#include "AbstractFileSystem.h"
#include <iostream>
#include <sstream>
#include "PasswordProxy.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* in_sys, AbstractFileFactory* in_fact) { //constructor sets factory and system equal to the parameters
	factory = in_fact;
	system = in_sys;
}

int TouchCommand::execute(std::string file_name) {

		if (file_name.substr(file_name.size() - 2, 2) == "-p") { //checks if flag -p is passed if so it prompts the user for a password
			istringstream iss(file_name);
			iss >> file_name;
			cout << "What is the password?" << endl;
			string pwd;
			cin >> pwd;
			AbstractFile* file = factory->createFile(file_name); //creates file with the given file name
			if (file == nullptr) {//checks if it can create the file if not returns file creation error
				return static_cast<int>(execute_result::file_creation_error);
			}
			AbstractFile* pwd_proxy = new PasswordProxy(file,  pwd); //creates password proxy with the file and the password given by the user 
			int add = system->addFile(file_name,pwd_proxy); // adds file to the system
			if (add != 0) { //if add does not equal zero returns file adding error
				return static_cast<int>(execute_result::file_adding_error);
			}
		
			return static_cast<int>(execute_result::success); //return success if passed through the rest of the if statements
		}
	
	AbstractFile* file = factory->createFile(file_name); //creates a file with the given file name
	
	if (file == nullptr) { //checks if the file could be created if not prints out error creating file and returns file creation error
		cout << "Error creating file" << endl;
		return static_cast<int>(execute_result::file_creation_error);
	}
	else { //if the file could be created it will check if the file exists if so it will print out error adding file to file system delete the file and return file adding error if not it will return success
		if (system->addFile(file_name, file) == 1) {//fileExists cant access appropriate enum to resolve hard coding the enum related to this error integer is located within abstractfilesystem.h
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