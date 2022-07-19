#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileFactory* factory;
	AbstractFileSystem* system;
};

enum class execute_result {
	success = 0,
	file_creation_error = 1,
	file_adding_error = 2,
};