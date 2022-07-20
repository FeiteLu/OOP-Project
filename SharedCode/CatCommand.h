#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* system;
};

enum class cat_state {
	success = 0,
	error_occurs = 1,
	no_file_name_argument = 2,
	file_not_exist =3,
	write_file_error = 4
};