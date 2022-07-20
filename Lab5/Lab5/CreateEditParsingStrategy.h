#pragma once
#include "..\..\SharedCode\AbstractParsingStrategy.h"
#include "..\..\SharedCode\AbstractFileSystem.h"

class CreateEditParsingStrategy : public AbstractParsingStrategy {
public:
	CreateEditParsingStrategy();
	virtual std::vector<std::string> parse(std::string);
};