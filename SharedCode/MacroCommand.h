/*File Name : MacroCommand.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <string>

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*); //constructor sets parameter passed equal to system
	virtual int execute(std::string); //executes macro command made of several commands
	virtual void displayInfo(); //prints out how to use the function and what the function does
	void addCommand(AbstractCommand*); //adds command to the set of commands
	void setParseStrategy(AbstractParsingStrategy*); //creates a new strategy
private:
	AbstractFileSystem* system;
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strategy;
};

enum class macro_state {
	success = 0,
	error = 1,
};