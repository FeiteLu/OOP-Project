/*File Name : DisplayCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string); //takes a file through a string and prints out the contents of that string formatted without -d and formatted with -d at the end of the command call 
	virtual void displayInfo(); //holds information on how to run the command
private:
	AbstractFileSystem* system;
};

enum class display_state { //all possible return types of the display command functions
	success = 0,
	error_occurs = 1,
	no_file_name_argument = 2,
	file_not_found = 3
};