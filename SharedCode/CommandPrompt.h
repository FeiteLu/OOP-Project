/*File Name : CommandPrompt.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>

class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*); //sets file system
	void setFileFactory(AbstractFileFactory*); //sets file factor
	int addCommand(std::string, AbstractCommand*); //adds command and sets the name to the string
	int run(); // runs the command prompt

protected:
	void listCommands(); //prints out the commands
	std::string prompt(); //prompts user for input of the commands


private:
	std::map<std::string, AbstractCommand*> map;
	AbstractFileSystem* system;
	AbstractFileFactory* factory;
};

enum class command_prompt_output { //possible return values of the command prompt class functions
	success = 0,
	failed_insert = 1,
	quit = 2,
};
