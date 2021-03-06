#pragma once
#include <string>
#include "TimeAllocation.h"
#include <vector>
#include <iostream>

class Extra : public TimeAllocation
{
private:
	std::string description;
	std::vector<std::string> programmer;
	std::string type = "Extra Feature";
public:
	const std::stringstream showDetails();
	void addProgrammer(std::string &a);
	const std::string getStart();
	const std::string getEnd();
	const std::string getDesc();

	const std::vector<std::string> getProg();
	const int getStartMins();
	const int getEndMins();
	Extra(std::string &start_, std::string &end_, std::string &desc_);
	Extra();
	~Extra();
};

const std::ostream& operator << (std::ostream& os, Extra& e);