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
	Task(std::string &name_, std::string &description_, std::string &start_, std::string &deadline_);
	void showTasks();
	
	void addTA(std::unique_ptr<TimeAllocation> ta_);

	const std::stringstream Task::showTimeAl();
	Task();
	~Task();
	const std::string countTime();
	const int Task::countM();
	const int Task::countH();
	const std::string getStart();
	const std::string getDeadline();
	const std::string getName();
	const std::string getDescription();

	std::unique_ptr<TimeAllocation> getTA();
};

const std::ostream& operator << (std::ostream& os, Task& t);