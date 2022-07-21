/*File Name : RemoveCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand :public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*); //constructor
	virtual int execute(std::string); //deletes the given file and returns an error or success integer
	virtual void displayInfo(); //holds information on how to run the command and what it does and displays it
private:
	AbstractFileSystem* system;
};

enum class Remove_state { //all possible return types of the functions of remove command
	success = 0,
	no_file_name_argument = 1,
};