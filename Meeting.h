#pragma once
#include <string>
#include "TimeAllocation.h"

class Meeting : public TimeAllocation
{
private:
	std::string location;
	std::string attendees;

public:
	void showDetails();
	Meeting();
	~Meeting();
};

