#include "Extra.h"
#include <iostream>

Extra::Extra(std::string &start_, std::string &end_, std::string &desc_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	description = desc_;

}
void Extra::addProgrammer(std::string &a)
{
	programmer.push_back(a);
}
const std::string Extra::getStart(){ return start.getFormatted(); }
const std::string Extra::getEnd(){ return end.getFormatted(); }
const std::string Extra::getDesc(){ return description; }
const std::vector<std::string> Extra::getProg() { return programmer; }

const int Extra::getStartMins(){ return start.getMins(); }

const int Extra::getStartHours(){ return start.getHours(); }


const int Extra::getEndMins(){ return end.getMins(); }

const int Extra::getEndHours(){ return end.getHours(); }

const std::stringstream Extra::showDetails()
{
	std::stringstream ss;
	ss << "     " << start.getFormatted() << " - " << end.getFormatted() << ": ";
	ss << description << " - ";
	for (auto i = programmer.begin(); i <programmer.end(); ++i)
	{
		if (i < programmer.end() - 1)
		{
			ss << (*i) << ", ";
		}
		else
		{
			ss << (*i);
		}

	}
	ss << std::endl;
	return ss;
}

Extra::Extra()
{
}


Extra::~Extra()
{
}

const std::ostream& operator << (std::ostream& os, Extra& e)
{
	os << e.showDetails().rdbuf();
	return os;
}