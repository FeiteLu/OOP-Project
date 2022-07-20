#include "RenameParsingStrategy.h"
#include "AbstractCommand.h"
#include "CopyCommand.h"
#include "RemoveCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

RenameParsingStrategy :: RenameParsingStrategy() {

}

vector<string> RenameParsingStrategy::parse(string file_names) {
	istringstream iss(file_names);
	string old_name;
	string new_name;
	vector<string> arguments;
	iss >> old_name;
	iss >> new_name;
	arguments.push_back(file_names);
	arguments.push_back(old_name);
	return arguments;
}