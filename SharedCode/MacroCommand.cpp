#include "MacroCommand.h"
#include <iostream>

MacroCommand::MacroCommand(AbstractFileSystem* in_sys): system(in_sys),commands(0), strategy(nullptr) {
	
}

int MacroCommand::execute(std::string input) {
	vector<string> arguments = strategy->parse(input);
	for (int index = 0; index < commands.size(); ++index) {
		AbstractCommand* command = commands.at(index);
		string argument = arguments.at(index);
		try {
			command->execute(argument);
		}
		catch (...) {
			return static_cast<int>(macro_state::error);
		}
	}
	return static_cast<int>(macro_state::success);
}

void MacroCommand::displayInfo() {
	string output = "macro executes several commands in order";
	cout << output << endl;
}

void MacroCommand::addCommand(AbstractCommand* new_command) {
	commands.push_back(new_command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* new_strategy) {
	strategy = new_strategy;
}