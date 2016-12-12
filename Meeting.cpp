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

const void Meeting::showDetails()
{
	std::cout << "     " << start.getFormatted() << " - " << end.getFormatted() << ": ";
	std::cout << location << " - ";
	for (auto i = attendees.begin(); i < attendees.end(); ++i)
	{
		if (i < attendees.end() - 1)
		{
			std::cout << (*i) << ", ";
		}
		else
		{
			std::cout << (*i);
		}

	}
	std::cout  << std::endl;

}

void Meeting::addAttendee(std::string &a)
{
	attendees.push_back(a);
}

const std::string Meeting::getStart(){ return start.getFormatted(); }
const std::string Meeting::getEnd(){ return end.getFormatted(); }
const std::string Meeting::getLoc(){ return location; }
const std::vector<std::string> Meeting::getAtt() { return attendees; }



Meeting::Meeting()
{
}


Meeting::~Meeting()
{
}

const std::ostream& operator << (std::ostream& os, Meeting& m)
{
	std::vector<std::string> attendees = m.getAtt();
	os << "     " << m.getStart() << " - " << m.getEnd() << ": ";
	os << m.getLoc() << " - ";
	for (auto i = attendees.begin(); i < attendees.end(); ++i)
	{
		if (i < attendees.end() - 1)
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