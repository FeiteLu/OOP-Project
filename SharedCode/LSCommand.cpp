/*File Name : LSCommand.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "LSCommand.h"
#include <string>
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>

LSCommand::LSCommand(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int LSCommand::execute(string option) {
	int count = 0;
	if (option == " " || option == "") { //checks if whitespace or empty
		set<string> fileNames = system->getFileNames(); 
		for (string fileName : fileNames) { //iterates through each of the files stored in fileNames and prints it out then returns success
			if (count == 0) {
				cout << setw(20) << fileName;
				++count;
			}
			else if (count == 1) {
				cout << setw(20) << fileName << endl;
				count = 0;
			}
		}
		return static_cast<int>(LS_state::success);
	}
	else if (option == "-m") { //if -m flag is called within the function call will print out the metadata with each of the files
		AbstractFileVisitor* metaVisitor = new MetadataDisplayVisitor;
		set<string> fileNames = system->getFileNames();
		for (string fileName : fileNames) { //itereates throughout all the files in filenames and prints out all of the files metadata
			AbstractFile* file = system->openFile(fileName);
			file->accept(metaVisitor);
			cout << endl;
			system->closeFile(file);
		}
		return static_cast<int>(LS_state::success);
		
	}
	else {
		return static_cast<int>(LS_state::command_fail);
	}
}

void LSCommand::displayInfo() { //prints out all the information of the command
	string output1 = "ls list the names of all files, ls can be invoked with the command: ls ";
	string output2 = "ls support an extension to display the metadata for each file, invoked with the command: ls -m";
	cout << output1 << endl;
	cout << output2 << endl;
}