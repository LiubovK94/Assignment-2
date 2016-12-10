#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Task.h"
#include "DateTime.h"

class Project
{
private:
	std::string name;
	std::string description;
	DateTime start;
	DateTime deadline;
	std::vector<Task *> tasks;
public:

	Project(const char* name_, const char* description_, const char* start_, const char* deadline_);
	void addTask(Task * t);
	void viewTasks();
	void show();
	Project();
	~Project();
};


