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

const void Extra::showDetails()
{

}

Extra::Extra()
{
}


Extra::~Extra()
{
}

const std::ostream& operator << (std::ostream& os, Extra& e)
{
	std::vector<std::string> programmer = e.getProg();
	os << "     " << e.getStart() << " - " << e.getEnd() << ": ";
	os << e.getDesc() << " - ";
	for (auto i = programmer.begin(); i <programmer.end(); ++i)
	{
		if (i < programmer.end() - 1)
		{
			os << (*i) << ", ";
		}
		else
		{
			os << (*i);
		}

	}
	os << std::endl;
	return os;
}