#pragma once
#include <string>
#include "DateTime.h"

class Project
{
private:
	std::string name;
	std::string description;
	DateTime start;
	DateTime deadline;

public:
	Project();
	~Project();
};

