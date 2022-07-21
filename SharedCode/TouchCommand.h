/*File Name : TouchCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*); //constructor sets parameters passed to factory and system
	virtual int execute(std::string); //creates file of the given name passed by the string
	virtual void displayInfo(); //displays info regarding how to use this command and what it does

private:
	AbstractFileFactory* factory;
	AbstractFileSystem* system;
};

enum class execute_result { //possible return values of the given functions in the touch command class
	success = 0,
	file_creation_error = 1,
	file_adding_error = 2,

};