#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* system;
};

enum class display_state {
	success = 0,
	error_occurs = 1,
	no_file_name_argument = 2,
	file_not_found = 3
};