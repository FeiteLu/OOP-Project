/*File Name : CommandPrompt.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "CommandPrompt.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

CommandPrompt::CommandPrompt() { //sets member variables
	system = nullptr;
	factory = nullptr;

}

void CommandPrompt::setFileFactory(AbstractFileFactory* in_factory) { //sets factory
	factory = in_factory;

}

void CommandPrompt::setFileSystem(AbstractFileSystem* in_sys) { //sets system
	system = in_sys;
}

int CommandPrompt::addCommand(std::string key, AbstractCommand* command) {
	int before_size = static_cast<int>(map.size());
	map.insert(std::pair<string, AbstractCommand*>(key, command)); //inserts command given through parameter and the name of that command into the map
	int after_size = static_cast<int>(map.size());
	if (after_size > before_size) { //checks if after size is greater than before size if so return success if not return failed insert
		return static_cast<int>(command_prompt_output::success);
	}
	else {
		return static_cast<int>(command_prompt_output::failed_insert);
	}

}

void CommandPrompt::listCommands() {
	for (auto it = map.begin(); it != map.end(); ++it) { //iterates through map and prints out all the commands within the map
		cout << it->first << endl;
	}
	

}

string CommandPrompt::prompt() { 
	cout << endl;
	cout << "Please enter a command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details for a specific command" << endl;
	cout << "$    ";
	string input;
	getline(cin, input); //reads in user input and returns the input
	return input;

}

int CommandPrompt::run() {
	while (1) {
		string user_command = prompt(); // continually calls print until q is typed
		if (user_command == "q") {
			return static_cast<int>(command_prompt_output::quit);
		}
		else if (user_command == "help") { //if help is typed calls list commands
			listCommands();
		}
		else {
			string first;
			string second;
			bool more_than_one_word = false;
			bool arg = false;
			for (char s : user_command) { //iterates through user input 
				if (s == ' ') { //if whitespace exists set arg = true
					arg = true;

				}

			}

			if (arg == true) { 

				
				more_than_one_word = true;
				istringstream iss(user_command);
				iss >> first;
				if (first == "help") { // if help is the first word typed it will display the info regarding to that command if the command exists if not it will print out that command does not exist
					iss >> second;
					if (map.find(second) != map.end()) {
						map.at(second)->displayInfo();

					}
					else {
						cout << "Command does not exist." << endl;
					}
				}
				else {
					if (map.find(first) != map.end()) { //iterates through map and finds matching key 
						string temp;
						iss >> temp;
						second = temp;
						if (second != " ") { //concatenates the rest of the input string as an arguement for the execute function 
							while (iss >> temp) {
								second += " ";
								second += temp;
							}

							if (map.at(first)->execute(second) == static_cast<int>(command_output::error)) { //call the command on the arguement extracted and checks if an error has occured if so will print out an error has occured
								cout << "An error has occured" << endl;
							}
						}
					}
					else { //if command is not in the command list it will print out the command does not exist
						cout << "Command does not exist" << endl;
					}
				}
			}
			
			if (more_than_one_word == false) { //if more than word is false it will wrap user command in input string stream and extract first into it 
				istringstream iss(user_command);
				iss >> first;
				if (map.find(first) != map.end()) { //iterates through map and executes the command if found 
					if (map.at(first)->execute(" ") == static_cast<int>(command_output::error)) { //if the command produces error it will print out an error has occured
						cout << "An error has occured" << endl;
					}
				}

			}
		

		}
	}
}