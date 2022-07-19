// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"

using namespace std;

int main()
{
	AbstractFileSystem* s = new SimpleFileSystem;
	AbstractFileFactory* f = new SimpleFileFactory;
	s->addFile("text1.txt", f->createFile("text1.txt"));
	s->addFile("text2.txt", f->createFile("text2.txt"));
	s->addFile("image1.img", f->createFile("image1.img"));
	s->addFile("image2.img", f->createFile("image2.img"));
	
	AbstractFile* t1 = s->openFile("text1.txt");
	t1->write({ 'H','e','l','l','o',','});
	t1->read();
	s->closeFile(t1);
	
	AbstractFile* t2 = s->openFile("text2.txt");
	t2->write({ 'w','o','r','l','d','!' });
	t2->read();
	s->closeFile(t2);

	cout << endl;

	AbstractFile* i1 = s->openFile("image1.img");
	i1->write({ 'X','X','X','X','2' });
	i1->read();
	s ->closeFile(i1);

	AbstractFile* i2 = s->openFile("image2.img");
	i2->write({ 'X',' ','X',' ','X',' ','X',' ', 'X','3'});
	i2->read();
	s->closeFile(i2);

	return 0;
}
