#include "CreateEditParsingStrategy.h"
#include <vector>
#include <string>
#include <sstream>

CreateEditParsingStrategy::CreateEditParsingStrategy() {

}

vector<string> CreateEditParsingStrategy::parse(string input) {
	istringstream iss(input);
	string argument;
	vector<string> arguments;
	while (iss >> argument) {
		arguments.push_back(argument);
	}
	return arguments;
}