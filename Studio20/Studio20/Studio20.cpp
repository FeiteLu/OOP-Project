// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/ImageFile.h"
#include <iostream>
#include "../../SharedCode/BasicDisplayVisitor.h"

using namespace std;

int main()
{

	AbstractFile* f;
	f = new ImageFile("test");
	string code = "123";
	PasswordProxy p (f, code);
	
	vector<char> input_vec;
	input_vec.push_back(' ');
	input_vec.push_back(' ');
	input_vec.push_back(' ');
	input_vec.push_back('X');
	input_vec.push_back('2');
	p.write(input_vec);
	p.read();
	BasicDisplayVisitor* v = new BasicDisplayVisitor;
	p.accept(v);

	return 0;
}

