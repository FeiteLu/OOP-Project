// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\AbstractCommand.h"
#include "..\..\SharedCode\AbstractFileSystem.h"
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\CopyCommand.h"
#include "..\..\SharedCode\RemoveCommand.h"
#include "..\..\SharedCode\MacroCommand.h"
#include "..\..\SharedCode\RenameParsingStrategy.h"
#include "..\..\SharedCode\CommandPrompt.h"
#include "..\..\SharedCode\TouchCommand.h"
#include "..\..\SharedCode\CatCommand.h"
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\Lab5\Lab5\CreateEditParsingStrategy.h"
#include "..\..\SharedCode\LSCommand.h"
#include "..\..\SharedCode\DisplayCommand.h"


int main()
{	
	AbstractFileSystem* sys = new SimpleFileSystem;
	AbstractFileFactory* fac = new SimpleFileFactory;
	vector<AbstractCommand*> renameCommands;
	renameCommands.push_back(new CopyCommand(sys));
	renameCommands.push_back(new RemoveCommand(sys));
	AbstractCommand* rn = new MacroCommand(renameCommands, new RenameParsingStrategy());
	CommandPrompt cmd;
	cmd.setFileSystem(sys);
	cmd.addCommand("rn", rn);

	vector<AbstractCommand*> createEditCommands;
	createEditCommands.push_back(new TouchCommand(sys, fac));
	createEditCommands.push_back(new CatCommand(sys));
	AbstractCommand* create_edit = new MacroCommand(createEditCommands, new CreateEditParsingStrategy());
	cmd.addCommand("ce", create_edit);

	cmd.addCommand("ls", new LSCommand(sys));
	cmd.addCommand("rm", new RemoveCommand(sys));
	cmd.addCommand("cat", new CatCommand(sys));
	cmd.addCommand("ds", new DisplayCommand(sys));
	cmd.addCommand("cp", new CopyCommand(sys));



	return 0;
}


