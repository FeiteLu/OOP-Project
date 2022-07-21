#include "RenameParsingStrategy.h"
#include "AbstractCommand.h"
#include "CopyCommand.h"
/*File Name : RenameParsingStrategy.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "RemoveCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

RenameParsingStrategy :: RenameParsingStrategy() {

}

vector<string> RenameParsingStrategy::parse(string file_names) { 
	istringstream iss(file_names);// istringstream of the file passed in
	string old_name;
	string new_name;
	vector<string> arguments;
	iss >> old_name;
	iss >> new_name;
	arguments.push_back(file_names); //pushes back the string given to arguments and iss of the string given then returns the arguments vector
	arguments.push_back(old_name);
	return arguments;
}