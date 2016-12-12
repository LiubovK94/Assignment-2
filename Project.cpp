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

const void Project::show()
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
		std::cout << (*it);

	}
}

const void Project::viewTasks()
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

	for (auto it = tasks.begin(); it != tasks.end(); ++it)
	{
		(*it)->showTasks();

	}
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
const std::string Project::getName(){ return name; }
const std::string Project::getDescription(){ return description; }
const std::vector<Task *>& Project::getTasks(){ return tasks; }


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
	std::string name = p.getName();

	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			os << "=";
		}
		else {
			os << "=" << std::endl;
		}
	}

	os << " " << name << "     " << p.countTime() << std::endl;
	for (int i = 0; i <= name.length(); ++i)
	{
		if (i <= name.length() - 1){
			os << "-";
		}
		else {
			os << "-" << std::endl;
		}
	}
	os << " - " << p.getDescription() << std::endl;
	os << " - Started: " << p.getStart() << std::endl;
	os << " - Deadline: " << p.getDeadline() << std::endl;
	std::vector<Task *> tasks = p.getTasks();
	for (auto it : tasks)
	{
		os << (*it);

	}
	return os;
}