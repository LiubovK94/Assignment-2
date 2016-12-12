#include "Task.h"


Task::Task(std::string &name_, std::string &description_, std::string &start_, std::string &deadline_)
{
	name = name_;
	description = description_;
	start = DateTime(start_);
	deadline = DateTime(deadline_);
}

const std::stringstream Task::showTasks() //out put formatted task
{
	std::stringstream ss;

	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			ss << "-";
		}
		else {
			ss << "-" << std::endl;
		}
	}
	ss << " " << name << "     " << countTime() << std::endl;
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			ss << "-";
		}
		else {
			ss << "-" << std::endl;
		}
	}
	ss << "  - " << description << std::endl;
	ss << "  - Started: " << start.getFormatted() << std::endl;
	ss << "  - Deadline: " << deadline.getFormatted() << std::endl;
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
const std::string Task::countTime() //count time spent on the task
{
	int hours = countH();
	int min = countM();
	std::string s = "Time Spent:  " + std::to_string(hours) + "h " + std::to_string(min) + "m ";
	return s;

}
const int Task::countH() //count hours spent on the task
{
	int min = 0;
	int hours = 0;
	for (auto& it : ta)
	{

		int sm = (*it).getStartMins();
		int em = (*it).getEndMins();

		min = min + (em - sm);
	}

	hours = min / 60;

	return hours;

}
const int Task::countM() //count minutes spent on the task
{
	int min = 0;
	int hours = 0;
	for (auto& it : ta)
	{
		int sm = (*it).getStartMins();
		int em = (*it).getEndMins();

		min = min + (em - sm);
	}

	min = min % 60;

	return min;

}




const void Task::loadAsc() //load Time Aloocations in ascending order
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

	sort(ta.begin(), ta.end(), [](std::unique_ptr<TimeAllocation> &a, std::unique_ptr<TimeAllocation> &b){return a < b; }); //sort vector of Time Allocations

	if (ta.empty()){ std::cout << "  - No time allocations are recorded for this task" << std::endl; }
	else{
		std::cout << "  - Time Allocations:" << std::endl;

		for (auto& it : ta)
		{
			std::cout << *it;
		}
	}

}
const void Task::loadDesc() //load Time Aloocations in descending order
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

	sort(ta.begin(), ta.end(), [](std::unique_ptr<TimeAllocation> &a, std::unique_ptr<TimeAllocation> &b){return a > b; }); //sort vector of Time Allocations

	if (ta.empty()){ std::cout << "  - No time allocations are recorded for this task" << std::endl; }
	else{
		std::cout << "  - Time Allocations:" << std::endl;

		for (auto& it : ta)
		{
			std::cout << *it;
		}
	}

}



void Task::addTA(std::unique_ptr<TimeAllocation> ta_) //put new Time allocation into vector
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
	os << t.showTasks().rdbuf();
	return os;
}