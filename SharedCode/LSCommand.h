#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand{
public:
	LSCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* system;
};

enum class LS_state {
	success = 0,
	command_fail = 1
};