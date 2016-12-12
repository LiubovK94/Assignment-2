#include "Project.h"


Project::Project(std::string &name_, std::string &description_, std::string &start_, std::string &deadline_)
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

const std::stringstream Project::show()
{
	std::stringstream ss;
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			ss << "=";
		}
		else {
			ss << "=" << std::endl;
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
	ss << " - " << description << std::endl;
	ss << " - Started: " << start.getFormatted() << std::endl;
	ss << " - Deadline: " << deadline.getFormatted() << std::endl;

	for (auto it : tasks)
	{
		ss << (*it);

	}
	return ss;
}



const std::string Project::countTime()
{
	int min = 0;
	int hours = 0;
	for (auto it : tasks)
	{
		int m = (*it).countM();
		int h  = (*it).countH();

		min = min + (h * 60) + m;

	}
	hours = min / 60;
	min = min % 60;
	std::string s = "Time Spent: " + std::to_string(hours) + "h " + std::to_string(min) + "m ";
	return s;

}

const std::string Project::getStart(){ return start.getFormatted(); }
const std::string Project::getDeadline(){ return deadline.getFormatted(); }



const void Project::loadAsc()
{

	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			std::cout << "=";
		}
		else {
			std::cout << "=" << std::endl;
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
	std::cout << " - " << description << std::endl;
	std::cout << " - Started: " << start.getFormatted() << std::endl;
	std::cout << " - Deadline: " << deadline.getFormatted() << std::endl;



	for (auto it : tasks)
	{
		(*it).loadAsc();
	}

}

const void Project::loadDesc()
{

	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			std::cout << "=";
		}
		else {
			std::cout << "=" << std::endl;
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
	std::cout << " - " << description << std::endl;
	std::cout << " - Started: " << start.getFormatted() << std::endl;
	std::cout << " - Deadline: " << deadline.getFormatted() << std::endl;



	for (auto it : tasks)
	{
		(*it).loadDesc();
	}

}

Project::Project()
{
}


Project::~Project()
{
}

const std::ostream& operator << (std::ostream& os, Project& p)
{
	os << p.show().rdbuf();
	return os;
}