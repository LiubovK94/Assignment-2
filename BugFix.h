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
	void showDetails();
	BugFix(char const * start_, char const * end_, char const * desc_, char const * id_);
	BugFix();
	~BugFix();
};

