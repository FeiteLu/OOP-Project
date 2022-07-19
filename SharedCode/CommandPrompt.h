#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>

class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();

protected:
	void listCommands();
	std::string prompt();


private:
	std::map<std::string, AbstractCommand*> map;
	AbstractFileSystem* system;
	AbstractFileFactory* factory;
};

enum class command_prompt_output {
	success = 0,
	failed_insert = 1,
	quit = 2,
};
