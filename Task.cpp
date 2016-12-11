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

		for (auto& it = ta.cbegin(); it != ta.cend(); ++it)
		{
			(*it)->showDetails();
		}
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
