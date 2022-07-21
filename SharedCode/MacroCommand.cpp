/*File Name : MacroCommand.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "MacroCommand.h"
#include <iostream>

MacroCommand::MacroCommand(AbstractFileSystem* in_sys): system(in_sys),commands(0), strategy(nullptr) { //constructor setting member variables
	
}

int MacroCommand::execute(std::string input) {
	vector<string> arguments = strategy->parse(input); //sets vector to return of parse on the input given
	for (int index = 0; index < commands.size(); ++index) { //iterates through the commands and executes all of them and checks if they return success and returns error if not and returns success if so
		AbstractCommand* command = commands.at(index);
		string argument = arguments.at(index);
		int status = command->execute(argument);
		if(status != 0){
			return static_cast<int>(macro_state::error);	
		}
	}
	return static_cast<int>(macro_state::success);
}

void MacroCommand::displayInfo() { //prints out use of the command
	string output = "macro executes several commands in order";
	cout << output << endl;
}

void MacroCommand::addCommand(AbstractCommand* new_command) { //adds command to commands variable
	commands.push_back(new_command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* new_strategy) { //creates new strategy
	strategy = new_strategy;
}