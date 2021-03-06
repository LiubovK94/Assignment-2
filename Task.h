#pragma once
#include <string>
#include "DateTime.h"
#include "TimeAllocation.h"
#include "WorkDone.h"
#include <iostream>
#include <algorithm>
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
	const std::stringstream showTasks();

	void addTA(std::unique_ptr<TimeAllocation> ta_);

	Task();
	~Task();
	const std::string countTime();
	const int Task::countM();
	const int Task::countH(); 


	const void loadAsc();
	const void loadDesc();
	std::unique_ptr<TimeAllocation> getTA();
};

const std::ostream& operator << (std::ostream& os, Task& t);
