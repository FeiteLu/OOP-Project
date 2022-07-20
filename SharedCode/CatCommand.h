#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* system;
};