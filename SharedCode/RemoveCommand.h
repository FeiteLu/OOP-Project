#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand :public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* system;
};

enum class Remove_state {
	success = 0,
	no_file_name_argument = 1,
};