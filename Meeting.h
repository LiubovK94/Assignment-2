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
	const void showDetails();
	void addAttendee(std::string &a);
	const std::string getStart();
	const std::string getEnd();
	const std::string getLoc();
	
	const std::vector<std::string> getAtt();

	Meeting(std::string &start_, std::string &end_, std::string &desc_);
	Meeting();
	~Meeting();
};

const std::ostream& operator << (std::ostream& os,Meeting& m);