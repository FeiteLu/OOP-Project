/*File Name : AbstractCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include <string>


class AbstractCommand {
public:
	virtual ~AbstractCommand() = default; //destructor
	virtual int execute(std::string) = 0; //takes in string and executes the command given by the string
	virtual void displayInfo() = 0;  //displays info regarded to the given string
};

enum class command_output { //possible return types of abstract command class functions
	success = 0,
	error = 1,
	command_DNE = 2
};