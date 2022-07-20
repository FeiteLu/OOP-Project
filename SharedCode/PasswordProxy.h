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
	PasswordProxy(AbstractFile* f, string p);
	~PasswordProxy();
	vector<char> read();
	int write(vector<char> v);
	int append(vector<char> v);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* vis);
	virtual AbstractFile* clone();
protected:
	string passwordPrompt();
	bool passwordCheck(string s);
};

enum stuff {
	write_failure = 1,
	append_failure = 2
};