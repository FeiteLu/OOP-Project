#pragma once
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	RenameParsingStrategy();
	virtual std::vector<std::string> parse(std::string);
};