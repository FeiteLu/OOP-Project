/*File Name : RenameParsingStrategy.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	RenameParsingStrategy();
	virtual std::vector<std::string> parse(std::string); //renames the file with the given string
};