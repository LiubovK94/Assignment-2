#pragma once
#include <string>
#include "TimeAllocation.h"
class BugFix : public TimeAllocation
{
private:
	int id;
	std::string note;

public:
	void showDetails();
	BugFix();
	~BugFix();
};

