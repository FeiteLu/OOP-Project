/*File Name : ImageFile.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractFile.h"

// Image file class declaration here

class ImageFile : public AbstractFile {
public:
	ImageFile(std::string s); //constructor sets name equal to s and size = 0
	virtual vector<char> read(); //returns contents
	virtual int write(std::vector<char>); //clears contents and stores the vector passed into the function into the file
	virtual int append(std::vector<char>);//returns append not supported
	virtual unsigned int getSize(); //returns size
	virtual string getName(); // returns name
	virtual void accept(AbstractFileVisitor*); //asks visitor to display the object
	virtual AbstractFile* clone(string);  // makes copy of the object with the name of the string passed in the parameter and returns that object
private:
	virtual int createIndex(int x_coord, int y_coord); //returns y coord times size plus x coord
	std::string name;
	std::vector<char> contents;
	char size;

};


