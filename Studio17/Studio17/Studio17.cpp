// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/TextFile.h"

using namespace std;


int main()
{
	SimpleFileSystem s;

	cout << s.addFile("image", new ImageFile("image")) << endl;
	cout << s.addFile("text", new ImageFile("text")) << endl;

	AbstractFile* a = s.openFile("image");

	cout << a << endl;

	a = s.openFile("image");

	cout << a << endl;

}

