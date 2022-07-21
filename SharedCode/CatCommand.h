#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	virtual int execute(std::string); //allows alteration of the given file and by typing input into the console after it is called on a valid file
	virtual void displayInfo(); //holds and displays info on how to run the command

private:
	AbstractFileSystem* system;
};

enum class cat_state { //possible return types of the functions within the class
	success = 0,
	error_occurs = 1,
	no_file_name_argument = 2,
	file_not_exist =3,
	write_file_error = 4
};