/*File Name : LSCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand{
public:
	LSCommand(AbstractFileSystem*); //constructor sets parameter passed equal to system
	virtual int execute(std::string); //prints out all files in the directory 
	virtual void displayInfo(); //prints out how to use the command and what it does
private:
	AbstractFileSystem* system;
};

enum class LS_state { //possible return types of the ls command class functions
	success = 0,
	command_fail = 1
};