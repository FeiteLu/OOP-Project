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
	if (option == " ") {
		set<string> fileNames = system->getFileNames();
		for (string fileName : fileNames) {
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
	else if (option == "-m") {
		AbstractFileVisitor* metaVisitor = new MetadataDisplayVisitor;
		set<string> fileNames = system->getFileNames();
		for (string fileName : fileNames) {
			AbstractFile* file = system->openFile(fileName);
			file->accept(metaVisitor);
		}
		return static_cast<int>(LS_state::success);
		
	}
	else {
		return static_cast<int>(LS_state::command_fail);
	}
}

void LSCommand::displayInfo() {
	string output1 = "ls list the names of all files, ls can be invoked with the command: ls ";
	string output2 = "ls support an extension to display the metadata for each file, invoked with the command: ls -m";
	cout << output1 << endl;
	cout << output2 << endl;
}