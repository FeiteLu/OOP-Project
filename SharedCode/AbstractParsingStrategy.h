/*File Name : AbstractParsingStrategy.h
Email : feite@wustl.edu & k.morrow@wustl.edu
Author : Feite Lu, Klein Morrow */
#pragma once
#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0; //parses string to vector of strings
};