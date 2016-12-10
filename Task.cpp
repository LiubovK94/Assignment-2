#include "Task.h"
#include "WorkDone.h"
#include <iostream>


Task::Task(const char* name_, const char* description_, const char* start_, const char* deadline_)
{
	name = name_;
	description = description_;
	start = DateTime(start_);
	deadline = DateTime(deadline_);
}

void Task::showTasks()
{
	std::cout << name << std::endl;
	std::cout << description << std::endl;
	
	for (auto& it = ta.cbegin(); it != ta.cend(); ++it)
	{
		(*it)->showDetails();
	}
	
}

void Task::showTimeAl()
{
	
	
}

void Task::addTA(std::unique_ptr<TimeAllocation> ta_)
{
	ta.emplace_back(std::move(ta_));
	
}

Task::Task()
{
}


Task::~Task()
{
}
