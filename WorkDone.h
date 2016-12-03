#pragma once
#include <string>
#include "DateTime.h"
#include "TimeAllocation.h"

class WorkDone : public TimeAllocation
{
private:
	std::string note;
public:
	void showDetails();
	WorkDone();
	~WorkDone();
};

