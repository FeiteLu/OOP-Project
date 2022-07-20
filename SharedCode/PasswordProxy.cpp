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

string PasswordProxy::passwordPrompt() {
	
	cout << "Type in your password." << endl;

	string input;

	getline(cin, input);

	return input;

}

bool PasswordProxy::passwordCheck(string s) {

	if (s == password) {
		return true;
	}
	else {
		return false;
	}

}

vector<char> PasswordProxy::read() {
	
	
	if (passwordCheck(passwordPrompt()) == true) {
		return file->read();
	}
	else {
		return vec;
	}
}

int PasswordProxy::write(vector<char> v) {
	
	if (passwordCheck(passwordPrompt()) == true) {
		return file->write(v);
	}
	else {
		return write_failure;
	}

}

int PasswordProxy::append(vector<char> v) {


	if (passwordCheck(passwordPrompt()) == true) {
		return file->append(v);
	}
	else {
		return append_failure;
	}

}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
}

string PasswordProxy::getName() {
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* vis) {
	
	
	if (passwordCheck(passwordPrompt()) == true) {
		file->accept(vis);
	}

}

AbstractFile* PasswordProxy::clone() {
	return new PasswordProxy(*this);
}