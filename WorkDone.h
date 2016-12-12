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
	const void showDetails();
	WorkDone(std::string &start_, std::string &end_, std::string &desc_);
	const std::string getStart();
	const std::string getEnd();
	const std::string getDesc();
	
	WorkDone();
	~WorkDone();
};

const std::ostream& operator << (std::ostream& os,WorkDone& w);