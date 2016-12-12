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

	Project(std::string &name_, std::string &description_, std::string &start_, std::string &deadline_);
	

	const void loadAsc();
	const void loadDesc();
	void addTask(Task * t);
	const std::stringstream show();
	const std::string countTime();
	Project();
	~Project();
};


const std::ostream& operator << (std::ostream& os, Project& t);