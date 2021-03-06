#pragma once
#include <string>
#include "DateTime.h"
#include "TimeAllocation.h"
#include <iostream>

class WorkDone : public TimeAllocation
{
private:
	std::string description;
	std::string type = "Work Done";
public:
	const std::stringstream showDetails();
	WorkDone(std::string &start_, std::string &end_, std::string &desc_);
	const std::string getStart();
	const std::string getEnd();

	const int getStartMins();
	const int getEndMins();
	WorkDone();
	~WorkDone();
};

const std::ostream& operator << (std::ostream& os, WorkDone& w);