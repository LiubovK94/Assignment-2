#include "Meeting.h"
#include <iostream>


Meeting::Meeting(std::string &start_, std::string &end_, std::string &desc_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	location = desc_;

}

const int Meeting::getStartMins(){ return start.getMins(); }

const int Meeting::getStartHours(){ return start.getHours(); }


const int Meeting::getEndMins(){ return end.getMins(); }

const int Meeting::getEndHours(){ return end.getHours(); }

const std::stringstream Meeting::showDetails()
{

	std::stringstream ss; 

	ss << "     " << start.getFormatted() << " - " << end.getFormatted() << ": ";
	ss << location << " - ";
	for (auto i = attendees.begin(); i < attendees.end(); ++i)
	{
		if (i < attendees.end() - 1)
		{
			ss << (*i) << ", ";
		}
		else
		{
			ss << (*i);
		}

	}
	ss  << std::endl;
	return ss;
}

void Meeting::addAttendee(std::string &a)
{
	attendees.push_back(a);
}

const std::string Meeting::getStart(){ return start.getFormatted(); }
const std::string Meeting::getEnd(){ return end.getFormatted(); }
const std::string Meeting::getLoc(){ return location; }


Meeting::Meeting()
{
}


Meeting::~Meeting()
{
}

const std::ostream& operator << (std::ostream& os, Meeting& m)
{

	os << m.showDetails().rdbuf();
	return os;
}