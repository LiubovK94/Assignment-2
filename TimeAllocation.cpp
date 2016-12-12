#include "TimeAllocation.h"


const std::stringstream TimeAllocation::showDetails()
{
	std::stringstream ss;
	ss << start.getFormatted() << std::endl;
	ss << end.getFormatted() << std::endl;
	return ss;
}

const std::string TimeAllocation::getStart(){ return start.getFormatted(); }
const std::string TimeAllocation::getEnd(){ return end.getFormatted(); }
const int TimeAllocation::getStartMins(){ return start.getFullMin(); }

const int TimeAllocation::getEndMins(){ return end.getFullMin(); } //returns DateTime object converted to minutes
long  TimeAllocation::getYMins() const { return start.getYMin(); }

TimeAllocation::TimeAllocation()
{
}


TimeAllocation::~TimeAllocation()
{
}



const std::ostream& operator << (std::ostream& os, TimeAllocation& tA) // overloading << operator
{

	os << tA.showDetails().rdbuf();
	return os;
}

static bool operator<(const TimeAllocation& t1, const TimeAllocation& t2) //overloading < operator
{

	long tm1 = t1.getYMins();
	long tm2 = t2.getYMins();
	return tm1 < tm2;
}
