#pragma once
#include "AbstractFile.h"
#include "ImageFile.h"
#include <vector>

class PasswordProxy : public AbstractFile {
private: 
	AbstractFile* file; 
	string password; 
	std::vector<char> vec;
public:
	PasswordProxy(AbstractFile* f, string p); //constructor for passwordproxy
	~PasswordProxy(); //destructor for passwordproxy
	vector<char> read();
	int write(vector<char> v); //checks the password and allows the ability to write if it matches
	int append(vector<char> v); //checks the password and allows the ability to append if it matches
	unsigned int getSize(); //returns size
	string getName(); //returns name
	void accept(AbstractFileVisitor* vis); //checks the password and allows accept if it matches
	virtual AbstractFile* clone(string); //creates a copy of the file and takes in a string of the name of the new file with the same password and contents of the previous one
protected:
	string passwordPrompt(); //prompts user to enter password
	bool passwordCheck(string s); //checks if the password matches the user input
};

enum stuff { //possible return types of the password proxy functions
	write_failure = 1,
	append_failure = 2
};