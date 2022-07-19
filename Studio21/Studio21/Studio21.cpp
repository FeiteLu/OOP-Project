// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\TouchCommand.h"
#include "..\..\SharedCode\CommandPrompt.h"

using namespace std;

int main()
{
	AbstractFileSystem* file_sys = new SimpleFileSystem;
	AbstractFileFactory* file_fac = new SimpleFileFactory;
	AbstractCommand* command = new TouchCommand(file_sys, file_fac);
	CommandPrompt prompt;
	prompt.setFileFactory(file_fac);
	prompt.setFileSystem(file_sys);
	prompt.addCommand("touch", command);
	prompt.run();
	if (AbstractFile* file = file_sys->openFile("test.txt")) {
		cout << endl;
		cout << "Open file successfully." << endl;
		cout << endl;
	}

	return 0;
}

