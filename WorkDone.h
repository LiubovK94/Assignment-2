#pragma once
#include <string>
#include "DateTime.h"
#include "TimeAllocation.h"

class WorkDone : public TimeAllocation
{
private:
	std::string description;
	std::string type = "Work Done";
public:
	void showDetails();
	WorkDone(char const * start_, char const * end_, char const * desc_);
	WorkDone();
	~WorkDone();
};

