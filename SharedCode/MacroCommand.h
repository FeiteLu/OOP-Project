#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <string>

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
private:
	AbstractFileSystem* system;
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strategy;
};

enum class macro_state {
	success = 0,
	error = 1,
};