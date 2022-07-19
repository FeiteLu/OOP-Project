// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>


using namespace std;


int main()
{
	/*TextFile test("test");
	vector<char> input = { 'h', 'i' };
	string hello = "hello";
	for (char k : hello) {
		input.push_back(k);
	}
	test.write(input);
	cout << "size: " << test.getSize() << endl;
	cout << "name: " << test.getName() << endl;
	test.read();*/
	TextFile test("test");
	AbstractFile* ab = &test;
	cout << "name: " << ab->getName() << endl;
	vector<char> in;
	ab->append(in);
	cout << "size: " << ab->getSize() << endl;
	ab->read();



}


