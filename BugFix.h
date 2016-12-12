#pragma once
#include <string>
#include "TimeAllocation.h"
class BugFix : public TimeAllocation
{
private:
	std::string id;
	std::string note;
	std::string type = "Bug Fix";
public:
	const void showDetails();
	const std::string getStart();
	const std::string getEnd();
	const std::string getNote();
	const std::string getId();
	BugFix(std::string &start_, std::string &end_, std::string &desc_, std::string &id_);
	BugFix();
	~BugFix();
};

const std::ostream& operator << (std::ostream& os, BugFix& b);