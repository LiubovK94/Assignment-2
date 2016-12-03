#pragma once
#include <string>
#include "DateTime.h"
class Task
{
	std::string name;
	std::string description;
	DateTime start;
	DateTime deadline;

public:
	Task();
	~Task();
};

