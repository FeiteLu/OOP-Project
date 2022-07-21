/*File Name : PasswordProxy.cpp
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#include "PasswordProxy.h"
#include "AbstractFile.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* f, string p) : file(f), password(p) {

}

PasswordProxy::~PasswordProxy() {
	delete file;
}

string PasswordProxy::passwordPrompt() { //prompts user to enter password and takes in the input from the command line and returns it
	
	cout << "Type in your password." << endl;

	string input;

	cin  >> input;

	return input;

}

bool PasswordProxy::passwordCheck(string s) { //checks if the string passed correlates with the password

	if (s == password) {
		return true;
	}
	else {
		return false;
	}

}

vector<char> PasswordProxy::read() { 
	
	
	if (passwordCheck(passwordPrompt()) == true) { //checks if the password matches the password given and if so will read the file if not returns vec
		return file->read();
	}
	else {
		return vec;
	}
}

int PasswordProxy::write(vector<char> v) {
	
	if (passwordCheck(passwordPrompt()) == true) { //checks if the password matches the password given and if so will write the file if not returns write failure
		return file->write(v);
	}
	else {
		return write_failure;
	}

}

int PasswordProxy::append(vector<char> v) {


	if (passwordCheck(passwordPrompt()) == true) {//checks if the password matches the password given and if so will append the file if not returns append failure
		return file->append(v);
	}
	else {
		return append_failure;
	}

}

unsigned int PasswordProxy::getSize() { //returns the size of the file
	return file->getSize();
}

string PasswordProxy::getName() { //returns the name of the file
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* vis) { //checks if the password matches the password given and if so will accept the file
	
	
	if (passwordCheck(passwordPrompt()) == true) {
		file->accept(vis);
	}

}

AbstractFile* PasswordProxy::clone(string new_file) { //clones the file with a new name and keeps the same password for the new file
	string pwd = this->password;
	AbstractFile* copy_file = this->file->clone(new_file);
	AbstractFile* copy = new PasswordProxy(copy_file, pwd);
	return copy;
}