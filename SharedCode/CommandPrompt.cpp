#include "CommandPrompt.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

CommandPrompt::CommandPrompt() {
	system = nullptr;
	factory = nullptr;

}

void CommandPrompt::setFileFactory(AbstractFileFactory* in_factory) {
	factory = in_factory;

}

void CommandPrompt::setFileSystem(AbstractFileSystem* in_sys) {
	system = in_sys;
}

int CommandPrompt::addCommand(std::string key, AbstractCommand* command) {
	int before_size = static_cast<int>(map.size());
	map.insert(std::pair<string, AbstractCommand*>(key, command));
	int after_size = static_cast<int>(map.size());
	if (after_size > before_size) {
		return static_cast<int>(command_prompt_output::success);
	}
	else {
		return static_cast<int>(command_prompt_output::failed_insert);
	}

}

void CommandPrompt::listCommands() {
	for (auto it = map.begin(); it != map.end(); ++it) {
		cout << it->first << endl;
	}
	

}

string CommandPrompt::prompt() {
	cout << "Please enter a command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details for a specific command" << endl;
	cout << "$    ";
	string input;
	getline(cin, input);
	return input;

}

int CommandPrompt::run() {
	while (1) {
		string user_command = prompt();
		if (user_command == "q") {
			return static_cast<int>(command_prompt_output::quit);
		}
		else if (user_command == "help") {
			listCommands();
		}
		else {
			string first;
			string second;
			bool more_than_one_word = false;
			for (char s : user_command) {
				if (s == ' ') {
					more_than_one_word = true;
					istringstream iss(user_command);
					iss >> first;
					if (first == "help") {
						iss >> second;
						if (map.find(second) != map.end()) {
							map.at(second)->displayInfo();
				
						}
						else {
							cout << "Command does not exist." << endl;
						}
					}
					else {
						if (map.find(first) != map.end()) {
							string temp;
							iss >> temp;
							second = temp;
							if(second != " "){
								while (iss >> temp) {
									second += " ";
									second += temp;
								}

								if (map.at(first)->execute(second) == static_cast<int>(command_output::error)) {
									cout << "An error has occured" << endl;
								}
							}
						}
						else {
							cout << "Command does not exist" << endl;
						}
					}
				}
			}
			
			if (more_than_one_word == false) {
				istringstream iss(user_command);
				iss >> first;
				if (map.find(first) != map.end()) {
					if (map.at(first)->execute(" ") == static_cast<int>(command_output::error)) {
						cout << "An error has occured" << endl;
					}
				}

			}
		

		}
	}
}