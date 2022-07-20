#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "string"

class CopyCommand : public AbstractCommand {
public:
	CopyCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* system;
};

enum class copy_state {
	success = 0,
	no_file_name_arguments = 1,
	no_new_file_name_argument = 2,
	fail_to_add_file = 3,
};