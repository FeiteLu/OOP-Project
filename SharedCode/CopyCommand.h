/*File Name : CopyCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "string"

class CopyCommand : public AbstractCommand {
public:
	CopyCommand(AbstractFileSystem*); 
	virtual int execute(std::string); //takes contents from one file and puts it into another 
	virtual void displayInfo(); //holds information on how to run the program
private:
	AbstractFileSystem* system;
};

enum class copy_state { //all possible return types of the copycommand class functions
	success = 0,
	no_file_name_arguments = 1,
	no_new_file_name_argument = 2,
	fail_to_add_file = 3,
	file_not_exist = 4,
	same_name_for_two_files = 5,
	file_already_exist = 6
};