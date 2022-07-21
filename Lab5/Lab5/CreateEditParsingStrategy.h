/*File Name : CreateEditParsingStrategy.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "..\..\SharedCode\AbstractParsingStrategy.h"
#include "..\..\SharedCode\AbstractFileSystem.h"

class CreateEditParsingStrategy : public AbstractParsingStrategy {
public:
	CreateEditParsingStrategy();
	virtual std::vector<std::string> parse(std::string); //takes the string and puts all its contents into a vector of type string and returns that vector
};