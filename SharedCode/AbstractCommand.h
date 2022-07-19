#pragma once
#include <string>


class AbstractCommand {
public:
	virtual ~AbstractCommand() = default;
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
};

enum class command_output {
	success = 0,
	error = 1,
	command_DNE = 2
};