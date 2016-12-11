#include "Meeting.h"
#include <iostream>


Meeting::Meeting(char const * start_, char const * end_, char const * desc_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	location = desc_;

}

void Meeting::showDetails()
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
			std::cout << (*i) << std::endl;
		}

	}

}

void Meeting::addAttendee(char const * a)
{
	attendees.push_back(a);
}

Meeting::Meeting()
{
}


Meeting::~Meeting()
{
}
