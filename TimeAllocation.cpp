#include "TimeAllocation.h"
#include "WorkDone.h"
#include "BugFix.h"
#include "Meeting.h"
#include "Extra.h"

const void TimeAllocation::showDetails()
{
}
const std::string TimeAllocation::getStart(){ return start.getFormatted(); }
const std::string TimeAllocation::getEnd(){ return end.getFormatted(); }
const int TimeAllocation::getStartMins(){ return start.getMins(); }
const int TimeAllocation::getStartHours(){ return start.getHours(); }
const int TimeAllocation::getEndMins(){ return end.getMins(); }
const int TimeAllocation::getEndHours(){ return end.getHours(); }
const long  TimeAllocation::getYMins(){ return start.getYMin(); }
TimeAllocation::TimeAllocation()
{
}


TimeAllocation::~TimeAllocation()
{
}


const std::ostream& operator << (std::ostream& os, TimeAllocation& tA)
{

	if (WorkDone* w = dynamic_cast<WorkDone*>(&tA)) {
		os << (*w);
	}
	else if (BugFix* b = dynamic_cast<BugFix*>(&tA))
	{
		os << (*b);
	}
	else if (Meeting* m = dynamic_cast<Meeting*>(&tA))
	{
		os << (*m);
	}
	else if (Extra* e = dynamic_cast<Extra*>(&tA))
	{
		os << (*e);
	}
	return os;
}
