#include "Project.h"


Project::Project(const char* name_, const char* description_, const char* start_, const char* deadline_)
{
	name = name_;
	description = description_;
	start = DateTime(start_);
	deadline = DateTime(deadline_);
}

void Project::addTask(Task * t)
{
	tasks.push_back(t);
}

void Project::show()
{
	std::cout << name << std::endl;
	std::cout << description << std::endl;
	for (auto it = tasks.begin(); it != tasks.end(); ++it)
	{
		(*it)->showTasks();
		
	}
}

void Project::viewTasks()
{
	for (auto it = tasks.begin(); it != tasks.end(); ++it)
	{
		(*it)->showTasks();

	}
}

Project::Project()
{
}


Project::~Project()
{
}
