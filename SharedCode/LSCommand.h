#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand{
	LSCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual int execute(std::string);

private:
	AbstractFileFactory* factory;
	AbstractFileSystem* system;
};