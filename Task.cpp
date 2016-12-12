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
	std::cout << " " << name << std::endl;
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			std::cout << "-";
		}
		else {
			std::cout << "-" << std::endl;
		}
	}
	std::cout << "  - " << description << std::endl;
	std::cout << "  - Started: " << start.getFormatted() << std::endl;
	std::cout << "  - Deadline: " << deadline.getFormatted() << std::endl;
	if (ta.empty()){ std::cout << "  - No time allocations are recorded for this task" << std::endl; }
	else{
		std::cout << "  - Time Allocations:" << std::endl;

		for (auto& it : ta)
		{
			std::cout << *it;
		}
	}

}
const std::string Task::countTime()
{
	int hours = countH();
	int min = countM();
	std::string s = "Time Spent:  " + std::to_string(hours) + "h " + std::to_string(min) + "m " ;
	return s;

}
const int Task::countH()
{
	int min = 0;
	int hours = 0;
	for (auto& it : ta)
	{
		int sh = (*it).getStartHours();
		int sm = (*it).getStartMins();
		int eh = (*it).getEndHours();
		int em = (*it).getEndMins();

		min = min + ((eh * 60 + em) - (sh * 60 + sm));
	}

	hours = min / 60;
	
	return hours;

}
const int Task::countM()
{
	int min = 0;
	int hours = 0;
	for (auto& it : ta)
	{
		int sh = (*it).getStartHours();
		int sm = (*it).getStartMins();
		int eh = (*it).getEndHours();
		int em = (*it).getEndMins();

		min = min + ((eh * 60 + em) - (sh * 60 + sm));
	}

	min = min % 60;

	return min;

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
	os << " " << name << "     " << t.countTime() << std::endl;
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