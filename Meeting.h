#pragma once
#include <string>
#include "TimeAllocation.h"
#include <vector>

class Meeting : public TimeAllocation
{
private:
	std::string location;
	std::vector<std::string> attendees;
	std::string type = "Meeting";

public:
	void showDetails();
	void addAttendee(char const * a);
	Meeting(char const * start_, char const * end_, char const * desc_);
	Meeting();
	~Meeting();
};

