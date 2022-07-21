/*File Name : CreateEditParsingStrategy.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
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
	while (iss >> argument) { //continually pushes back inputs from istringstream into arguments until it returns false and returns arguments
		arguments.push_back(argument);
	}
	return arguments;
}