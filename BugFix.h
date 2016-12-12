#pragma once

#include <string>
#include "TimeAllocation.h"
#include <iostream>

class BugFix : public TimeAllocation
{
private:
	std::string id;
	std::string note;
	std::string type = "Bug Fix";
public:
	const std::stringstream showDetails();
	const std::string getStart();
	const std::string getEnd();
	const std::string getNote();
	const std::string getId();
	const int getStartMins();
	const int getEndMins();

	BugFix(std::string &start_, std::string &end_, std::string &desc_, std::string &id_);
	BugFix();
	~BugFix();
};

const std::ostream& operator << (std::ostream& os, BugFix& b);