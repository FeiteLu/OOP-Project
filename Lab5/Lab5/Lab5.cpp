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
	MacroCommand* macro = new MacroCommand(sys);
	macro->addCommand(new CopyCommand(sys));
	macro->addCommand(new RemoveCommand(sys));
	macro->setParseStrategy(new RenameParsingStrategy());
	CommandPrompt cmd;
	cmd.setFileSystem(sys);
	cmd.addCommand("rn", macro);


	MacroCommand* macro2 = new MacroCommand(sys);
	macro2->addCommand(new TouchCommand(sys, fac));
	macro2->addCommand(new CatCommand(sys));
	macro2->setParseStrategy (new CreateEditParsingStrategy());
	cmd.addCommand("ce", macro2);

	cmd.addCommand("ls", new LSCommand(sys));
	cmd.addCommand("rm", new RemoveCommand(sys));
	cmd.addCommand("cat", new CatCommand(sys));
	cmd.addCommand("ds", new DisplayCommand(sys));
	cmd.addCommand("cp", new CopyCommand(sys));
	AbstractCommand* command = new TouchCommand(sys, fac);
	cmd.setFileFactory(fac);
	cmd.addCommand("touch", command);
	cmd.run();



	return 0;
}


