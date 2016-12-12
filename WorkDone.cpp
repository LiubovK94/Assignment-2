#include "WorkDone.h"
#include "TimeAllocation.h"
#include <iostream>

WorkDone::WorkDone(std::string &start_, std::string &end_, std::string &desc_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	description = desc_;

}

const int WorkDone::getStartMins(){ return start.getMins(); }

const int WorkDone::getStartHours(){ return start.getHours(); }


const int WorkDone::getEndMins(){ return end.getMins(); }

const int WorkDone::getEndHours(){ return end.getHours(); }

const std::stringstream WorkDone::showDetails()
{
	std::stringstream ss;
	ss << "     " << start.getFormatted() << " - " << end.getFormatted() << ": " << description << std::endl;
	return ss;
}

WorkDone::WorkDone()
{
}


WorkDone::~WorkDone()
{
}
const std::string WorkDone::getStart(){ return start.getFormatted(); }
const std::string WorkDone::getEnd(){ return end.getFormatted(); }
const std::string WorkDone::getDesc(){ return description; }


const std::ostream& operator << (std::ostream& os, WorkDone& w)
{
	os << w.showDetails().rdbuf();
	return os;
}