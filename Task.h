#pragma once
#include <string>
#include "DateTime.h"
#include "TimeAllocation.h"
#include <vector>
#include <memory>
class Task
{
	private:
	std::string name;
	std::string description;
	DateTime start;
	DateTime deadline;
	std::vector<std::unique_ptr<TimeAllocation>> ta;
public:
	Task(const char* name_, const char* description_, const char* start_, const char* deadline_);
	void showTasks();
	
	void addTA(std::unique_ptr<TimeAllocation> ta_);
	void showTimeAl();
	Task();
	~Task();
};

