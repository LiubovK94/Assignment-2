#include "Task.h"
#include "WorkDone.h"
#include <iostream>

Task::Task(std::string &name_, std::string &description_, std::string &start_, std::string &deadline_)
{
	name = name_;
	description = description_;
	start = DateTime(start_);
	deadline = DateTime(deadline_);
}

void Task::showTasks()
{
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			std::cout << "-";
		}
		else {
			std::cout << "-" << std::endl;
		}
	}
	std::cout <<" "<< name << std::endl;
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			std::cout << "-";
		}
		else {
			std::cout << "-" << std::endl;
		}
	}
	std::cout <<"  - "<< description << std::endl;
	std::cout << "  - Started: " << start.getFormatted() << std::endl;
	std::cout << "  - Deadline: " << deadline.getFormatted() << std::endl;
	if (ta.empty()){ std::cout << "  - No time allocations are recorded for this task" << std::endl;}
	else{
		std::cout << "  - Time Allocations:" << std::endl;

		for (auto& it : ta)
		{
			std::cout << *it;
		}
	}

}

const std::string Task::getStart(){ return start.getFormatted(); }
const std::string Task::getDeadline(){ return deadline.getFormatted(); }
const std::string Task::getName(){ return name; }
const std::string Task::getDescription(){ return description; }


const std::stringstream Task::showTimeAl()
{
	std::stringstream ss;
	if (ta.empty()){ ss << "  - No time allocations are recorded for this task" << std::endl; }
	else{
		ss << "  - Time Allocations:" << std::endl;

		for (auto& it : ta)
		{
			ss << *it;
		}
	}
	return ss;
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

const std::ostream& operator << (std::ostream& os, Task& t)
{
	std::string name = t.getName();

	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			os << "-";
		}
		else {
			os << "-" << std::endl;
		}
	}
	os << " " << name << std::endl;
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			os << "-";
		}
		else {
			os << "-" << std::endl;
		}
	}
	os << "  - " << t.getDescription() << std::endl;
	os << "  - Started: " << t.getStart() << std::endl;
	os << "  - Deadline: " << t.getDeadline() << std::endl;
	os << t.showTimeAl().rdbuf();
	return os;
}